// ---------------------------------------------------------
// myString.h
// Definition der Klasse MyString
// ---------------------------------------------------------
#ifndef _MYSTRING_
#define _MYSTRING_

#include <string>
using namespace std;

class MyString : public string
{
  public:
   MyString() {}

   MyString( const string& str, size_type pos = 0, size_type n = npos)
   : string(str, pos, n) {}

   MyString( size_type n, char c) : string(n,c) {}

   MyString toUpper() const;
   MyString toLower() const;
   MyString center( int width, char fc=' ')  const;
   int eraseLeadingWS();
   int eraseTrailingWS();
};

#endif  // _MYSTRING_
