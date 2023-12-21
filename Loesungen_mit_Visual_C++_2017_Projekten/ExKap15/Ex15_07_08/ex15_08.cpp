// --------------------------------------------------------
// ex15_08.cpp
// Testet die Klasse MoneyChanger.
// --------------------------------------------------------
#include "MoneyChanger.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
   MoneyChanger sale(1254.95);

   cout << "\n\t\t    *****  Geldwechselautomat  *****\n\n";

   cout << fixed << setprecision(2);
   cout << "\n\t\t EUR               CND               YEN"
        << "\n\t  ---------------------------------------------------"
        << endl;

   cout << setw(20) << sale.getEUR()
        << setw(20) << sale.getCND()
        << setw(20) << sale.getYEN() << endl;

   MoneyChanger::setRateCND(1.575);      // Aktualisert den 
   MoneyChanger::setRateYEN(124.3535);   // Wechselkurs.

   sale.setAmount(403250.875);           // Wechselbetrag

   cout << setw(20) << sale.getEUR()
        << setw(20) << sale.getCND()
        << setw(20) << sale.getYEN() << endl;
   return 0;
}
