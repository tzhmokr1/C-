// --------------------------------------------------------
// ex10_04.cpp 
// Definiert und testet die Funktion cylinderVolume(), 
// die das Volumen eines Zylinders berechnet.
// --------------------------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;

double cylinderVolume( double radius, double height);

int main()
{
   double radius = 0.0, height = 0.0;

   cout << "\n\t    **** Volumen eines Zylinders ****\n"
        << "\n\t  Radius        Hoehe         Volumen"
        << "\n\t---------------------------------------"
        << endl;

   cout << fixed;
   for( radius = 0.5; radius < 2.1; radius += 0.5)
      for( height = 0.5; height < 2.1; height += 0.5)
      {
         cout << setprecision(1)
              << setw(14) << radius << setw(14) << height;
         cout << setprecision(6)
              << setw(18) << cylinderVolume( radius, height)
              << endl;
      }

   return 0;
}

// ------- Die Funktion cylinderVolume() -------
//
#define PI  3.1415927
double cylinderVolume( double r, double h)
{
   return  PI * r * r * h;
}
