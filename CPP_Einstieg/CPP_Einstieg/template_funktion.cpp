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
      postenTyp(const int&, const double&, const string&);
      bool operator > (const postenTyp&);
      void ausgeben();
};

postenTyp::postenTyp(const int &a, const double &p, const string &b)
{
   anzahl = a;
   preis = p;
   bezeichnung = b;
}

void postenTyp::ausgeben()
{
   cout << anzahl << " " << preis << " " << bezeichnung << endl;
}

bool postenTyp::operator > (const postenTyp &anderesObjekt)
{
   if(anzahl*preis  >  anderesObjekt.anzahl*anderesObjekt.preis)
      return true;
   else
      return false;
}

template <typename T>
T maximum(T &a, T &b)
{
   T ergebnis = b;
   if(a > b)
      ergebnis = a;
   return ergebnis;
}

int main()
{
   int a=15, b=8;
   double x=6.3, y=8.2;
   postenTyp postenEins(2, 1.45, "Apfel");
   postenTyp postenZwei(5, 0.75, "Kiwi");

   if(postenEins > postenZwei)
      cout << "Eins > Zwei" << endl;
   else
      cout << "Zwei > Eins" << endl;

   cout << maximum(a, b) << endl;
   cout << maximum(x, y) << endl;
   maximum(postenEins, postenZwei).ausgeben();
}

