#pragma once

#include <sstream>

class Valeur {
    private:
        double _real;
        std::string _nom;

    public:
        Valeur(double r=0.0, std::string nom="inconnu"): _real(r), _nom(nom) { }

        double getNombre() const {
            return _real;
        }

        std::string getEtudiant() const { //? std::string const &
            return _nom;
        }

        double getNote() const {
            return _real;
        }
        
        void setNombre(double real) {
            _real = real;
        }

        void setNote(double a) {
            _real = a;
        }
        
        //! see effective modern cpp
        void setEtudiant(std::string && n) {
            _nom = n;
        }

        std::string toString() const {
            std::stringstream oss;
            oss << "(" << _nom << ";" << _real << ")";
            return oss.str();
        }

};

