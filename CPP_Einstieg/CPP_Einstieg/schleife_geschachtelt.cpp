#include <iostream>
using namespace std;
int main()
{
   double betrag, summe, gesamtsumme = 0.0;
   
   for(int i=1; i<=2; i++)
   {
      summe = 0.0;
      for(int k=1; k<=3; k++)
      {
         cout << "Tag " << i << ", Betrag " << k << ": ";
         cin >> betrag;
         summe += betrag;
      }
      gesamtsumme += summe;
      cout << "Tag " << i << ", Summe: " << summe << endl << endl;
   }

   cout << "Gesamtsumme: " << gesamtsumme << endl;
}

