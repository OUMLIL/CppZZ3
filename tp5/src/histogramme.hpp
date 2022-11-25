#pragma once

#include <classe.hpp>
#include <vector>
#include <echantillon.hpp>
#include <iostream>
#include <set>
#include <algorithm>
#include <typeinfo>
#include <map>

template<typename TypeToCompare>
struct ComparateurQuantite {
    //! comparison object must be invocable as const
    bool operator()(const TypeToCompare & c1, const TypeToCompare & c2) const {
        int const q1 = c1.getQuantite();
        int const q2 = c2.getQuantite();
        if(q1 == q2) {
            return c1 < c2;
        } else {
            return c1.getQuantite() > c2.getQuantite();
        }
    }
};

template<typename T=std::less<Classe>>
class Histogramme {
    private:
        using set_t = typename std::set<Classe, T>;
        using mmap_t = std::multimap<Classe, Valeur>;
        double _borne_inf{};
        double _borne_sup{};
        int _nombre_classes{};

        // std::vector<Classe> _classes;
        std::set<Classe, T> _classes{};
        mmap_t _classes_values_map{};
        

    public:
        Histogramme(double inf, double sup, int nbclasse): _borne_inf(inf), _borne_sup(sup), _nombre_classes(nbclasse) {
            double amplitude = (sup - inf) / (nbclasse * 1.0);
            double tmp = inf;

            auto gen = [&]() mutable -> Classe {
                double supp  = tmp + amplitude;
                double inff = tmp;
                tmp += amplitude;
                return Classe{inff, supp};
            };

            std::generate_n(std::inserter(_classes ,_classes.begin()), nbclasse, gen);
        }

        template<typename relation_ordre>
        Histogramme(Histogramme<relation_ordre> const & inHisto) {
            _classes.clear();
            std::copy(inHisto.getClasses().begin(), inHisto.getClasses().end(), 
                        std::inserter(_classes, _classes.begin()));            
        }
       

        const set_t & getClasses() const {
            return _classes;
        }

        const mmap_t & getValeurs() const {
            return _classes_values_map;
        }

        auto getValeurs(Classe const & c) {
            auto range = _classes_values_map.equal_range(c);
            return range;
        }

        void ajouter(Echantillon & e) {

            int e_size = e.getTaille();
            
            for(int i = 0; i < e_size; ++i) {
                Valeur v = e.getValeur(i);

                auto findclass = [&v](const Classe & c) {
                    return v.getNombre() >= c.getBorneInf() && v.getNombre() < c.getBorneSup();
                };

                auto result = std::find_if(_classes.begin(), _classes.end(), findclass);
                auto ex = _classes.extract(result).value(); 
                ex.ajouter();
                
                _classes.insert(std::move(ex));  
                // move -> ex useless after and imagine if _classe had a complicated type 
                    // it'll be better to move :)
            }
        }

        //! manière à pouvoir associer plusieurs valeurs à une classe
        void ajouter(double e) {
            auto findclass = [e](const Classe & c) {
                    return e >= c.getBorneInf() && e < c.getBorneSup();
            };
            auto result = std::find_if(_classes.begin(), _classes.end(), findclass);
            auto ex = _classes.extract(result).value(); 
            ex.ajouter();
            _classes_values_map.insert(std::pair{ex, Valeur(e)});
            _classes.insert(std::move(ex)); 
        }
        template<typename U>
        friend std::ostream & operator<<(std::ostream & ss, Histogramme<U> const & histo); 
    // const std::vector<Classe> & getClasses() const {
        //     return _classes;
    // }
};  

template<typename U>
inline std::ostream & operator<<(std::ostream & ss, Histogramme<U> const & histo) {
    std::stringstream tmp;
    auto i = histo._classes_values_map.begin();

    for(; i != histo._classes_values_map.end();) {
        auto itr = histo._classes_values_map.lower_bound(i->first);
        std::cout << "[" << itr->first.getBorneInf() << ";" << itr->first.getBorneSup() << "] = " << itr->first.getQuantite() << " : " ;
        for(; itr != histo._classes_values_map.upper_bound(i->first); itr++) {
            std::cout << itr->second.toString() << " ";
        }
        i = itr;
        std::cout << std::endl;
    }

    return ss;
}