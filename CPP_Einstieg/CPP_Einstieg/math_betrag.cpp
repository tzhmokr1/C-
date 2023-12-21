#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
   cout << "|-6.75| = " << fabs(-6.75) << endl;
   cout << "|-4| = "<< abs(-4) << endl << endl;
   
   cout << fixed << setprecision(15);
   double a = 1.0 / 7.0;
   cout << a << endl;
   double b = 0.142857;
   cout << b << endl;

   if(fabs(a-b) < 1e-6)
      cout << "1e-6: Werte sind gleich" << endl;

   if(fabs(a-b) < 1e-7)
      cout << "1e-7: Werte sind gleich" << endl;
}

