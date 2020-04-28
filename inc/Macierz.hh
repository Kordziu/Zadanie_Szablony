 #ifndef MACIERZ_HH
#define MACIERZ_HH

#include "Wektor.hh"
#include "rozmiar.h"
#include <iostream>

using namespace std;

template <typename Styp, int Swymiar>
class Macierz{
  SWektor<Styp, Swymiar> tab[Swymiar];

public:
  /////////////// Konstruktory ///////////////
  Macierz()
  {for (int i = 0; i < Swymiar; i++){tab[i] = SWektor<Styp, Swymiar>();}};
  Macierz(SWektor<Styp, Swymiar> *w1)
  {for(int i = 0; i < Swymiar; i++){tab[i] = w1[i];}}; 
  Macierz(const Macierz &m)
  {for(int i = 0; i < Swymiar; i++){tab[i] = m[i];}};

  /////////////// Transpozycja ///////////////
  Macierz transpozycja() const
  {
    SWektor<Styp, Swymiar> kolumna;
    Macierz temp;
      for(int i = 0; i < Swymiar; i++)
      {
        kolumna = zwroc_kolumne(i);
        temp[i] = kolumna;
      }
    return temp;
  };

  /////////////// Odwrotnosc ///////////////
  // const Macierz & odwrotnosc() const;
  //void odwrotnosc();
  
  /////////////// Macierz * Wektor ///////////////
  SWektor<Styp, Swymiar> operator * (const SWektor<Styp, Swymiar> w1) const
  {
    SWektor<Styp, Swymiar> wynik;
      for(int i = 0; i < Swymiar; i++)
      {
        wynik[i] = tab[i] * w1;
	cout << "wynik i" << wynik[i] <<endl;
      }
      return wynik; 
  };

  /////////////// Macierz * Macierz ///////////////
  Macierz operator * ( Macierz m1) const
  {
    Macierz wynik;
      for(int i = 0; i < Swymiar; i++)
      {
        for(int j=0; j < Swymiar; j++)
	{
          wynik[i][j] = tab[i] * m1.zwroc_kolumne(j);
        }
      }
    return wynik;
  };
  
  /////////////// Macierz + Macierz ///////////////
  Macierz operator + (const Macierz m1) const
  {
    Macierz wynik;
      for(int i = 0; i < Swymiar; i++)
      {
        for(int j = 0; j < Swymiar; j++)
	{
          wynik[i] = tab[i] + m1[i];
        }
      }
    return wynik;
  };
  
  /////////////// Macierz - Macierz ///////////////
  Macierz operator - (const Macierz m1) const
  {
    Macierz wynik;
      for(int i = 0; i < Swymiar; i++)
      {
        for(int j = 0; j < Swymiar; j++)
        {
          wynik[i] = tab[i] - m1[i];
        }
      }
    return wynik;
  };
  
  /////////////// Macierz * liczba ///////////////
  Macierz operator * (const double liczba) const
  {
    Macierz wynik;
      for(int i = 0; i < Swymiar; i++)
      {
        wynik[i] = tab[i] * liczba;
      }
    return wynik;
  };
  
  /////////////// Przeciążenie operatorów == != ///////////////
  bool operator == (const Macierz & m1) const
  {
    for(int i = 0; i < Swymiar; i++)
    {
      if(tab[i] != m1[i])
      {
	return false;
      }
    }
    return true;
  };
  
  bool operator != (const Macierz & m1) const
  {
    if(*this == m1)
      {
        return false;
      }
    return true;
  };
  
  /////////////// Przeciążenia [] ///////////////
  const SWektor<Styp, Swymiar> & operator[] (int index) const
  {
    if (index < 0 || index >= Swymiar)
    {
      cerr << "Wartość spoza zakresu" << endl;
      exit(1);
    }
    return tab[index];
  };
  
  SWektor<Styp, Swymiar> & operator[] (int index) // M[2][0]-[Wektor][Element]
  {
    if (index < 0 || index >= Swymiar)
    {
      cerr << "Wartość spoza zakresu" << endl;
      exit(1);
    }
    return tab[index];
  };
  
  /////////////// Zwracanie i zmiana kolumny ///////////////
  SWektor<Styp, Swymiar> zwroc_kolumne(int nr_kolumny) const //dla wierszowej
  {
    SWektor<Styp, Swymiar> kolumna;
      for(int i = 0; i < Swymiar; i++)
      {
        kolumna[i] = tab[i][nr_kolumny];
      }
    return kolumna;
  };
  
  Macierz zmien_kolumne(int nr_kolumny, SWektor<Styp, Swymiar> nowa)
  {
    Macierz pom;
    pom = transpozycja();
    pom[nr_kolumny] = nowa;
    pom = pom.transpozycja();
    return pom;
  };
  
  //////////// Iloczyn liczb na przekątnej macierzy ////////////
  double przekatna() const
  {
    double wynik = 1.0;
      for(int i = 0; i < Swymiar; i++)
      {
        wynik *= tab[i][i];
      }
    return wynik;	
  };

  /////////////// Wyznacznik z gaussa ///////////////
  double wyznacznik() const
  {  
    int licznik = 0; //ile razy zamieniliśmy wiersze
    Macierz pom(*this); //stworzenie kopii żeby nie zmieniać obiektu
      for(int i = 0; i < Swymiar - 1; i++)
      {
        int k = i;
        bool kolumna_ready = false;  
	  while(pom[i][i] == 0.0)
	  { //dopóki wartość na przekątnej nie będzie równa 0	
	    if(k++ >= Swymiar)
	    {//jeśli przeszliśmy całą kolumne
	      kolumna_ready = true; //ustaw ją jako gotową
              break;
	    }
	    swap(pom[i], pom[k]); //w przeciwnym razie zamień wiersze
	    licznik++; //zwiększ licznik
          }
	if(kolumna_ready)
	  { //jeśli kolumna jest gotowa to kontynuuj pętlę while
           continue;
          }
          for(int j = i+1; j < Swymiar; j++)
	  {		  
            double val = pom[j][i] / pom[i][i];//zmienna do ustalenia wartości przez którą będziemy mnożyć wiersz który będzie odejmowany
	    pom[j] = pom[j] - pom[i] * val;//wyzerowanie punktu	
          }
        }
      double wynik = pom.przekatna(); //wyliczenie wyznacznika z wartości na przekątnej macierzy trójkątnej
    wynik *= pow(-1, licznik%2); //jeśli licznik jest jest parzysty to nasz wyznacznik mnożymy przez -1^0 czyli *1 i nic się nie zmienia, jeśli jest nieparzysty to zmienia się znak wyznacznika

   return wynik;
  };

}; //koniec klasy

template<typename Styp, int Swymiar>
istream& operator >> (istream &is, Macierz<Styp, Swymiar> &m1)
{  
  for(int i = 0; i < Swymiar; i++)
  {   
    is >> m1[i];  
  }
  return is;
}

template<typename Styp, int Swymiar>
ostream& operator << (ostream &os, const Macierz<Styp, Swymiar> &m1)
{
  for(int i = 0; i < Swymiar; i++)
  {
    os << m1[i];
  }
  os << endl;
  return os;
}

#endif
