// ---------------------------------------------------------
// ex29_09.cpp
// Testet die Klassen Customer und CustomerFile (siehe
// Aufgabe 18.9) mit einer Indexdatei zum schnellen Suchen
// und der neuen CustomerFile-Methode retrieve().
// ---------------------------------------------------------
#include <iostream>
#include <cctype>            // für toupper()
#include "customer.h"
using namespace std;

int menu();

inline void goon()
{ cout << "\n Eingabetaste druecken, um fortzufahren. ";
  cin.get();
}

inline void skipRestOfLine()   // Verwirft restliche Zeichen
{                              // im Eingabepuffer incl. '\n'.
  char c;  
  while( cin.get(c) && c != '\n')
      ;
}

char filename[] = "customer";    // Basisname

char header[] = "\n\n\t   ***** Kundendatei ****** \n\n";

int main()
{
   int action = 0;         // Wahl des Benutzers 
   char name[128];         // Name des Kunden
   unsigned pin;           // Kundennummer
   Customer cust;          // Ein Kunde

   CustomerFile custFile(filename);

   while( action != 'B')
   {
      action = menu();
      switch(action)
      {
         case 'E':                            // Anhängen:
           cout << "\n Kundennummer eingeben:  ";
           if( !(cin >> pin))
              break;
           else
              skipRestOfLine();

           cout << " Name des Kunden eingeben: "; 
           if( !cin.getline(name, 127))
               break;
           if(!custFile.append( Customer(pin, name)) )
               cout << "Kundennummer schon vorhanden!" << endl;
           break;

        case 'A':                   // Ausgabe auf dem Bildschirm:
           cout << "\n Die Kunden in der Datei "
                << filename << " : \n" << endl;
           custFile.display();
           goon();
           break;

        case 'S':                   // Einen Kunden suchen: 
           cout << "\n Kundennummer eingeben:  ";
           if( !(cin >> pin))
              break;
           skipRestOfLine();

           if( custFile.retrieve( pin, cust))
              cout << "\n Der gefundene Kunde: " << cust.getName() << endl;
           else 
              cout << "\n Der Kunde wurde nicht gefunden!" << endl;
           goon();
           break;

        case 'B': 
           cout << " Bye, bye!" << endl;
           break;
      }
   }

   return 0;
}

int menu()
{
   char choice;

   static char menuStr[] =
     "\n\n             E = Neue Kunden einfuegen"
     "\n\n             A = Alle Kunden anzeigen"
     "\n\n             S = Einen Kunden suchen"
     "\n\n             B = Programm beenden"
     "\n\n Ihre Wahl:  ";

   cout << header << menuStr;
   do
   {
     if (!cin.get(choice))
        choice = 'B';
     else
        choice = toupper(choice);
   } while( choice != 'E' && choice != 'A' && choice != 'S' && choice != 'B');
   
   skipRestOfLine();

   return choice;
}
