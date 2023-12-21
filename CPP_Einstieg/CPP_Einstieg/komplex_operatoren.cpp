#include <iostream>
#include <complex>
using namespace std;
int main()
{
   complex<double> c1(3.0, 4.0), c2(2.0, -5.0), c3(0.0, 2.0);

   cout << "c1 = " << c1 << endl;
   cout << "c2 = " << c2 << endl;
   cout << "c3 = " << c3 << endl << endl; 

   cout << "c1 + 2.0 = " << c1 + 2.0 << endl;
   cout << "c1 - 2.0 = " << c1 - 2.0 << endl;
   cout << "c1 * 2.0 = " << c1 * 2.0 << endl;
   cout << "c1 / 2.0 = " << c1 / 2.0 << endl << endl;

   cout << "c1 + c2 = " << c1 + c2 << endl;
   cout << "c1 - c2 = " << c1 - c2 << endl;
   cout << "c1 * c2 = " << c1 * c2 << endl;
   cout << "c1 / c2 = " << c1 / c2 << endl << endl;

   cout << "c1 + c3 = " << c1 + c3 << endl;
   cout << "c1 - c3 = " << c1 - c3 << endl;
   cout << "c1 * c3 = " << c1 * c3 << endl;
   cout << "c1 / c3 = " << c1 / c3 << endl << endl;

   cout << "c3 * c3 = " << c3 * c3 << endl;
}
