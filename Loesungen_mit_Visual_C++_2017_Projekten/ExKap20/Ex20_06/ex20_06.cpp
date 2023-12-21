// ----------------------------------------------------
// ex20_06.cpp 
// Testet die Konvertierungsfunktion der Klasse DayTime.
// ----------------------------------------------------
#include "DayTime.h"        // Definition der Klasse
#include <iostream>
using namespace std;

int main()
{
   DayTime cinema( 20,30);
   cout << "\nDer Film beginnt um " << (string)cinema
        << endl;

   return 0;
}
