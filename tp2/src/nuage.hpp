#pragma once
#include <vector>
#include <typeinfo>

template <typename point_type>
class Nuage {
    
    private:
        std::vector<point_type> _nuage;

    public:

        using const_iterator = typename std::vector<point_type>::const_iterator;
        
        Nuage() = default;

        void ajouter(const point_type element);
        size_t size() const;
        
        //iterator
        const_iterator begin() const;
        const_iterator end() const;

        //barycentre
};


template <typename point_type>
typename Nuage<point_type>::const_iterator Nuage<point_type>::begin() const {
    return _nuage.begin();
}

template <typename point_type>
typename Nuage<point_type>::const_iterator Nuage<point_type>::end() const {
    return _nuage.end();
}

template <typename point_type>
void Nuage<point_type>::ajouter(const point_type element) {
    _nuage.push_back(element);
}

template <typename point_type>
size_t Nuage<point_type>::size() const{
    return _nuage.size();
}

template <typename point_type>
point_type barycentre_v1(const Nuage<point_type> & n) {
    double sumX = 0, sumY = 0;

    if(n.size() != 0) {
        for(point_type p : n) {
 
            Cartesien c;
            p.convertir(c); //convertir en cartesien

            sumX += c.getX();
            sumY += c.getY();
        }
        //calcul barycentre cartesien
        sumX = sumX/n.size();
        sumY = sumY/n.size(); 
    }

    return point_type(Cartesien(sumX, sumY));
} 


template <>
Polaire barycentre_v1(const Nuage<Polaire> & n) {
    double sumAngle = 0, sumDist = 0;
    if(n.size() != 0) {
        for(Polaire p : n) {
            sumAngle += p.getAngle();
            sumDist  += p.getDistance();
        }
        sumAngle = sumAngle / n.size();
        sumDist  = sumDist / n.size();
    }

    return Polaire(sumAngle, sumDist);
}


template<template<typename ...> class Container, 
        typename Point>
Point barycentre_v2(const Container<Point> & n) {
    double sumX = 0, sumY = 0;
    if(n.size() != 0) {
        for(Point p : n) {
 
            Cartesien c;
            p.convertir(c); //convertir en cartesien

            sumX += c.getX();
            sumY += c.getY();
        }
        //calcul barycentre cartesien
        sumX = sumX/n.size();
        sumY = sumY/n.size(); 
    }
    return Point(Cartesien(sumX, sumY));
}

