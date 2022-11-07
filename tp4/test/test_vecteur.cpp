// Entetes //---------------------------------------------------------------------------------------
#include <algorithm>
#include <deque>
#include <vecteur.hpp>

// Fonction principale //---------------------------------------------------------------------------
int main(void) {
 complexe_t::stats();

 Vecteur v1;
 Vecteur v2;

 std::cout << std::endl << "v1 = " << v1 << std::endl;
 std::cout << "v2 = " << v2 << std::endl;
 //constructions par defaut 20
 complexe_t::stats();  //0 20 0 0

 //20 rvalues -> 20 affct par mouvement 
 //20 construction ad hoc
 for (unsigned i = 0; i<v1.getTaille(); ++i) v1[i]=complexe_t(10*i,i*i);
 for (unsigned i = 0; i<v2.getTaille(); ++i) v2[i]=complexe_t(i,i+1);

 std::cout << std::endl << "v1 = " << v1 << std::endl;
 std::cout << "v2 = " << v2 << std::endl;
 complexe_t::stats(); //20 40 0 20


 //10 construction par def + 10 affectations par copie
 Vecteur v3 = v1; 
 std::cout << std::endl << "v3 = " << v3 << std::endl;
 complexe_t::stats(); //30 50 10 20


 Vecteur v4; //10 par déf constructions
 v4 = v1+v2; //10 affec copie
 /*
  {
      10 par déf

      10 affect mvm (+ des complexes)
      10 adhoc

      10 construction mvm ?
  }
 */

 std::cout << std::endl << "v4 = " << v4 << std::endl;
 complexe_t::stats();  //50 80 20 30

//  Vecteur v5;

//  v5=v1*(v2+v4);

//  std::cout << std::endl << "v5 = " << v5 << std::endl;
//  complexe_t::stats();

//  std::deque<complexe_t> liste;

//  for (unsigned i = 0; i<v5.getTaille(); ++i) liste.push_back(v5[i]);

//  std::cout << std::endl << "liste = v5" << std::endl;
//  complexe_t::stats();

//  std::sort(liste.begin(),liste.end(),ComparateurComplexe());

//  std::cout << std::endl;
//  for (unsigned i = 0; i<liste.size(); ++i) std::cout << liste[i] << " ";
//  std::cout << std::endl;
//  complexe_t::stats();
}

// Fin //-------------------------------------------------------------------------------------------
