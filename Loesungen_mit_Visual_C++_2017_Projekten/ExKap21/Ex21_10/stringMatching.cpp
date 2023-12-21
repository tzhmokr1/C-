// -----------------------------------------------------------
// stringMatching.cpp
// Implementiert die Methoden der Klasse StringMatching.
// Es wird der Boyer-Moore Algorithmus verwendet.
// -----------------------------------------------------------
#include "stringMatching.h"
#include <iostream>
#include <climits>                 // Für  UCHAR_MAX
using namespace std;

StringMatching::StringMatching( const string& pat)
: pattern(pat) 
{
   int len = pattern.length(),     // Länge des Suchstrings
       i, code;                    // Index und Zeichencode;
   deltaTable = new int[UCHAR_MAX+1];  // Entfernungstabelle

   for( code = 0; code <= UCHAR_MAX; ++code)  // Vorbelegung für
      deltaTable[code] = len;                 // alle Zeichen.

   for( i = 0; i < len-1; ++i)     // Abstand der Zeichen vom Stringende,
   {                               // ausgenommen dem letzten Zeichen.
      code = (unsigned char)pattern[i];
      deltaTable[code] = len-i-1;
   }
}

void StringMatching::print() const // Suchstring und 
{                                  // Entfernungstabelle anzeigen. 
   int len = pattern.length();

   cout << pattern << "\n---------------------" << endl;
   for( int i = 0; i <= UCHAR_MAX; ++i)
      if( deltaTable[i] != len)
        cout << (char)i << " : " << deltaTable[i] << endl;
}
