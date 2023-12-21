// ---------------------------------------------------------
// point3D.h
// Definiert die Klasse Point3D.
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
    // Konstruktor:
    Point3D( double _x=0.0, double _y=0.0, double _z=0.0)
    : x(_x), y(_y), z(_z) {}

    string toString() const;
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
};

inline string Point3D::toString() const
{
   stringstream sstream;
   sstream << '(' << x << ", " << y << ", " << z << ')';
   return sstream.str();
}

inline ostream& operator<<(ostream& os, const Point3D& p)
{
   os << p.toString(); 
   return os;
}

#endif  // _POINT3D_
