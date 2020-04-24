#include "Wektor.hh"
#include "rozmiar.h"
#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;


//dodaj i podstaw wynik za podany wektor
template <typename Styp, int Swymiar>
const SWektor<Styp, Swymiar>& SWektor<Styp, Swymiar>::operator += (const SWektor &w1){
 
  for(int i = 0; i < Swymiar; i++){
    this->tab[i] = this->tab[i] + w1[i]; 
  };
  return *this;
}

//dodawanie dwóch wektorów
template <typename Styp, int Swymiar>
SWektor<Styp, Swymiar> SWektor<Styp, Swymiar>::operator + (const SWektor &w1) const{
  SWektor<Styp, Swymiar> wynik;
    for(int i = 0; i < Swymiar; i++){
      wynik[i] = this->tab[i] + w1[i];
    };
   
  return wynik;
}

//odejmowanie dwóch wektorów
template <typename Styp, int Swymiar>
SWektor<Styp, Swymiar> SWektor<Styp, Swymiar>::operator - (const SWektor &w1) const{
  SWektor<Styp, Swymiar> wynik;
    for(int i = 0; i < Swymiar; i++){

    wynik[i] = this->tab[i] - w1[i];
  };

  return wynik;
}

//iloczyn skalarny
template <typename Styp, int Swymiar>
Styp SWektor<Styp, Swymiar>::operator * (const SWektor &w1) const{
  SWektor<Styp, Swymiar> tmp;
  Styp wynik = 0;
    for(int i = 0; i < Swymiar; i++){
      tmp[i] = this->tab[i] * w1[i];
  };
    
    for(int i = 0; i < Swymiar; i++){
      wynik = wynik + tmp[i];
    }
  return wynik;
}

//mnożenie wektora przez liczbę
template <typename Styp, int Swymiar>
SWektor<Styp, Swymiar> SWektor<Styp, Swymiar>::operator * (Styp liczba) const{
  SWektor<Styp, Swymiar> wynik;
    for(int i = 0; i < Swymiar; i++){
      wynik[i] = liczba * this->tab[i];
    }

  return wynik;
}

//mnożenie liczba * wektor
template <typename Styp, int Swymiar>
SWektor<Styp, Swymiar> operator * (Styp liczba, SWektor <Styp, Swymiar> w1){
  SWektor<Styp, Swymiar> wynik;

  for(int i = 0; i < Swymiar; i++){
    wynik[i] = liczba * w1[i];
  }

  return wynik;
}

//porównanie dwóch wektorów
template <typename Styp, int Swymiar>
bool SWektor<Styp, Swymiar>::operator == (const SWektor &w1) const{
  
  for(int i = 0; i < Swymiar; i++){
    if(this->tab[i]!=w1[i]){
      return false;
    }
  }
  return true;
}

//porownanie != dwóch wektorów
template <typename Styp, int Swymiar>
bool SWektor<Styp, Swymiar>::operator != (const SWektor &w1) const{
 
  for(int i = 0; i < Swymiar; i++){
    if(this->tab[i]==w1[i]){
      return false;
    }
  }
  return true;
}

//dlugosc wektora
template <typename Styp, int Swymiar>
Styp SWektor<Styp, Swymiar>::dlugosc() const{
  Styp dlugosc = 0;

  for(int i = 0; i < Swymiar; i++){
  dlugosc = dlugosc + this->tab[i] * this->tab[i];
  }

  return sqrt(dlugosc);
}

//przeciazenie operatora <<     Przeniesione do .hh
//ostream & operator << (ostream &os, const Wektor &w1){
//  int i;
//  
//  os <<'[';
//  for(i = 0; i < ROZMIAR; i++){
//    os << w1[i];
//    if(i < ROZMIAR-1){
//      os << ',';
//    }
//  }
//  os << ']';
//  os << endl;
//  
//  return os;
//}

//przeciazenie operatora >>     Przeniesione do .hh
//istream & operator >> (istream &is, Wektor &w1){
//  
//  for(int i = 0; i < ROZMIAR; i++){
//    is >> w1[i];
//  }
//
//  return is;
//}

//kontruktor bezparametryczny   Przeniesione do .hh
//Wektor::Wektor(){
//  for(int i = 0; i < ROZMIAR; i++){
//    tab[i] = 0.0;
//  }
//}

//przeciazenie []                Przeniesione do .hh
//const double& Wektor::operator[] (int index) const{
//if (index < 0 || index >= ROZMIAR){
//     cerr << "Wartość spoza zakresu" << endl;
//      exit(1);
//    }
//    return tab[index];
//  }

//double& Wektor::operator[] (int index){
//    if (index < 0 || index >= ROZMIAR){
//      cerr << "Wartość spoza zakresu" << endl;
//      exit(1);
//    }
//    return tab[index];
//  }

//konstruktor parametryczny       Przeniesione do .hh
//Wektor::Wektor(double * tab){
//   for(int i = 0; i < ROZMIAR; i++){
//   this->tab[i] = tab[i];
//  }
//  
//}
