#include "Macierz.hh"
#include "Wektor.hh"
#include <cmath>

using namespace std;

//Mnożenie macierz * wektor
Wektor Macierz::operator * (const Wektor w1) const


//Mnożenie macierz * macierz
Macierz Macierz::operator * (Macierz m1) const


//Dodawanie macierzy
Macierz Macierz::operator + (const Macierz m1) const


//Odejmowanie macierzy
Macierz Macierz::operator - (const Macierz m1) const


//Mnożenie macierzy przez liczbę
Macierz Macierz::operator * (const double liczba) const

//przeciazenie operatora >>
istream & operator >> (istream &is, Macierz &m1)



//przeciazenie operatora <<
ostream & operator << (ostream &os, const Macierz &m1)




//Funkcja licząca iloczyn wyrazów po przekątnej  ** WRZUCIĆ JAKO PRIVATE **
double Macierz::przekatna() const
                       

//Liczenie wyznacznika macierzy metodą Gaussa
double Macierz::wyznacznik() const
