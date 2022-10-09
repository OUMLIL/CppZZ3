#pragma once

//Operator overloading
#include "Point.hpp"
#include "iostream"
#include "sstream"
#include "Nuage.hpp"

std::ostream & operator<<(std::stringstream & ss, const Point & p);
