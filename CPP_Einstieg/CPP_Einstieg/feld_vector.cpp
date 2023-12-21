#include <iostream>
#include <vector>
using namespace std;
int main()
{
   vector<double> preise;

   int postenAnzahl;
   cout << "Anzahl der Rechnungsposten: ";
   cin >> postenAnzahl;
   preise.resize(postenAnzahl);

   for(unsigned int index=0; index<preise.size(); index++)
   {
      cout << "Preis von Rechnungsposten " << index+1 << ": ";
      cin >> preise.at(index);
   }
   
   double p;
   cout << "Noch ein Preis: ";
   cin >> p;
   preise.push_back(p);

   double summe = 0.0;
   for(double &p:preise)
      summe += p;
   cout << "Summe: " << summe << endl;
}

