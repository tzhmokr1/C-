// ------------------------------------------------------
// ex15_01.cpp
// Was gibt folgendes Programm auf dem Bildschirm aus?
// ------------------------------------------------------
#include <iostream>
using namespace std;

class A
{
   public:
      A(){ cout << "Ich bin der Konstruktor von A\n";}
};
 
class B
{
   private:
      A a;
   public:
      B(){ cout << "Ich bin der Konstruktor von B\n"; }
};

class C
{
   private:
    B b;
    A a;
   public:
      C(){ cout << "Ich bin der Konstruktor von C\n"; }
};

int main()       
{
   C c;
   cout << "Bye, bye!" << endl;
   return 0;
}
