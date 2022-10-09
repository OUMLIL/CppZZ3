#pragma once

#include "Point.hpp"
#include <sstream>
#include <iostream> //->s iosfwd forward declarations
#include <cmath>

class Cartesien;

class Polaire : public Point {

    private:
        double _angle{}, _dist{};

    public:
        Polaire(double angle=0, double dist=0): Point(), _angle(angle), _dist(dist) {}
        Polaire(const Cartesien & c);

        void afficher(std::stringstream & oss) const override {
            oss << "(a=" << _angle << ";d=" << _dist << ")";
        }

        //getters
        double getAngle() const {
            return _angle;
        }

        double getDistance() const {
            return _dist;
        }

        //setters
        void setAngle(const double ang) {
            _angle = ang;
        }

        void setDistance(const double dist) {
            _dist = dist;
        }

        void convertir(Cartesien & cartesian_point) const override;

        void convertir(Polaire & polaire_point) const override {
            polaire_point.setAngle(_angle);
            polaire_point.setDistance(_dist);
        }

        ~Polaire() = default;
};