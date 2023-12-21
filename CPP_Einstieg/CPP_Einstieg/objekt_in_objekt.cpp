#include <iostream>
#include <string>
#include <vector>
using namespace std;

class postenTyp
{
   private:
      int anzahl;
      double preis;
      string bezeichnung;
   public:
      postenTyp(const int&, const double&, const string&);
      void ausgeben();
};

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

void postenTyp::ausgeben()
{
   cout << anzahl << " " << preis << " " << bezeichnung << endl;
}

class rechnungTyp
{
   private:
      int nummer;
      vector<postenTyp> pFeld;
   public:
      rechnungTyp(const int&);
      void postenHinzu(const int&, const double&, const string&);
      void ausgeben();
};

rechnungTyp::rechnungTyp(const int &n)
{
   nummer = n;
}

void rechnungTyp::postenHinzu(const int &a,
   const double &p, const string &b)
{
   pFeld.push_back(postenTyp(a, p, b));
}

void rechnungTyp::ausgeben()
{
   cout << nummer << endl;
   for(postenTyp &p:pFeld)
      p.ausgeben();
}

int main()
{
   rechnungTyp rEins(4711);
   rEins.postenHinzu(4, 1.15, "Mango");
   rEins.postenHinzu(7, 0.85, "Birne");
   rEins.postenHinzu(2, 0.65, "Orange");
   rEins.ausgeben();
}

