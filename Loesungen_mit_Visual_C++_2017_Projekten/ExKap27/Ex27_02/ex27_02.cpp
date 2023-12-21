#include <iostream>
using namespace std;

class X
{  public:
     X(){cout <<"Konstruktor von X" << endl; } 
};

class Base1 : public X
{  public:
     Base1(){cout <<"Konstruktor von Base1" << endl; } 
};

class Base2 : public X
{  public:
     Base2(){cout << "Konstruktor von Base2" << endl; } 
};

class Derived : public Base1, public Base2
{  public:
     Derived(){cout <<"Konstruktor von Derived\n"; } 
};
class DDerived : public Derived
{  public:
     DDerived(){cout << "Konstruktor von DDerived\n"; } 
};

int main()
{
   DDerived dd;
   return 0;
}
