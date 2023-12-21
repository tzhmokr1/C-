#include <iostream>
#include <string>
using namespace std;

struct pTyp
{
   int anzahl;
   double preis;
   string bezeichnung;
};

int main()
{
   struct pTyp pEins;

   pEins.anzahl = 7;
   pEins.preis = 0.85;
   pEins.bezeichnung = "Birne";

   cout << pEins.anzahl << " " << pEins.preis
      << " " << pEins.bezeichnung << endl;
}

