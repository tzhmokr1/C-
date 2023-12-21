#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

class postenTyp
{
   private:
      int anzahl;
      double preis;
      string bezeichnung;
   public:
      postenTyp(string);
      void ausgeben();
};

postenTyp::postenTyp(string zeile)
{
   anzahl = 0;
   preis = 0.0;
   
   replace(zeile.begin(), zeile.end(), ';', ' ');
   istringstream zeilenStrom(zeile);

   zeilenStrom >> anzahl;

   string preisString;
   zeilenStrom >> preisString;
   replace(preisString.begin(), preisString.end(), ',', '.');
   istringstream preisStrom(preisString);
   preisStrom >> preis;

   getline(zeilenStrom, bezeichnung);
   while(bezeichnung.at(0) == ' ')
      bezeichnung.erase(0, 1);
}

void postenTyp::ausgeben()
{
   cout << anzahl << " " << preis << " " << bezeichnung << endl;
}

int main()
{
   ifstream textDatei("C:/Temp/datei_schreiben.csv");
   if(!textDatei)
   {
      cout << "Dateifehler" << endl;
      return 1;
   }

   vector<postenTyp> pFeld;
   while(textDatei)
   {
      string zeile;
      getline(textDatei, zeile);
      if(!textDatei)
         break;

      pFeld.push_back(postenTyp(zeile));
   }

   for(postenTyp &p:pFeld)
      p.ausgeben();
}

