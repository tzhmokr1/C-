// ------------------------------------------------------
// ex06_10.cpp
// Liest drei Ganzzahlen ein und gibt den Median aus.
// ------------------------------------------------------
 
#include <iostream>
using namespace std;

int main()
{
   int n1, n2, n3, median;

   cout << "  **** Berechnet den Median von drei Ganzzahlen ****\n"
        << endl;
   cout << "Geben Sie drei Ganzzahlen ein: " << endl;
   if( !(cin >> n1 && cin >> n2 && cin >> n3) )
   {
     cout << "Unzulaessige Eingabe!" << endl;
     return 1;
   }

   if( n1 < n2 && n1 < n3)
      median = n2 < n3 ? n2 : n3;         // Min(n2, n3) 
   else if( n1 > n2 && n1 > n3) 
      median = n2 > n3 ? n2 : n3;         // Max(n2, n3) 
   else
      median = n1;

   cout << "Median: " << median << endl; 
   return 0; 
}
