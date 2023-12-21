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

      static int anzahlPosten;
      static void ausgabeAnzahlPosten();
};

int postenTyp::anzahlPosten = 0;

postenTyp::postenTyp()
{
   anzahlPosten++;
   cout << "Konstruktor, Anzahl: " << anzahlPosten << endl;

   anzahl = 0;
   preis = 0.;
   bezeichnung = "unbekannt";
}

postenTyp::postenTyp(const int &a, const double &p, const string &b)
{
   anzahlPosten++;
   cout << "Konstruktor, Anzahl: " << anzahlPosten << endl;

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
   anzahlPosten--;
   cout << "Destruktor, Anzahl: " << anzahlPosten << endl;
}

void postenTyp::ausgeben()
{
   cout << anzahl << " " << preis << " " << bezeichnung << endl;
}

void postenTyp::ausgabeAnzahlPosten()
{
   cout << "Statische Methode, Anzahl: " << anzahlPosten << endl;
}

int main()
{
   postenTyp pEins(2, 1.45, "Apfel");
   pEins.ausgeben();
   cout << "Anzahl: " << postenTyp::anzahlPosten << endl;
   postenTyp::ausgabeAnzahlPosten();
   cout << endl;

   postenTyp pZwei(5, 0.75, "Kiwi");
   pZwei.ausgeben();
   cout << "Anzahl: " << postenTyp::anzahlPosten << endl;
   postenTyp::ausgabeAnzahlPosten();
   cout << endl;
}

