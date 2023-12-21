// --------------------------------------------------------
// ex10_05.cpp 
// Definiert und testet die Funktion round2(), die
// eine Gleitpunktzahl auf zwei Dezimalziffern rundet.
// --------------------------------------------------------

#include <iostream>
using namespace std;

double round2(double x);

int main()       // Testet die Funktion round2().
{
   double x;

   cout << "  ****    Runden... ****\n"
        << endl;

   cout << "Geben Sie eine Gleitpunktzahl ein: ";
   cin  >> x;

   cout << "Der gerundete Wert " << round2(x) << endl;

   return 0;
}

// --------------------------------------------------------
// Die Funktion round2() 
//
#include <math.h>

double round2(double x)
{
    double sign = 1.0;
    if( x < 0.0)
        x = -x,  sign = -1.0;

    return sign * floor(x*100.0 + 0.5) / 100.0;
}

