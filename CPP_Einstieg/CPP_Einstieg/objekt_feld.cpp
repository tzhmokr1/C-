#include <iostream>
#include <vector>
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

postenTyp::~postenTyp()
{
   cout << "Destruktor: ";
   ausgeben();
}

void postenTyp::ausgeben()
{
   cout << anzahl << " " << preis << " " << bezeichnung << endl;
}

int main()
{
   cout << "Feld erzeugen: " << endl;
   vector<postenTyp> pFeld =
      { postenTyp(4, 1.15, "Mango"),
        postenTyp(7, 0.85, "Birne") };
   cout << endl;

   cout << "Feld erweitern mit resize(): " << endl;
   pFeld.resize(3);
   cout << endl;

   cout << "Element zuweisen: " << endl;
   pFeld.at(2) = postenTyp(8, 1.75, "Ananas");
   cout << endl;

   cout << "Feld erweitern mit push_back(): " << endl;
   pFeld.push_back(postenTyp(2, 0.65, "Orange"));
   cout << endl;

   cout << "Feld ausgeben: " << endl;
   for(postenTyp &p:pFeld)
      p.ausgeben();
   cout << endl;
}

