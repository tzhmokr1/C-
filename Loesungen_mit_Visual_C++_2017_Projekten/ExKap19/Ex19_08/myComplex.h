// ---------------------------------------------------------
// myComplex.h
// Definiert die Klasse Complex.
// ---------------------------------------------------------
#ifndef _MYCOMPLEX_
#define _MYCOMPLEX_

#include <iostream>
using namespace std;

class Complex
{
  private:
    double re, im;

  public:
    // Konstruktor:
    Complex( double r=0.0, double i=0.0) : re(r), im(i)
    { }

    double real() const { return re; }
    double imag() const { return im; }

    Complex operator-() const
    {
       return Complex(-re, -im);
    }

    Complex& operator+= (const Complex& z)
    {
      re += z.re;           // this->re += z.re;
      im += z.im;
      return *this;
    }

    Complex& operator-= (const Complex& z)
    {
      re -= z.re;           // this->re -= z.re;
      im -= z.im;
      return *this;
    }
};

inline ostream& operator<< ( ostream& os, const Complex& z)
{
   os << z.real() << " + " << z.imag() << "i";
   return os;
}

inline Complex operator+( const Complex& z1, const Complex& z2)
{
    Complex z(z1);          // A copy of z1
    return z += z2;
}

inline Complex operator-( const Complex& z1, const Complex& z2)
{
    Complex z(z1);          // A copy of z1
    return z -= z2;
}

#endif   // _MYCOMPLEX_
