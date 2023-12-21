// --------------------------------------------------------
// ex05_07.cpp
// Erzeugt für eine positive und eine negative Ganzzahl
// einen Überlauf.
// --------------------------------------------------------
#include <iostream>
#include <climits>    
using namespace std;

int main()
{
   long lmax = LONG_MAX,
        lmin = LONG_MIN;
   
   cout << showpos;
   cout << "LONG_MAX:  " << lmax
        << "   LONG_MAX + 1: " << lmax+1 << endl; 

   cout << "LONG_MIN:  " << lmin
        << "   LONG_MIN - 1: " << lmin-1 << endl; 

   return 0;
}
