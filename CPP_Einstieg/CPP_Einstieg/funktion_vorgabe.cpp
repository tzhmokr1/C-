#include <iostream>
using namespace std;

void ausgabeGesamt(const int &anzahl = 1,
   const double &preisEinzel = 0.95)
{
   double preisGesamt;
   preisGesamt = anzahl * preisEinzel;
   cout << "Gesamtpreis: " << preisGesamt << " Euro" << endl;
}

int main()
{
   int anzahlApfel = 3;
   double preisApfel = 1.45;

   ausgabeGesamt(anzahlApfel, preisApfel);
   ausgabeGesamt(anzahlApfel);
   ausgabeGesamt();
}

