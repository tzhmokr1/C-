// --------------------------------------------------------
// ex09_03.cpp 
// Liest ein Paar formatiert als 'Name=Wert' ein. Der Name
// und der Wert werden extrahiert und in verschiedenen 
// Strings gespeichert. Die Länge des Eingabestrings, der
// Name und der Wert werden auf dem Bildschirm ausgegeben. 
// --------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

int main()
{
   int pos, len;
   string s, name, value;

   cout << "Geben Sie ein Paar 'Name=Wert' ein:  "
        << endl;
   getline(cin, s);
   len = s.length();
   cout << "Laenge des Eingabestrings: " << len << endl;

   pos = s.find("=");
   if( pos != string::npos && pos > 0)
   {
      name  = string( s, 0, pos);
      ++pos;
      value = string( s, pos, len-pos);
      cout << "Name: " << name << endl
           << "Wert: " << value << endl;
   }
   else
      cout << "Unzulaessige Eingabe!" << endl;

   return 0;
}
