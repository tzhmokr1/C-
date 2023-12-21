#include <iostream>
#include <iomanip>
using namespace std;

double quadrat(double x)
{
   return x * x;
}

double hochdrei(double x)
{
   return x * x * x;
}

void ausgabeTabelle(double unten, double oben,
   double schritt, double fkt(double x))
{
   double p;
   cout << fixed << setprecision(2);
   for(p = unten; p < oben + schritt / 2.0; p += schritt)
      cout << setw(7) << p << setw(8) << fkt(p) << endl;
   cout << endl;
}

int main()
{
   ausgabeTabelle(5.0, 15.0, 2.5, quadrat);
   ausgabeTabelle(3.0, 7.0, 1, hochdrei);
}

