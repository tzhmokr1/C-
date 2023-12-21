// ----------------------------------------------------
// ex03_07.cpp
// Ruft die Funktion ceil() mit einer positiven und
// einer negativen Gleitpunktzahl auf.
// ----------------------------------------------------

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
   double x = 1.42;
   cout << "ceil(" << x << ") = " << ceil(x) << endl;

   x = -1.65;
   cout << "ceil(" << x << ") = " << ceil(x) << endl;

   return 0;
}
