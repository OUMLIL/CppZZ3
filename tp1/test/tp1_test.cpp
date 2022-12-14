// Entetes //---------------------------------------------------------------------------------------
#include "catch.hpp"
#include <sstream>
#include <typeinfo>

#include <cartesien.hpp>
#include <polaire.hpp>
#include <utils.hpp>
#include <nuage.hpp>
#include <vecteur.hpp>

// Tests //-----------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------ 1
TEST_CASE ( "TP1_Polaire::Constructeur" ) {
 const double a = 12.0;
 const double d = 24.0;

 Polaire p(a,d);

 REQUIRE ( p.getAngle() == Approx(a) );
 REQUIRE ( p.getDistance() == Approx(d) );
}

//------------------------------------------------------------------------------------------------ 2
TEST_CASE ( "TP1_Polaire::ConstructeurDefaut" ) {
 Polaire p;

 REQUIRE ( p.getAngle() == Approx(0.0) );
 REQUIRE ( p.getDistance() == Approx(0.0) );
}

//------------------------------------------------------------------------------------------------ 3
TEST_CASE ( "TP1_Polaire::Accesseurs" ) {
 const double a = 12.0;
 const double d = 24.0;

 Polaire p(13.0,25.0);

 p.setAngle(a);
 p.setDistance(d);

 REQUIRE ( p.getAngle() == Approx(a) );
 REQUIRE ( p.getDistance() == Approx(d) );
}

//------------------------------------------------------------------------------------------------ 4
TEST_CASE ( "TP1_Polaire::AccesseursConstants" ) {
 const Polaire p;

 REQUIRE ( p.getAngle() == Approx(0.0) );
 REQUIRE ( p.getDistance() == Approx(0.0) );
}

//------------------------------------------------------------------------------------------------ 5
TEST_CASE ( "TP1_Polaire::Affichage" ) {
 Polaire p(12.0,24.0);
 std::stringstream flux;

 p.afficher(flux);

 REQUIRE ( flux.str() == "(a=12;d=24)" );
}

//------------------------------------------------------------------------------------------------ 6
TEST_CASE ( "TP1_Cartesien::Constructeur" ) {
 const double x = 12.0;
 const double y = 24.0;

 Cartesien c(x,y);

 REQUIRE ( c.getX() == Approx(x) );
 REQUIRE ( c.getY() == Approx(y) );
}

//------------------------------------------------------------------------------------------------ 7
TEST_CASE ( "TP1_Cartesien::ConstructeurDefaut" ) {
 Cartesien c;

 REQUIRE ( c.getX() == Approx(0.0) );
 REQUIRE ( c.getY() == Approx(0.0) );
}

//------------------------------------------------------------------------------------------------ 8
TEST_CASE ( "TP1_Cartesien::Accesseurs" ) {
 const double x = 12.0;
 const double y = 24.0;

 Cartesien c(13.0,25.0);

 c.setX(x);
 c.setY(y);

 REQUIRE ( c.getX() == Approx(x) );
 REQUIRE ( c.getY() == Approx(y) );
}

//------------------------------------------------------------------------------------------------ 9
TEST_CASE ( "TP1_Cartesien::AccesseursConstants" ) {
 const Cartesien c;

 REQUIRE ( c.getX() == Approx(0.0) );
 REQUIRE ( c.getY() == Approx(0.0) );
}

//----------------------------------------------------------------------------------------------- 10
TEST_CASE ( "TP1_Cartesien::Affichage" ) {
 Cartesien c(12.0,24.0);
 std::stringstream flux;

 c.afficher(flux);

 REQUIRE ( flux.str() == "(x=12;y=24)" );
}

//----------------------------------------------------------------------------------------------- 11
TEST_CASE ( "TP1_Point::AffichageVirtuel" ) {
 Polaire p(12.0,24.0);
 Cartesien c(13.0,25.0);

 const Point & p1 = p;
 const Point & p2 = c;

 std::stringstream flux1;
 std::stringstream flux2;

 p1.afficher(flux1);
 p2.afficher(flux2);

 REQUIRE ( flux1.str() == "(a=12;d=24)" );
 REQUIRE ( flux2.str() == "(x=13;y=25)" );
}

