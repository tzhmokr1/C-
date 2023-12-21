// ---------------------------------------------------------
// ex17_10.cpp
// Das Programm liest Gleitpunktzahlen von der  
// Kommandozeile ein. Die Zahlen, ihre Summe und 
// der Durchschnitt werden ausgegeben. 
// ---------------------------------------------------------
#include <iostream>
#include <cstdlib>
using namespace std;

int main( int argc, char *argv[])
{
   int i=0;
   if( argc < 2)
   {
     cerr << "Aufruf: sum Zahl1 [Zahl2 ... ]" << endl;
     return 0;
   }

   cout << "\nDie eingelesenen Zahlen:\n";
   for( i = 1; i < argc; i++)
       cout << argv[i] << "  ";
   cout << endl;

   double sum = 0;                  // Summe berechnen.
   for( i = 1; i < argc; i++)
        sum += atof(argv[i]);

   cout << "Summe:        " << sum << endl
        << "Durchschnitt: " << sum/(argc - 1) << endl;
   return 0;
}
