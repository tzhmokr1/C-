// -------------------------------------------------------
// ex06_06.cpp
// Liest eine binäre Zahl (z.B. 1101) im Dialog ein 
// und gibt den entsprechenden dezimalen Wert aus.
// -------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
   char c = 0;
   int result = 0;

   cout << "Geben Sie eine binäre Zahl ein (e.g. 1101): ";
//   cin >> ws;    // Führende Zwischenraumzeichen überspringen
   while( cin.get(c) && (c == '0' || c == '1'))
   {
       result *= 2;
       if( c == '1')
          ++result;
   }

   cout << "\nDer dezimale Wert: " << result << endl;
   return 0;
}