//----------------------------------------------------------------------------------------------- 12
TEST_CASE ( "TP1_Point::OperateurFlux" ) {
 Polaire p(12.0,24.0);
 Cartesien c(13.0,25.0);

 const Point & p1 = p;
 const Point & p2 = c;

 std::stringstream flux1;
 std::stringstream flux2;

 flux1 << p1;
 flux2 << p2;

 REQUIRE ( flux1.str() == "(a=12;d=24)" );
 REQUIRE ( flux2.str() == "(x=13;y=25)" );
}

//----------------------------------------------------------------------------------------------- 13
TEST_CASE ( "TP1_Point::ConversionVersPolaire_V1" ) {
 const double x = 12.0;
 const double y = 24.0;
 const double a = 63.434948;
 const double d = 26.832815;

 const Cartesien c(x,y);
 Polaire p;

 c.convertir(p);

 REQUIRE ( p.getAngle() == Approx(a).epsilon(1e-3) );
 REQUIRE ( p.getDistance() == Approx(d).epsilon(1e-3) );
}

//----------------------------------------------------------------------------------------------- 14
TEST_CASE ( "TP1_Point::ConversionVersCartesien_V1" ) {
 const double a = 12.0; //en degr??s
 const double d = 24.0; 
 const double x = 23.475542;
 const double y = 4.9898805;

 const Polaire p(a,d);
 Cartesien c;

 p.convertir(c); //convert polaire to cart

 REQUIRE ( c.getX() == Approx(x).epsilon(1e-3) );
 REQUIRE ( c.getY() == Approx(y).epsilon(1e-3) );
}

//----------------------------------------------------------------------------------------------- 15
TEST_CASE ( "TP1_Point::ConversionVirtuel" ) {
 const double x = 12.0;
 const double y = 24.0;
 const double a = 63.434948;
 const double d = 26.832815;

 Cartesien c(x,y);
 Polaire p(a,d);

 const Point * x1 = &c;
 const Point * x2 = &p;

 Cartesien c1;
 Cartesien c2;
 Polaire p1;
 Polaire p2;

 x1->convertir(c1);
 x1->convertir(p1);
 x2->convertir(c2);
 x2->convertir(p2);

 REQUIRE ( c1.getX() == Approx(x).epsilon(1e-3) );
 REQUIRE ( c1.getY() == Approx(y).epsilon(1e-3) );
 REQUIRE ( c2.getX() == Approx(x).epsilon(1e-3) );
 REQUIRE ( c2.getY() == Approx(y).epsilon(1e-3) );

 REQUIRE ( p1.getAngle() == Approx(a).epsilon(1e-3) );
 REQUIRE ( p1.getDistance() == Approx(d).epsilon(1e-3) );
 REQUIRE ( p2.getAngle() == Approx(a).epsilon(1e-3) );
 REQUIRE ( p2.getDistance() == Approx(d).epsilon(1e-3) );
}

//----------------------------------------------------------------------------------------------- 16
TEST_CASE ( "TP1_Point::ConversionVersPolaire_V2" ) {
 const double x = 12.0;
 const double y = 24.0;
 const double a = 63.434948;
 const double d = 26.832815;

 Cartesien c(x,y);
 Polaire p(c);

 REQUIRE ( p.getAngle() == Approx(a).epsilon(1e-3) );
 REQUIRE ( p.getDistance() == Approx(d).epsilon(1e-3) );
}

//----------------------------------------------------------------------------------------------- 17
TEST_CASE ( "TP1_Point::ConversionVersCartesien_V2" ) {
 const double a = 12.0;
 const double d = 24.0;
 const double x = 23.475542;
 const double y = 4.9898805;

 Polaire p(a,d);
 Cartesien c(p);

 REQUIRE ( c.getX() == Approx(x).epsilon(1e-3) );
 REQUIRE ( c.getY() == Approx(y).epsilon(1e-3) );
}

