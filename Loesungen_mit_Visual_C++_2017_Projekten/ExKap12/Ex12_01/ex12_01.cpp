// --------------------------------------------------------
// ex12_01.cpp
// Was gibt folgendes Programm auf dem Bildschirm aus?
// --------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
   long n = 100;
   long& ref = n;

   ++ref;
   cout << n << "   " << ref << endl;

   n += 100;
   cout << n << "   " << ref << endl;

   return 0;
} 
