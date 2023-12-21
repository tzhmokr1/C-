#include <iostream>
using namespace std;
int main()
{
   int anzahl;
   double preis, summe = 0.0;
   
   for(int i=1; i<4; i++)
   {
      cout << "Nr. " << i << ", Anzahl: ";
      cin >> anzahl;
      cout << "Nr. " << i << ", Preis in Euro: ";
      cin >> preis;
      summe += anzahl * preis;
   }

   cout << "Summe: " << summe << " Euro" << endl;
}

