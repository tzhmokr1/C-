// -------------------------------------------------------
// ex07_08.cpp
// Ein Filterprogramm, das Steuerzeichen in einer Textdatei
// sichtbar macht. Z.B. wird (9) für den horizontalen 
// Tabulator ausgegeben.
// -------------------------------------------------------

#include <iostream>
#include <cctype>
using namespace std;

int main()
{
   char c;
   int c_code;
   while( cin.get(c))
   {
      if( iscntrl(c))
      {
         c_code = c;
         cout << '(' << c_code << ')';
         if( c == '\n')
           cout << c;
      }
      else
         cout << c;
   }
   return 0;
}
