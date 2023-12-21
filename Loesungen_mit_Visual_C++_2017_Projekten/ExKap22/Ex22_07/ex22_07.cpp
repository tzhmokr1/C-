// ---------------------------------------------------------
// ex22_07.cpp
// Verwendet die Klasse AutoPtr.
// ---------------------------------------------------------
#include <iostream>
#include "autoPtr.h"
using namespace std;

void testFunc( AutoPtr& ap);

int main()
{
   AutoPtr ap1, ap2, ap3( new Demo("Jupiter"));
// AutoPtr clone(ap3);        // Compiler-Fehler! 
                              // Kopie nicht möglich!
   ap1 = ap3;                 // ok, ap1 neuer Besitzer von "Jupiter"
   cout << "Hallo " << (*ap1).getName() << endl;

   ap2 = new Demo("Mars");    // ok
   cout << "Hallo " << ap2->getName() << endl;

//   ap1 = ap2;               // Laufzeit-Fehler!
                              // AutoPtr ap1 nicht mehr frei!
   ap3 = ap2;                 // Besitz vom Objekt "Mars" geht
                              // an ap3 über.
   testFunc(ap2);
   cout << "--- Wieder in der Funktion main() ---" << endl;
   if( ap2.get() != NULL)
      cout << "Hallo " << ap2->getName() << endl;

   Demo *pd = ap1.release();  // ap1 von seinem Objekt lösen.
   delete pd;
//   cout << "Hallo " << ap1->getName() << endl;  // Laufzeitfehler!
                                                // Kein Objekt.
   return 0;
}

void testFunc( AutoPtr& ap)
{
   cout << "--- In der Funktion testFunc() ---" << endl;
   if( ap.get() == NULL)
      ap = new Demo("Saturn");
   AutoPtr localPtr( new Demo("Venus"));
   cout << "Hallo " << ap->getName()
        << " und " << localPtr->getName() << endl;
}
