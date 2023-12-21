#include <iostream>
#include <complex>
using namespace std;
int main()
{
   complex<double> c1(3.5, 3.5);

   cout << "Realteil: " << real(c1) << endl;
   cout << "Imaginaerteil: " << imag(c1) << endl;
   cout << "Konjugiert komplex: " << conj(c1) << endl << endl;

   cout << "Betrag: " << abs(c1) << endl;
   cout << "Winkel, Radiant: " << arg(c1) << endl;

   const double pi = 4 * atan(1.0);
   cout << "Winkel, Grad: " << arg(c1) * 180 / pi << endl;

   complex<double> c2;
   c2 = polar(4.95, 0.785);
   cout << "Aus Betrag und Winkel: " << c2 << endl;
}
