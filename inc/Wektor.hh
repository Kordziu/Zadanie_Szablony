#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <cmath>
#include "rozmiar.h"
#include <iostream>
using namespace std;

template <typename Styp, int Swymiar>
class SWektor {
  Styp tab[Swymiar];

public:
  //////////// Konstruktor bezparametryczny i parametryczny ////////////
  SWektor()
  {for (int i = 0; i < Swymiar; i++){tab[i] = 0.0;}};
  explicit SWektor(Styp * tab)
  {for (int i = 0; i < Swymiar; i++){this->tab[i] = tab[i];}};

  /////////////// dodaj i podstaw ///////////////
  const SWektor & operator += (const SWektor & w1)
  {
    for(int i = 0; i < Swymiar; i++){
      this->tab[i] = this->tab[i] + w1[i]; 
    };
    return *this;
  };
  
  /////////////// dodawanie ///////////////
  SWektor operator + (const SWektor & w1) const
  {
    SWektor<Styp, Swymiar> wynik; 
      for(int i = 0; i < Swymiar; i++)
      {
        wynik[i] = this->tab[i] + w1[i];
      };   
    return wynik;
  };

  /////////////// odejmowanie ///////////////
  SWektor operator - (const SWektor & w1) const
  {
    SWektor<Styp, Swymiar> wynik;
      for(int i = 0; i < Swymiar; i++)
      {
         wynik[i] = this->tab[i] - w1[i];
      };
    return wynik;
  };

  /////////////// iloczyn skalarny ///////////////
  Styp operator * (const SWektor & w1) const
  {
    SWektor<Styp, Swymiar> tmp;
    Styp wynik;
    wynik = 0;
      for(int i = 0; i < Swymiar; i++)
      {
        tmp[i] = this->tab[i] * w1[i];
      };
      for(int i = 0; i < Swymiar; i++)
      {
        wynik = wynik + tmp[i];
      }
    return wynik;
  };
  
  /////////////// wektor * liczba ///////////////
  SWektor operator * (Styp liczba) const
  {
    SWektor<Styp, Swymiar> wynik;
      for(int i = 0; i < Swymiar; i++){
        wynik[i] = liczba * this->tab[i];
      }
    return wynik;
  };

  /////////////// operator równości ///////////////
  bool operator == (const SWektor & w1) const
  {  
    for(int i = 0; i < Swymiar; i++)
    {
      if(this->tab[i]!=w1[i])
      {
        return false;
      }
    }
    return true;
  };

  /////////////// operator nierówności ///////////////
  bool operator != (const SWektor & w1) const
  {
    if(*this == w1)
      {
	return false;
      }
    return true;
  };

  /////////////// dlugosc wektora ///////////////
  Styp dlugosc() const
  {
    Styp dlugosc = 0;
      for(int i = 0; i < Swymiar; i++)
      {
        dlugosc = dlugosc + this->tab[i] * this->tab[i];
      }
  return sqrt(dlugosc);
  };

  /////////////// Przeciążenia operatorów [] ///////////////
  const Styp & operator [] (int index) const //Styp z=W[3]
  {
    if (index < 0 || index >= ROZMIAR)
    {
      cerr << "Wartość spoza zakresu" << endl;
      exit(1);
    }
    return tab[index];
  };
  
  Styp & operator [] (int index)
  {
    if (index < 0 || index >= Swymiar)
    {
      cerr << "Wartość spoza zakresu" << endl;
      exit(1);
    }
    return tab[index];
  };

}; //Koniec klasy

/////////////// mnozenie liczba*wektor ///////////////
template <typename Styp, int Swymiar>
SWektor<Styp, Swymiar> operator * (Styp liczba, SWektor<Styp, Swymiar> w1)
{
  SWektor<Styp, Swymiar> wynik;

  for(int i = 0; i < Swymiar; i++){
    wynik[i] = liczba * w1[i];
  }

  return wynik;
}

/////////////// Przeciążenie operatora >> ///////////////
template <typename Styp, int Swymiar>
istream & operator >> (istream &is, SWektor<Styp, Swymiar> &w1){
  
  for(int i = 0; i < ROZMIAR; i++){
    is >> w1[i];
  }

  return is;
}

/////////////// Przeciążenie operatora << ///////////////
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
