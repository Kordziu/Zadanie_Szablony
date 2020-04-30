#include "UkladRownanLiniowych.hh"
#include "Macierz.hh"
#include "Wektor.hh"
#include "rozmiar.h"

using namespace std;

//Wektor błędu
Wektor UkladRownan::w_bledu() const


//Dlugosc Wektora błędu
double UkladRownan::dl_bledu() const


//Obliczanie metodą Cramera
Wektor UkladRownan::Oblicz() const {
  
istream & operator >> (istream &is, UkladRownan & UklRown) 
ostream & operator << (ostream & os, const UkladRownan & UklRown)
