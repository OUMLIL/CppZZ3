#include <vecteur.hpp>
#include <iterator>
#include <algorithm>
#include <sstream>

std::ostream & operator<<(std::ostream & ss, const vecteur & v) {
    if(v.size() == 0) {
        return ss;
    }
    std::stringstream tmp;
    std::transform(v.begin(), v.end(), std::ostream_iterator<int>(tmp, " "), 
                    [](int x) {return x;});

    std::string tmp_string{tmp.str()};
    tmp_string.pop_back();
    ss << tmp_string;

    return ss;
}

vecteur operator+(vecteur & v1, vecteur & v2) {
    int new_cap = v1._capacity + v2._capacity;
    int numb_elem = v1._nbelements + v2._nbelements;
    vecteur res{new_cap};
    std::copy(v1._array, v1._array + v1._nbelements, res._array);
    std::copy(v2._array, v2._array + v2._nbelements, res._array + v1._nbelements);
    res._nbelements = numb_elem;

    return res;
}

int operator*(const vecteur & v1, const vecteur & v2) {
    int res = 0;
    if(v1._nbelements == v2._nbelements) {
        for(int i = 0; i < v1._nbelements; ++i) {
            res += v1[i] * v2[i];
        }
    }

    return res;

}