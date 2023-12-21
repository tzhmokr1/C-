// --------------------------------------------------------------------
// ex10_10.cpp 
// Definiert und ruft die überladene Funktion geoMean() auf, die 
// das geometrische Mittel von zwei bzw. drei nicht-negativen 
// Gleitpunktzahlen berechnet.
// --------------------------------------------------------------------

#include <iostream>
using namespace std;

// Prototypen
double geoMean( double x, double y);
double geoMean( double x, double y, double z);

int main()     // Testet die überladenen Funktionen geoMean()
{
   double a=0.0, b=0.0, c=0.0;

   cout << "  **** Geometrisches Mittel ****\n"
        << endl;

   cout << "Geben Sie zwei Gleitpunktzahlen ein: " << endl;
   cin  >> a >> b;

   cout << "Das geometrische Mittel von " << a << " und " << b
        << " ist " << geoMean( a, b) << endl;

   cout << "Geben Sie eine dritte Zahl ein: " << endl;
   cin  >> c;

   cout << "Das geometrische Mittel von " << a << ", " << b << " und " << c
        << " ist " << geoMean( a, b, c) << endl;

   return 0;
}

// --------------------------------------------------------
// Die Funktionen geoMean() 
//
#include <cmath>       // Prototypen von sqrt() und pow()
using namespace std;

double geoMean( double x, double y)
{
   if( x >= 0 && y >= 0) 
      return sqrt(x * y);
   else
      return -1;
}

double geoMean( double x, double y, double z) 
{
   if( x >= 0 && y >= 0 && z >= 0) 
      return pow( x*y*z, 1.0/3.0);
   else
      return -1;
}
