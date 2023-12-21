// ------------------------------------------------
// ex11_01.cpp
// Was gibt folgendes Programm auf dem Bildschirm aus?
// ------------------------------------------------
#include <iostream>
using namespace std;

double z = 11.1;
double func( double);

int main( )
{
   double x = 1.1;
   cout << x       << "   " << z       << endl;
   cout << func(x) << "   " << func(z) << endl;
   cout << x       << "   " << z       << endl;

   return 0;
}

double func(double z)
{
   z = 2 * z;
   return z;
}
