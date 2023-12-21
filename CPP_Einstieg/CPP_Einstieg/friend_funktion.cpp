#include <iostream>
#include <string>
using namespace std;

class postenTyp
{
   friend double preisGesamt(const postenTyp &p);

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

double preisGesamt(const postenTyp &p)
{
   return p.anzahl * p.preis;
}

int main()
{
   postenTyp pEins(4, 1.15, "Mango");
   pEins.ausgeben();
   
   cout << "Gesamtpreis: " << preisGesamt(pEins) << endl;
}

