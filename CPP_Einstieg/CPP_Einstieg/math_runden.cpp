#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
   double a = 6.75, b = -6.75;
   cout << fixed << setprecision(2);
   
   cout << "Werte:   " << a << " " << b << endl;
   cout << "ceil():  " << ceil(a) << " " << ceil(b) << endl;
   cout << "floor(): " << floor(a) << " " << floor(b) << endl;
   cout << "round(): " << round(a) << " " << round(b) << endl;
   cout << "trunc(): " << trunc(a) << " " << trunc(b) << endl;
   cout << endl;

   cout << "Cast mit (int): " << endl;
   cout << (int) a << " " << (int) b << endl << endl;

   cout << "Cast mit (double): " << endl;
   cout << (double) 15 / 4 << endl;
   cout << (double) (15 / 4) << endl;
}

