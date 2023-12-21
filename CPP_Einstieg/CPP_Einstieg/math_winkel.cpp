#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
   double winkelGrad, winkelRadiant;
   const double pi = 4 * atan(1.0);
   
   cout << " Grad     Radiant   sin()   cos()       tan()" << endl;
   for(winkelGrad=80.0; winkelGrad<90.5; winkelGrad++)
   {
      winkelRadiant = winkelGrad * pi / 180.0;
      cout << fixed;
      cout << setw(5) << setprecision(1) << winkelGrad;
      cout << setw(12) << setprecision(3) << winkelRadiant;
      cout << setw(8) << setprecision(3) << sin(winkelRadiant);
      cout << setw(8) << setprecision(3) << cos(winkelRadiant);
      cout << scientific;
      cout << setw(12) << setprecision(2)
         << tan(winkelRadiant) << endl;
   }
}

