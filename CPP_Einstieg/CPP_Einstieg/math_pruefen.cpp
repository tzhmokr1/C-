#include <iostream>
#include <cmath>
using namespace std;
int main()
{
   double x = pow(-4.5, 3.5);
   cout << "-4.5 hoch 3.5 = " << x << endl;
   if(isnan(x))
      cout << "Das ist keine Zahl" << endl;

   x = 1.7e308;
   if(isfinite(x))
      cout << "1.7e308 ist finit" << endl;
   x= x * 10;
   if(isinf(x))
      cout << "1.7e309 ist infinit" << endl;
}

