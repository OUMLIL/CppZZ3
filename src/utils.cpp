#include "utils.hpp"




std::ostream & operator<<(std::stringstream & oss, const Point & p) {
    
    p.afficher(oss);
    return oss;
}