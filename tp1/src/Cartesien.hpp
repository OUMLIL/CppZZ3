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
        
        void afficher(std::stringstream & oss) const override {
            oss << "(x=" << _x << ";y=" << _y << ")";
        }

        //getters
        double getX() const {
            return _x;
        }

        double getY() const {
            return _y;
        }
        
        //setters
        void setX(double x) {
            _x = x;
        }

        void setY(double y) {
            _y = y;
        }

        void setAttributes(double x, double y) {
            _x = x; 
            _y = y;
        }

        //Conversion
        void convertir(Point & p) const override {
            
            double dist = std::sqrt(std::pow(_x, 2)+std::pow(_y, 2)); //pow less performant than x*x
            double ang  = std::atan(_y / _x) * (180.0/3.141592653589793238463);

            
            p.setAttributes(ang, dist);
        }

        ~Cartesien() = default;
};