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
};