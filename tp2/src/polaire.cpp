#include "point.hpp"
#include "polaire.hpp"
#include "cartesien.hpp"



Polaire::Polaire(const Cartesien & c) {
    c.convertir(*this);
}

void Polaire::convertir(Cartesien & c) const {
 //Polaire -> cartesien (appel sur polaire)
    double x = _dist * std::cos(_angle * (M_PI/180));
    double y = _dist * std::sin(_angle * (M_PI/180));
    std::cout << "polaire -> cartesien" << std::endl;
    c.setX(x);
    c.setY(y);
}

