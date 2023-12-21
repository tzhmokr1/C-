// --------------------------------------------------------
// random.h
// Deklariert die Funktionen randInt() und randDouble().
// --------------------------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;

#include "random.h"
using namespace myLib;

int main()
{
   cout << "\n\t\t  ******   Zufallszahlen   ******\n\n";

   int i;
   for( i = 1 ; i <= 10 ; ++i)
   {
      cout << setw(15) << randInt();
      if( i%5 == 0)
          cout << endl;
   }
   cout << endl;

   for( i = 1 ; i <= 10 ; ++i)
   {
      cout << setw(15) << randDouble();
      if( i%5 == 0)
          cout << endl;
   }
   cout << endl;

   return 0;
}
