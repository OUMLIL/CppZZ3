#include <vecteur.hpp>
#include <iterator>
#include <algorithm>

std::ostream & operator<<(std::ostream & ss, const vecteur & v) {
    std::transform(v.begin(), v.end(), std::ostream_iterator<int>(ss, " "), 
                    [](int x) {return x;});
    return ss;
}


//concatenation
vecteur operator+(const vecteur & v1, const vecteur & v2) {
    return vecteur();
}

//produit scalaire
vecteur operator*(const vecteur & v1, const vecteur & v2) {
    return vecteur();
}

