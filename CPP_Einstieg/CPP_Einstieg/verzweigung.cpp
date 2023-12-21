#include <iostream>
using namespace std;
int main()
{
   double preis;
   cout << "Preis: ";
   cin >> preis;

   if (preis > 1.5)
   {
      cout << "Ein teurer Artikel" << endl;
   }
   else
   {
      cout << "Ein preiswerter Artikel" << endl;
      cout << "Den nehmen wir" << endl;
   }
}

