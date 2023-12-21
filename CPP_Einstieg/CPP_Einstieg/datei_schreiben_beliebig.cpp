#include <iostream>
#include <string>
#include <iomanip>
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
      postenTyp(const int&, const double&, const string&);
      void zeileSchreibenNummer(ofstream &, int);
};

postenTyp::postenTyp(const int &a, const double &p, const string &b)
{
   anzahl = a;
   preis = p;
   bezeichnung = b;
}

void postenTyp::zeileSchreibenNummer(ofstream &td, int nummer)
{
   cout << "Position: " << td.tellp() << endl;
   td.seekp(nummer * laenge);
   cout << "Position: " << td.tellp() << endl;

   td << right << setw(4) << anzahl
      << right << setw(8) << preis << " "
      << left << setw(20) << bezeichnung << endl;
}

int main()
{
   ofstream textDatei("C:/Temp/datei_schreiben_beliebig.txt",
      ios::in | ios::out);
   if(!textDatei)
   {
      cout << "Dateifehler" << endl;
      return 1;
   }

   textDatei << fixed << setprecision(2);

   postenTyp pEins(6, 2.1, "Mango");
   pEins.zeileSchreibenNummer(textDatei, 1);
}

