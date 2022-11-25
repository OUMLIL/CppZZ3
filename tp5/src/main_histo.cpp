#include <cstdlib>
#include <iostream>

#include <histogramme.hpp>
#include <classe.hpp>
#include <valeur.hpp>
#include <echantillon.hpp>

int main() {
    using histo_t = Histogramme<>;

    double v[] = { 7.0, 9.0, 8.0, 5.0, 10.0, 14.0, 13.0, 6.0, 5.5, 13.5 };

    histo_t h(5.0,15.0,5);

    for (unsigned i = 0; i<10; ++i) h.ajouter(v[i]);

    std::vector<double> notes[] = { { 5.0, 6.0, 5.5 },
                                    { 7.0, 8.0 },
                                    { 9.0, 10.0 },
                                    {},
                                    { 14.0, 13.0, 13.5 } };
    std::cout << "testing oprator <<" << std::endl;
    std::cout << h;
 return EXIT_SUCCESS;
}
