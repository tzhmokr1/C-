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

int main()
{
   vector<personTyp> personFeld;
   personTyp personNeu;

   string weiter, eingabe;
   int eingabeInt;
   double eingabeDouble;
   istringstream eingabeStrom;

   do
   {
      cout << "Datensatz eingeben (J/N): ";
      getline(cin, weiter);
   }
   while(weiter != "J" && weiter != "N");

   while(weiter == "J")
   {
      cout << "Name: ";
      getline(cin, personNeu.name);

      cout << "Vorname: ";
      getline(cin, personNeu.vorname);

      cout << "Personalnummer: ";
      getline(cin, eingabe);
      if(eingabe == "")
         eingabeInt = 0;
      else
      {
         eingabeStrom.str(eingabe);
         eingabeStrom >> eingabeInt;
         eingabeStrom.clear();
      }
      personNeu.personalnummer = eingabeInt;

      cout << "Gehalt: ";
      getline(cin, eingabe);
      if(eingabe == "")
         eingabeDouble = 0.0;
      else
      {
         eingabeStrom.str(eingabe);
         eingabeStrom >> eingabeDouble;
         eingabeStrom.clear();
      }
      personNeu.gehalt = eingabeDouble;

      do
      {
         cout << "Geburtstag: ";
         getline(cin, eingabe);
      }
      while(eingabe.length() != 10 || eingabe.at(2) != '.'
         || eingabe.at(5) != '.');
      personNeu.geburtstag = eingabe;
      
      personFeld.push_back(personNeu);

      do
      {
         cout << "Datensatz eingeben (J/N): ";
         getline(cin, weiter);
      }
      while(weiter != "J" && weiter != "N");
   }
   
   if(personFeld.empty())
      return 0;

   cout << fixed << setprecision(2);
   cout << left << setw(17) << "Name" << setw(17) << "Vorname"
      << right << setw(14) << "Personalnummer" << setw(10)
      << "Gehalt" << setw(12) << "Geburtstag" << endl;
   for(unsigned int i=0; i<personFeld.size(); i++)
      cout << left << setw(17) << personFeld.at(i).name.substr(0,15)
         << setw(17) << personFeld.at(i).vorname.substr(0,15)
         << right << setw(14) << personFeld.at(i).personalnummer
         << setw(10) << personFeld.at(i).gehalt << setw(12)
         << personFeld.at(i).geburtstag << endl;
}

