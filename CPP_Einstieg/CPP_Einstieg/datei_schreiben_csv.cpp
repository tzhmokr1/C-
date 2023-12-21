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
      postenTyp(const int&, const double&, const string&);
      void ausgeben_csv(ofstream&);
};

postenTyp::postenTyp(const int &a, const double &p, const string &b)
{
   anzahl = a;
   preis = p;
   bezeichnung = b;
}

void postenTyp::ausgeben_csv(ofstream &td)
{
   stringstream preisStream;
   preisStream << preis;
   string preisString = preisStream.str();
   replace(preisString.begin(), preisString.end(), '.', ',');
   
   td << anzahl << ";" << preisString << ";" << bezeichnung << endl;
}

int main()
{
   ofstream textDatei("C:/Temp/datei_schreiben.csv");
   if(!textDatei)
   {
      cout << "Dateifehler" << endl;
      return 1;
   }

   vector<postenTyp> pFeld;
   pFeld.push_back(postenTyp(3, 1.4, "Apfel, Bio"));
   pFeld.push_back(postenTyp(12, 0.85, "Birne"));
   pFeld.push_back(postenTyp(5, 0.75, "Kiwi"));

   for(postenTyp &p:pFeld)
      p.ausgeben_csv(textDatei);
}

