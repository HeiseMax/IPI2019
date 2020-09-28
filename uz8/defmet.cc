#include <iostream>
#include "fcpp.hh"
// Programm zu Aufgabe Objektverhalten in C++

// Volker Reichenberger, Sommersemester 2001

/* @VERBON */
class Zahl
{
public:
  Zahl();                // Konstruktor
  Zahl( const int& n );  // int-Konstruktor
  Zahl( const Zahl& n ); // Copy-Konstruktor
  ~Zahl();               // Destruktor
  // int-Zuweisung
  Zahl& operator=( const int& n );
  // Zuweisung
  Zahl& operator=( const Zahl& n );
  // Addition
  Zahl operator+( const Zahl& n );
private:
  int z;
};

Zahl::Zahl() {  std::cout << "normalerKon" << std::endl; z = 0; }
Zahl::Zahl( const int& n )  {std::cout << "intKOnstr" << std::endl; z = n; }
Zahl::Zahl( const Zahl& n ) { std::cout << "kopyKonst" << std::endl;z = n.z; }
Zahl::~Zahl()               { std::cout << "destruk." << std::endl;}
Zahl& Zahl::operator=( const int& n )
{ z=n;  std::cout << "intzuweis" << std::endl; return *this; }
Zahl& Zahl::operator=( const Zahl& n )
{ z=n.z; std::cout << "zuwei." << std::endl; return *this; }
Zahl Zahl::operator+( const Zahl& n )
{ std::cout << "adii" << std::endl; return Zahl(z+n.z); }

Zahl f( Zahl a, Zahl& b) { std::cout << "fMethode" << std::endl; return a+b; }

int main()
{
  Zahl a(3), b(4);
  Zahl c(a), d, e;
  d = 5;
  d = f(d,c);
  e = d + a + b;
  return 0;
}
/* @VERBOFF */


