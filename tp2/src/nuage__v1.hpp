#pragma once
#include <vector>
#include <typeinfo>

template <typename T>
class Nuage {
    
    private:
        std::vector<T> _nuage;
    public:

        using const_iterator = typename std::vector<T>::const_iterator;
        
        Nuage() = default;

        void ajouter(const T element);
        size_t size() const;
        
        //iterator
        const_iterator begin() const;
        const_iterator end() const;

        //barycentre
};


template <typename T>
typename Nuage<T>::const_iterator Nuage<T>::begin() const {
    return _nuage.begin();
}

template <typename T>
typename Nuage<T>::const_iterator Nuage<T>::end() const {
    return _nuage.end();
}

template <typename T>
void Nuage<T>::ajouter(const T element) {
    _nuage.push_back(element);
}

template <typename T>
size_t Nuage<T>::size() const{
    return _nuage.size();
}

template <typename T>
T barycentre_v1(const Nuage<T> & n) {
    double sumX = 0, sumY = 0;

    if(n.size() != 0) {
        for(T p : n) {
 
            Cartesien c;
            p.convertir(c); //convertir en cartesien

            sumX += c.getX();
            sumY += c.getY();
        }
        //calcul barycentre cartesien
        sumX = sumX/n.size();
        sumY = sumY/n.size(); 
    }

    return T(Cartesien(sumX, sumY));
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