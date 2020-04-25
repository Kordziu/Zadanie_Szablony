#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include<iostream>

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */

using namespace std;

/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */

  LZespolona();
  LZespolona(double);
  LZespolona(double, double);
  double modul();
  LZespolona sprzezenie();
  void wyswietl();
  LZespolona operator = (double liczba)
  {
    re=liczba;
    im=0.0;
    return *this;
  }
  
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */


LZespolona operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona operator - (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona operator * (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona operator / (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona operator / (LZespolona, double);
ostream& operator << (ostream&, LZespolona);
istream& operator >> (istream&, LZespolona&);
bool operator == (const LZespolona, const LZespolona);
bool operator != (const LZespolona, const LZespolona); 
#endif
