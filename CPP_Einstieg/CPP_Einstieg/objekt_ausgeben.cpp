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
      friend ostream& operator << (ostream&, const postenTyp&);  
};

postenTyp::postenTyp(const int &a, const double &p, const string &b)
{
   anzahl = a;
   preis = p;
   bezeichnung = b;
}

ostream& operator << (ostream& om, const postenTyp& p)
{  
   om << p.anzahl << " " << p.preis << " " << p.bezeichnung;  
   return om;  
}  

int main()
{
   postenTyp pEins(2, 1.45, "Apfel");
   cout << pEins << endl;
}

