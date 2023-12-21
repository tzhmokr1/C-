#include <iostream>
#include <fstream>
using namespace std;
int main()
{
   ofstream oDatei("ausgabe.txt");
   if(!oDatei)
   {
      cout << "Dateifehler" << endl;
      return 1;
   }

   oDatei << 1.0 / 7.0 << endl;
   oDatei.close();

   if(rename("ausgabe.txt", "kopie.txt"))
   {
      cout << "Kein Umbenennen der Datei" << endl;
      return 1;
   }

   ifstream iDatei("kopie.txt");
   if(!iDatei)
   {
      cout << "Dateifehler" << endl;
      return 1;
   }

   double zahl;
   iDatei >> zahl;
   cout << zahl << endl;
   iDatei.close();

   if(remove("kopie.txt"))
      cout << "Kein Entfernen der Datei" << endl;
}

