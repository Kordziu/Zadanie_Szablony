#include <iostream>
#include "Wektor.hh"
//#include "Macierz.hh"
//#include "UkladRownanLiniowych.hh"

using namespace std;

// Program wczytuje dane z pliku w sposób: cat data.dat | ./uklad_rownan
// Dane w pliku powinny być zapisane wierszowo. Ostanim wierszem jest wektor
// wyrazów wolnych. Program został przetestowany dla załączonych plików data.dat
// data2.dat, żeby kolejno sprawdzić poprawność dla zwykłego rozwiązania, oraz
//braku rozwiązań. Wyniki zostały porównane z obliczeniami 'na kartce' oraz z
//kalkulatorem online są zgodne. Na podstawie tych i wielu wcześniejszych testów
// poszczególnych funkcji - program działa poprawnie.
// Program działa poprawnie również po zmianie zadanego rozmiaru.

int main()
{ 
  double init[]={1, 2, 3};
  double init2[]={1, 1, 0};
  
  SWektor<double, 3> W(init);
  SWektor<double, 3> W2(init2);
  SWektor<double, 3> Wynik;

  Wynik = W + W2;

  cout << W << endl;
  cout << W2 << endl;
  cout << Wynik << endl;


  
  //UkladRownan U;
  //cin >> U;
  //cout << U << endl;

  return 0;
}
