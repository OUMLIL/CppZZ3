#pragma once

//Operator overloading
#include "point.hpp"
#include "iostream"
#include "sstream"
#include "nuage.hpp"

std::ostream & operator<<(std::stringstream & ss, const Point & p);
