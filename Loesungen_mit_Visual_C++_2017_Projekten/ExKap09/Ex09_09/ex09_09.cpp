// -------------------------------------------------------
// ex09_09.cpp 
// Konvertiert einen String mit Hexadezimalziffern 
// in eine Ganzzahl.
// -------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

int main()
{
   string hexStr;
   int result = 0, digitvalue = 0;
   char c;

   cout << "\nGeben Sie eine Hexadezimalzahl ein: ";
   getline( cin, hexStr);

   for( unsigned int i = 0; i < hexStr.length(); i++)
   {
       c = toupper(hexStr[i]);

       if( '0' <= c && c <= '9')       // oder: if( isdigit(c))
          digitvalue = c - '0';
       else if( 'A' <= c && c <= 'F')
          digitvalue = 10 + (c - 'A');
       else
          break;

       result = result * 16 + digitvalue;
   }

   cout << hexStr << " entspricht der Dezimalzahl "
        << dec << result << endl;

   return 0;
}
