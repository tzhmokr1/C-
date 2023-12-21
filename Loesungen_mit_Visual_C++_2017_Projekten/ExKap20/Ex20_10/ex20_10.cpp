// -------------------------------------------------------------
// ex20_10.cpp
// Arithmetische Operationen mit komplexen and reellen Zahlen.
// -------------------------------------------------------------
#include <iostream>
#include "myComplex.h"
using namespace std;

int main()
{
   cout << "\n\t***** Testet die Klasse Complex *****" << endl; 

   Complex  z(0.5, 1);
   double   x(2.7); 

   cout << "\nKomplexe Zahl: " << z
        << "\nReelle Zahl:   " << x << endl;

   cout << "\nSumme:        " << z + (Complex)x
        << "\nDifferenz:    " << z - (Complex)x
        << "\nProdukt:      " << z * (Complex)x 
        << "\nQuotient z/x: " << z / (Complex)x
        << "\nQuotient x/z: " << (Complex)x / z << endl << endl;

   return 0;
}
