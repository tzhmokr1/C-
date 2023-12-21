// ------------------------------------------------------
// ex25_05.cpp
// Klassen Data, XData und SData verwenden.
// ------------------------------------------------------
#include "data.h"

void typeDemo( Data* pd);

int main()
{
   Data *ptr = new XData(7.77);
   cout << *ptr << endl;
   typeDemo(ptr);
   cout << *ptr << endl;
   delete ptr;

   cout << "... und eine SData-Objekt:" << endl;
   ptr = new SData("Ein Test!");
   cout << *ptr << endl;
   typeDemo(ptr);
   cout << *ptr << endl;
   delete ptr;

   return 0;
}

void typeDemo( Data* pd)
{
   cout << typeid(*pd).name() << endl;
   
   if( typeid(*pd) == typeid(XData) )
     dynamic_cast<XData*>(pd)->setData(9.007);

   else if( typeid(*pd) == typeid(SData) )
     dynamic_cast<SData*>(pd)->setData("Alles ok?\nBye, bye!");
}

/*
// Alternative:
void typeDemo( Data* pd)
{
   cout << typeid(*pd).name() << endl;
   
   XData *ptrX = dynamic_cast<XData*>(pd);
   if( ptrX != NULL)
     ptrX->setData(9.007);

   SData *ptrS = dynamic_cast<SData*>(pd);
   if( ptrS != NULL )
     ptrS->setData("Alles ok?\nBye bye!");
}
*/
