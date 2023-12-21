// --------------------------------------------------------
// ex09_06.cpp 
// Verschlüsselt einen String, indem benachbarte Zeichen
// im String vertauscht werden. 
// --------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

int main()
{
   char c;
   string s;

   cout << "Geben Sie eine Zeile Text ein: ";
   getline(cin, s);

   for( unsigned int i = 0; i < s.length() - 1; i += 2)
   {
      c      = s[i];
      s[i]   = s[i+1];
      s[i+1] = c; 
   }
   cout << "Der verschluesselte Text: " << s << endl;

   return 0;
}
