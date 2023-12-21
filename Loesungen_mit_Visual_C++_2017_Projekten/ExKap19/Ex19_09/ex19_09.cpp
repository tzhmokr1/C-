// ---------------------------------------------------------
// ex19_09.cpp
// Testet die erweiterte Klasse Complex. 
// ---------------------------------------------------------
#include <iostream>
#include "myComplex.h"
using namespace std;

int main()
{
   cout << "\n\t***** Die Klasse Complex testen *****" << endl; 

   Complex  z1(0.5, 1), z2(2, 1.5);

   cout << "\nErste Zahl:  " << z1 << "\t Absolutbetrag: " << z1.abs()
        << "\nZweite Zahl: " << z2 << "\t Absolutbetrag: " << z2.abs()
        << endl;

   Complex prod = z1 * z2;
   cout << "\nProdukt:    " << prod 
        << "\nQuotient:   " << z1 / z2 << endl;

   cout << "\n z1 * z2 / z1 : " << prod / z1 << "      ";
   cout << ((prod/z1 == z2) ? "OK!!" : "NOT OK!!") << endl;

   cout << "\n ... und noch einige arithmetische Operationen:\n" << endl;
   z1 = (z1/Complex(1,1) - z2) * z1;
   cout << "(z1/Complex(1,1) - z2) * z1 :  " << z1 << endl;

   return 0;
}
