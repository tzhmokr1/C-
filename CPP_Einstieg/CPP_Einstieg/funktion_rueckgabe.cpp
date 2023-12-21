#include <iostream>
using namespace std;

double berechneGesamt(const int &anzahl, const double &preisEinzel)
{
   double preisGesamt;
   preisGesamt = anzahl * preisEinzel;
   return preisGesamt;
}

int main()
{
   int anzahlApfel = 3, anzahlBirne = 7;
   double preisApfel = 1.45, preisBirne = 0.85;
   double preisGesamt;

   preisGesamt = berechneGesamt(anzahlApfel, preisApfel);
   cout << "Gesamtpreis: " << preisGesamt << " Euro" << endl;

   cout << "Gesamtpreis: " << berechneGesamt(anzahlBirne,
      preisBirne) << " Euro" << endl;
}

