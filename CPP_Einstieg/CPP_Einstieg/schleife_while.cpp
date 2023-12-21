#include <iostream>
using namespace std;
int main()
{
   int anzahl;
   double preis, summe;
   cout << "Summe bisher: ";
   cin >> summe;

   while(summe < 20)
   {
      cout << "Anzahl: ";
      cin >> anzahl;
      cout << "Preis in Euro: ";
      cin >> preis;
      summe += anzahl * preis;
   }

   cout << "Summe: " << summe << " Euro" << endl;
}

