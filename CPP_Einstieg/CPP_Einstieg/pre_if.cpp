#include <iostream>
// #define AUSGABE 0
#ifndef AUSGABE
   #define AUSGABE 3
#endif
using namespace std;
int main()
{
   int summe = 0;
   for(int i=1; i<=5; i++)
   {
      summe += i;
      #if AUSGABE == 1
         cout << summe << endl;
      #elif AUSGABE == 2
         cout << i << " " << summe << endl;
      #elif AUSGABE == 3
         cout << "Zahl: " << i << ", Summe: " << summe << endl;
      #else
         ;
      #endif
   }
   cout << "Summe: " << summe << endl;
}

