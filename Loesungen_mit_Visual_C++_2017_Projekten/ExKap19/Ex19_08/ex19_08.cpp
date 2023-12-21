// ---------------------------------------------------------
// ex19_08.cpp
// Testet die Klasse Complex. 
// ---------------------------------------------------------
#include <iostream>
#include "myComplex.h"
using namespace std;

int main()
{
   cout << "\n\t***** Die Klasse Complex testen *****" << endl; 

   Complex  z1(-1.1, 2.2), z2 = 3.3;

   cout << "\nErste Zahl:  " << z1
        << "\nZweite Zahl: " << z2 << endl;

   //z1 += z2;
   cout << "\nSumme:       " << z1 + z2;
   cout << "\nDifferenz:   " << z1 - z2 << endl;

   cout << "\n ... und noch einige arithmetische Operationen:\n" << endl;
   z2 = -(z2 + Complex(0.0, -4.4));
   cout << "-(z2 + Complex(0.0, -4.4)):   " << z2 << endl;

   return 0;
}
