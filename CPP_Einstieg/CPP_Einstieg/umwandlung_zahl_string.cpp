#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
   string bezeichnung = "Preis: ";
   double preis = 1.45;
   string ausgabe;
   
   // ausgabe = bezeichnung + to_string(preis);
   // cout << ausgabe << endl;

   ostringstream ausgabeStrom;

   ausgabeStrom.str("");
   ausgabeStrom << bezeichnung << preis;
   ausgabe = ausgabeStrom.str();
   cout << ausgabe << endl;
}

