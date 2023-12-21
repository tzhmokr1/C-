#include <iostream>
#include <string>
using namespace std;

class postenTyp
{
   private:
      int anzahl = 0;
      double preis = 0.0;
      string bezeichnung = "unbekannt";
   public:
      postenTyp(){};
      postenTyp(const int&, const double&, const string&);
      postenTyp(const postenTyp &);
      postenTyp& operator = (const postenTyp &);
      void ausgeben();
};

postenTyp::postenTyp(const int &a, const double &p, const string &b)
{
   anzahl = a;
   preis = p;
   bezeichnung = b;
}

postenTyp::postenTyp(const postenTyp &p)
{
   *this = p;
}

postenTyp& postenTyp::operator = (const postenTyp &p)
{
   if(p.anzahl <= 0) anzahl = 0;
   else              anzahl = p.anzahl;

   if(p.preis < 0.1) preis = 0.0;
   else              preis = p.preis;

   if(p.bezeichnung == "") bezeichnung = "unbekannt";
   else                    bezeichnung = p.bezeichnung;
      
   return *this;
}

void postenTyp::ausgeben()
{
   cout << anzahl << " " << preis << " " << bezeichnung << endl;
}

int main()
{
   postenTyp pEins(4, 1.15, "Mango");
   pEins.ausgeben();

   postenTyp pZwei(pEins);
   pZwei.ausgeben();

   postenTyp pDrei;
   pDrei.ausgeben();
   pDrei = pZwei;
   pDrei.ausgeben();
}

