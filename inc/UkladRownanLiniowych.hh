#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Macierz.hh"
#include "Wektor.hh"
#include "rozmiar.h"

using namespace std;

template<typename Styp, int Swymiar>
class UkladRownan {
  Macierz <Styp, Swymiar> A;
  SWektor <Styp, Swymiar> b;
public:

  /////////////// Konstruktory ///////////////
  UkladRownan() : A(), b() {};

  UkladRownan(Macierz<Styp, Swymiar> AA, SWektor<Styp, Swymiar> bb) : A(AA), b(bb) {};

  //////////// Pobieranie macierzy i w wyrazów wolnych ////////////
  const Macierz<Styp, Swymiar> & get_A() const {return A;};
  const SWektor<Styp, Swymiar> & get_b() const {return b;};

  /////////////// Wektor błędu ///////////////
  SWektor<Styp, Swymiar> w_bledu() const
  {
    SWektor<Styp, Swymiar> wynik;
    wynik = get_A() * Oblicz() - get_b();
    return wynik;
  } ;

  Styp dl_bledu() const;
  
  SWektor<Styp, Swymiar> Oblicz() const
  {
    Macierz<Styp, Swymiar> temp;
    temp = get_A(); // Kopia macierzy głównej, żeby nie pracować na oryginale
    Styp tab_wyznacznikow[Swymiar]; // Tablica z wynikami x1, x2... żeby potem wrzucić ją do Wektora wynikowego
    Styp wyznacznik_glowny;
    wyznacznik_glowny = get_A().wyznacznik();
    SWektor<Styp, Swymiar> wolne;
    wolne = get_b(); // Kopia wektora wyrazów wolnych
      if(wyznacznik_glowny == 0.0)
	{ // Jeśli wyznacznik jest różny od 0
	  for(int i = 0; i < ROZMIAR; i++)
	    {
	      temp = temp.zmien_kolumne(i, wolne); //zamien kolumnę na wektor wyrazów wolnych
	      tab_wyznacznikow[i] = temp.wyznacznik(); //wyliczenie wyznacznika nowej macierzy
	      tab_wyznacznikow[i] = tab_wyznacznikow[i] / wyznacznik_glowny; //wyliczenie wartości xi
	      temp = get_A(); // przywrócenie kopii oryginalnej macierzy
	    }
	}
      else //w innym wypadku wyświetl komunikat i wyjdź z programu
	{
	  cerr << "Wyznacznik macierzy głównej wynosi 0. Uklad równań nie ma rozwiązania." << endl;
	  exit(0);
	}
      SWektor<Styp, Swymiar> wynik(tab_wyznacznikow); 
      return wynik;
  };

}; //koniec klasy

template <typename Styp, int Swymiar>
istream& operator >> (istream &is, UkladRownan<Styp, Swymiar> &UklRown)
{
  SWektor <Styp, Swymiar> tempw;
  Macierz <Styp, Swymiar> tempm;

  is >> tempm;
  is >> tempw;

  UklRown = UkladRownan(tempm, tempw);
  return is;
}


template <typename Styp, int Swymiar>
ostream& operator << (ostream &os, const UkladRownan <Styp, Swymiar> &UklRown )
{
  cout << "Macierz główna: " << endl << UklRown.get_A() << endl;
  cout << "Wektor wyrazów wolnych: " << endl << UklRown.get_b() << endl;
  cout << "Rozwiązanie (x1, x2, ... xn): " << endl << UklRown.Oblicz() << endl;
  cout << "Wektor błędu: Ax-b = " << UklRown.w_bledu() << endl;
  // cout << "Długość wektora błędu: |Ax-b| = " << UklRown.dl_bledu() << endl;
  return os;
}


#endif
