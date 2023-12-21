#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class postenTyp
{
   private:
      int anzahl;
      double preis;
      string bezeichnung;
      static const int laenge = 35;
   public:
      postenTyp();
      void zeileLesenNummer(ifstream &, int);
      void ausgeben();
};

postenTyp::postenTyp()
{
   anzahl = 0;
   preis = 0.0;
   bezeichnung = "unbekannt";
}

void postenTyp::zeileLesenNummer(ifstream &td, int nummer)
{
   cout << "Position: " << td.tellg() << endl;
   td.seekg(nummer * laenge);
   cout << "Position: " << td.tellg() << endl;

   td >> anzahl >> preis;
   getline(td, bezeichnung);
   while(bezeichnung.at(0) == ' ')
      bezeichnung.erase(0,1);
}

void postenTyp::ausgeben()
{
   cout << anzahl << " " << preis << " |" << bezeichnung << endl;
}

int main()
{
   ifstream textDatei("C:/Temp/datei_schreiben_beliebig.txt");
   if(!textDatei)
   {
      cout << "Dateifehler" << endl;
      return 1;
   }

   postenTyp pEins;

   pEins.zeileLesenNummer(textDatei, 2);
   pEins.ausgeben();

   pEins.zeileLesenNummer(textDatei, 1);
   pEins.ausgeben();
}

