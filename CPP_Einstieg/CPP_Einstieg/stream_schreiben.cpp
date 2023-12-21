#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;
int main()
{
   ostringstream ausgabeStrom;

   int anzahl = 3;
   double preis = 1.40;
   string bezeichnung = "Apfel, Bio";

   ausgabeStrom << anzahl << " " << preis << " " << bezeichnung;
   cout << ausgabeStrom.str() << endl;

   ausgabeStrom.str("");
   ausgabeStrom << right << setw(4) << anzahl
      << right << setw(8) << preis << " "
      << left << setw(20) << bezeichnung;
   cout << ausgabeStrom.str() << endl;

   ausgabeStrom.seekp(13);
   ausgabeStrom << "Birne";
   cout << ausgabeStrom.str() << endl;
}

