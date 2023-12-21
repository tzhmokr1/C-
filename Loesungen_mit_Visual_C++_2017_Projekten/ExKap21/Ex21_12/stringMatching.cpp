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
   // 1. Entfernungstabelle für die Zeichen:
   deltaTable1 = new int[UCHAR_MAX+1];

   for( code = 0; code <= UCHAR_MAX; ++code)  // Vorbelegung für
      deltaTable1[code] = len;                // alle Zeichen.

   for( i = 0; i < len-1; ++i)     // Abstand der Zeichen vom Stringende,
   {                               // ausgenommen dem letzten Zeichen.
      code = (unsigned char)pattern[i];
      deltaTable1[code] = len-i-1;
   }

   // 2. Entfernungstabelle für die Vorgänger der Suffixe:
   deltaTable2 = new int[len];
   int last = len-1;               // Index des letzten Zeichens.
   deltaTable2[last] = 1; 

   for( i = last-1; i >= 0; --i)   // Suffix ab i+1
   {                               // Letzten Vorgänger suchen. 
      int j = last-1;              // Index des letzten Zeichens 
                                   // im Vorgänger.
      for( ; j >= 0; --j)
      {
         int ki = last, kj = j;    // Von hinten nach vorne vergleichen:
         while( ki > i && kj >= 0 && pattern[ki] == pattern[kj] )
            --ki, --kj;

         if( kj < 0 || ( ki == i && pattern[kj] != pattern[i]) )
           break;                  // gefunden! ( => j >= 0 )
      }
      deltaTable2[i] = (j>=0) ? last-j : len;  // Abstand des Vorgängers
   }                                           // vom Suffix.
}

void StringMatching::print() const // Suchstring und 
{                                  // Entfernungstabellen anzeigen. 
   int i, len = pattern.length();

   cout << pattern << "\n---------------------" << endl;
   for( i = 0; i <= UCHAR_MAX; ++i)
      if( deltaTable1[i] != len)
        cout << (char)i << " : " << deltaTable1[i] << endl;

   cout << "---------------------" << endl;
   for( i = 0; i < len; ++i)
      cout << deltaTable2[i] << ' ';
   cout << endl;
}

int StringMatching::findIn( const string& text, int start) const
{
   int i, j, code, shift1, shift2, shift,
       len = pattern.length();

   if( len == 0) return 0;

   for( i = start;  i <= (int)text.length() - len;  i += shift)  
   {
     cout.width(i+len);                  // Nur zu Testzwecken!
     cout << pattern << endl;            // 
     cout << text << endl;               // 

     j = len-1;            // Vergleicht letztes Zeichen zuerst.
     while( j >= 0 && text[i+j] == pattern[j])
       --j;

     if( j == -1)          // Suchstring gefunden!
         return i;
     else                  // Falls nicht gefunden, "schiebe" 
     {                     // den Suchstring nach rechts.
        code = (unsigned char)text[i+j];       // Zeichen-Code
        shift1 = deltaTable1[code] - (len-1-j);
        shift2 = deltaTable2[j];
        shift = shift1 > shift2 ? shift1 : shift2;
     }
   }

   return -1;              // Nicht gefunden!
}
