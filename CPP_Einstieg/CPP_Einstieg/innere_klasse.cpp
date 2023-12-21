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
      void werteZuweisen(int, double, string);
      void ausgeben();

   class fehlerKlasse
   {
      private:
         int nummer;
      public:
         string what();
         fehlerKlasse(const int &n) {nummer = n;};
   };
};

void postenTyp::werteZuweisen(int a, double p, string b)
{
   if(a < 0)
      throw fehlerKlasse(1);
   anzahl = a;

   if(p < 0)
      throw fehlerKlasse(2);
   preis = p;

   if(b == "")
      throw fehlerKlasse(3);
   bezeichnung = b;
}

void postenTyp::ausgeben()
{
   cout << anzahl << " " << preis << " " << bezeichnung << endl;
}

string postenTyp::fehlerKlasse::what()
{
   if(nummer == 1)
      return "Anzahl zu klein";
   else if(nummer == 2)
      return "Preis zu klein";
   else
      return "Keine Bezeichnung";
}

int main()
{
   postenTyp pEins;

   try
   {
      pEins.werteZuweisen(1, 1.15, "");
   }
   catch(postenTyp::fehlerKlasse &e)
   {
      pEins.werteZuweisen(0, 0.0, "unbekannt");
      cout << "Fehler: " << e.what() << endl;
   }

   pEins.ausgeben();
}

