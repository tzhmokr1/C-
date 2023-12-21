// --------------------------------------------------------
// strReverse.cpp  (Excercise 12.5)
// Definiert die Funktion strReverse().
// --------------------------------------------------------
#include <string>
using namespace std;

const string& strReverse(const string& s1)
{
   static string s2;
   s2 = "";

   s2.reserve(s1.length());    // Der erforderliche Speicher.
   for( int i = s1.length()-1; i >= 0; --i)
        s2 += s1[i];

   return s2;
}
