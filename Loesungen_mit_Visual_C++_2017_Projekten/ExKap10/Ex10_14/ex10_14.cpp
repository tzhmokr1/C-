// ---------------------------------------------------------
// Definiert die rekursive Funktion gcd() und ruft sie auf,
// um den größten gemeinsamen Teiler von zwei positiven Zahlen 
// mit dem Algorithmus von Euklid zu berechnen. 
// ---------------------------------------------------------

#include <iostream>
using namespace std;

unsigned long gcd(unsigned long a, unsigned long b);

int main()       // Testet die Funktion gcd()
{
   unsigned int m=0, n=0;

   cout << "  **** Groesster gemeinsamer Teiler ****\n"
        << endl;

   cout << "Geben Sie zwei positve Ganzzahlen ein:" << endl;
   cin >> m >> n;
   
   cout << "Der groesste gemeinsame Teiler ist " << gcd( m, n) << endl;

   return 0;
}
/*
// --------------------------------------------------------
// Die Funktion gcd() berechnet den größten gemeinsamen
// Teiler von zwei positiven Ganzzahlen mit dem
// Algorithmus von Euklid. 

unsigned long gcd(unsigned long m, unsigned long n)
{
    unsigned long tmp;
    while( n != 0)
    {
        // m = m % n  und  m, n vertauschen
        tmp = m % n;   m = n;  n = tmp;
    }

  // Jetzt ist m der größte gemeinsame Teiler.
    return m;
}
*/

// --------------------------------------------------------
// Die rekursive Version der Funktion gcd()

unsigned long gcd(unsigned long m, unsigned long n)
{
    if( n == 0)
       return m;
    else
       return gcd( n, m%n);
} 
