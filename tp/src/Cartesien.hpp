#pragma once

#include "Point.hpp"
#include <sstream>
#include <iostream>
#include <math.h>

class Cartesien : public Point {

    private:
        double _x{0}, _y{0};
    public:
        Cartesien(double x=0, double y=0): _x(x), _y(y) {}
        Cartesien(Polaire & p);
        
        void afficher(std::stringstream & oss) const override {
            oss << "(x=" << _x << ";y=" << _y << ")";
        }

        //getters
        double getX() const override {
            return _x;
        }

        double getY() const override {
            return _y;
        }
        
        //setters
        void setX(double x) {
            _x = x;
        }

        void setY(double y) {
            _y = y;
        }

        void convertir(Polaire & p) const override;
        void convertir(Cartesien & s) const override {
            s.setX(_x);
            s.setY(_y);
        }

        ~Cartesien() = default;
};