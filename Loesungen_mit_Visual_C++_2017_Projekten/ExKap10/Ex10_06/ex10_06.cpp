// --------------------------------------------------------
// ex10_06.cpp 
// Definiert und testet die Funktion median(), die 
// den Median von drei Gleitpunktzahlen berechnet.
// --------------------------------------------------------

#include <iostream>
using namespace std;

double median(double x, double y, double z);

int main()       // Testet die Funktion median()
{
   double a=0.0, b=0.0, c=0.0;

   cout << "  **** Berechnet den Median von drei Zahlen  ****\n"
        << endl;

   cout << "Geben Sie drei Gleitpunktzahlen ein:" << endl;
   cin  >> a >> b >> c;

   cout << "Der Median ist " << median( a, b, c) << endl;

   return 0;
}

// --------------------------------------------------------
// Die Funktion median() liefert den Median von
// drei Gleitpunktzahlen.


double median(double x, double y, double z) 
{
    if( x < y && x < z)
        return y < z ? y : z;     // Min(y,z)

    else if( x > y && x > z)
        return y > z ? y : z;     // Max(y,z)

    else
        return x;
}
