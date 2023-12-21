// ------------------------------------------------------
// ex16_11.cpp
// Testet die Klasse TowersOfHanoi.
// ------------------------------------------------------
#include <iostream>
#include "towersOfHanoi.h"
using namespace std;

int main()
{
   cout << "\t\t  ****   Tuerme von Hanoi  ****\n" << endl;

   int nDisks = 0;
   cout << "Die Anzahl Scheiben fuer dieses Spiel: ";
   cin >> nDisks;

   TowersOfHanoi toh(nDisks);
   int from = 0, to = 0;

   toh.display();

   cout << "\nAbbruch des Spiels mit einem Buchstaben." << endl;
   while( ! toh.isFinished())
   {
      cout << "\nEine Schreibe uebertragen!  Vom Stab: ";
      if( !(cin >> from)) break;
      cout <<   "                zum Stab: ";
      if( !(cin >> to))  break;

      if( !toh.move( from-1, to-1))       // Indizes: 0, 1, 2
         cout << "Aktion unzulaessig!" << endl;
      else
         toh.display();
   }

   cout << "Das Spiel ist aus!" << endl;
   if( toh.isFinished())
       cout << "Sie haben gewonnen!" << endl;

   return 0;
}
