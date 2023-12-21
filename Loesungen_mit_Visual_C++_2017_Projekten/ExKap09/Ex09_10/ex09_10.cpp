// ---------------------------------------------------------
// ex09_10.cpp 
// Wandelt eine dezimale Ganzzahl in einen String um.
// Der String und die Summe der Ziffern werden ausgegeben.
// ----------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

int main()
{
   unsigned int  num = 0;
   string decStr;            // Ein leerer String
   char digit;

   cout << "\nGeben Sie eine Dezimalzahl ein: ";
   cin >> num;

   do                        // Konvertiert die Ganzzahl in einen String.
   {
      digit = (char)(num % 10 + '0');
      decStr = digit + decStr; 
      num /= 10;
   }
   while( num != 0);

   cout << "Der String:            " << decStr << endl; 

   int sum=0;
   for( unsigned int i = 0; i < decStr.length();  ++i)
       sum += (decStr[i] - '0');

   cout << "Die Summe der Ziffern: " << sum << endl;
   
   return 0;
}
