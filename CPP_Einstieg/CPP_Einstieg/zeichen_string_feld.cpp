#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
int main()
{
   vector<string> land;
   string eingabe;
   int anzahl;
   istringstream eingabeStrom;

   cout << "Anzahl: ";
   getline(cin, eingabe);
   if(eingabe == "")
   {
      cout << "Keine Eingabe" << endl;
      anzahl = 0;
   }
   else
   {
      eingabeStrom.str(eingabe);
      eingabeStrom >> anzahl;
      eingabeStrom.clear();
   }

   land.resize(anzahl);

   for(unsigned int index=0; index<land.size(); index++)
   {
      cout << "Name des Landes " << index+1 << ": ";
      getline(cin, land.at(index));
   }
   
   string L;
   cout << "Noch ein Land: ";
   getline(cin, L);
   land.push_back(L);

   for(string &L:land)
   {
      for(char &c:L)
         cout << c << " ";
      cout << endl;
   }
}

