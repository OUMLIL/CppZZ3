#pragma once

#include <iostream>
#include <memory>
#include <carte.hpp>
#include <vector>
#include <iterator>
#include <algorithm>
#include <sstream>

class UsineCarte {
    private:
        int _nb_cartes{};
        static int _total_cartes;
    
    public:
        //UsineCarte() {}
        UsineCarte(int n=52): _nb_cartes(n) {_total_cartes = 0;}
        auto getCarte() { 
            std::unique_ptr<Carte> p(nullptr);
            if(_total_cartes > _nb_cartes - 1) {
                return p;
            }
            p.reset(new Carte(UsineCarte::_total_cartes));
            _total_cartes++;

            return p;
        }
        
        int getNbCarte() const {
            return _nb_cartes;
        }

        UsineCarte(UsineCarte & inUsineCarte) = delete;
        UsineCarte & operator=(UsineCarte & inUsineCarte) = delete;
};

using paquet_t = std::vector<std::unique_ptr<Carte>>;

inline void remplir(paquet_t & paquet, UsineCarte & usine) {

    for(int i = 0; i < usine.getNbCarte(); ++i) {
        paquet.push_back(usine.getCarte());
    }
}

inline std::ostream & operator<<(std::ostream & ss, paquet_t & paquet) {
    //std::cout << "size : "<< paquet.size() << std::endl;
    if(paquet.size() == 0) {
        return ss;
    }

    std::stringstream tmp;
    std::transform(paquet.begin(), paquet.end(), 
                    std::ostream_iterator<int>(tmp, " "), 
                    [](std::unique_ptr<Carte> & x) {return x->getValeur();});
    std::string tmp_string{tmp.str()};
    ss << tmp_string;

    // for(auto & element : paquet) {
    //     ss << element->getValeur() << " ";
    // }  
    return ss;
}