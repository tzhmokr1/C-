#include <iostream>
using namespace std;

void ausgabeGesamt(int &anzahl, double &preisEinzel)
{
   double preisGesamt;
   preisGesamt = anzahl * preisEinzel;
   cout << "Gesamtpreis: " << preisGesamt << " Euro" << endl;
}

int main()
{
   int anzahlApfel = 3, anzahlBirne = 7;
   double preisApfel = 1.45, preisBirne = 0.85;

   ausgabeGesamt(anzahlApfel, preisApfel);
   ausgabeGesamt(anzahlBirne, preisBirne);
   // ausgabeGesamt(5, 1.75);
}

