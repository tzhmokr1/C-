// -------------------------------------------------------
// ex07_10.cpp
// Ein Filterprogram, das einzelne Ziffern durch 
// ihren Namen ersetzt.
// -------------------------------------------------------

#include <iostream>
#include <cctype>
using namespace std;

int main()
{
   char previous='\n', current;
   bool fDigit = false;    // true, falls das letzte Zeichen
                           // eine Ziffer ist, der ein 
                           // Zwischenraumzeichen vorangeht.
   while( cin.get(current))
   {
      if( fDigit)
         if( isspace(current))
         {
            switch(previous)
            {
              case '0': cout << "null";
                        break;
              case '1': cout << "eins";
                        break;
              case '2': cout << "zwei";
                        break;
              case '3': cout << "drei";
                        break;
              case '4': cout << "vier";
                        break;
              case '5': cout << "fuenf";
                        break;
              case '6': cout << "sechs";
                        break;
              case '7': cout << "sieben";
                        break;
              case '8': cout << "acht";
                        break;
              case '9': cout << "neun";
                        break;
            }
         }
         else
            cout << previous;

      fDigit = false;
      if( isdigit(current) && isspace(previous))
         fDigit = true;
      else
          cout << current;

      previous = current;
   }

   return 0;
}
