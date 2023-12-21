// ------------------------------------------------------
// ex25_01_03.cpp
// ------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

class A
{
  public:
    ~A() { cout << "Destuktor der Klasse A" << endl; }
    virtual string toString() const
    {  return string("Class A"); }
};

class B : public A
{
  protected: 
    double x;
  public:
    B(double xx = 0.0) : x(xx) {}
    virtual ~B() { cout << "Destuktor der Klasse B" << endl; }
    virtual double calc() const { return x+1.0; }
};

class C : public B
{
  public:
    C(double x = 1.0) : B(x) {}
    ~C() { cout << "Destuktor der Klasse C" << endl; }
    virtual string toString() const
    {  return string("Class C"); }
    virtual double calc() const { return x+10.0; }
};


int main()
{
  {
    cout << "\n --- Aufgabe 25.1 --- " << endl;
    B bObj;
    C cObj;
// a)
    A* ptr1 = &bObj;
    cout << ptr1->toString() << endl;
// b)
    B* ptr2 = &cObj;
    cout << ptr2-> toString() << endl;
// c)
    A* ptr3 = &cObj;
    cout << ptr3-> toString() << endl;
  }

    cout << "\n --- Aufgabe 25.2 --- " << endl;
// a)
    A*ptr1 = new C; 
    delete ptr1;
    cout << endl;
// b)
    B *ptr2 = new C; 
    delete ptr2;
    cout << endl;
// c)
    A *ptr3 = new B; 
    delete ptr3;

    cout << "\n --- Aufgabe 25.3 --- " << endl;
    A*ptr = new C; 
    double res = 0;
    B* ptrB = dynamic_cast<B*>(ptr);
    if( ptrB)
      res = ptrB->calc();
    else
      cout << "Kein Objekt der Klassen B oder C" << endl; 
    cout << "Ergebnis = " << res << endl;

    return 0;
}
