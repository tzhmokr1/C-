// ---------------------------------------------------------
// shape.h
// Definition der Klassen Point, Shape und Polyline. 
// ---------------------------------------------------------
#ifndef _SHAPE_
#define _SHAPE_

#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

// -----  Klasse Point  -----
//
struct Point
{
   double x, y;
   Point( double xx = 0.0, double yy = 0.0)
   : x(xx), y(yy) {}

   double distance( const Point& p2) const
   { 
      double dx = x - p2.x,
             dy = y - p2.y;
      return sqrt( dx*dx + dy*dy);
   }
   string toString() const
   {
      stringstream sstream;
      sstream << '(' << x << ", " << y << ')';
      return sstream.str();
   }
   Point& operator*=( double c)
   {  x *= c; y *= c;  return *this; }  
};

inline Point operator+( const Point& p1, const Point& p2)
{
   return Point(p1.x + p2.x, p1.y + p2.y);
}

inline Point operator-( const Point& p1, const Point& p2)
{
   return Point(p1.x - p2.x, p1.y - p2.y);
}

inline bool operator==( const Point& p1, const Point& p2)
{
   return p1.x == p2.x && p1.y == p2.y;
}

inline bool operator!=( const Point& p1, const Point& p2)
{
   return !(p1 == p2);
}

inline ostream& operator<<( ostream& os, const Point& p)
{
   os << p.toString();   return os;
}

// -----  Klasse Shape  -----
//
class Shape
{
  protected:
    Point anchor;     // Anker = Bezugspunkt für die Lage der Figur
  public:
    Shape( const Point& a = Point()) : anchor(a) {}
    virtual ~Shape() {}

    Point getAnchor() const  { return anchor; }
    void setAnchor(Point a) { anchor = a; }

    void move(double dx, double dy)      // Verschiebung
    { anchor.x += dx; anchor.y += dy; }

    virtual void scale( double scalingFactor) {}
    virtual void draw() const {}

    virtual string toString() const
    {
       string str("Shape-Anker: ");
       return str += anchor.toString();
    }
};

// -----  Klasse Polyline  -----
//
class Polyline : public Shape
{
  protected: 
    Point *arrPoints;  // Die "Endpunkte" der Linien,
                       // relativ zum Betzugspunkt.
    int nLines;        // Anzahl der Linien-Segmente
                       // == Anzahl Endpunkte.
  public:
    Polyline( const Point& a = Point())         // Nur ein Punkt
    : Shape(a), nLines(0), arrPoints(NULL) {}
    Polyline( const Point& p1, const Point& p2) // Eine Linie
    : Shape(p1), nLines(1)
    {
       arrPoints = new Point(p2 - p1);
    }
    Polyline( Point arr[], int n); 
    Polyline( const Polyline& src);        // Kopierkonstruktor
    ~Polyline() { delete [] arrPoints; }   // Destruktor

    Polyline& operator=( const Polyline& src); // Zuweisung.

    int getNumberOfLines() const { return nLines; } 
    double getLength() const;
    void scale( double scalingFactor);         // Skalierung.

    Polyline& operator+=( const Point& p);     // Haengt einen neuen Punkt an.
    Polyline& operator+=( const Polyline& pl); // Haengt einen zweiten
                                               // Linienzug an.
    string toString() const;
};

#endif   // _SHAPE_
