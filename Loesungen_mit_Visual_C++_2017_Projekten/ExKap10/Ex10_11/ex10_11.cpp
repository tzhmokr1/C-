// --------------------------------------------------------
// ex10_11.cpp 
// Definiert und testet überladene Funktionen zur
// Berechnung von linearen, quadratischen und 
// kubischen Polynomen. 
// -------------------------------------------------------- 
#include <iostream>
using namespace std;

double P(double x, double a0, double a1);
double P(double x, double a0, double a1, double a2);
double P(double x, double a0, double a1, double a2, double a3);

double a0 =  2.5,     // Die Koeffizienten der Polynome
       a1 = -1.8,
       a2 =  4.2,
       a3 = -0.9;

int main()           // Testet die überladenen Funktionen P()
{
   cout << "\t **** Berechnet y = P(x) für das Polynom P ****\n"
        << endl;

   // P(x) = a0 + a1*x
   cout << "Das lineare Polynom:      P(x) = "
        << a0 << " + " << a1 << "*x" << endl;

   // P(x) = a0 + a1*x + a2*x*x
   cout << "Das quadratische Polynom: P(x) = "
        << a0 << " + " << a1 << "*x" << " + " << a2 << "*x*x" << endl;

   // P(x) = a0 + a1*x + a2*x*x + a3*x*x*x
   cout << "Das kubische Polynom:     P(x) = "
        << a0 << " + " << a1 << "*x" << " + " << a2 << "*x*x"
        << " + " << a3 <<"*x*x*x" << endl;

   double x;

   while(true)
   {
     cout << "\nGeben Sie einen x-Wert ein (Abbruch mit einem Buchstaben): ";
     if( !(cin >> x))
         break;
     cout << "\nFuer x = " << x << " liefert das " << endl;
     cout << "lineare Polynom den Wert      " << P(x, a0, a1)         << endl;
     cout << "quadratische Polynom den Wert " << P(x, a0, a1, a2)     << endl;
     cout << "kubische Polynom den Wert     " << P(x, a0, a1, a2, a3) << endl;
   }

   return 0;
}

// --------------------------------------------------------
// Die Funktionen P(x,...) 
//

double P(double x, double a0, double a1)
{
   return a0 + a1 * x;
}

double P(double x, double a0, double a1, double a2)
{
   return a0 + P(x,a1,a2) * x;
}

double P(double x, double a0, double a1, double a2, double a3)
{
   return a0 + P(x,a1,a2,a3) * x;
}
