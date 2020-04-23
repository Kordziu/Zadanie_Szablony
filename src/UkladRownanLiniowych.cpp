#include "UkladRownanLiniowych.hh"
#include "Macierz.hh"
#include "Wektor.hh"
#include "rozmiar.h"

using namespace std;

//Wektor błędu
Wektor UkladRownan::w_bledu() const {
  Wektor wynik;

  wynik = get_A() * Oblicz() - get_b();

  return wynik;
}

//Dlugosc Wektora błędu
double UkladRownan::dl_bledu() const {
  double wynik = w_bledu().dlugosc();

  return wynik;
}

//Obliczanie metodą Cramera
Wektor UkladRownan::Oblicz() const {
  Wektor wynik;
  Macierz temp = get_A(); // Kopia macierzy głównej, żeby nie pracować na oryginale
  double tab_wyznacznikow[ROZMIAR]; // Tablica z wynikami x1, x2... żeby potem wrzucić ją do Wektora wynikowego
  double wyznacznik_glowny = get_A().wyznacznik();
  Wektor wolne = get_b(); // Kopia wektora wyrazów wolnych
  
  if(abs(wyznacznik_glowny) > dokladnosc) { // Jeśli wyznacznik jest różny od 0
  
  for(int i = 0; i < ROZMIAR; i++) {
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
  return Wektor(tab_wyznacznikow);
}

istream & operator >> (istream &is, UkladRownan & UklRown) {
  Wektor tempw;
  Macierz tempm;

  is >> tempm;
  is >> tempw;

  UklRown = UkladRownan(tempm, tempw);
  return is;
}

ostream & operator << (ostream & os, const UkladRownan & UklRown) {
  cout << "Macierz główna: " << endl << UklRown.get_A() << endl;
  cout << "Wektor wyrazów wolnych: " << endl << UklRown.get_b() << endl;
  cout << "Rozwiązanie (x1, x2, ... xn): " << endl << UklRown.Oblicz() << endl;
  cout << "Wektor błędu: Ax-b = " << UklRown.w_bledu() << endl;
  cout << "Długość wektora błędu: |Ax-b| = " << UklRown.dl_bledu() << endl;
  return os;
}
