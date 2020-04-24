#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>
using namespace std;

template <typename Styp, int Swymiar>
class SWektor {
  Styp tab[Swymiar];

public:
  SWektor() {for (int i = 0; i < Swymiar; i++){tab[i] = 0.0;}};
  SWektor(Styp * tab) {for (int i = 0; i < Swymiar; i++){this->tab[i] = tab[i];}};
  
  const SWektor <Styp, Swymiar> & operator += (const SWektor<Styp, Swymiar> & W2);
  SWektor<Styp, Swymiar> operator + (const SWektor<Styp, Swymiar> & W2) const;
  SWektor<Styp, Swymiar> operator - (const SWektor<Styp, Swymiar> & W2) const;
  Styp operator * (const SWektor<Styp, Swymiar> & W2) const; //iloczyn skalarny
  SWektor<Styp, Swymiar> operator * (Styp liczba) const; //mnożenie wektor*liczba

  bool operator == (const SWektor<Styp, Swymiar> & W2) const;
  bool operator != (const SWektor<Styp, Swymiar> & W2) const;

  Styp dlugosc() const;

//Przeciążenia operatorów []
  const Styp & operator [] (int index) const{return tab[index];}; //Styp z=W[3]
  Styp & operator [] (int index){return tab[index];};
};

//mnozenie liczba*wektor
template <typename Styp, int Swymiar>
SWektor<Styp, Swymiar> operator * (Styp l1, SWektor<Styp, Swymiar> W2);

//Przeciążenie operatora >>
template <typename Styp, int Swymiar>
istream & operator >> (istream &is, SWektor<Styp, Swymiar> &w1){
  
  for(int i = 0; i < ROZMIAR; i++){
    is >> w1[i];
  }

  return is;
}


//Przeciążenie operatora << 
template <typename Styp, int Swymiar>
ostream & operator << (ostream &os, const SWektor<Styp, Swymiar> &w1){
  int i;  
  os <<'[';
  for(i = 0; i < Swymiar; i++){
    os << w1[i];
    if(i < Swymiar-1){
      os << ',';
    }
  }
  os << ']';
  os << endl;
  return os;
}



#endif
