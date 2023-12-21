// -------------------------------------------------------
// autoPtr.h
// Definition der Klassen Demo und AutoPtr.
// -------------------------------------------------------
#ifndef _AUTOPTR_
#define _AUTOPTR_

#include <iostream>          // Deklaration von cerr
#include <string>            // Klasse string
#include <cstdlib>           // Prototyp exit()
using namespace std;

// -------------------------------------------------------
// Definition der Klasse Demo
class Demo
{
    string name;
  public:
    Demo(const string& n)               // Konstruktor 
    {  
       name = n;
       cout << "Neues Objekt " << name << endl;
    }
    ~Demo()                             // Destruktor
    {  cout << "Objekt " << name << " zerstoert!" << endl; }
    const string& getName() const {  return name;  } 
};

// -------------------------------------------------------
// Definition der Klasse AutoPtr
class AutoPtr
{
  private:
    Demo* ptrObj;
    AutoPtr( const AutoPtr& a);    // Keine Kopien zulassen.

  public:
    AutoPtr( Demo* p = NULL) : ptrObj(p) {}
    ~AutoPtr() { delete ptrObj; }

    Demo* get() const { return ptrObj; }
    Demo* release() 
    {
       Demo* ptr = ptrObj;
       ptrObj = NULL;
       return ptr; 
    }

    Demo& operator*() const
    {
       if( !ptrObj)
       { cerr << "AutoPtr::operator* : Kein Objekt!" << endl;
         exit(100);
       }
       return *ptrObj;
    }

    Demo* operator->() const 
    {
       if( !ptrObj)
       { cerr << "AutoPtr::operator-> : Kein Objekt!" << endl;
         exit(101);
       }
       return ptrObj;
    }

    AutoPtr& operator=(Demo* p)
    {
       if( ptrObj)
       { cerr << "AutoPtr::operator= : Unzulaessig!" << endl;
         exit(102);
       }
       ptrObj = p;
       return *this;
    }

    AutoPtr& operator=(AutoPtr& a)
    {
       if( ptrObj)
       { cerr << "AutoPtr::operator= : Unzulaessig!" << endl;
         exit(103);
       }
       ptrObj = a.ptrObj;
       a.ptrObj = NULL;
       return *this;
    }
};

#endif   // _AUTOPTR_
