// --------------------------------------------------------
// Definiert und testet die rekursive Funktion power(), 
// die ganzzahlige Potenzen einer Gleitpunktzahl berechnet.
// --------------------------------------------------------
#include <iostream>
#include <cmath>
using namespace std;

double power(double base, unsigned int exp);

int main()       // Testet die rekursive Funktion pow()
{
   double       base     = 0.0;
   unsigned int exponent = 0;

   cout << "  **** Berechnet ganzzahlige Potenzen ****\n"
        << endl;

   cout << "Geben Sie Werte zum Testen ein\n"
        << "Basis (Gleitpunktzahl):             ";  cin >> base;
   cout << "Exponent (nicht-negative Ganzzahl): ";  cin >> exponent;

   cout << "Ergebnis:                   " << base << " hoch "
        << exponent << " = " << power( base, exponent) 
        << endl;

   cout << "\nEin Aufruf der Standardfunktion liefert: " 
        << pow( base, (double)exponent) << endl;

   return 0;
}

// -----------------------------------------------------
// Die rekursive Funktion power() berechnet 
// ganzzahlige Potenzen einer Gleitpunktzahl.

double power(double base, unsigned int exp) 
{
    if( exp == 0)
        return 1.0;
    else
        return base * power( base, exp-1);
}
