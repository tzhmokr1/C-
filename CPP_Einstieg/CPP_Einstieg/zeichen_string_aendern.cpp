#include <iostream>
#include <string>
using namespace std;

int main()
{
   string satz = "Das ist ein Satz";
   cout << "Original: " << satz << endl;

   satz.at(0) = 'd';
   satz.at(12) = 's';
   cout << "Zeichen wechseln: " << satz << endl;

   satz.insert(12, "neuer ");
   cout << "Einsetzen: " << satz << endl;

   satz.erase(12, 6);
   cout << "Entfernen: " << satz << endl;

   satz.replace(4, 3, "wird");
   cout << "Ersetzen: " << satz << endl;

   satz.push_back('X');
   cout << "Erweitern mit char: " << satz << endl;

   satz.pop_back();
   cout << "Entfernen von char: " << satz << endl;
}

