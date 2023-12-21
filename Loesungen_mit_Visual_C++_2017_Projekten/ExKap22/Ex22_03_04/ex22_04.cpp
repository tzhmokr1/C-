// --------------------------------------------------------------
// ex22_04.cpp
// Verwendet die Klasse Polynomial zur Darstellung von Polynomen
//   y = a0 + a1 * x^1 + ... + an * x^n.
// --------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include "polynom.h"
using namespace std;

int main()
{
   cout << "\t ****  Klasse Polynomial  ****\n"
        << endl;

   // Die Koeffizienten a0, a1, ... des 1. Polynoms:
   double  coef[] = { 2.5, -1.8, 4.2, -0.9, 1.7 };
   int n = sizeof(coef) / sizeof(double) - 1;        // Grad

   Polynomial p1( coef, n);          // Definition der Polynome
   Polynomial p2( -1.5, 2.0, -0.5);

   cout << "Das erste Polynom P1:\n  ";
   p1.display();

   cout << "\nEinige Werte des Polynoms:" << endl;

   cout << "       x     |    y = P1(x)\n"
           "   ---------------------------\n";
   cout << fixed << setprecision(2);
   for( double x = -1.0;  x <= 1.1;  x += 0.5)
       cout << setw(10) << x << "   |" 
            << setw(10) << p1.evaluate(x) << endl;
   // Standard wieder herstellen:
   cout.unsetf(ios::fixed); cout.precision(6);

   cout << "\nDas zweite Polynom P2:\n  ";
   p2.display();

   Polynomial p3(p1);                // Kopie von p1
   p3 += p2;
   cout << "\nDie Summe der Polynome P1 + P2:\n  ";
   p3.display();

   p2 += p1;
   cout << "\nund die Summe P2 += P1:\n  ";
   p2.display();

   cout << "\nP2 hat jetzt den Grad:  " << p2.getDegree() << endl;

   return 0;
}
