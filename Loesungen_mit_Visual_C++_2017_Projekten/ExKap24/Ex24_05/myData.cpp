// ---------------------------------------------------------
// myData.cpp
// Implementierung der Methoden der Klasse MyData.
// ---------------------------------------------------------

#include "myData.h"

MyData::MyData() : count(0), iCur(0)
{
   for( int i=0; i < ARR_LENGTH; ++i)
      arrPtrData[i] = NULL;
}

MyData::~MyData()              // Destuktor
{
   Data *p;
   for( int i=0; i < ARR_LENGTH; ++i)
      if( (p = arrPtrData[i]) != NULL)
        switch( p->getTypeID())
        {
          case Data::XClass:
            delete (XData*)p;
            break;
          case Data::SClass:
            delete (SData*)p;
            break;
          default:
            delete p;
            break;
        } 
}

int MyData::nextFreePos()      // Hilfsmethode: Liefert
{                              // nächsten freien Index oder -1
   int i=iCur;
   do 
     if( arrPtrData[i] == NULL)
        return i;
     else 
        i = (i+1) % ARR_LENGTH;
   while( i != iCur);
   return -1;
}

bool MyData::insertX( double x)
{
   int i = nextFreePos();
   if( i < 0)
       return false;
   iCur = i;
   ++count;
   arrPtrData[i] = new XData(x);
   return true;
}

bool MyData::insertX()
{
   if( count == ARR_LENGTH)
   {   cout << "Kein freier Platz!" << endl;
       return false;
   }
   bool ok = true;
   double x = 0.0;
   cout << "Gleitpunktzahl eingeben: ";
   if( !(cin >> x))
   {  cout << "Ungueltige Eingabe!" << endl;
      cin.clear();
      ok = false;  
   }
   else
      ok = insertX(x);
   cin.ignore(256, '\n');  // Rest der Zeile ignorieren.
   return ok;
}

bool MyData::insertS(const char* s)
{
   int i = nextFreePos();
   if( i < 0)
       return false;
   iCur = i;
   if( strlen(s) > 0)
   {
     arrPtrData[i] = new SData(s);
     ++count;
     return true;
   }
   else
     return false;
}

bool MyData::insertS()
{
   if( count == ARR_LENGTH)
   {   cout << "Kein freier Platz!" << endl;
       return false;
   }
   bool ok = true;
   char buf[256];
   cout << "\nEine Zeile Text eingeben:" << endl;
   if( !cin.getline(buf, 256) || strlen(buf) == 0)
   {  cout << "Ungueltige Eingabe!" << endl;
      cin.clear();
      return false;  
   }
   else
      return insertS(buf);
}

void MyData::printData() const
{
   if( isEmpty())
   {  cout << "Keine Daten vorhanden!" << endl;
      return;
   }
   Data * p;
   for( int i=0; i < ARR_LENGTH; ++i)
      if( (p = arrPtrData[i]) != NULL)
        switch( p->getTypeID())
        {
          case Data::XClass:
            cout << ((XData*)p)->getData() << endl;
            break;
          case Data::SClass:
            cout << ((SData*)p)->getData() << endl;
            break;
          default:
            cout << "Unbekannter Typ!" << endl;
          break;
        } 
}
