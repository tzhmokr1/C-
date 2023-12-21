#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

typedef struct pTyp
{
   int anzahl;
   double preis;
   string bezeichnung;
} postenTyp;

void groesseFeld(vector<postenTyp> &feld)
{
   string eingabe;
   int postenZahl;
   istringstream eingabeStrom;

   cout << "Zahl der Rechnungsposten: ";
   getline(cin, eingabe);
   if(eingabe == "")
   {
      cout << "Keine Eingabe" << endl;
      postenZahl = 0;
   }
   else
   {
      eingabeStrom.str(eingabe);
      eingabeStrom >> postenZahl;
      eingabeStrom.clear();
   }

   feld.resize(postenZahl);
}

void eingabe(postenTyp &p)
{
   string eingabe;
   istringstream eingabeStrom;

   cout << "Anzahl: ";
   getline(cin, eingabe);
   if(eingabe == "")
      p.anzahl = 0;
   else
   {
      eingabeStrom.str(eingabe);
      eingabeStrom >> p.anzahl;
      eingabeStrom.clear();
   }

   cout << "Preis: ";
   getline(cin, eingabe);
   if(eingabe == "")
      p.preis = 0.0;
   else
   {
      eingabeStrom.str(eingabe);
      eingabeStrom >> p.preis;
      eingabeStrom.clear();
   }

   cout << "Bezeichnung: ";
   getline(cin, p.bezeichnung);
}

void eingabeFeld(vector<postenTyp> &feld)
{
   for(postenTyp &p:feld)
      eingabe(p);
}

void ausgabe(const postenTyp &p)
{
   cout << p.anzahl << " " << p.preis
      << " " << p.bezeichnung << endl;
}

void ausgabeFeld(const vector<postenTyp> &feld)
{
   for(const postenTyp &p:feld)
      ausgabe(p);
}

int main()
{
   vector<postenTyp> pFeld;

   groesseFeld(pFeld);
   eingabeFeld(pFeld);

   cout << "Noch ein Element:" << endl;
   postenTyp pNeu;
   eingabe(pNeu);
   pFeld.push_back(pNeu);

   ausgabeFeld(pFeld);
}

