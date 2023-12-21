#include <iostream>
using namespace std;

void aendern(double *pz)
{
   *pz = *pz + 0.1;
}

int main()
{
   double preis = 1.45;

   double *preisZeiger;
   preisZeiger = &preis;
   cout << "Preis: " << *preisZeiger << endl;

   *preisZeiger = 0.85;
   cout << "Preis: " << preis << endl;

   aendern(&preis);
   cout << "Preis: " << preis << endl;

   aendern(preisZeiger);
   cout << "Preis: " << preis << endl;
}

