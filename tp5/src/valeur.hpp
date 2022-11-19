#pragma once

class Valeur {
    private:
        double _real;

    public:
        Valeur(double r=0.0): _real(r) { }

        double getNombre() const {
            return _real;
        }

        void setNombre(double real) {
            _real = real;
        }
};

