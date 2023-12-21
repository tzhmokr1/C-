// ---------------------------------------------------------
// ex07_09.cpp
// Bestimmt die Anzahl Tage in einem Monat und gibt sie aus.
// ---------------------------------------------------------
#include <iostream>
using namespace std;

#define isLeapYear(year) \
          ((year%4 == 0 && year%100 != 0) || year%400 == 0)

int main()
{
   int month = 0, year = 0;
   
   cout << "\nGeben Sie eine Monatszahl ein: ";
   cin >> month;

   switch( month)
   {
     case 1:
     case 3:
     case 5:
     case 7:
     case 8:
     case 10:
     case 12: cout << "Anzahl Tage: 31" << endl;
              break;
     case 4:
     case 6:
     case 9:
     case 11: cout << "Anzahl Tage: 30" << endl;
              break;
     case 2:  cout << "Geben Sie das Jahr ein: "; 
              if( !(cin >> year))
                cout << "Unzulaessige Eingabe!" << endl; 
              else
              {
                 cout << "Anzahl Tage: ";
                 if( isLeapYear(year))
                   cout << 29 << endl;
                 else
                   cout << 28 << endl;
              }
              break;
      default: cout << "Unzulaessige Monatszahl." << endl;
   }

   return 0;
}
