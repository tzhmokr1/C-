#include <iostream>
#include <string>
using namespace std;

int main()
{
   string satz = "Das ist ein Satz";
   cout << satz << endl;

   if(satz == "Das ist ein Satz")
      cout << "Das ist derselbe Text" << endl;
   if(satz != "Hallo")
      cout << "'Hallo' ist ungleich" << endl;
   if(satz < "Hallo")
      cout << "'Hallo' steht danach" << endl;

   cout << "Drei Zeichen ab Position 4: "
      << satz.substr(4, 3) << endl;
   cout << "Alle Zeichen ab Position 12: "
      << satz.substr(12) << endl;

   string::size_type pos;

   cout << "'ist'";
   pos = satz.find("ist");
   if(pos == string::npos)
      cout << " nicht gefunden" << endl;
   else
      cout << " gefunden an Position " << pos << endl;

   cout << "'wird'";
   pos = satz.find("wird");
   if(pos == string::npos)
      cout << " nicht gefunden" << endl;
   else
      cout << " gefunden an Position " << pos << endl;
}

