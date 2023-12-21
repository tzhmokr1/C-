#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
   istringstream eingabeStrom;

   int anzahl;
   double preis;
   string waehrung, bezeichnung;
   
   eingabeStrom.str("12 0.85     Euro     Birne, Demeter   ");
   eingabeStrom >> anzahl >> preis;
   eingabeStrom >> waehrung;

   getline(eingabeStrom, bezeichnung);
   while(bezeichnung.at(0) == ' ')
      bezeichnung.erase(0,1);
   while(bezeichnung.at(bezeichnung.length()-1) == ' ')
      bezeichnung.pop_back();

   eingabeStrom.clear();

   cout << anzahl << "|" << preis << "|"
      << waehrung << "|" << bezeichnung << "|" << endl;
}

