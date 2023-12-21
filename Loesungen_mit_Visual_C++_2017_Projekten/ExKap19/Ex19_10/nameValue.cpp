// ---------------------------------------------------------
// nameValue.cpp
// Definiert die Methoden der Klasse NameValueArr.
// ---------------------------------------------------------
#include <iostream>
#include "nameValue.h"
using namespace std;

// --- Implementiert die Methoden der Klasse NameValueArr: ---
 
NameValueArr& NameValueArr::operator+=( const string& str)
{
   int pos = str.find("=");
   if( pos != string::npos && pos > 0)
   {
      int len = str.length();
      NameValue nv;
      nv.name = string( str, 0, pos);
      ++pos;
      nv.value = string( str, pos, len-pos);
      *this += nv;
   }
   return *this;
}

NameValue& NameValueArr::operator[]( int i)
{
   static NameValue empty;
   if( i < count)
      return pairs[i];
   else
      return empty;
}

const NameValue& NameValueArr::operator[]( int i) const
{
   static NameValue empty;
   if( i < count)
      return pairs[i];
   else
      return empty;
}

string NameValueArr::operator[]( const string& name) const
{
   for( int i=0; i < count; ++i)
       if( pairs[i].name == name)
           return pairs[i].value;
   
   return string();
}

// --- Überlädt die Operatoren << und >> zur Stream I/O ---
 
ostream& operator<<(ostream& os, const NameValueArr& nvArr)
{
    for( int i=0; i < nvArr.getCount(); ++i)
        cout << nvArr[i].toString() << endl;
    return os;
}

istream& operator>>(istream& is, NameValueArr& nvArr)
{
    string line;
    if( getline( is, line))
        nvArr += line;
    return is;
}
