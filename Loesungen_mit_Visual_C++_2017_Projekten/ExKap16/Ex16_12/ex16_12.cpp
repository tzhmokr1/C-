// ------------------------------------------------------
// ex16_12.cpp
// Testet die Klasse TowersOfHanoi.
// ------------------------------------------------------
#include <iostream>
#include <cctype>
#include "towersOfHanoi.h"
using namespace std;

char menu();

inline void skipRestOfLine()  // Ueberspringt Zeichen im 
{                             // Eingabepuffer incl. '\n'.
  char c;  
  cin.clear();
  while( cin.get(c) && c != '\n')
      ;
}

int main()
{
   while( true)
   {
     char choice = menu();
     if( choice == 'Q') break;

     int nDisks = 0;
     cout << "Geben Sie die Anzahl der Scheiben ein: ";
     if( !(cin >> nDisks)) break;
     skipRestOfLine();

     TowersOfHanoi toh(nDisks);
     toh.display();

     switch( choice)
     {
       case 'P':              // Der Benutzer spielt.
       {
         int from = 0, to = 0;

         cout << "\nSpielabbruch mit einem Buchstaben."
              << endl;
         while( ! toh.isFinished())
         {
            cout << "\nScheibe uebertragen!  Vom Stab: ";
            if( !(cin >> from)) break;
            cout <<   "                zum Stab: ";
            if( !(cin >> to))  break;

            if( !toh.move( from-1, to-1)) // Indizes: 0, 1, 2
              cout << "Aktion unzulaessig!" << endl;
            else
              toh.display();
         }
         skipRestOfLine();

         cout << "Das Spiel ist aus!" << endl;
         if( toh.isFinished())
            cout << "Sie haben gewonnen!\n" << endl;
       }
       break;

       case 'S':            // Zeigt eine Loesung des Spiels.
         toh.autoPlay();
         cout << "Das Spiel ist aus!" << endl;
         if( !toh.isFinished())
           cout << "Fehler!\n" << endl;
         break;
     }
   }
   return 0;
}

char menu()
{
   cout << "\n\n\t\t  ****   Tuerme von Hanoi  ****\n"
        << endl;
   char choice = 0;
   cout << "\n             P = Spiel starten"
        << "\n             S = Loesung anzeigen"
        << "\n             Q = Spiel beenden"
        << "\nIhre Wahl: ";

   while( choice != 'P' && choice != 'S' && choice != 'Q')
   {
      if( !(cin >> choice)) choice = 'Q';
      choice = toupper(choice);
   }
   return choice;
}
