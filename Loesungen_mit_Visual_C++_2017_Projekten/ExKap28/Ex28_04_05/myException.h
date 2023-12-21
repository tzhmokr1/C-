// ----------------------------------------------
// myException.h : Von der Standardfehlerklasse 
// exception abgeleitete Fehlerklasse MyException
// ----------------------------------------------
#ifndef _MYEXCEPTION_ 
#define _MYEXCEPTION_

#include <string>
#include <exception>
using namespace std;

class MyException : public exception
{
    string m;
  public:
     MyException(const string& s) : m(s){ } 
     const char* what() const { return m.c_str(); }
};

#endif  // _MYEXCEPTION_
