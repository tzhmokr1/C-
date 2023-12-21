// ---------------------------------------------------------
// shape2D.h
// Definition der Klassen Shape2D, Circle. Rectangle, Square
// ---------------------------------------------------------
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

// -----  Klasse Circle  -----
//
class Circle : public Shape2D     // Kreis um den
{                                 // Bezugspunkt
 private:
   double radius;     // Radius

 public:
   Circle::Circle( double x, double y, double r)
   : Shape2D(x,y), radius(r)
   {}

   double getRadius() const  { return radius; }
   bool setRadius( double r)
   {  if( r >= 0) { radius = r;  return true; }
      else return false;
   }
   void print() const
   {
      cout << "Kreis-Mittelpunkt: ";  Shape2D::print();
      cout << "     -Radius:      " << radius << endl;
   }
};

// -----  Klasse Rectangle  -----
//
class Rectangle : public Shape2D  // Rechteck
{                                 // Bezugspunkt: linke obere Ecke
 private:
   double height, width;         // Höhe, Breite

 public:
   Rectangle( double x, double y, double h, double w)
   : Shape2D(x,y), height(h), width(w)
   {}

   double getHeight() const { return height; }
   double getWidth() const  { return width; }
   bool setHeight( double h)
   { if( h >= 0) { height = h;  return true; }
     else return false;
   }
   bool setWidth( double w)
   { if( w >= 0) { width = w;  return true; }
     else return false;
   }
   double getArea() const { return height * width; }
   void print() const
   {
      cout << "--- Rechteck ---\n"
           << "Linke obere Ecke: ";  Shape2D::print();
      cout << "Hoehe: " << height << "   Breite: " << width << endl;
   }
};

// -----  Klasse Square  -----
//
class Square : public Rectangle   // Quadrat
{                                 // Bezugspunkt: linke obere Ecke
 private:
   bool setHeight( double h);     // Vor dem Anwender verstecken.
   bool setWidth( double w);

 public:
   Square( double x, double y, double side)  // Rechteck mit  
   : Rectangle(x,y,side,side)                // Höhe = Breite = Seitenlaenge
   {}

   bool setSideLength( double sl)
   { 
      return Rectangle::setHeight(sl) && Rectangle::setWidth(sl);  
   }
   double getSideLength() const { return getHeight(); }

   void print() const
   {
      cout << "--- Quadrat ---\n"
           << "Linke obere Ecke: ";  Shape2D::print();
      cout << "Seitenlaenge: " << getSideLength() << endl;
   }
};

#endif   // _SHAPE2D_
