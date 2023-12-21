#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
   double zahlEins, zahlZwei, zahlDrei, summe, mittelwert;

   cout << "Erste Zahl eingeben: ";
   cin >> zahlEins;
   cout << "Ihre erste Zahl: " << zahlEins << endl;

   cout << "Zweite Zahl eingeben: ";
   cin >> zahlZwei;
   cout << "Ihre zweite Zahl: " << zahlZwei << endl;

   cout << "Dritte Zahl eingeben: ";
   cin >> zahlDrei;
   cout << "Ihre dritte Zahl: " << zahlDrei << endl;

   summe = zahlEins + zahlZwei + zahlDrei;
   mittelwert = summe / 3;

   cout << fixed << setprecision(3);
   cout << "Summe: " << summe << endl;
   cout << "Mittelwert: " << mittelwert << endl;
}

