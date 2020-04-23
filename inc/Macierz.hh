 #ifndef MACIERZ_HH
#define MACIERZ_HH

#include "Wektor.hh"
#include "rozmiar.h"
#include <iostream>

using namespace std;

class Macierz{
  Wektor tab[ROZMIAR];//3 propozycja, sugerowana

public:
  Macierz(); //DONE
  Macierz(Wektor *w1); //DONE
  Macierz(const Macierz &m); //DONE
  Macierz transpozycja() const; //DONE
  //void transpozycja();

  const Macierz & odwrotnosc() const;
  void odwrotnosc();//z definicji, gauss

  double wyznacznik() const;//laplace, gauss, sarrus DONE
  //double wyznacznikGauss(); //double wyznacznik(Metoda = Gauss) <- enum
  
  Wektor operator * (const Wektor W) const; //DONE
  Macierz operator * ( Macierz W) const; //DONE
  Macierz operator + (const Macierz W) const; //DONE
  Macierz operator - (const Macierz W) const; //DONE
  Macierz operator * (const double l) const; //DONE

  bool operator == (const Macierz & W2) const; //DONE
  bool operator != (const Macierz & W2) const; //DONE

  const Wektor & operator[] (int index) const; //DONE
  Wektor & operator[] (int index); // M[2][0]-[Wektor][Element] DONE

  //const double & operator() (int ind1, int ind2) const;
  // double & operator() (int ind1, int ind2); //M(2,0)

  Wektor zwroc_kolumne(int ind) const; //dla wierszowej //DONE
  Macierz zmien_kolumne(int ind, Wektor nowa); //DONE
  double przekatna() const;
};



/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
istream& operator >> (istream &Strm, Macierz &m1); //DONE

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
ostream& operator << (ostream &Strm, const Macierz &m1); //DONE


#endif
