// Entetes //---------------------------------------------------------------------------------------
#include <iostream>
#include <complexe.hpp>

// Fonction principale //---------------------------------------------------------------------------
int main(void) {
 complexe_t::stats(); //0 0 0 0 

 std::cout << std::endl << "complexe_t c1(1,2);" << std::endl;
 complexe_t c1(1,2); 
 complexe_t::stats(); //0 1 0 0 construction simple

 std::cout << std::endl << "complexe_t c2(3,4);" << std::endl;
 complexe_t c2(3,4);
 complexe_t::stats(); //0 2 0 0 construction simple

 std::cout << std::endl << "complexe_t c3(c1);" << std::endl;
 complexe_t c3(c1); //construction par copie -> car c1 lvalue
 complexe_t::stats(); //0 3 1 0 copie

 std::cout << std::endl << "complexe_t c4(std::move(c2));" << std::endl;
 complexe_t c4(std::move(c2)); //construction par mouvement, converts c2 to rvalue
 complexe_t::stats(); //0 4 1 1

 std::cout << std::endl << "c3=c1;" << std::endl;
 c3=c1; //affectation + copie
 complexe_t::stats(); //1 4 2 1

 std::cout << std::endl << "c4=complexe_t(5,6);" << std::endl;
 c4=complexe_t(5,6); //rvalue en params -> affectation + copie mouvement
 complexe_t::stats(); //2 5 2 2

 return 0;
}

//affec  cpy 1
//affec  mvm 1
//constr spl 3
//constr cpy 1
//constr mvm 1

// Fin //-------------------------------------------------------------------------------------------