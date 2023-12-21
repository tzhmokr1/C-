// --------------------------------------------------------
// ex12_04.cpp
// Korrigieren Sie den Fehler in folgender Definition.
// --------------------------------------------------------
#include <string>
#include <cctype>
using namespace std;

const string& strToUpper( const string& s1)
{
   static string s2;
   s2 = "";

   s2.reserve(s1.length());
   for( unsigned int i = 0; i < s1.length(); ++i)
      s2 += toupper(s1[i]);

   return s2;
}

#include <iostream>
int main()
{
    string msg("Hello, World!");
    cout << msg << endl;

    string MSG = strToUpper(msg);  
    cout << MSG << endl;

    // Zweiter Aufruf von strToUpper():
    MSG = strToUpper("How're you?");  
    cout << MSG << endl;

    return 0;
}
