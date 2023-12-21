// --------------------------------------------------------
// ex08_10.cpp 
// Rundet eine Gleitpunktzahl auf 2 Dezimalstellen.
// --------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
   double x=0.0, sign = 1.0;

   cout << "  ****    Runden...    ****\n" << endl;

   cout << "Geben Sie eine Gleitpunktzahl ein: ";
   cin  >> x;

   if( x < 0.0) {  x = -x;  sign = -1.0; }

   long temp = (long)(x*100.0 + 0.5);
   x = (double)temp/100.0;
// oder:
//   x = (double)((long)(x*100.0 + 0.5))/100.0;

   cout << "Der gerundete Wert ist: " << sign*x << endl;

   return 0;
}
