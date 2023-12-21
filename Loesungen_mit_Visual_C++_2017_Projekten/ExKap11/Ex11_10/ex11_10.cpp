// --------------------------------------------------------
// ex11_10.cpp
// Ruft die Funktionen aus den
// Namensbereichen Circle und Square auf.
// --------------------------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;

#include "circle.h"
#include "square.h"

int main()
{
   cout << "\n\t  ******   Namensberieche Circle und Square   ******\n";

   double radius = 0.0, side = 0.0;

   // --- Circle ---
   cout << "\nGeben Sie den Radius eines Kreises ein: ";
   if( !(cin  >> radius) || radius <= 0.0)
   {
       cerr << "Invalid input!" << endl;
       return 1;
   }

   Circle::setRadius(radius);

   cout << "\nDer Kreis mit dem Radius " << radius << " hat den "
        << "\nUmfang:         " << Circle::getCircumference()
        << "\nFlaecheninhalt: " << Circle::getArea() << endl;

   // --- Square ---
   cout << "\nSeitenlaenge eines Quadrats: ";
   if( !(cin  >> side) || side <= 0.0)
   {
       cerr << "Unzulaessige Eingabe!" << endl;
       return 1;
   }

   Square::setSide(side);

   cout << "\nDas Quadrat mit der Seitenlaenge " << side << " hat den"
        << "\nUmfang:         " << Square::getCircumference()
        << "\nFlaecheninhalt: " << Square::getArea() << endl;
   cout << endl;

   return 0;
}
