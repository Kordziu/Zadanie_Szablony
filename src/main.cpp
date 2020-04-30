#include <iostream>
#include "Wektor.hh"
#include "LZespolona.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"

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
  //LZespolona init[]={LZespolona(1.0,-2.0), LZespolona(2.0,1.0), LZespolona(3.0,2.0)};
  // LZespolona init2[]={LZespolona(1.0,1.0), LZespolona(1.0,1.0), LZespolona(0.0,0.0)};
  // LZespolona init3[]={LZespolona(0.0,3.0), LZespolona(2.0,-1.0), LZespolona(-1.0,5.0)};
  
  //  SWektor<LZespolona, 3> W(init);
  // SWektor<LZespolona, 3> W2(init2);
  // SWektor<LZespolona, 3> W3(init3);
  //Macierz<double, 3> Wynik;
  //cin >> Wynik;
  //cout << Wynik;
  
  // SWektor<LZespolona, 3> data[]={W, W2, W3};
  
  // Macierz<LZespolona, 3> M(data);
  // Macierz<LZespolona, 3> M2(data);
  // LZespolona Wynik;
  //LZespolona Wynik;
  //SWektor<LZespolona, 3> Wynik;
  //Macierz<LZespolona, 3> Wynik;
  // cout << M << endl;
  // Wynik = M.wyznacznik();
 
  //if(M!=M){ cout << "nierowne" <<endl;};


  //cout << W2 * W <<endl;
  //cout << W << endl;
  //cout << W2 << endl;
  //cout << Wynik << endl;
  // cout << M << endl;
  //cout << Wynik << endl;
  // cout << Wynik <<endl;

  //  double dinit[3]={1, 2, 3};
  // double dinit2[3]={4, 5, 6};
  // double dinit3[3]={7, 8, 9};
  // SWektor<double, 3> Wd(dinit);
  //SWektor<double, 3> Wd2(dinit2);
  //SWektor<double, 3> Wd3(dinit3);

  //  SWektor<double, 3> minit[]={Wd, Wd2, Wd3};
  // Macierz <double, 3> MAD(minit);
  //cout << MAD <<endl;
  //cout << MAD.wyznacznik() <<endl;
    
/////////////////////////////////////// FAKTYCZNY PROGRAM ///////////////////////////////////////////////////////
  
  //switch(a.get())
  //{
  // case 'r': 
   UkladRownan<double, 3> U;
     cin >> U;
     cout << U << endl;
      //  break;

      //   case 'z':
      // UkladRownan<LZespolona, 3> U;
      //cin >> U;
      //cout << U << endl;
      //}


  return 0;
}
