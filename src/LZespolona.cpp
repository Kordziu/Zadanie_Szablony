#include "LZespolona.hh"
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

// definicje metod struktury LZespolona
LZespolona::LZespolona() {
  LZespolona(0.0, 0.0);
}

LZespolona::LZespolona(double re) {
  LZespolona(re, 0.0);
}

LZespolona::LZespolona(double re, double im) {
  this->re=re;
  this->im=im;
}

double LZespolona::modul() {
  return sqrt((re * re) + (im * im));
}

LZespolona LZespolona::sprzezenie() const{
  LZespolona Wynik;
  Wynik.re = re;
  Wynik.im = -im;
  return Wynik;
}

void LZespolona::wyswietl() const{
  cout << this;
}

// END definicje

//Przeciążenie operatora <<

ostream& operator << (ostream& os, LZespolona LZ) {
	os << "(" << LZ.re << showpos << LZ.im << "i)" << noshowpos; 
	return os;
}

//Przeciążenie operatora >>

istream& operator >> (istream& is, LZespolona& LZ) {
	stringstream buf;  // strumień pomocniczy
	char chr; // aktualny znak

	do {
		is.get(chr);  // pobierz znak ze strumienia i wpisz do chr
	} while(is && isspace(chr)); // usuwanie spacji

	if(chr != '(') { //sprawdzanie wczytanego znaku czy jest nawiasem
	  is.setstate(ios::failbit);
	  // cerr << "BRAK NAWIASU!"<<endl;
		return is;
	}
	is.get(chr); //pobranie kolejnego znaku
	
	do { //wczytaj liczbę rzeczywistą dopóki nie natrafisz na +,-
	     //oznaczający początek liczby urojonej
		if( (chr < '0' || chr > '9') && chr != '-' && chr != '.') {
		  is.setstate(ios::failbit);
		  //cerr << "BŁĄD WCZYTYWANIA CZĘŚCI RZECZYWISTEJ" << endl;
			return is;
		}
		buf << chr;
		is.get(chr);
	} while(chr != '-' && chr != '+');
	
	buf << " ";
	if (chr == '-') {
		buf << "-";
	}

	is.get(chr);

	do {
		if( (chr < '0' || chr > '9') && chr != 'i' && chr != '.' ) {
		  is.setstate(ios::failbit);
		  //cerr << "BŁĄD WCZYTYWANIA CZĘŚCI UROJONEJ!" << endl;
			return is;
		}
		buf << chr;
		is.get(chr);
	} while(chr != 'i');

	while(chr != ')') {
		is.get(chr);
	}

	buf >> LZ.re >> LZ.im;
	return is;
}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = (Skl1.re * Skl2.re) - (Skl1.im * Skl2.im);
  Wynik.im = (Skl1.im * Skl2.re) + (Skl2.im * Skl1.re);
  return Wynik;
}

LZespolona operator / (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;
  double dzielnik;
  LZespolona gora;
  LZespolona sprz;

  dzielnik = Skl2.modul() * Skl2.modul();
  sprz = Skl2.sprzezenie();
  gora = Skl1 * sprz;
  Wynik = gora / dzielnik;
  
  return Wynik;
}



LZespolona operator / (LZespolona Skl1, double liczba)
{
  LZespolona Wynik;

  if(liczba == 0) {
    cerr << "BŁĘDNE WYRAŻENIE - NIE DZIELIMY PRZEZ 0" << endl;
  }
  else {
    Wynik.re = Skl1.re / liczba;
    Wynik.im = Skl1.im / liczba;
  }
  
  return Wynik;
}

LZespolona operator * (LZespolona Skl1, double liczba)
{
  LZespolona Wynik = 0;

  Wynik.re = Skl1.re * liczba;
  Wynik.im = Skl1.im * liczba;

  return Wynik;
}

bool operator == (const LZespolona Skl1,const LZespolona Skl2) 
{
  if(Skl1.re == Skl2.re && Skl1.im == Skl2.im){
    return true;
  }
  return false;
}

bool operator != (const LZespolona Skl1, const LZespolona Skl2) 
{
  if(Skl1 == Skl2)
    {
      return false;
    }
  return true;
}
