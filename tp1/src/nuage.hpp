#pragma once

#include "point.hpp"
#include <vector>
#include <iterator>
#include "cartesien.hpp"
#include "polaire.hpp"

class Nuage {
    private:
        std::vector<Point *> points;
    public:

        class const_iterator {
            private:

                // using C = decltype(points);
                // using I = C::iterator;
                std::vector<Point *>::iterator _ptr;
            public:
                // using value_type = I::value_type;

                const_iterator(std::vector<Point *>::iterator p): _ptr(p){
                }

                const_iterator & operator++(){
                    _ptr++;
                    return *this;
                }

                const_iterator operator++(int) {
                    const_iterator ret_val = *this;
                    ++(*this);
                    return ret_val;
                }

                friend bool operator==(const_iterator a, const_iterator b) {
                    return a._ptr == b._ptr;
                }

                friend bool operator!=(const_iterator a, const_iterator b) {
                    return a._ptr != b._ptr;
                }

                Point * operator *() {
                    return *_ptr;
                }
        };

        size_t size() {
            return points.size();
        }

        void ajouter(Point & p) {
            points.push_back(&p);
        }

        const_iterator begin() {
            return const_iterator(points.begin());
        }

        const_iterator end() {
            return const_iterator(points.end());
        }   

        friend Cartesien barycentre(Nuage & n) {
            double sumX = 0, sumY = 0;
            for(Point * p : n) {
                Cartesien c;
                p->convertir(c);
                sumX += c.getX();
                sumY += c.getY();
            }
            Cartesien c(sumX/n.size(), sumY/n.size());
            return c;
        }
};

class BarycentreCartesien {

    public:
        Cartesien operator()(Nuage & n) {
            Cartesien c = barycentre(n);
            return c;
        }

};

class BarycentrePolaire {

    public:
        Polaire operator()(Nuage & n) {
            Polaire c(BarycentreCartesien()(n));
            return c;
        }

};