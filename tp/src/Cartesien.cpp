#include "Cartesien.hpp"
#include "Point.hpp"
#include "Polaire.hpp"

Cartesien::Cartesien(Polaire & p) {
    p.convertir(*this);
}

void Cartesien::convertir(Polaire & p) const {
    //cartesian -> polaire (call sur cartesian)
    double dist = std::sqrt(std::pow(_x, 2)+std::pow(_y, 2)); //pow less performant than x*x
    double ang  = std::atan(_y / _x) * (180.0/3.141592653589793238463);
            
    p.setAngle(ang);
    p.setDistance(dist);
}