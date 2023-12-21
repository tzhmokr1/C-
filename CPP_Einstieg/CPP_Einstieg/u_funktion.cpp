#include <iostream>
using namespace std;

double summe(const double&, const double&);

int main()
{
   double x, y, z;
   
   for(int i=1; i<=3; i++)
   {
      cout << "Erste Zahl: ";
      cin >> x;
      cout << "Zweite Zahl: ";
      cin >> y;

      z = summe(x, y);
      cout << x << " + " << y << " = " << z << endl;
   }
}

double summe(const double &a, const double &b)
{
   double c = a + b;
   return c;
}

