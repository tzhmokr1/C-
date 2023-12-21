// -------------------------------------------------------
// polynom.cpp
// Implementierung der Klasse Polynomial.
// -------------------------------------------------------
#include <iostream>
#include "polynom.h"
using namespace std;

// Private Hilfsfunktion zur Initialisierung:
void Polynomial::init( double coef[], int g)
{
   degree = 0;
   if( g > 0)
      degree = g;
   arrCoef = new double[degree+1];
   for( int i=0; i <= degree; ++i)
      arrCoef[i] = coef[i];
}


// Konstruktor für bis zu vier Koeffizienten:
Polynomial::Polynomial( double a0, double a1,
                        double a2, double a3)
{
   double coef[] = { a0, a1, a2, a3 };
   int i = 3;
   for(  ; i > 0 && coef[i] == 0.0; --i)
      ;
   init( coef, i);    // i == Grad des Polynoms
}

// Wert des Polynoms an der Stelle x:
double Polynomial::evaluate( double x) const
{
   int i = degree;     // Index des letzten Koeffizienten
   double y = arrCoef[i];

   while( --i >= 0)
       y = y * x + arrCoef[i];

   return y;
}

// Das Polynom anzeigen:
void Polynomial::display() const
{
   cout <<  "y = " << arrCoef[0];
   for( int i= 1; i <= degree; ++i)
      cout << " + " << arrCoef[i] << "*x^" << i;
   cout << endl;
}

// Zuweisung:
Polynomial& Polynomial::operator=(const Polynomial& p)
{
   delete [] arrCoef;
   init( p.arrCoef, p.degree);
   return *this;
}

// Operator +=
Polynomial& Polynomial::operator+=(const Polynomial& p) 
{
   int i=0;
   if( p.degree > degree)
   {                          // Vektor arrCoef verlaengern.
       double* arr = new double[p.degree + 1];
       for( i = 0; i <= degree; ++i)  // Koeffizienten kopieren.
           arr[i] = arrCoef[i];
       for( ; i <= p.degree; ++i)  // Rest mit 0 initialisieren.
           arr[i] = 0.0;
       degree = p.degree;
       delete [] arrCoef;          // Alten Vektor freigeben.
       arrCoef = arr;
   }
   for( i = 0; i <= p.degree; ++i)   // Addieren.
      arrCoef[i] += p.arrCoef[i];
   
   return *this;
}