//----------------------------------------------------------------------------------------------- 18
TEST_CASE ( "TP1_Nuage::Ajout" ) {
 Cartesien p1(12.0,24.0);
 Polaire p2(13.0,25.0);
 Polaire p3(p1);
 Cartesien p4(p2);

 Nuage n;

 REQUIRE ( n.size() == 0u );

 n.ajouter(p1);
 n.ajouter(p2);
 n.ajouter(p3);
 n.ajouter(p4);

 REQUIRE ( n.size() == 4u );
}


//----------------------------------------------------------------------------------------------- 19
TEST_CASE ( "TP1_Nuage::Iterateurs" ) {
 Cartesien p1(12.0,24.0);
 Polaire p2(13.0,25.0);
 Polaire p3(p1);
 Cartesien p4(p2);

 Nuage n;

 n.ajouter(p1);
 n.ajouter(p2);
 n.ajouter(p3);
 n.ajouter(p4);

 Point * t[4];
 unsigned i = 0;
 Nuage::const_iterator it = n.begin();

 while (it!=n.end()) {
    t[i++] = *(it++);
 }

 REQUIRE ( typeid(*(t[0])) == typeid(Cartesien) );
 REQUIRE ( typeid(*(t[1])) == typeid(Polaire) );
 REQUIRE ( typeid(*(t[2])) == typeid(Polaire) );
 REQUIRE ( typeid(*(t[3])) == typeid(Cartesien) );

 Cartesien & p5 = *static_cast<Cartesien *>(t[0]);
 Polaire & p6 = *static_cast<Polaire *>(t[1]);
 Polaire & p7 = *static_cast<Polaire *>(t[2]);
 Cartesien & p8 = *static_cast<Cartesien *>(t[3]);

 REQUIRE ( p5.getX() == Approx(12.0) );
 REQUIRE ( p5.getY() == Approx(24.0) );
 REQUIRE ( p6.getAngle() == Approx(13.0) );
 REQUIRE ( p6.getDistance() == Approx(25.0) );

 REQUIRE ( p7.getAngle() == Approx(63.434948).epsilon(1e-3) );
 REQUIRE ( p7.getDistance() == Approx(26.832815).epsilon(1e-3) );
 REQUIRE ( p8.getX() == Approx(24.359251).epsilon(1e-3) );
 REQUIRE ( p8.getY() == Approx(5.623776).epsilon(1e-3) );
}

//--------------------------------------------------------------------------------------Commun 20-22
double x[] = { 3,7,13,27 };
double y[] = { 4,8,16,32 };

Cartesien p1(x[0],y[0]);
Cartesien p2(x[1],y[1]);
Cartesien p3(x[2],y[2]);
Cartesien p4(x[3],y[3]);

Nuage n;

//----------------------------------------------------------------------------------------------- 20
TEST_CASE ( "TP1_Nuage::Barycentre" ) {
 n.ajouter(p1);
 n.ajouter(p2);
 n.ajouter(p3);
 n.ajouter(p4);

 Cartesien b = barycentre(n);

 REQUIRE ( b.getX() == Approx((x[0]+x[1]+x[2]+x[3])/4) );
 REQUIRE ( b.getY() == Approx((y[0]+y[1]+y[2]+y[3])/4) );
}

//----------------------------------------------------------------------------------------------- 21
TEST_CASE ( "TP1_Nuage::BarycentreCartesien" ) {
 Cartesien b = BarycentreCartesien()(n);

 REQUIRE ( b.getX() == Approx((x[0]+x[1]+x[2]+x[3])/4) );
 REQUIRE ( b.getY() == Approx((y[0]+y[1]+y[2]+y[3])/4) );
}

