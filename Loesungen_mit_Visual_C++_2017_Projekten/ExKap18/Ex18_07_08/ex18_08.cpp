// ---------------------------------------------------------
// ex18_08.cpp
// Testet die Klassen Customer und CustomerFile.
// ---------------------------------------------------------
#include <iostream>
#include "customer.h"
using namespace std;

int menu();

inline void skipRestOfLine()   // Verwirft restliche Zeichen
{                              // im Eingabepuffer incl. '\n'.
  char c;
  while( cin.get(c) && c != '\n')
      ;
}

char filename[] = "customer.dat";

char header[] = "\n\n\t   ***** Kundendatei ****** \n\n";

int main()
{
   int action = 0;         // Wahl des Benutzers 
   char name[128];         // Name des Kunden
   unsigned pin;           // Kundennummer

   CustomerFile file(filename);

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
           file.append( Customer(pin, name));
           break;

        case 'A':                   // Ausgabe auf dem Bildschirm:
           cout << "\n Die Kunden in der Datei "
                << filename << " : \n" << endl;
           file.display();
           break;

        case 'B':                   // Programm beenden:
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
     "\n\n             B = Programm beenden"
     "\n\n Ihre Wahl:  ";

   cout << header << menuStr;
   do
   {
     if (!cin.get(choice))
        choice = 'B';
     else
        choice = toupper(choice);
   } while( choice != 'E' && choice != 'A' && choice != 'B');
   
   skipRestOfLine();

   return choice;
}
