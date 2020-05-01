#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include<iostream>

using namespace std;

/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */

  LZespolona();
  explicit LZespolona(double);
  LZespolona(double, double);
  double modul();
  LZespolona sprzezenie() const;
  void wyswietl() const;
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
LZespolona operator * (LZespolona  Skl1,  double liczba);
LZespolona operator *= (LZespolona Skl1,  LZespolona  Skl2);
LZespolona operator *= (double liczba, LZespolona Skl1);
LZespolona operator / (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona operator / (LZespolona, double);
ostream& operator << (ostream&, LZespolona);
istream& operator >> (istream&, LZespolona&);
bool operator == (const LZespolona, const LZespolona);
bool operator != (const LZespolona, const LZespolona);
bool operator == (const LZespolona, const double);
bool operator != (const LZespolona, const double);

//inline bool operator > (LZespolona lz, double l1)
//{
  // if(lz.re > l1 && lz.im == 0)
    //  {
      //    return true;
      //  }
  // return false;
  //}

//inline bool operator < (LZespolona lz, double l1)
//{
//  if(lz > l1)
//    {
//      return false;
//    }
//  return true;
//}

#endif
