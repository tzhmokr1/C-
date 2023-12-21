// ------------------------------------------------------
// ex24_04.cpp
// Klassen XData und SData verwenden.
// ------------------------------------------------------
#include "data.h"

void printData( const Data&);

int main()
{
    XData xObj(7.77);
    SData sObj("Ein Test!");

    printData( xObj);
    printData( sObj);

    sObj.setData("Alles ok?\nBye, bye!");
    printData( sObj);

    return 0;
}

void printData( const Data& d)
{
   switch( d.getTypeID())
   {
     case Data::BaseClass:
         cout << "Keine Daten" << endl;
         break;
     case Data::XClass:
         cout << "XData: " << ((const XData&)d).getData()
              << endl;
         break;
     case Data::SClass:
         cout << "SData: " << ((const SData&)d).getData()
              << endl;
         break;
     default:
         cout << "Unbekannter Typ!" << endl;
         break;
   }
}
