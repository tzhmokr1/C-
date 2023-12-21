#include <iostream>
using namespace std;
int main()
{
   int anzahlApfel = 2, anzahlBirne = 4;
   double preisApfel = 1.45, preisBirne = 0.85;
   double summe, mittel, anteil, differenz;

   summe =
      anzahlApfel * preisApfel + anzahlBirne * preisBirne;
   mittel = summe / (anzahlApfel + anzahlBirne);
   anteil = 100.0 * anzahlBirne / (anzahlApfel + anzahlBirne);
   differenz = preisApfel - preisBirne;

   cout << "Summe: " << summe << " Euro" << endl;
   cout << "Mittlerer Preis: " << mittel << " Euro" << endl;
   cout << "Anteil: " << anteil << " %" << endl;
   cout << "Differenz: " << differenz << " Euro" << endl;
}

