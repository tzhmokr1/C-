#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
   ifstream textDatei("C:/Temp/datei_schreiben.txt");
   if(!textDatei)
   {
      cout << "Dateifehler" << endl;
      return 1;
   }

   int anzahl;
   double preis;
   string bezeichnung;

   while(textDatei)
   {
      textDatei >> anzahl;
      if(!textDatei)
         break;

      textDatei >> preis;

      getline(textDatei, bezeichnung);
      while(bezeichnung.at(0) == ' ')
         bezeichnung.erase(0,1);

      cout << anzahl << " " << preis
         << " |" << bezeichnung << endl;
   }
}

