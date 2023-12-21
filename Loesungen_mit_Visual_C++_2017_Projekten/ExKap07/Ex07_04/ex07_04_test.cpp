// ------------------------------------------------------------
// ex07_04_test.cpp
// Testet die in der Header-Datei ex07_04.h definierten Makros.
// ------------------------------------------------------------
#include <iostream>
using namespace std;

#include "ex07_04.h"

int main()
{
   char c = '?';

   cout << "  **** Testet Makros zur Klassifizierung von Zeichen ****\n"
        << endl;
   do
   {
     cout << "Geben Sie ein Zeichen ein (Abbruch mit q): ";
     if( !cin.get(c) || c == 'q')
         break;
     if( c != '\n') cin.get();      // Nachfolgendes Newline überspringen.

     cout << "\nDas zeichen '" << c << "' ist ";
     if( isBlank(c))
        cout << "ein Blank." << endl;
     else if( isPunct(c))
        cout << "ein Interpunktionszeichen." << endl;
     else if( isXDigit(c))
        cout << "eine Hexadezimalziffer." << endl;
     else
        cout << "\nweder ein Blank noch ein Interpunktionszeichen "
             << "noch eine Hexadezimalziffer." << endl;
   }
   while( c != 'q');

   return 0;
}
