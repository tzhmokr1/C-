// -----------------------------------------------------------
// ex17_05.cpp
// Definiert und testet die Funktion rFind(), die die Position 
// des letzten Vorkommens einer Zahl in einem Vektor von 
// long-Werten bestimmt.
// -----------------------------------------------------------
#include <iostream>
using namespace std;

// Prototyp
int rFind(long arr[], int len, long target);

int main()     // Testet die Funktion rfind()
{
   long testArr[] = { 9, -2, 30, 4, 0, -21, -2, 4, 15 },  num = -2;
   int len = sizeof(testArr) / sizeof(long),
       pos = 0;

   cout << " **** Einen Vektor nach dem letzten Auftreten eines Wertes durchsuchen ****"
        << endl;

   cout << "\nThe array:\n  ";
   for( int i=0; i < len; ++i)
       cout << testArr[i] << "   ";
   cout << "\n\nSuche nach " << num << endl;
   
   pos = rFind( testArr, len, num);
   if( pos < 0)
      cout << "Die Zahl " << num << " wurde nicht gefunden!" << endl;
   else
      cout << "Der Index des letzten Auftretens ist " << pos << endl;

   return 0;
}

// --------------------------------------------------------
// Die Funktion rFind() 
//
int rFind(long arr[], int len, long target)
{
   long *ptr = arr + len -1;   // Adresse des letzten Elements 

   for(  ; ptr >= arr; --ptr)
       if( *ptr == target)
           return (ptr-arr);   // Index des Elements *ptr

   return -1;
}
