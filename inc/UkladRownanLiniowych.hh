#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Macierz.hh"
#include "Wektor.hh"
#include "rozmiar.h"

using namespace std;

class UkladRownan {
  Macierz A;
  Wektor b;
public:
  UkladRownan() : A(), b() {};
  UkladRownan(Macierz AA, Wektor bb) : A(AA), b(bb) {};
  const Macierz & get_A() const {return A;};
  const Wektor & get_b() const {return b;};
  Wektor w_bledu() const;
  double dl_bledu() const;
  
  Wektor Oblicz() const;
};


istream& operator >> (istream &Strm, UkladRownan &UklRown);


ostream& operator << (ostream &Strm, const UkladRownan &UklRown );


#endif
