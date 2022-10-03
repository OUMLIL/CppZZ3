#pragma once

#include "Point.hpp"
#include <sstream>
#include <iostream> //-> iosfwd forward declarations

class Polaire : public Point {

    private:
        double _angle{}, _dist{};

    public:
        Polaire(double angle=0, double dist=0): Point(), _angle(angle), _dist(dist) {}

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

        void convertir(Point & p) const override {
            double x = _dist * std::cos(_angle);
            double y = _dist * std::sin(_angle);
            std::cout << "CALLS Polaire conv" << std::endl;
            p.setAttributes(x, y);
        }

        void setAttributes(double ang, double dst) {
            _angle = ang; 
            _dist = dst;
        }

        ~Polaire() = default;
};