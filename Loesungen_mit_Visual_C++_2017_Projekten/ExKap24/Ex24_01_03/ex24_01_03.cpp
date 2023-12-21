// ------------------------------------------------------
// ex24_01_03.cpp
// ------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

class Base
{
  protected:
    int id;
  public:
    Base(int i=0) : id(i) {}
    void modify() { cout << "Aufruf fuer Klasse Base\n"; } 
    void print() const
    { cout << "Klasse Base:\nID = " << id << endl; }
};

class Derived : public Base
{
    string name;
  public:
    Derived(int id = 0, const string& s = "XXX")
    : Base(id), name(s) {}

    void modify() { cout << "Aufruf fuer Klasse Derived\n"; } 
    void print() const
    { cout << "Klasse Derived:\n"
           << "ID = " << id << "Name: " << name << endl; }
};

int main()
{
   cout << "\n --- Aufgabe 24.1 --- " << endl;
// a)
   Base bObj(0); Derived dObj(10203);
   bObj = dObj;                     // Korrekt

// b)
   Base bObj2(11234); Derived dObj2;
// dObj2 = bObj2;                   // Fehler

// c)
   Derived dObj3( 43210, "Shirt");
   void func( const Base& bObj);
   func( dObj3);                    // Korrekt

// d)
// Derived* ptr;
// ptr = new Base(9876);            // Fehler

   cout << "\n --- Aufgabe 24.2 --- " << endl;
// a)
   dObj.modify();

// b)
   Base& bRef = dObj;
   bRef.modify();

// c)
   Derived *dPtr = &dObj;
   dPtr->modify();

// d)
   Base* bPtr = dPtr;   // dPtr ist in c) definiert.
   bPtr->modify();

   cout << "\n --- Aufgabe 24.3 --- " << endl;
// a)
   dObj.Base::modify();

// b)
   ((Derived&)bRef).modify();
   // oder:
   static_cast<Derived&>(bRef).modify();

// c)
   dPtr->Base::modify();
   // oder:
   ((Base*)dPtr)->modify();
   // oder:
   static_cast<Base*>(dPtr)->modify();

// d)
   ((Derived*)bPtr)->modify();
   // oder:
   static_cast<Derived*>(bPtr)->modify();
   // oder dPtr verwenden:
   dPtr->modify();

   return 0;
}

void func( const Base& bObj) { bObj.print(); } // Für Uebung 24.1