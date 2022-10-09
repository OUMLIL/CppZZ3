#pragma once

#include "sstream"

class Polaire;
class Cartesien;

class Point {

    private:
        //attributes
    public:
        
        //constructors
        Point() = default;

        //methods
        virtual void afficher(std::stringstream & oss) const = 0;
        
        virtual void convertir(Polaire & p) const = 0;
        virtual void convertir(Cartesien & c) const = 0;

        virtual double getX() const {
            return 0;
        }
        virtual double getY() const {
            return 0;
        }

        //add two fonctions here Point should know Cartesian and Polar
};