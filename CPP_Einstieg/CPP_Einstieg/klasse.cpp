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
      void werteZuweisen(const int&, const double&, const string&);
      void ausgeben();
};

void postenTyp::werteZuweisen(const int &a,
   const double &p, const string &b)
{
   anzahl = a;
   preis = p;
   bezeichnung = b;
}

void postenTyp::ausgeben()
{
   cout << anzahl << " " << preis << " " << bezeichnung << endl;
}

int main()
{
   postenTyp pEins;
   pEins.werteZuweisen(2, 1.45, "Apfel");
   pEins.ausgeben();
   
   postenTyp pZwei = pEins;
   pZwei.ausgeben();
}

