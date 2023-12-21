// --------------------------------------------------------
// Definiert und testet die Funktion gcd(), die den 
// größten gemeinsamen Teiler von zwei ganzen Zahlen.  
// berechnet. Es wird der Algorithmus von Euklid verwendet.
// -------------------------------------------------------- 
#include <iostream>
using namespace std;

unsigned long gcd(unsigned long a, unsigned long b);

int main()       // Testet die Funktion gcd()
{
   unsigned int m=0, n=0;

   cout << "  **** Groesster gemeinsamer Teiler ****\n"
        << endl;

   cout << "Geben Sie zwei positive Ganzzahlen ein: ";
   cin >> m >> n;

   cout << "Der groesste gemeinsame Teiler ist " << gcd( m, n) << endl;

   return 0;
}

// -----------------------------------------------------------
// Mit dem Algorithmus von Euklid berechnet die Funktion gcd()
// den größten gemeinsamen Teiler von zwei positiven Ganzzahlen.

unsigned long gcd(unsigned long m, unsigned long n)
{
    unsigned long tmp;
    while( n != 0)
    {
        // m = m % n  und  m, n vertauschen
        tmp = m % n;   m = n;  n = tmp;
    }

  // Jetzt ist m der größte gemeinsame Teiler:
    return m;
}
