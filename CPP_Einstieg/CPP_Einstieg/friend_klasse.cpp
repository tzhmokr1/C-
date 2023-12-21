#include <iostream>
#include <string>
using namespace std;

class postenTyp
{
   friend class postenAktion;

   private:
      int anzahl;
      double preis;
      string bezeichnung;
   public:
      postenTyp(int, double, string);
      void ausgeben();
};

postenTyp::postenTyp(int a, double p, string b)
{
   anzahl = a;
   preis = p;
   bezeichnung = b;
}

void postenTyp::ausgeben()
{
   cout << anzahl << " " << preis << " " << bezeichnung << endl;
}

class postenAktion
{
   public:
      static void anzahlVerdoppeln(postenTyp &);
      static void preisVerdoppeln(postenTyp &);
};

void postenAktion::anzahlVerdoppeln(postenTyp &p)
{
   p.anzahl *= 2;
}

void postenAktion::preisVerdoppeln(postenTyp &p)
{
   p.preis *= 2;
}

int main()
{
   postenTyp pEins(4, 1.15, "Mango");
   pEins.ausgeben();

   postenAktion::anzahlVerdoppeln(pEins);   
   postenAktion::preisVerdoppeln(pEins);   
   pEins.ausgeben();
}

