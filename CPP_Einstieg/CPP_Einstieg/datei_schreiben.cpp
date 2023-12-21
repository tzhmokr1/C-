#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
   ofstream textDatei("C:/Temp/datei_schreiben.txt");
   if(!textDatei)
   {
      cout << "Dateifehler" << endl;
      return 1;
   }

   int anzahl = 3;
   double preis = 1.40;
   string bezeichnung = "Apfel, Bio";

   textDatei << anzahl << " " << preis
      << " " << bezeichnung << endl;
   textDatei << "12 0.85 Birne" << endl;
}

