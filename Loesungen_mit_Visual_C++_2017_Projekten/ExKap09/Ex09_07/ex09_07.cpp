// --------------------------------------------------------
// ex09_07.cpp 
// Formatierung von Namen wie das Beispiel zeigt:
//   "Michael Martin Murphey" -->  "Murphey, Michael M."
// --------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

int main()
{
   int pos1, pos2;
   string name;

   cout << "Geben Sie einen oder zwei Vornamen "
        << "und einen Nachnamen ein: " << endl;
   if( !getline( cin, name))
       name = "Giovanni Battista Pergolesi";

   pos1 = name.find(" ");
   if( pos1 == string::npos)
   {
       cout << "Ungueltige Eingabe!" << endl;
       return 1;
   }

   string firstname(name, 0, pos1);

   pos2 = name.rfind(" ");
   if( pos1 < pos2)                    // Zwei Vornamen?
       firstname += string(name, pos1, 2) + ".";

   ++pos2;
   name.erase(0, pos2);                // Nur ein Nachname.

   name += ", " + firstname;
   
   cout << name << endl;

   return 0;
}
