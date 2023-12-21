// --------------------------------------------------------
// ex06_05.cpp
// Liest eine Dezimalzahl (z.B. 19) von der Tastatur und 
// gibt die entsprechende bin�re Zahl (also 10011) aus.
// --------------------------------------------------------

#include <iostream>
using namespace std;

#include <string>
int main()
{
   unsigned int n = 0;
   string bits;             // Ein leerer String

   cout << "Geben Sie eine Dezimalzahl ein: ";
   cin >> n;

   do
   {
     if( n%2 == 0)          // N�chste Bin�rziffer
       bits = "0" + bits;   // am Anfang einf�gen.
     else
       bits = "1" + bits;

     n /= 2;

   } while( n != 0);

   cout << "\nDie entsprechende binaere Zahl: " << bits << endl;
   return 0;
}
