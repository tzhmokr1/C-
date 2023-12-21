// --------------------------------------------------------
// data.h
// Definition der Klassen Data, XData und SData.
// --------------------------------------------------------
#ifndef _DATA_
#define _DATA_

#define _CRT_SECURE_NO_WARNINGS    // Für VC++ und strcpy()
#include <iostream>
#include <cstring>
#include <typeinfo>   // Fuer Aufrufe des Operators typeid()
using namespace std;

class Data            // Basisklasse für XData und SData
{
 public:
   virtual ~Data() {}
   virtual void print(ostream& os) const
   { os << "Keine Daten!"; }
   // Dynamisch Kopie des Objekts erzeugen:
   virtual Data* clone() const { return new Data(*this); }
};

class XData : public Data
{
 private:
   double* pData;     // Zeiger auf X-Daten (double-Wert)

 public:
   XData( double x = 0.0)  { pData = new double(x); }
   XData( const XData& src)             // Kopierkonstruktor
   {  
      pData = new double(*src.pData);
   }
   ~XData()                             // Destruktor
   {
      cout << "Destruktor der Klasss XData" << endl;
      delete pData;
   }
   XData& operator=( const XData& src)  // Zuweisung
   {  *pData = *src.pData;
   }
   // Dynamisch Kopie des Objekts erzeugen:
   Data* clone() const { return new XData(*this); }

   void setData(double x) { *pData = x; }
   double getData() const { return *pData; }
   void print(ostream& os) const { os << *pData; }
};

// Hilfsfunktion für Klasse SData
inline char *newStr( const char* str)   // Liefert Kopie von str
{
   int n = strlen(str);
   char *s = new char[n+1];
   strcpy( s, str);
   return s;
}

class SData : public Data
{
 private:
   char* pData;     // Zeiger auf S-Daten (char-Vektor)

 public:
   SData( const char str[] = "")  {  pData = newStr(str);  }

   SData( const SData& src)             // Kopierkonstruktor
   {  pData = newStr(src.pData);
   }
   
   ~SData()                             // Destruktor
   {
      cout << "Destruktor der Klasss SData" << endl;
      delete [] pData;
   }

   SData& operator=( const SData& src)  // Zuweisung
   {
      if( this != &src)
        setData( src.getData());
   }
   // Dynamisch Kopie des Objekts erzeugen:
   Data* clone() const { return new SData(*this); }

   void setData(const char str[])
   { 
      char *s = newStr(str);
      delete [] pData;
      pData = s;
   }
   const char* getData() const { return pData; }
   void print(ostream& os) const { os << pData; }
};

inline ostream& operator<<(ostream& os, const Data& d)
{
    d.print(os);
    return os;
}

#endif  // _DATA_
