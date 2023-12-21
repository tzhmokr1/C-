#include <iostream>
#include <cmath>
using namespace std;
int main()
{
   cout << "Quadratwurzel(64) = " << sqrt(64) << endl;
   cout << "Kubikwurzel(64) = " << cbrt(64) << endl << endl;

   cout << "4 hoch 3 = " << pow(4, 3) << endl;
   cout << "-4.1 hoch -3 = " << pow(-4.1, -3) << endl;
   cout << "4.1 hoch -3.1 = " << pow(4.1, -3.1) << endl << endl;

   cout << "10er-Logarithmus von 1000 = " << log10(1000) << endl;
   cout << "Nat. Logarithmus von 100 = " << log(100) << endl;
   cout << "e hoch 4.6 = " << exp(4.6) << endl << endl;

   cout << "fmod(3.75, 1.5) = " << fmod(3.75, 1.5) << endl;
}

