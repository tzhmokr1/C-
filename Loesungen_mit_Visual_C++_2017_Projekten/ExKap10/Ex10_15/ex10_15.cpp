// ------------------------------------------------------------
// ex10_15.cpp 
// Definiert die Funktion isFibonacci() und ruft sie auf, um zu
// prüfen, ob eine positive Ganzzahl eine Fibonaccizahl ist.
// ------------------------------------------------------------

#include <iostream>
using namespace std;

bool isFibonacci(unsigned int n);

int main()       // Testet die Funktion isFibonacci()
{
   unsigned int n;

   cout << "  ****     Test fuer Fibonaccizahlen    ****\n"
        << endl;

   while(true)
   {
      cout << "Geben Sie eine positive Ganzzahl ein (Abbruch mit Buchstaben): ";
      if( !(cin  >> n))
         break;

      cout << n << " ist " << (isFibonacci(n)? "eine " : "keine ")
           << "Fibonaccizahl." << endl;
   }
   return 0;
}

// --------------------------------------------------------
// Die Funktion isFibonacci() 
//
bool isFibonacci(unsigned int n)
{
   if( n <= 3) return true;   // 0,1,2,3 sind Fibonaccizahlen

   unsigned int f1 = 2, f2 = 3, f;
   while( f2 < n)
   {
     f = f1 + f2;             // Die nächste Fibonaccizahl
     if( n == f)
        return true;
     else
        f1 = f2, f2 = f;
   }
   return false;
}
