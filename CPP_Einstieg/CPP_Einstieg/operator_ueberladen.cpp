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
      void ausgeben();

      postenTyp operator + (const int&);
      postenTyp operator + (const string&);
      bool operator > (const postenTyp&);
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

void postenTyp::ausgeben()
{
   cout << anzahl << " " << preis << " " << bezeichnung << endl;
}

postenTyp postenTyp::operator + (const int &anzahlHinzu)
{
   postenTyp pTemp = *this;
   if(anzahl + anzahlHinzu < 0)
      pTemp.anzahl = 0;
   else
      pTemp.anzahl += anzahlHinzu;
   return pTemp;
}

postenTyp postenTyp::operator + (const string &textHinzu)
{
   postenTyp pTemp = *this;
   pTemp.bezeichnung += ", " + textHinzu;
   return pTemp;
}

bool postenTyp::operator > (const postenTyp &anderesObjekt)
{
   if(anzahl * preis > anderesObjekt.anzahl * anderesObjekt.preis)
      return true;
   else
      return false;
}

int main()
{
   postenTyp pEins(2, 1.45, "Apfel");
   postenTyp pZwei;

   pZwei = pEins + 7;
   pEins.ausgeben();         // 2 1.45 Apfel
   pZwei.ausgeben();         // 9 1.45 Apfel

   pEins = pEins + 4;
   pEins.ausgeben();         // 6 1.45 Apfel

   pEins = pEins + "Bio";
   pEins.ausgeben();         // 6 1.45 Apfel, Bio

   postenTyp pDrei(5, 0.75, "Kiwi");
   pDrei.ausgeben();         // 5 0.75 Kiwi

   if(pEins > pDrei)         // pEins > pDrei
      cout << "pEins > pDrei" << endl;
   else
      cout << "pEins <= pDrei" << endl;

   (pEins+2).ausgeben();     // 8 1.45 Apfel, Bio
}

