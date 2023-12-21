// -------------------------------------------------------
// intArr.cpp
// Implementierung der Klassen IntArr.
// -------------------------------------------------------
#include <iostream>
#include <cstdlib>
#include "intArr.h"
using namespace std;

IntArr::IntArr( int len)
{
   this->len = len;
   ptrArr = new int[len];
   for( int i=0; i < len; ++i)
      ptrArr[i] = 0;
}

IntArr::~IntArr()
{
    delete [] ptrArr;
}

int& IntArr::operator[](int i)    // Index-Operator
{
   if( i < 0 || i >= len)
   {
      cerr << "IntArr: " << i << " Out of Range!" << endl;
      exit(1);
   }
   return ptrArr[i];
}

void IntArr::compress()
{
   int i, j, count = 0;

   for( i = 0; i < len; ++i)        // Anzahl Elemente != 0
      if( ptrArr[i] != 0) ++count; 

   int *newArr = new int[count];

   for( i = 0, j = 0;  i < len; ++i)
      if( ptrArr[i] != 0)
          newArr[j++] = ptrArr[i];

   delete [] ptrArr;

   ptrArr = newArr;
   len = count;
}
