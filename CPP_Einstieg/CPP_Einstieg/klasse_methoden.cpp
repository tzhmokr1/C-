#include "klasse_definition.cpp"

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

