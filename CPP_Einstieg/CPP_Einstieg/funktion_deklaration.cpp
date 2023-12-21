#include <iostream>
using namespace std;

void ausgabeGesamt(const int&, const double&);

int main()
{
   int anzahlApfel = 3, anzahlBirne = 7;
   double preisApfel = 1.45, preisBirne = 0.85;

   ausgabeGesamt(anzahlApfel, preisApfel);
   ausgabeGesamt(anzahlBirne, preisBirne);
}

void ausgabeGesamt(const int &anzahl, const double &preisEinzel)
{
   double preisGesamt;
   preisGesamt = anzahl * preisEinzel;
   cout << "Gesamtpreis: " << preisGesamt << " Euro" << endl;
}

