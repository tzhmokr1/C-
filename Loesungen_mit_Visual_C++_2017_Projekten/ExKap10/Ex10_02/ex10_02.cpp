// --------------------------------------------------------
// ex10_02.cpp 
// Definiert (und testet) die Funktion isLetter(), 
// die prüft, ob ein Zeichen ein Buchstabe ist.
//-------------------------------------------------------

#include <iostream>
using namespace std;

bool isLetter( char c);     // Prototyp

int main()
{
   char c;

   cout << "\nGeben Sie ein Zeichen ein:" << endl;
   while( cin.get(c) && c != '\n')
   {
       if( isLetter(c))
           cout << c << " : Buchstabe" << endl;
       else
           cout << c << " : Kein Buchstabe" << endl;
   }
   return 0;
}

// ------------ Funktion isLetter() ------------
#include <cctype>
using namespace std;

bool isLetter( char c)
{
   return ( islower((unsigned char)c) || isupper((unsigned char)c) );
}
/*
// oder:
bool isLetter( char c)
{
   return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

// oder:
bool isLetter( char c)
{
   return (toupper(c)>= 'A' && toupper(c)<= 'Z');
}
*/
