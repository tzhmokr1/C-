// ---------------------------------------------------------
// ex20_05.cpp
// Testet die Konvertierungsfunktionen der Klasse Person.
// ---------------------------------------------------------
#include <iostream>
#include <string>
#include "person.h"
using namespace std;

int main()
{
   Person pers1( 178997L, "Washington, George"),
          pers2( 186165L, "Lincoln, Abraham");

   string s1(" 1. Praesident: "),
          s2("16. Praesident: ");

   s1 += (string)pers1;
   s2 += (string)pers2;
   cout << s1 << endl << s2 << endl;

   cout << "\nNach Namen sortiert:" << endl;
   if( (string)pers1 < (string)pers2)
        pers1.display(), pers2.display();
   else
        pers2.display(), pers1.display();

   cout << "\nNach ID sortiert:" << endl;
   if( (long)pers1 <  (long)pers2)
        pers1.display(), pers2.display();
   else
        pers2.display(), pers1.display();

   return 0;
}
