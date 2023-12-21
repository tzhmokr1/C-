#include <iostream>
#include <iomanip>
using namespace std;

void halbiere(double &x, const double &gr)
{
   cout << setw(20) << x << endl;
   x = x/2;
   if(x > gr)
      halbiere(x, gr);
}

int main()
{
   double wert, grenze;
   cout << "Wert: ";
   cin >> wert;
   cout << "Grenze: ";
   cin >> grenze;

   cout << fixed << setprecision(12);
   halbiere(wert, grenze);
}

