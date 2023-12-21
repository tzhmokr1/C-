// --------------------------------------------------------
// shape2D.h
// Definition der Klassen Shape2D und Circle.
// --------------------------------------------------------
#ifndef _SHAPE2D_
#define _SHAPE2D_

#include <iostream>
using namespace std;

class Shape2D        // Basisklasse für zweidimensionale
{                    // geometrische Figuren.
 private:
   double x, y;      // Bezugspunkt für die Lage der Figur

 public:
   Shape2D(double x, double y) { setX(x); setY(y); }

   double getX() const  { return x; }
   double getY() const  { return y; }
   void setX(double xx) { x = xx; }
   void setY(double yy) { y = yy; };

   void move(double dx, double dy)    // Verschiebung
   { x += dx; y += dy; }

   void print() const                 // Anzeige
   { cout << '(' << x << ',' << y << ')' << endl;  }
};

class Circle : public Shape2D     // Kreis um den
{                                 // Bezugspunkt
 private:
   double radius;     // Radius

 public:
   Circle( double x, double y, double r);

   double getRadius() const  { return radius; }
   bool setRadius( double r)
   { if( r >= 0) { radius = r;  return true; }
     else return false;
   }
   void print() const;
};

inline Circle::Circle( double x, double y, double r)
: Shape2D(x,y), radius(r)
{}

inline void Circle::print() const
{
   cout << "Kreis-Mittelpunkt: ";  Shape2D::print();
   cout << "     -Radius:      " << radius << endl;
}

#endif   // _SHAPE2D_
