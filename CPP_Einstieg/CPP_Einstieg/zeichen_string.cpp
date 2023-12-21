#include <iostream>
#include <string>
using namespace std;

int main()
{
   string satz;
   satz = "Das ist";
   cout << "Zuweisen: " << satz << endl;

   satz += " ein Satz";
   cout << "Erweitern: " << satz << endl;

   for(unsigned int i=0; i<satz.length(); i++)
      cout << satz.at(i) << " ";
   cout << endl;

   for(const char &z:satz)
      cout << z << " ";
   cout << endl;

   cout << "Einfach: " << satz.c_str() << endl;

   string linie = string(10, '+');
   cout << linie << endl;
}

