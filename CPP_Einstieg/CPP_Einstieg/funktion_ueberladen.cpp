#include <iostream>
using namespace std;

int addieren(const int&, const int&);
double addieren(const double&, const double&);
double addieren(const double&, const double&,
   const double&, const double&);

int main()
{
   cout << "Summe: " << addieren(6, 13) << endl;
   cout << "Summe: " << addieren(6.5, 13.2) << endl;
   cout << "Summe: " << addieren(6.5, 13.2, 2.5, 11.3) << endl;
}

int addieren(const int &a, const int &b)
{
   int ergebnis;
   ergebnis = a + b;
   return ergebnis;
}

double addieren(const double &a, const double &b)
{
   double ergebnis;
   ergebnis = a + b;
   return ergebnis;
}

double addieren(const double &a, const double &b,
   const double &c, const double &d)
{
   double ergebnis;
   ergebnis = a + b + c + d;
   return ergebnis;
}

