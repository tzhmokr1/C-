#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main()
{
   vector<string> name;
   vector<string> vorname;
   vector<int> personalnummer;
   vector<double> gehalt;
   vector<string> geburtstag;

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
      getline(cin, eingabe);
      name.push_back(eingabe);

      cout << "Vorname: ";
      getline(cin, eingabe);
      vorname.push_back(eingabe);

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
      personalnummer.push_back(eingabeInt);

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
      gehalt.push_back(eingabeDouble);

      do
      {
         cout << "Geburtstag: ";
         getline(cin, eingabe);
      }
      while(eingabe.length() != 10 || eingabe.at(2) != '.'
         || eingabe.at(5) != '.');
      geburtstag.push_back(eingabe);

      do
      {
         cout << "Datensatz eingeben (J/N): ";
         getline(cin, weiter);
      }
      while(weiter != "J" && weiter != "N");
   }
   
   if(name.empty())
      return 0;

   cout << fixed << setprecision(2);
   cout << left << setw(17) << "Name" << setw(17) << "Vorname"
      << right << setw(14) << "Personalnummer" << setw(10)
      << "Gehalt" << setw(12) << "Geburtstag" << endl;
   for(unsigned int i=0; i<name.size(); i++)
      cout << left << setw(17) << name.at(i).substr(0,15)
         << setw(17) << vorname.at(i).substr(0,15) << right
         << setw(14) << personalnummer.at(i) << setw(10)
         << gehalt.at(i) << setw(12) << geburtstag.at(i) << endl;
}

