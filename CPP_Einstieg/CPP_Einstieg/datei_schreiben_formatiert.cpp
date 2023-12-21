#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
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
      void zeileSchreiben(ofstream&);
};

postenTyp::postenTyp(const int &a, const double &p, const string &b)
{
   anzahl = a;
   preis = p;
   bezeichnung = b;
}

void postenTyp::zeileSchreiben(ofstream &td)
{
   td << right << setw(4) << anzahl
      << right << setw(8) << preis << " "
      << left << setw(20) << bezeichnung << endl;
   cout << "Position: " << td.tellp() << endl;
}

int main()
{
   ofstream textDatei("C:/Temp/datei_schreiben_beliebig.txt");
   if(!textDatei)
   {
      cout << "Dateifehler" << endl;
      return 1;
   }

   vector<postenTyp> pFeld;
   pFeld.push_back(postenTyp(3, 1.40, "Apfel, Bio"));
   pFeld.push_back(postenTyp(12, 0.85, "Birne"));
   pFeld.push_back(postenTyp(5, 0.75, "Kiwi"));

   textDatei << fixed << setprecision(2);
   for(postenTyp &p:pFeld)
      p.zeileSchreiben(textDatei);
}

