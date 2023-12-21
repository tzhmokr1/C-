// ------------------------------------------------------
// ex13_10.cpp
// Definiert und verwendet die Union FloatULong.
// ------------------------------------------------------
#include <iostream>
using namespace std;

union FloatULong { float f;  unsigned long ul; };

int main()
{
   cout << "*** Bitmuster von Gleitpunktzahlen ***"
        << endl;

   FloatULong number;

   cout << "\nGeben Sie einige Gleitpunktzahlen ein\n"
           "(Abbruch mit einem Buchstaben): ";

   cout << uppercase << hex;
   while( cin >> number.f)
   {
      cout << "\nDas Bitmuster von " << number.f 
           << " ist " << number.ul << endl;
   }
   return 0;
}