//----------------------------------------------------------------------------------------------- 22
TEST_CASE ( "TP1_Nuage::BarycentrePolaire" ) {
 Polaire p(Cartesien((x[0]+x[1]+x[2]+x[3])/4,(y[0]+y[1]+y[2]+y[3])/4));
 Polaire b = BarycentrePolaire()(n);

 REQUIRE ( b.getAngle() == Approx(p.getAngle()) );
 REQUIRE ( b.getDistance() == Approx(p.getDistance()) );
}

// Fin //-------------------------------------------------------------------------------------------
TEST_CASE ("Vecteur1") {
  const vecteur v;
 
  REQUIRE ( v.capacity() >= 10 );
  REQUIRE ( v.size()     == 0  );
}

TEST_CASE ("Vecteur2" ) {
  vecteur v(20);
 
  REQUIRE ( v.capacity() == 20 );
  REQUIRE ( v.size()     == 0  );
}

TEST_CASE ("Vecteur3" ) {
  vecteur v(5);

  SECTION("ajout de quelques elements") {
    REQUIRE ( v.capacity() == 5 );

    for (int i=0; i<4; ++i)
      v.push_back(i*1.0);

    REQUIRE ( v.size()     == 4  );
  }

  SECTION("tableau un peu agrandi") {
    // on peut verifier que vecteur est bien un nouveau :-) 
  REQUIRE ( v.capacity() == 5 );
    for (int i=0; i<6; ++i)
      v.push_back(i*1.0);

    REQUIRE ( v.capacity()  == 10 );
    REQUIRE ( v.size()      == 6  );
  }

  SECTION("on verifie les valeurs dans le vecteur") {
    for (int i=0; i<25; ++i)
      v.push_back(i*1.0);

    REQUIRE( v.capacity() ==  40 );
    REQUIRE( v.size()     ==  25 );

    for (int i=0; i<25; ++i)
      CHECK(v[i] == Approx(i*1.0));  // :-)
    
    for(double x : v) {
     CHECK(x == Approx(x*1.0));  // :-)
    }

    SECTION("on verifie les exceptions") {
      REQUIRE_THROWS_AS( v[-1] == 0,  vecteur::OutOfRangeException ); 
    }
  }
}

TEST_CASE("Vecteur4") {
  vecteur v;
  for (int i=0; i<10; ++i)
      v.push_back(i*1.0);

  SECTION("constructeur de copie") {
    const vecteur c(v);
    for(double x : c) {
     CHECK(x == Approx(x*1.0));  // :-)
    }
  }

  SECTION("affectation") {
    vecteur x;
    for (int i=0; i<6; ++i) {
      x.push_back(-1);
    }
    x = v;
    for(double e : x) {
     CHECK(e == Approx(e*1.0));  // :-)
    }
  }

  SECTION("operateur <<") {
    std::stringstream ss;
    ss << v;
    CHECK(ss.str() == "0 1 2 3 4 5 6 7 8 9");
  }

  SECTION("operateur << vecteur vide") {
    std::stringstream ss;
    vecteur x;
    ss << x;
    CHECK(ss.str() == "");
  }
}

TEST_CASE("Vecteur 5") {
  vecteur v;
  for (int i=0; i<5; ++i) //0 1 2 3 4
      v.push_back(i*1.0);
  
  vecteur v2;
  for (int i=5; i<8; ++i) //5 6 7
    v2.push_back(i*1.0);
  
  SECTION("Concatenation +") { 
    std::stringstream ss;
    vecteur v3 = v + v2; //0 1 2 3 4 5 6 7
    ss << v3;
    CHECK(ss.str() == "0 1 2 3 4 5 6 7");

    vecteur v4 = v + v3; //0 1 2 3 4 0 1 2 3 4 5 6 7
    ss.str("");
    ss << v4;
    CHECK(ss.str() == "0 1 2 3 4 0 1 2 3 4 5 6 7");
  }

  SECTION("Produit scalaire") {
    vecteur v4;
    vecteur v5;
    for (int i=1; i<4; ++i){
      v4.push_back(i*1.0);
      v5.push_back(i*1.0);
    }
    int r = v4 * v5;
    CHECK(r == (1*1) + (2*2) + (3*3));
  }
}