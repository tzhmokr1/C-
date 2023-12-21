#include <iostream>
#include <complex>
using namespace std;
int main()
{
   complex<double> c1(3.0, 4.0), c2(2.0, -5.0);
   cout << "c1 = " << c1 << endl; 
   cout << "c2 = " << c2 << endl; 

   cout << "Quadratwurzel(c1) = " << sqrt(c1) << endl;
   
   cout << "c1 hoch -3.5 = " << pow(c1, -3.5) << endl;
   cout << "-3.5 hoch c1 = " << pow(-3.5, c1) << endl;
   cout << "c1 hoch c2 = " << pow(c1, c2) << endl;

   cout << "e hoch c1 = " << exp(c1) << endl;
   cout << "Nat. Logarithmus von c1 = " << log(c1) << endl;
}
