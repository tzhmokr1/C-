#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class postenTyp
{
   private:
      int anzahl;
      double preis;
      string bezeichnung;
   public:
      void werteZuweisen(const int&, const double&, const string&);
      void mehrDavon(const int&);
      void rabattGeben(double);
      void ausgeben();
};

void postenTyp::werteZuweisen(const int &a,
   const double &p, const string &b)
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

void postenTyp::mehrDavon(const int &anzahlHinzu)
{
   if(anzahl + anzahlHinzu < 0)
      anzahl = 0;
   else
      anzahl += anzahlHinzu;
}

void postenTyp::rabattGeben(double rabattProzent)
{
   if(rabattProzent < 0)
      rabattProzent = 0;
   if(rabattProzent > 100)
      rabattProzent = 100;
   preis = preis * (1 - rabattProzent / 100);
   preis = round(preis * 100) / 100;
}

void postenTyp::ausgeben()
{
   cout << anzahl << " " << preis << " " << bezeichnung << endl;
}

int main()
{
   postenTyp pEins;

   pEins.werteZuweisen(-5, -1.5, "");
   pEins.ausgeben();         // 0 0 unbekannt

   pEins.werteZuweisen(2, 1.45, "Apfel");
   pEins.ausgeben();         // 2 1.45 Apfel

   pEins.mehrDavon(-6);
   pEins.ausgeben();         // 0 1.45 Apfel

   pEins.mehrDavon(6);
   pEins.ausgeben();         // 6 1.45 Apfel

   pEins.rabattGeben(-20);
   pEins.ausgeben();         // 6 1.45 Apfel

   pEins.rabattGeben(10);
   pEins.ausgeben();         // 6 1.31 Apfel

   pEins.rabattGeben(120);
   pEins.ausgeben();         // 6 0 Apfel
}

