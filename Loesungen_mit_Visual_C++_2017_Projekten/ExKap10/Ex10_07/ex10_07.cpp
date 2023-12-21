// --------------------------------------------------------
// Die Funktion isPrime() prüft, ob eine 
// positive Ganzzahl eine Primzahl ist.
// -------------------------------------------------------- 
#include <iostream>
using namespace std;

bool isPrime(unsigned int n);

int main()       // Testet die Funktion isPrime().
{
   unsigned int n;

   cout << "  **** Prueft, ob eine positive ganze Zahl eine Primzahl ist ****\n"
        << endl;

   cout << "Geben Sie eine positive Ganzzahl ein: ";
   cin  >> n;

   cout << n << " ist " << (isPrime(n)? "eine " : " keine ")
        << "Primzahl." << endl;

   return 0;
}

// --------------------------------------------------------
// Die Funktion isPrime() 
//
bool isPrime(unsigned int n)
{
   if( n < 2)  return false;
   if( n == 2) return true;    // 2 ist die erste Primzahl

   unsigned int i=2, limit = n/2;
   for( ; i <= limit; ++i)
      if( n % i == 0)
         return false;

   return true;
}
