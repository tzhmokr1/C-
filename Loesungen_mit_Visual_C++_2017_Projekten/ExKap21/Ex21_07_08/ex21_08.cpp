// ---------------------------------------------------------
// ex21_08.cpp
// Test der Klasse IntArr mit der Methode compress().
// ---------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include "intArr.h"
using namespace std;

int main()
{
   cout << "\n   *** Test der Klasse IntArr *** \n"
        << endl;

   IntArr arr(100);           // Ein int-Array der Länge 100
   int i = 0;

   srand( (unsigned int)time(NULL));   // Initialisierung des 
                                       // Zufallszahlengenerators.
   for( i = 0; i < arr.length();  ++i) // Den Vekto-Elementen
      arr[i] = rand() % 10;            // Zufallszahlen zuweisen.

   cout << "\nDer Inhalt des Vektors:" << endl;
   for( i = 0; i < arr.length();  ++i)
       cout << setw(8) << arr[i];

   arr.compress();                     // Vektor kompremieren.

   cout << "\nDer kompremierte Vektor:" << endl;
   for( i = 0; i < arr.length();  ++i)
       cout << setw(8) << arr[i];

   cout << "\nDie Laenge des kompremierten Vektors: "
        << arr.length() << endl;

   return 0;
}


