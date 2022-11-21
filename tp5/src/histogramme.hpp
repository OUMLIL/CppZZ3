#pragma once

#include <classe.hpp>
#include <vector>
#include <echantillon.hpp>
#include <iostream>
#include <set>
#include <algorithm>

template<typename TypeToCompare>
class ComparateurQuantite {
    public:
        //! comparison object must be invocable as const
        bool operator()(const TypeToCompare & c1, const TypeToCompare & c2) const {
            return c1.getQuantite() >= c2.getQuantite();
        }
};

template<typename T=std::less<Classe>>
class Histogramme {
    private:
        double _borne_inf;
        double _borne_sup;
        // std::vector<Classe> _classes;
        std::set<Classe, T> _classes;
        int _nombre_classes;

    public:
        using set_t = typename std::set<Classe, T>;
        Histogramme(double inf, double sup, int nbclasse): _borne_inf(inf), _borne_sup(sup), _nombre_classes(nbclasse) {
            double amplitude = (sup - inf) / (nbclasse * 1.0);
            double tmp = inf;
            for(int i = 0; i < nbclasse; ++i) {
                // _classes.push_back(Classe{tmp, tmp+amplitude});
                _classes.insert(Classe{tmp, tmp+amplitude});
                tmp+=amplitude;
            }
        }

        // const std::vector<Classe> & getClasses() const {
        //     return _classes;
        // }

        const set_t & getClasses() const {
            return _classes;
        }

        void ajouter(Echantillon & e) {

            int e_size = e.getTaille();
            
            for(int i = 0; i < e_size; ++i) {
                Valeur v = e.getValeur(i);

                auto findclass = [v](const Classe & c) {
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

        void ajouter(double e) {
            auto findclass = [e](const Classe & c) {
                    return e >= c.getBorneInf() && e < c.getBorneSup();
            };

            auto result = std::find_if(_classes.begin(), _classes.end(), findclass);
            auto ex = _classes.extract(result).value(); 
            ex.ajouter();
            _classes.insert(std::move(ex)); 
        }
};  