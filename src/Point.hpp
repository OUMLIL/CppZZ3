#pragma once

#include "sstream"

class Point {

    private:
        //attributes
    public:
        
        //constructors
        Point() = default;

        //methods
        virtual void afficher(std::stringstream & oss) const = 0;
        virtual void convertir(Point & p) const = 0;
        
        virtual void setAttributes(double x, double y) = 0;

        //add two fonctions here Point should know Cartesian and Polar
};