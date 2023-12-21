// -----------------------------------------------------
// measureArr.cpp 
// Implementierung der Methoden von MeasureArr
// -----------------------------------------------------

#include "measureArr.h"
#include <cstdlib>               // Fuer exit()
MeasureArr::MeasureArr( int n )
{
    max = n;   anz = 0;          // max und anz setzen.
    vekPtr = new Measure[max];   // Speicher reservieren.
    cout << "Konstruktor von MeasureArr aufgerufen" << endl;
}

MeasureArr::MeasureArr(const MeasureArr& src)
{
    max = src.max;
    anz = src.anz;
    vekPtr = new Measure[max];

    for( int i = 0; i < anz; i++ )
     vekPtr[i] = src.vekPtr[i];
    cout << "Kopierkonstruktor von MeasureArr aufgerufen\n";
}

MeasureArr::MeasureArr(MeasureArr&& src)  // Move-Konstruktor
{
    max    = src.max;         
    anz    = src.anz;
    vekPtr = src.vekPtr;

    src.vekPtr = NULL;
    cout << "Move-Konstruktor von MeasureArr aufgerufen\n";
}

MeasureArr::~MeasureArr()
{
    delete[] vekPtr;
    cout << "Destruktor von MeasureArr aufgerufen" << endl;
}

void MeasureArr::append( const Measure& wert)
{ 
    if( anz + 1 > max )
    { 
       cerr << "\n class MeasureArr: Out of Range! "; 
       exit(1);
    }
    vekPtr[anz++] = wert;  // Messwert anhängen.
}


MeasureArr& MeasureArr::operator=( const MeasureArr& src )
{
   if( this != &src )  // Keine Selbstzuweisung!
   { 
      max = src.max; 
      anz = src.anz;

      delete[] vekPtr;            // Speicher freigeben,
      
      vekPtr = new Measure[max];  // neu reservieren,

      for( int i=0; i < anz; i++) // Elemente kopieren.
        vekPtr[i] = src.vekPtr[i];
   }

   cout << "Zuweisungsoperator von MeasureArr aufgerufen\n";
   return *this;
}


MeasureArr& MeasureArr::operator=(MeasureArr&& src)  
{
    if( this != &src )      // Keine Selbstzuweisung!
    { 
       Measure* p = vekPtr;  // Adressen tauschen.
       vekPtr = src.vekPtr; 
       src.vekPtr = p;      

       max = src.max;      // Andere Elemente zuweisen.         
       anz = src.anz;  
    }
    cout << "Move-Zuweisung von MeasureArr aufgerufen\n";
    return *this;
}


Measure& MeasureArr::operator[]( int i )
{
   if( i < 0 || i >= anz )
   { 
      cerr << "\n class MeasureArr: Out of Range! "; 
      exit(1);
   }
   return vekPtr[i];
}


const Measure& MeasureArr::operator[]( int i ) const
{
   if( i < 0 || i >= anz )
   { 
      cerr << "\n class MeasureArr: Out of Range! "; 
      exit(1);
   }
   return vekPtr[i];
}
