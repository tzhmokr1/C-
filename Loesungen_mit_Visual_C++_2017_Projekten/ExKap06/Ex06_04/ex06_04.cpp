// -------------------------------------------------------
// ex06_04.cpp
// Gibt die Summe der Quadrate der ersten n 
// positiven ganzen Zahlen aus.
// -------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
   int n=0;
   unsigned long sum;

   cout << "Geben Sie eine positive Ganzzahl ein: ";
   cin >> n;
   while(n > 0)
   {
      sum = 0;
      for (int i = 1; i <= n; i++) 
         sum += i*i;

      cout << "\nDie Summe der Quadrate der ersten " << n 
           << " positiven Ganzzahlen ist: " << sum << endl;

      cout << "\nGeben Sie eine positive Ganzzahl ein "
           << "(Abbruch mit 0): " ;
      cin >> n;
   }
   return 0;
}
