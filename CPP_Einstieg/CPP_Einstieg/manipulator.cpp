#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
   double preis = 1.4;
   cout << preis << " Euro" << endl;

   cout << setw(8) << preis << " Euro" << endl;

   cout << setfill('.');
   cout << setw(8) << preis << " Euro" << endl;

   cout << fixed << setprecision(2);
   cout << setw(8) << preis << " Euro" << endl;

   cout << left;
   cout << setw(8) << preis << " Euro" << endl;
}

