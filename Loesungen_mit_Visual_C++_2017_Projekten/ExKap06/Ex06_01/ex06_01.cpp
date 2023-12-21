// --------------------------------------------------------
// ex06_01.cpp
// Berechnet die Summe der ersten 100 positiven 
// Ganzzahlen und gibt sie aus.
// --------------------------------------------------------

#include <iostream>
using namespace std;

int main()
{
   unsigned long sum = 0;
   
   for (int i = 1; i <= 100; ++i)
     sum += i;

   cout << "1 + 2 + ... + 99 + 100 = " << sum << endl;

   return 0;
}
