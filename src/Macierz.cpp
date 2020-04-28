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


//porównanie == dla macierzy
bool Macierz::operator == (const Macierz &m1) const{

  for(int i = 0; i < ROZMIAR; i++){
    if(tab[i] != m1[i]){
      return false;
    }
  }
  return true;
}

//porównanie != dla macierzy
bool Macierz::operator != (const Macierz &m1) const
{
  if(*this == m1)
    {
      return false;
    }
  return true;
}


//zwracanie kolumny z macierzy
Wektor Macierz::zwroc_kolumne(int nr_kolumny) const{
  Wektor kolumna;

  for(int i = 0; i < ROZMIAR; i++){
    kolumna[i] = tab[i][nr_kolumny];
  }
  return kolumna;
}

//zamiana kolumny na dowolny podany wektor
Macierz Macierz::zmien_kolumne(int nr_kolumny, Wektor nowa){
  Macierz pom;
  pom = transpozycja();
  pom[nr_kolumny] = nowa;
  pom = pom.transpozycja();
  return pom;
}



//przeciazenie operatora >>
istream & operator >> (istream &is, Macierz &m1){
  
  for(int i = 0; i < ROZMIAR; i++){
    
    is >> m1[i];
    
  }

  return is;
}


//przeciazenie operatora <<
ostream & operator << (ostream &os, const Macierz &m1){

   for(int i = 0; i < ROZMIAR; i++){
     os << m1[i];
   }
   os << endl;
  return os;
}

//przeciazenie []
const Wektor& Macierz::operator[] (int index) const{
    if (index < 0 || index >= ROZMIAR){
      cerr << "Wartość spoza zakresu" << endl;
      exit(1);
    }
    return tab[index];
  }

Wektor& Macierz::operator[] (int index){
    if (index < 0 || index >= ROZMIAR){
      cerr << "Wartość spoza zakresu" << endl;
      exit(1);
    }
    return tab[index];
  }

//Funkcja licząca iloczyn wyrazów po przekątnej  ** WRZUCIĆ JAKO PRIVATE **
double Macierz::przekatna() const {
  double wynik = 1.0;
    for(int i = 0; i < ROZMIAR; i++) {
      wynik *= tab[i][i];
    }
        return wynik;	
}                       

//Liczenie wyznacznika macierzy metodą Gaussa
double Macierz::wyznacznik() const {  
  int licznik = 0; //ile razy zamieniliśmy wiersze
  Macierz pom(*this); //stworzenie kopii żeby nie zmieniać obiektu

  for(int i = 0; i < ROZMIAR - 1; i++) {
      int k = i;
        bool kolumna_ready = false;  
	while(pom[i][i] == 0.0) { //dopóki wartość na przekątnej nie będzie równa 0	  
	  if(k++ >= ROZMIAR) {//jeśli przeszliśmy całą kolumną	    
	    kolumna_ready = true; //ustaw ją jako gotową
              break;
	    }
	  swap(pom[i], pom[k]); //w przeciwnym razie zamień wiersze
	  licznik++; //zwiększ licznik
          }
	if(kolumna_ready) { //jeśli kolumna jest gotowa to kontynuuj pętlę while
           continue;
          }
        for(int j = i+1; j < ROZMIAR; j++) {		  
          double val = pom[j][i] / pom[i][i];//zmienna do ustalenia wartości przez którą będziemy mnożyć wiersz który będzie odejmowany
	  pom[j] = pom[j] - pom[i] * val;//wyzerowanie punktu	    
         }
     }
  double wynik = pom.przekatna(); //wyliczenie wyznacznika z wartości na przekątnej macierzy trójkątnej
  wynik *= pow(-1, licznik%2); //jeśli licznik jest jest parzysty to nasz wyznacznik mnożymy przez -1^0 czyli *1 i nic się nie zmienia, jeśli jest nieparzysty to zmienia się znak wyznacznika

 return wynik;
}
