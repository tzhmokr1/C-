// ---------------------------------------------------------
// ex02_03.cpp
// Speicherbedarf, kleinster positiver und größter
// Wert sowie die Genauigkeit des Datentyps double. 
// ---------------------------------------------------------
#include <iostream>
#include <cfloat>
using namespace std;

int main()
{
   cout << "Speicherbedarf, Wertebereich und "  
        << "Genauigkeit des Datentyps double" << endl << endl;
   cout << "Speicherbedarf:                 " << sizeof(double) << endl;
   cout << "Groesster Wert:                 " << DBL_MAX << endl;
   cout << "Kleinster positiver Wert:       " << DBL_MIN << endl;
   cout << "Genauigkeit (Dezimalziffern):   " << DBL_DIG << endl;

   return 0;
}
