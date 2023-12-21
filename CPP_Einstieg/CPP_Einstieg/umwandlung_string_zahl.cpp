#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
   string eingabe;
   double zahl;
   int ganzzahl;

   cout << "Bitte einen Text: ";
   getline(cin, eingabe);
   cout << "Ihr Text: " << eingabe << endl;

   istringstream eingabeStrom;

   cout << "Bitte eine Zahl: ";
   getline(cin, eingabe);
   if(eingabe == "")
   {
      cout << "Keine Eingabe" << endl;
      zahl = 0.0;
   }
   else
   {
      eingabeStrom.str(eingabe);
      eingabeStrom >> zahl;
      eingabeStrom.clear();
      cout << "Ihre Zahl: " << zahl << endl;
   }

   cout << "Bitte eine ganze Zahl: ";
   getline(cin, eingabe);
   if(eingabe == "")
   {
      cout << "Keine Eingabe" << endl;
      ganzzahl = 0;
   }
   else
   {
      eingabeStrom.str(eingabe);
      eingabeStrom >> ganzzahl;
      eingabeStrom.clear();
      cout << "Ihre ganze Zahl: " << ganzzahl << endl;
   }
}

