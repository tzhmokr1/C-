#include <iostream>
#include <string>
using namespace std;

typedef struct pTyp
{
   int anzahl;
   double preis;
   string bezeichnung;
} postenTyp;

int main()
{
   postenTyp pEins, pZwei;

   pEins = {2, 1.45, "Apfel"};
   cout << pEins.anzahl << " " << pEins.preis
      << " " << pEins.bezeichnung << endl;

   pZwei = pEins;
   cout << pZwei.anzahl << " " << pZwei.preis
      << " " << pZwei.bezeichnung << endl;

   postenTyp &pDrei = pEins;
   pDrei.anzahl = 17;
   cout << "Anzahl: " << pEins.anzahl << endl;

   postenTyp *pZeiger = &pEins;
   cout << "Anzahl: " << (*pZeiger).anzahl << endl;
   cout << "Anzahl: " << pZeiger->anzahl << endl;
}

