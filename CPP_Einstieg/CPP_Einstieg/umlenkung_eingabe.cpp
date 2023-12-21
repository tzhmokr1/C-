#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
   double zahl, summe = 0.0;
   string eingabe;
   istringstream eingabeStrom;

   for(int i=1; i<=3; i++)
   {
      // cout << "Bitte eine Zahl: ";
      getline(cin, eingabe);
      if(eingabe == "")
         zahl = 0.0;
      else
      {
         eingabeStrom.str(eingabe);
         eingabeStrom >> zahl;
         eingabeStrom.clear();
      }
      summe += zahl;
   }

   cout << "Summe: " << summe << endl;
}

