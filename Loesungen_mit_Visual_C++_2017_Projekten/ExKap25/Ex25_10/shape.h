// ---------------------------------------------------------
// shape.h
// Definition der Klassen Point, Shape, Polyline,
// Line, Polygon, Rectangle,  Ellipse, Circle.
// Incl. der virtuellen Methode clone().
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
    virtual ~Shape() { cout << "Shape-Destruktor" << endl; }

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
    virtual Shape* clone() const { return new Shape(*this); }
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
    Shape* clone() const { return new Polyline(*this); }
}; 

// -----  Klasse Line  -----
//
class Line : public Polyline
{
  public:
    Line( Point a, Point b) : Polyline(a,b) {}
    Line( double x1, double y1, double x2, double y2)
    : Polyline( Point(x1,y1), Point(x2,y2)) {}
    Shape* clone() const { return new Line(*this); }

  private:
    Polyline& operator+=( const Point&);       // Diese Operationen
    Polyline& operator+=( const Polyline&);    // "verbieten".
};

// -----  Klasse Polygon  -----
//
class Polygon : public Polyline
{
  public:
    Polygon( Point a = Point(0,0)) : Polyline(a) {}
    Polygon( Point arr[], int n) 
    : Polyline( arr, n)
    {}

    int getNumberOfVertices() const
    { 
       if( nLines == 0 || arrPoints[nLines-1] != anchor)
          return nLines + 1;
       else 
          return nLines;
    }
    int getNumberOfLines() const
    { return getNumberOfVertices(); } 

    double getCircumference() const
    {
       double len = Polyline::getLength();
       if( nLines > 0)
          len += anchor.distance( anchor + arrPoints[nLines-1]);
       return len;
    }
    double getLength() const { return getCircumference(); }
    Shape* clone() const { return new Polygon(*this); }
};

// -----  Klasse Rectangle  -----
//
class Rectangle : public Polygon  // Rechteck
{                                 // Anker: linke untere Ecke
  public:
    Rectangle( Point lBottom, double w, double h)
    : Polygon(lBottom)
    {
      nLines = 3;                  // Anzahl Linien: nLines+1 
      arrPoints = new Point[3];
      arrPoints[0] = Point(0,h);
      arrPoints[1] = Point(w,h);
      arrPoints[2] = Point(w,0);
    }
    Rectangle( Point lBottom, Point rTop)
    {
      *this = Rectangle( lBottom, rTop.x - lBottom.x, rTop.y - lBottom.y);
    }
    double getHeight() const { return arrPoints[0].y; }
    double getWidth() const  { return arrPoints[2].x; }
    double getArea() const { return getHeight() * getWidth(); }
    Shape* clone() const { return new Rectangle(*this); }

  private:
    Polyline& operator+=( const Point&);       // Diese Operationen
    Polyline& operator+=( const Polyline&);    // "verbieten".
};

// -----  Klasse Ellipse  -----
//
class Ellipse : public Shape      // Ellipse um den Anker
{
  protected:
    double a, b;        // Grosse und kleine Halbachse
                        // = groester und kleinster Abstand
  public:               // vom Mittelpunkt (Anker).
    Ellipse( Point m, double aa, double bb)
    : Shape(m), a(aa), b(bb)
    {}
    double getSemimajorAxis() const  { return a; }
    double getSemiminorAxis() const  { return b; }
    bool setSemimajorAxis( double aa)
    {  if( aa >= 0) { a = aa;  return true; }
       else return false;
    }
    bool setSemiminorAxis( double bb)
    {  if( bb >= 0) { b = bb;  return true; }
       else return false;
    }
    void scale( double scalingFactor)         // Skalierung.
    {
       a  *= scalingFactor;  b *= scalingFactor;
    }
    double getCircumference() const
    {
       return 3.14159 * (1.5*(a+b) - sqrt(a*b)); 
    }
    string toString() const
    {
       stringstream sstream;
       sstream << "Ellipsen-Mittelpunkt: " << anchor.toString() 
               << "  Halbachsen: " << a << " und " << b; 
       return sstream.str();
    }
    Shape* clone() const { return new Ellipse(*this); }
};

// -----  Klasse Circle  -----
//
class Circle : public Ellipse     // Kreis um den
{                                 // Bezugspunkt
  public:
    Circle( Point m, double r)
    : Ellipse(m, r, r)
    {}
    double getRadius() const  { return a; }
    bool setRadius( double r)
    {  if( r >= 0) { a = r; b = r;  return true; }
       else return false;
    }
    string toString() const
    {
       stringstream sstream;
       sstream << "Kreis-Mittelpunkt: " << anchor.toString() 
               << "  Radius: " << a;
       return sstream.str();
    }
    Shape* clone() const { return new Circle(*this); }
};

#endif   // _SHAPE_
