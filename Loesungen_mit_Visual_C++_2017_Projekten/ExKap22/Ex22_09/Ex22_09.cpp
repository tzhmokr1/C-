// ---------------------------------------------------------
// ex22_09.cpp
// Aufruf der Methode printTop() der Klasse SearchTree.
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
   for( int i=0; i< 10; ++i)
       aTree.insert( rand()%100);

   cout << "Anzahl Elemente: " << aTree.getCount() << endl;

   cout << "Die Spitze des Baumes:" << endl;
   aTree.printTop(2);

   cout << "Der gesamte Baum:" << endl;
   aTree.printTop();

   return 0;
}
