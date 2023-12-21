// -------------------------------------------------------
// ex07_03.cpp
// Berechnet die Oberfläche und das Volumen einer Kugel.
// -------------------------------------------------------

#include <iostream>
using namespace std;

#define PI        3.1415927
#define SQUARE(n) ((n)*(n))
#define CUBE(n)   ((n)*(n)*(n))

int main()
{
   double radius = 0.0;

   cout << "  **** Oberflaeche und Volumen einer Kugel ****\n"
        << endl;
   cout << "Geben Sie den Radius einer Kugel ein: ";
   cin >> radius;

   cout << "\nOberflaeche: " << 4.0 * PI * SQUARE(radius)
        << "\nVolumen:     " << 4.0/3.0 * PI * CUBE(radius)
        << endl;

   return 0;
}
