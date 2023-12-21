// ------------------------------------------------------
// ex23_01.cpp
// Was gibt das folgende Programm auf den Bildschirm aus?
// ------------------------------------------------------
#include <iostream>
using namespace std;

class B
{
  public:
    B() { cout << "Konstruktor der Klasse B\n";}
    ~B(){ cout << "Destruktor der Klasse B\n";}
};
 
class D : public B
{
  public:
    D() { cout << "Konstruktor der Klasse D\n"; }
    ~D(){ cout << "Destruktor der Klasse D\n"; }
};

class X
{
  private:
    D d;
  public:
    X() { cout << "Konstruktor der Klasse X\n"; }
    ~X(){ cout << "Destruktor der Klasse X\n"; }
};

int main()
{
   X x;
   cout << "Bye, bye!" << endl;
   return 0;
}
