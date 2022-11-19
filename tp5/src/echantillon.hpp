#pragma once
#include <vector>
#include <valeur.hpp>
#include <algorithm>

class valeurComp {
    public:
        bool operator()(const Valeur & a, const Valeur & b) {
            return a.getNombre() < b.getNombre();
        }
};

class Echantillon {
    private:
        std::vector<Valeur> _values;
    public:
        Echantillon() = default;
        size_t getTaille() {
            return _values.size();
        }

        void ajouter(const Valeur & v) {
            _values.push_back(v);
        }

        // need < operator on values
        const Valeur & getMinimum() const {
            if(_values.size() == 0u) {
                throw std::domain_error("empty container");
            }
            std::vector<Valeur>::const_iterator result;
            result = std::min_element(_values.begin(), _values.end(), valeurComp{});
            return *result;
        }

        const Valeur & getMaximum() const {
            if(_values.size() == 0u) {
                throw std::domain_error("empty container");
            }
            std::vector<Valeur>::const_iterator result;
            result = std::max_element(_values.begin(), _values.end(), valeurComp{});
            return *result;
        }

        const Valeur & getValeur(int index) {
            if(index >= (int) _values.size() || index < 0) {
                throw std::out_of_range("index out of range");
            }
            return _values[index];
        }
        

};
