// ------------------------------------------------------
// ex17_08.cpp
// Sortiert einen Vektor von Zeigern auf 
// Objekte vom Typ MobilePhone.
// ------------------------------------------------------

#include "mobilePhone.h"
#include <iostream>
using namespace std;

void sortMobiles( MobilePhone *arrM[], int len);

int main()
{
   MobilePhone
       mobile0("Nokia 6510", "Mary", "214-3658709"),
       mobile1("Motorola v70", "Bonny", "987-654321"),
       mobile2("Siemens C55 GPRS", "Clyde", "123-456789"),
       mobile3("Sony Ericsson T300", "Alex", "642-9753180");

   MobilePhone *arrMobiles[] =         // Vektor von Zeigern
   { &mobile0, &mobile1, &mobile2, &mobile3 };

   int i, len = sizeof(arrMobiles) / sizeof(MobilePhone *);

   cout << "Die Handys:" << endl;
   for( i = 0;  i < len;  ++i)
      arrMobiles[i]->display();

    cout <<"\nEs wird sortiert . . ."<< endl;

    sortMobiles( arrMobiles, len);

    cout << "Die sortierten Handys:" << endl;
    for( i = 0;  i < len;  ++i)
       arrMobiles[i]->display();

    return 0;
}

void sortMobiles( MobilePhone *arrM[], int len)
{
   MobilePhone *temp = NULL;
   int i, j, minj = 0;

   for( i = 0;  i < len-1;  ++i)
   {
     minj = i;
     for( j = i+1; j < len;  ++j)
        if( arrM[i]->getOwner() > arrM[j]->getOwner())
           minj = j;
     // Swap array elements:
     temp = arrM[i]; arrM[i] = arrM[minj]; arrM[minj] = temp;
   }
}
