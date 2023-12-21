// ---------------------------------------------------------
// ex19_06.cpp
// Testet die neuen Operatoren der Klasse Point3D. 
// ---------------------------------------------------------
#include <iostream>
#include <string>
#include <cmath>
#include "point3D.h"
using namespace std;

int main()
{
   cout << "\n\t***** Die Klasse Point3D testen *****" << endl; 

   Point3D p1(0,2,3);
   const Point3D p2(1.7, -0.7, 2.3);

   p1[0] = p2[0] + p2[1];
   cout << "\nErster Punkt:  " << p1
        << "\nZweiter Punkt: " << p2 << endl;

   cout << "\nSumme:         " << p1 + p2
        << "\nDifferenz:     " << p1 - p2 << endl;

   p1 *= 1.5;
   cout << "\nErster Punkt * 1.5 :  " << p1
        << "\n-0.5 * zweiter Punkt: " << -0.5 * p2 << endl;

   cout << "\nDer Absolutbetrag von     " << p1 << " ist " << sqrt(p1*p1) 
        << endl;

   cout << "\nDas innere Produkt von   " << p1 << " und " << -p2 << " ist "
        << p1 * -p2 << endl;

   p1 = Point3D(1,1,0);
   const Point3D p3(-1,1,0);
   cout << "\nDas innere Produkt von   " << p1 << " und " << p3 << " ist "
        << p1 * p3 << endl;

   return 0;
}
