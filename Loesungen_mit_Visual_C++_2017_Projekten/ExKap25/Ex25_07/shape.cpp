// ---------------------------------------------------------
// shape.cpp
// Implementierung der Methoden der Klassen
// Shape und Polyline.
// ---------------------------------------------------------
#include "shape.h"

// ----- Klasse Shape -----
// Alle Methoden inline

// ----- Klasse Polyline -----
//
Polyline::Polyline( Point arr[], int n)
{
   arrPoints = NULL;
   nLines = 0;
   if( n > 0)
   {
      anchor = arr[0];          // Anker
      if( n > 1)
      {
        nLines = n-1;
        // Punkte relativ zum Anker speichern;
        arrPoints = new Point[nLines];
        for( int i = 0; i < n-1; ++i)
           arrPoints[i] = arr[i+1] - anchor;  
      }
   }
}

Polyline::Polyline( const Polyline& src)   // Kopierkonstruktor
{
   nLines = src.nLines;
   anchor = src.anchor;
   arrPoints = NULL;
   
   if( src.nLines > 0)
   {
      arrPoints = new Point[nLines];
      for( int i = 0; i < nLines; ++i)
         arrPoints[i] = src.arrPoints[i];  
   }
}

Polyline& Polyline::operator=( const Polyline& src) // Zuweisung.
{
   if( this != &src)
   {
      delete [] arrPoints;
      nLines = src.nLines;
      anchor = src.anchor;
      arrPoints = NULL;
      if( src.nLines > 0)
      {
         arrPoints = new Point[nLines];
         for( int i = 0; i < nLines; ++i)
            arrPoints[i] = src.arrPoints[i];  
      }
   }
   return *this;
}

double Polyline::getLength() const
{
   double len = 0.0;
   if( nLines > 0)
   {
      Point begin(0,0);
      for( int i = 0; i < nLines; ++i)
      {
         len += begin.distance( arrPoints[i]);
         begin = arrPoints[i];
      }
   }
   return len;
}

// Einen weiteren Punkt anhaengen:
Polyline& Polyline::operator+=( const Point& p)
{
   Point *ptr = new Point[nLines+1];      // Neuer Vektor.
   for( int i = 0 ; i < nLines; ++i)      // Punkte in neuen
      ptr[i] = arrPoints[i];              // Vektor kopieren.
   ptr[nLines] = p - anchor;              // Neuen Punkt hinzufuegen.
   ++nLines;
   delete [] arrPoints;                   // Alten Vektor freigeben.
   arrPoints = ptr;
   return *this;
}

// Einen zweiten Linienzug anhaengen:
Polyline& Polyline::operator+=( const Polyline& src)
{
   if( src.nLines > 0)
   {
      Point last = Point(0,0);  // Rel. Koordinaten des letzten Punktes.
      if( nLines > 0)
         last = arrPoints[nLines-1];
      Point *ptr = new Point[nLines + src.nLines];    // Neuer Vektor
      int i;
      for( i = 0; i < nLines; ++i)      // Punkte in neuen Vektor kopieren.
         ptr[i] = arrPoints[i];   
      for( i = 0; i < src.nLines; ++i)  // Punkte von src anhaengen.
         ptr[nLines+i] = last + src.arrPoints[i];

      nLines += src.nLines;
      delete [] arrPoints;              // Alten Vektor freigeben.
      arrPoints = ptr;
   }
   return *this;
}

void Polyline::scale( double scalingFactor)
{
   for( int i=0; i < nLines; ++i)
      arrPoints[i] *= scalingFactor;
}

string Polyline::toString() const
{
   string str = anchor.toString();
   for( int i=0; i < nLines; ++i)
      str += "  ",  str += (anchor+arrPoints[i]).toString();
   return str;
}
