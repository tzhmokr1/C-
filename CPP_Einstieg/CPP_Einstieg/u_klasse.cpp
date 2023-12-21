#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class personTyp
{
   friend ostream& operator << (ostream&, const personTyp&);  

   private:
      string name, vorname, geburtstag;
      int personalnummer;
      double gehalt;

      static string eingabeString(const string&);
      static int eingabeInt(const string&);
      static double eingabeDouble(const string&);
      static string eingabeDatum(const string&);
   public:
      static bool weiter();
      void eingabe();
      static void ausgabeTabelle(vector<personTyp>&);
};

ostream& operator << (ostream& om, const personTyp& p)
{  
   om << left << setw(17) << p.name.substr(0,15)
      << setw(17) << p.vorname.substr(0,15)
      << right << setw(14) << p.personalnummer
      << setw(10) << p.gehalt << setw(12)
      << p.geburtstag << endl;
   return om;  
}  

string personTyp::eingabeString(const string &anzeige)
{
   string eingabe;
   cout << anzeige << ": ";
   getline(cin, eingabe);
   return eingabe;
}

int personTyp::eingabeInt(const string &anzeige)
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

double personTyp::eingabeDouble(const string &anzeige)
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

string personTyp::eingabeDatum(const string &anzeige)
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

bool personTyp::weiter()
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

void personTyp::eingabe()
{
   name = eingabeString("Name");
   vorname = eingabeString("Vorname");
   personalnummer = eingabeInt("Personalnummer");
   gehalt = eingabeDouble("Gehalt");
   geburtstag = eingabeDatum("Geburtstag");
}

void personTyp::ausgabeTabelle(vector<personTyp> &pf)
{
   cout << fixed << setprecision(2);
   cout << left << setw(17) << "Name" << setw(17) << "Vorname"
      << right << setw(14) << "Personalnummer" << setw(10)
      << "Gehalt" << setw(12) << "Geburtstag" << endl;
   for(unsigned int i=0; i<pf.size(); i++)
      cout << pf.at(i);
}

int main()
{
   vector<personTyp> personFeld;
   personTyp personNeu;

   while(personTyp::weiter())
   {
      personNeu.eingabe();
      personFeld.push_back(personNeu);
   }
   
   if(personFeld.empty())
      return 0;
   personTyp::ausgabeTabelle(personFeld);
}

