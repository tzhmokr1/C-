// ---------------------------------------------------------
// measureArr.h : Klasse mit Move-Konstruktor und -Zuweisung
// ---------------------------------------------------------
#ifndef _MEASUREARR_
#define _MEASUREARR_

#include <iostream>
#include <iomanip>
using namespace std;

class Measure
{
  private:
    double mw;
  public:
    Measure (double w = 0.0) : mw(w){}
    double getWert() const { return mw; }
    void   setWert(double w) { mw = w; }
};

class MeasureArr
{
  private:
    Measure* vekPtr;    // Dynamisches Element
    int max;            // Länge des Vektors
    int anz;            // Aktuelle Anzahl Elemente

  public:
    MeasureArr( int n );
    MeasureArr(const MeasureArr& src);  // Kopierkonstruktor
    MeasureArr(MeasureArr&& src);       // Move-Konstruktor

    ~MeasureArr();

    void append( const Measure& wert);
                                        // Zuweisung: 
    MeasureArr& operator=( const MeasureArr& );  
                                        // Move-Zuweisung:
    MeasureArr& operator=(MeasureArr&& src) ;    

    Measure& operator[](int i);         // Index-Operator
    const Measure& operator[](int i) const;

    // Ausgabe des Vektors
    friend ostream& operator<<( ostream& os, 
                                const MeasureArr& v)
    {
      int w = (int)os.width();        // Feldbreite merken.

      for( Measure* p = v.vekPtr; p < v.vekPtr + v.anz; ++p)
      {
         os.width(w);
         os << p->getWert();
      }

      return os;
     }
};

#endif   // _MEASUREARR_
