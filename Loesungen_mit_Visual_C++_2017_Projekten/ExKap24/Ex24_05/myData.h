// --------------------------------------------------------
// myData.h
// Definition der Klasse MyData. Container fuer Objekte 
// vom Typ Data und davon abgeleitete Klassen.
// --------------------------------------------------------
#ifndef _MYDATA_
#define _MYDATA_

#include "data.h"

class MyData      // Container f�r XData- und SData-Objekte
{
  private:
    enum { ARR_LENGTH = 100} ;
    Data *arrPtrData[ARR_LENGTH];
    int count,               // Anzahl Objekte 
        iCur;                // und Einf�geposition.
    int nextFreePos();       // Hilfsmethode: Liefert
                             // n�chsten freien Platz.
  public:
    MyData();                            // Default-Konstruktor
    ~MyData();                           // Destruktor
    bool isEmpty() const { return count == 0; }
    bool insertX( double x);
    bool insertX();
    bool insertS( const char* s);
    bool insertS();
    void printData() const;
};

#endif  // _MYDATA_ 
