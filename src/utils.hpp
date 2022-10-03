#pragma once

//Operator overloading
#include "Point.hpp"
#include "iostream"
#include "sstream"


std::ostream & operator<<(std::stringstream & ss, const Point & p);