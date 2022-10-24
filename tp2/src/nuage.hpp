#pragma once
#include <vector>
#include <typeinfo>
#include "cartesien.hpp"
#include "polaire.hpp"

template <typename point_type>
class Nuage {
    
    private:
        std::vector<point_type> _nuage;

    public:
        using value_type     = typename std::vector<point_type>::value_type;

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

            // if(typeid(p) == typeid(Cartesien)) {
            //     sumX += p.getX();
            //     sumY += p.getY();
            // } else if(typeid(p) == typeid(Polaire)){
            //     sumX += p.getAngle();
            //     sumY += p.getDistance();
            // }
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


// template <  typename value_type, //Polaire - Cartesien
//             template <typename T, typename A> class Container = std::vector, //Conteneur
//             typename alloc_t = std::allocator<value_type>>


// value_type barycentre_v2(const Container<value_type, alloc_t> & n) {
//     double sumX = 0, sumY = 0;
//     if(n.size() != 0) {
//         for(value_type p : n) {
 
//             Cartesien c;
//             p.convertir(c); //convertir en cartesien

//             sumX += c.getX();
//             sumY += c.getY();
//         }
//         //calcul barycentre cartesien
//         sumX = sumX/n.size();
//         sumY = sumY/n.size(); 
//     }
//     return value_type(Cartesien(sumX, sumY));
// }

template <typename Container>
auto barycentre_v2(const Container & n) {

    using polaire_or_cartesien = typename Container::value_type;
    //using polaire_or_cartesien = typename Nuage<Cartesien>::value_type;
    //using polaire_or_cartesien = typename Nuage<Cartesien>::typename std::vector<point_type>::value_type;;

    double sumX = 0, sumY = 0;

    if(n.size() != 0) {
        for(polaire_or_cartesien p : n) {
 
            Cartesien c;
            p.convertir(c); //convertir en cartesien

            sumX += c.getX();
            sumY += c.getY();
        }
        //calcul barycentre cartesien
        sumX = sumX/n.size();
        sumY = sumY/n.size(); 
    }
    return polaire_or_cartesien(Cartesien(sumX, sumY));
}

