// ---------------------------------------------------------
// ex19_05.cpp
// Testet die Klasse Point3D. 
// ---------------------------------------------------------
#include <iostream>
#include <string>
#include "point3D.h"
using namespace std;

int main()
{
   cout << "\n\t*****  Die Klasse Point3D testen  *****" << endl; 

   Point3D p1, p2(1,2,3);

   cout << "\nErster Punkt:  " + p1.toString()
        << "\nZweiter Punkt: " + p2.toString() << endl;

   p1 = Point3D(0.5, 0.7, 1.1);
   p2 += p1;
   cout << "\nErster Punkt:  " << p1.toString()
        << "\nZweiter Punkt: " << p2.toString() << endl;

   p1 = -p1;
   p2 -= p1;
   cout << "\nErster Punkt:  " << p1
        << "\nZweiter Punkt: " << p2 << endl;

   return 0;
}
