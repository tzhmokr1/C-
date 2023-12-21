// -------------------------------------------------------------
// nameValueArr.h
// Definiert die Struktur NameValue und die Klasse NameValueArr.
// -------------------------------------------------------------
#ifndef _NAMEVALUEARR_
#define _NAMEVALUEARR_

#include <string>
using namespace std;

struct NameValue
{
   string name, value;

   NameValue() {}
   NameValue(const string& n, const string& v)
   : name(n), value(v) {}
   string toString() const {  return name + "=" + value; }
};

#define ARR_SIZE 100

class NameValueArr
{
  private:
    NameValue pairs[ARR_SIZE];
    int count;

  public:
    NameValueArr() : count(0) {}
    int getCount() const { return count; }

    NameValueArr& operator+=( const NameValue& nv)
    {
       if( count < ARR_SIZE-1)
          pairs[count++] = nv;
       return *this;
    }
    NameValueArr& operator+=( const string& str);

    NameValue& operator[]( int i);
    const NameValue& operator[]( int i) const;
    string operator[]( const string& name) const;
};

// Prototypen globaler Operatorfunktionen:
ostream& operator<<(ostream& os, const NameValueArr& nvArr);
istream& operator>>(istream& is, NameValueArr& nvArr);

#endif  // _NAMEVALUEARR_
