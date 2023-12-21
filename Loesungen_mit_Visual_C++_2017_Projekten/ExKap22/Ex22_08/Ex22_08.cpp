// ---------------------------------------------------------
// ex22_08.cpp
// Verwendet die Klasse SearchTree.
// ---------------------------------------------------------
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "searchTree.h"
using namespace std;

int main()
{
   cout << "\t ****  Ein Binaerer Suchbaum  ****\n" << endl;

   SearchTree aTree;

   srand((unsigned int)time(NULL));   // Zufallszahlengenerator
                                      // initialisieren.
   for( int r=0, i=0; i < 7; ++i)
   {
      r = rand() % 100;
      cout << "Einfuegen: " << r << endl;
      aTree.insert(r);
   }
   cout << "Anzahl Elemente: " << aTree.getCount() << endl;

   cout << "\nWelcher Wert soll gesucht werden: ";
   int val = 0;
   cin >> val;
   if( aTree.search(val))
      cout << val << " gefunden!" << endl;
   else
      cout << val << " nicht gefunden!" << endl;

   return 0;
}
