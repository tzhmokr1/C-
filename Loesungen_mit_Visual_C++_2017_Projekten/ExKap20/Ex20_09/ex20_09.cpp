// ---------------------------------------------------------
// ex20_09.cpp
// Testet Mehrdeutigkeiten bei Typumwandlungen für Klassen
// ---------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

class Pair
{
  private:
   long key;   string name;

  public:
   Pair( long k, string s) : key(k), name(s) {}
   // Zur Vermeidung von Mehrdeutigkeiten:
   explicit Pair( long k) : key(k) {}

   friend ostream& operator <<(ostream& os, const Pair& p)
   { 
      os << '(' << p.key << ",\"" << p.name << "\")";
      return os;
   } 

   friend bool operator<(const Pair& p1, const Pair& p2)
   {
      cout << "\n\n-- Operator < der Klasse Pair! --"<< endl;
      return (p1.key < p2.key);
   }

   operator long() const
   { 
      cout << "\n\n-- Konvertierung: Pair in long! --" << endl;
      return key;
   }
};

int main()
{
   Pair p(1234, "Jim");
   //long n  = 4321L;

   cout << "\nDas Paar " << p; 
   if( p < n) 
      cout << "\nist kleiner als " << Pair(n) << endl << endl;
   else
      cout << "\nist groesser oder gleich " << Pair(n) 
           << endl << endl;

   return 0;
}
// Bemerkung:
// Vergleich von Ganzzahlen:  if( (long)p < n )
//           von Paaren:      if( p < Pair(n) )
