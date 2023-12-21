// ---------------------------------------------------------
// ex09_08.cpp 
// Löscht führende Zwischenraumzeichen in einem String.
// ----------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

int main()
{
   string s("  \n    \t   No news is good news!");
   unsigned int i = 0;
   cout << s << endl;
   while( i < s.length() && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
      ++i;

   if( i > 0)
       s.erase(0,i);

   cout << s << endl; 
   return 0;
}
