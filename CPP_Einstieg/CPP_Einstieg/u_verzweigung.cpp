#include <iostream>
using namespace std;
int main()
{
   double zahlEins, zahlZwei;

   cout << "Erste Zahl eingeben: ";
   cin >> zahlEins;

   cout << "Zweite Zahl eingeben: ";
   cin >> zahlZwei;

   cout << "Ihre Zahlen:" << endl;
   if(zahlEins > zahlZwei)
   {
      cout << zahlEins << endl;
      cout << zahlZwei << endl;
   }
   else
   {
      cout << zahlZwei << endl;
      cout << zahlEins << endl;
   }
}

