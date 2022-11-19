#pragma once

#include <classe.hpp>
#include <vector>
#include <echantillon.hpp>
#include <iostream>

class Histo {
    private:
        double _borne_inf;
        double _borne_sup;
        std::vector<Classe> _classes;
        int _nombre_classes;

    public:
        Histo(double inf, double sup, int nbclasse): _borne_inf(inf), _borne_sup(sup), _nombre_classes(nbclasse) {
            double amplitude = (sup - inf) / (nbclasse * 1.0);
            double tmp = inf;
            for(int i = 0; i < nbclasse; ++i) {
                _classes.push_back(Classe{tmp, tmp+amplitude});
                tmp+=amplitude;
            }
        }

        const std::vector<Classe> & getClasses() const {
            return _classes;
        }

        void ajouter(Echantillon & e) {

            size_t e_size = e.getTaille();
            
            for(int i = 0; i < e_size; ++i) {
                Valeur v = e.getValeur(i);
                auto findclass = [v](Classe & c) {
                    return v.getNombre() >= c.getBorneInf() && v.getNombre() < c.getBorneSup();
                };
                auto result = std::find_if(_classes.begin(), _classes.end(), findclass);                
                result->ajouter();          
            }
        }


};