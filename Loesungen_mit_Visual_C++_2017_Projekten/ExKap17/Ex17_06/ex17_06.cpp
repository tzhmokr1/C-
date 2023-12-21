// --------------------------------------------------------------
// ex17_06.cpp
// Definiert und testet die Funktion polynomial() zur
// Berechnung des Polynoms y = an * x^n + ... + a1 * x^1 + a0  
// --------------------------------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;

// Prototyp
double polynomial( double x, double coefficients[], int n);

// Die Koeffizienten a0, a1, ... des Polynoms:
double  coef[] = { 2.5, -1.8, 4.2, -0.9, 1.7 };
int n = sizeof(coef) / sizeof(double) - 1;

int main()
{
   cout << "\t **** Berechnung des Polynoms y = P(x)  ****\n"
        << endl;

   cout << "Das Polynom: \n  y = " << coef[0];
   for( int i= 1; i <= n; ++i)
       cout << " + " << coef[i] << "*x^" << i;
   cout << endl << endl;

   cout << "       x     |    y = P(x)\n"
           "   ---------------------------\n";
   cout << fixed << setprecision(2);
   for( double x = -2.0;  x <= 2.1;  x += 0.5)
       cout << setw(10) << x << "   |" 
            << setw(10) << polynomial(x, coef, n) << endl;

   return 0;
}

// --------------------------------------------------------
// Die Funktion polynomial() berechnet ein Polynom
// für einen gegebenen Wert x.
// Parameter:    x, ein Vektor mit den Koeffizienten
//               und der Grad des Polynoms. 
// Return-Wert:  Das Ergebnis.
double polynomial( double x, double coefficients[], int n)
{
   double *p = coefficients + n;     // p zeigt auf den letzten Koeffizient
   double y = *p;                    // = coefficients[n]

   while( --p >= coefficients)
   {
       y = y * x + *p;
   } 
   return y;
}
