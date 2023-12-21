// --------------------------------------------------------
// data.h
// Definition der Klassen Data, XData und SData.
// --------------------------------------------------------
#ifndef _DATA_
#define _DATA_

#define _CRT_SECURE_NO_WARNINGS    // Für VC++ und strcpy()
#include <iostream>
#include <cstring>
using namespace std;

class Data           // Basisklasse für XData und SData
{
 public:
   enum TypeID { BaseClass, XClass, SClass };

   Data() : id(BaseClass) {}
   TypeID getTypeID() const { return id; }
   Data* clone() const;         // Kopie in Abhängikeit  
                                // vom Typ anlegen.
 protected:
   TypeID id;
};

class XData : public Data
{
 private:
   double* pData;     // Zeiger auf X-Daten (double-Wert)
 public:
   XData( double x = 0.0)
   {
      id = XClass;
      pData = new double(x);
   }
   XData( const XData& src)             // Kopierkonstruktor
   {
      id = XClass;
      pData = new double(*src.pData);
   }
   ~XData()                             // Destruktor
   {
      cout << "Destruktor der Klasss XData" << endl;
      delete pData;
   }
   XData& operator=( const XData& src)  // Zuweisung
   {
      id = XClass;
      *pData = *src.pData;
   }

   void setData(double x) { *pData = x; }
   double getData() const { return *pData; }
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
   char* pData;         // Zeiger auf S-Daten (char-Vektor)
 public:
   SData( const char str[] = "")
   {
      id = SClass;
      pData = newStr(str);
   }
   SData( const SData& src)             // Kopierkonstruktor
   {
      id = SClass;
      pData = newStr(src.pData);
   }
   ~SData()                             // Destruktor
   {
      cout << "Destruktor der Klasss SData" << endl;
      delete [] pData;
   }
   SData& operator=( const SData& src)  // Zuweisung
   {
      id = SClass;
      if( this != &src)
        setData( src.getData());
   }

   void setData(const char str[])
   { 
      char *s = newStr(str);
      delete [] pData;
      pData = s;
   }
   const char* getData() const { return pData; }
};

// Kopie in Abhängikeit vom Typ anlegen:
inline Data* Data::clone() const
{
   Data *p = NULL;
   switch( getTypeID())
   {
      case XClass:
         p = new XData( *(const XData*)this);
         break;
      case SClass:
         p = new SData( *(const SData*)this);
         break;
      default:
         p = new Data(*this);
   }
   return p;
}

#endif  // _DATA_
