// ---------------------------------------------------------
// point3D.h
// Die Klasse Point3D mit Indexoperator, Skalarprodukt und 
// innerem Produkt.
// ---------------------------------------------------------
#ifndef _POINT3D_
#define _POINT3D_

#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

class Point3D
{
  private:
    double x, y, z;

  public:
    // Constructor:
    Point3D( double _x=0.0, double _y=0.0, double _z=0.0)
    : x(_x), y(_y), z(_z) {}

    string toString() const;

    double& operator[]( int i);       // Für den Zugriff auf x, y, z

    double operator[]( int i) const   // Für read-only Objekte
    {
       return ((Point3D)(*this))[i];  // "const" weg-casten
    }

    Point3D operator-() const { return Point3D(-x, -y, -z); }

    Point3D& operator+=( const Point3D& p)
    {
       x += p.x;  y += p.y;  z += p.z;
       return *this;
    }

    Point3D& operator-=( const Point3D& p)
    {
       x -= p.x;  y -= p.y;  z -= p.z;
       return *this;
    }

    Point3D& operator*=( double a)
    {
       x *= a;  y *= a;  z *= a;
       return *this;
    }

    friend double operator*( const Point3D& p1, const Point3D& p2);
};

// Explizit inline-Methoden:
inline string Point3D::toString() const
{
   stringstream sstream;
   sstream << '(' << x << ", " << y << ", " << z << ')';
   return sstream.str();
}

inline double& Point3D::operator[]( int i)
{
   switch(i) 
   {
      case 0: return x;
      case 1: return y;
      case 2: return z;
      default:
         cerr << "Point3D: Unzulaessiger Index!" << endl;
         exit(1);
   }
}

// Global operator functions:
inline ostream& operator<<(ostream& os, const Point3D& p)
{
   os << p.toString(); 
   return os;
}

inline Point3D operator+( const Point3D& p1, const Point3D& p2)
{
   Point3D p(p1);
   return p += p2;
}

inline Point3D operator-( const Point3D& p1, const Point3D& p2)
{
   Point3D p(p1);
   return p -= p2;
}

inline Point3D operator*( double c, const Point3D& p)
{
   Point3D pnt(p);
   return pnt *= c;
}

inline Point3D operator*( const Point3D& p, double c)
{
   return c * p;
}

inline double operator*( const Point3D& p1, const Point3D& p2)
{
   return p1.x * p2.x  +  p1.y * p2.y  +  p1.z * p2.z;
}

#endif  // _POINT3D_
