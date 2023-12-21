#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

typedef struct psTyp
{
   string name, vorname, geburtstag;
   int personalnummer;
   double gehalt;
} personTyp;

bool weiter();
string eingabeString(const string&);
int eingabeInt(const string&);
double eingabeDouble(const string&);
string eingabeDatum(const string&);
void ausgabeTabelle(const vector<personTyp>&);
void ausgabe(const personTyp &);

int main()
{
   vector<personTyp> personFeld;
   personTyp personNeu;

   while(weiter())
   {
      personNeu.name = eingabeString("Name");
      personNeu.vorname = eingabeString("Vorname");
      personNeu.personalnummer = eingabeInt("Personalnummer");
      personNeu.gehalt = eingabeDouble("Gehalt");
      personNeu.geburtstag = eingabeDatum("Geburtstag");
      personFeld.push_back(personNeu);
   }
   
   if(personFeld.empty())
      return 0;
   ausgabeTabelle(personFeld);
}

bool weiter()
{
   string eingabe;

   do
   {
      cout << "Datensatz eingeben (J/N): ";
      getline(cin, eingabe);
   }
   while(eingabe != "J" && eingabe != "N");

   if(eingabe == "J")
      return true;
   else
      return false;
}

string eingabeString(const string &anzeige)
{
   string eingabe;
   cout << anzeige << ": ";
   getline(cin, eingabe);
   return eingabe;
}

int eingabeInt(const string &anzeige)
{
   string eingabe;
   istringstream eingabeStrom;
   int eingabeZahl;

   cout << anzeige << ": ";
   getline(cin, eingabe);
   if(eingabe == "")
      eingabeZahl = 0;
   else
   {
      eingabeStrom.str(eingabe);
      eingabeStrom >> eingabeZahl;
      eingabeStrom.clear();
   }

   return eingabeZahl;
}

double eingabeDouble(const string &anzeige)
{
   string eingabe;
   istringstream eingabeStrom;
   double eingabeZahl;

   cout << anzeige << ": ";
   getline(cin, eingabe);
   if(eingabe == "")
      eingabeZahl = 0;
   else
   {
      eingabeStrom.str(eingabe);
      eingabeStrom >> eingabeZahl;
      eingabeStrom.clear();
   }

   return eingabeZahl;
}

string eingabeDatum(const string &anzeige)
{
   string eingabe;

   do
   {
      cout << anzeige << ": ";
      getline(cin, eingabe);
   }
   while(eingabe.length() != 10 || eingabe.at(2) != '.'
      || eingabe.at(5) != '.');
   return eingabe;
}

void ausgabeTabelle(const vector<personTyp> &pf)
{
   cout << fixed << setprecision(2);
   cout << left << setw(17) << "Name" << setw(17) << "Vorname"
      << right << setw(14) << "Personalnummer" << setw(10)
      << "Gehalt" << setw(12) << "Geburtstag" << endl;
   for(unsigned int i=0; i<pf.size(); i++)
      ausgabe(pf.at(i));
}

void ausgabe(const personTyp &p)
{
   cout << left << setw(17) << p.name.substr(0,15)
      << setw(17) << p.vorname.substr(0,15)
      << right << setw(14) << p.personalnummer
      << setw(10) << p.gehalt << setw(12)
      << p.geburtstag << endl;
}

