// ---------------------------------------------------------
// myString.cpp
// Implementierung der Klasse MyString
// ---------------------------------------------------------
#include "myString.h"
#include <ctype.h>        // Deklaration toupper(), tolower()

MyString MyString::toUpper() const
{
    MyString str(*this);
    for( unsigned int i=0; i < str.length(); ++i)
        str[i] = ::toupper(str[i]);
    return str;
}

MyString MyString::toLower() const
{
    MyString str(*this);
    for( unsigned int i=0; i < length(); ++i)
        str[i] = tolower(str[i]);
    return str;
}

MyString MyString::center( int w, char fc) const
{
    int len = length();
    if( len >= w)
       return *this;
    else
    {
       int space = (w - len)/2;     // Anzahl Fuellzeichen
       MyString str( space, fc);
       str += *this;
       str += MyString( w - (space + len), fc);
       return str;
    }
}

int MyString::eraseLeadingWS()
{
    string& s = *this;       // Als Abkürzung
    unsigned int i = 0;
    while( i < length() && isspace(s[i]) )
        ++i;
    if( i > 0)
        s.erase( 0, i);      // i Zeichen ab Position 0 loeschen
    return i;
}

int MyString::eraseTrailingWS()
{
    string& s = *this;              // Als Abkürzung.
    unsigned int i = length() -1;   // Index des letzten Zeichens.
    while( i >= 0 && isspace(s[i]) )
        --i;
    if( i < length() )
        s.erase(i+1);        // Ab Position 0 den Rest loeschen.
    return i;
}

