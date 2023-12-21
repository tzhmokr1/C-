#include <iostream>
using namespace std;
int main()
{
   int anzahl;
   double preis, summe = 0;

   while(true)
   {
      cout << "Anzahl: ";
      cin >> anzahl;

      if(anzahl == 0)
         break;
      else if(anzahl < 0)
         continue;

      cout << "Preis in Euro: ";
      cin >> preis;
      summe += anzahl * preis;
   }

   cout << "Summe: " << summe << " Euro" << endl;
}

