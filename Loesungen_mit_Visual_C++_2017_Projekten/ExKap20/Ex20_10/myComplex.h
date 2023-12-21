// ---------------------------------------------------------
// myComplex.h
// Definies the class Complex.
// ---------------------------------------------------------
#ifndef _MYCOMPLEX_
#define _MYCOMPLEX_

#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
  private:
    double re, im;

  public:
    // Constructor:
    explicit Complex( double r=0.0, double i=0.0) : re(r), im(i)
    { }
    // Conversion function:
    operator double() const { return re; }

    double real() const { return re; }
    double imag() const { return im; }

    Complex conj() const { return Complex(re, -im); }
    double  norm() const { return re*re + im*im; }
    double  abs()  const { return sqrt( norm()); }
  
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

    Complex& operator*= (const Complex& z)
    {
      double r = re;        // Saves the original value.
      re = re * z.re - im * z.im;
      im = r  * z.im + im * z.re;
      return *this;
    }

    Complex& operator/= (const Complex& z)
    {
      double n = z.norm();
      Complex temp( z.re/n, -z.im/n);   // z.conj() / z.norm()
      return *this *= temp;
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

inline Complex operator*( const Complex& z1, const Complex& z2)
{
    Complex z(z1);          // A copy of z1
    return z *= z2;
}

inline Complex operator/( const Complex& z1, const Complex& z2)
{
    Complex z(z1);          // A copy of z1
    return z /= z2;
}

inline bool operator==( const Complex& z1, const Complex& z2)
{
    return z1.real() == z2.real()  &&  z1.imag() == z2.imag();
}

inline bool operator!=( const Complex& z1, const Complex& z2)
{
    return !(z1 == z2);
}

#endif  // _MYCOMPLEX_
