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
   virtual ~Data() {}
   virtual TypeID getTypeID() const { return BaseClass; }
};

class XData : public Data
{
 private:
   double* pData;     // Zeiger auf X-Daten (double-Wert)
 public:
   XData( double x = 0.0)
   {
      pData = new double(x);
   }
   ~XData()                             // Destruktor
   {
      cout << "Destruktor der Klasss XData" << endl;
      delete pData;
   }
   TypeID getTypeID() const { return XClass; }
   void setData(double x) { *pData = x; }
   double getData() const { return *pData; }
};

class SData : public Data
{
 private:
   char* pData;     // Zeiger auf S-Daten (char-Vektor)
 public:
   SData( const char str[] = "")
   {
      int n = strlen(str);
      pData = new char[n+1];
      strcpy( pData, str);
   }
   ~SData()                             // Destruktor
   {
      cout << "Destruktor der Klasss SData" << endl;
      delete [] pData;
   }
   TypeID getTypeID() const { return SClass; }

   void setData(const char str[])
   { 
      int n = strlen(str);
      char *s = new char[n+1];
      strcpy( s, str);
      delete [] pData;
      pData = s;
   }
   const char* getData() const { return pData; }
};

#endif  // _DATA_
