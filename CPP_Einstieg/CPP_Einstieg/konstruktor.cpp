#include <iostream>
#include <string>
using namespace std;

class postenTyp
{
   private:
      int anzahl;
      double preis;
      string bezeichnung;
   public:
      postenTyp();
      postenTyp(const int&, const double&, const string&);
      ~postenTyp();
      void ausgeben();
};

postenTyp::postenTyp()
{
   anzahl = 0;
   preis = 0.0;
   bezeichnung = "unbekannt";
}

postenTyp::postenTyp(const int &a, const double &p, const string &b)
{
   if(a < 0)
      anzahl = 0;
   else
      anzahl = a;

   if(p < 0)
      preis = 0.0;
   else
      preis = p;

   if(b == "")
      bezeichnung = "unbekannt";
   else
      bezeichnung = b;
}

postenTyp::~postenTyp()
{
   cout << "Destruktor: ";
   ausgeben();
   // (*this).ausgeben();
   // this->ausgeben();
}

void postenTyp::ausgeben()
{
   cout << anzahl << " " << preis << " " << bezeichnung << endl;
}

int main()
{
   postenTyp pEins(2, 1.45, "Apfel");
   pEins.ausgeben();

   postenTyp pZwei(-5, -0.2, "");
   pZwei.ausgeben();

   postenTyp pDrei;
   pDrei.ausgeben();
   cout << endl;
}

