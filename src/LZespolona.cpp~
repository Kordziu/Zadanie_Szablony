#include "LZespolona.hh"
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */

void Wyswietl(LZespolona LZ)
{
  cout << "(" << LZ.re << showpos << LZ.im << "i)" << noshowpos;
}

//Przeciążenie operatora <<

ostream& operator<<(ostream& os, LZespolona LZ) {
	os << "(" << LZ.re << showpos << LZ.im << "i)" << noshowpos; 
	return os;
}

//Przeciążenie operatora >>

istream& operator>>(istream& is, LZespolona& LZ) {
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


LZespolona utworz(double re, double im)
{
  LZespolona LZ;
  LZ.re=re;
  LZ.im=im;

  return LZ;
}

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

  Wynik.re = Skl1.re * Skl2.re + (Skl1.im * Skl2.im * -1);
  Wynik.im = (Skl1.im * Skl2.re) + (Skl2.im * Skl1.re);
  return Wynik;
}

LZespolona operator / (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;
  double dzielnik;
  LZespolona gora;
  LZespolona sprz;

  dzielnik=modul(Skl2)*modul(Skl2);
  sprz=sprzezenie(Skl2);
  gora=Skl1*sprz;
  Wynik=gora/dzielnik;
  
  return Wynik;
}


LZespolona sprzezenie(LZespolona Skl1)
{
  LZespolona Wynik;
   Wynik.re=Skl1.re;
   Wynik.im=Skl1.im*-1;
   return Wynik;
}

double modul(LZespolona Skl1)
{
  double Wynik;
  Wynik=sqrt((Skl1.re * Skl1.re) + (Skl1.im * Skl1.im));
  return Wynik;
}

LZespolona operator / (LZespolona Skl1, double liczba)
{
  LZespolona Wynik;
  if(liczba==0){
  cout<<"BŁĘDNE WYRAŻENIE - NIE DZIELIMY PRZEZ 0"<<endl;
  }
  else
  Wynik.re=Skl1.re/liczba;
  Wynik.im=Skl1.im/liczba;
  
  return Wynik;
}

int operator == (LZespolona Skl1, LZespolona Skl2)
{
  if(Skl1.re==Skl2.re && Skl1.im==Skl2.im){
    return 1;
  }
  else {
    return 0;
  }
}
