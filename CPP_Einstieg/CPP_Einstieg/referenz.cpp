#include <iostream>
using namespace std;
int main()
{
   double preis = 1.45;

   double &preisReferenz = preis;
   cout << "Preis: " << preisReferenz << " Euro" << endl;

   double &preisReferenzZwei = preisReferenz;
   cout << "Preis: " << preisReferenzZwei << " Euro" << endl;

   const double &preisReferenzDrei = preis;
   cout << "Preis: " << preisReferenzDrei << " Euro" << endl;
   // preisReferenzDrei = 2.05;

   preisReferenzZwei = 2.05;
   cout << "Preis: " << preis << " Euro" << endl;
}

