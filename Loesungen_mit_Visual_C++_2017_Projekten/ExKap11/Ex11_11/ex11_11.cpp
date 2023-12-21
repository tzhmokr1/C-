// --------------------------------------------------------
// ex11_11.cpp
// Verwenden von Namensbereichen.
// --------------------------------------------------------
namespace A
{
    double func( double a) { return ++a; }
}
namespace B
{
   double x = 1.1;
   namespace C
   {
      double y = 0.0;
      double func( double c) { return 2*c; };
   }
}

#include <iostream>
using namespace std;

int main()
{
   double x = 0.0;

   x = A::func(B::x);
   cout << "x = " << x << endl;

   B::x = B::C::func(x);
   cout << "B::x = " << B::x << endl;

   B::C::y = B::C::func(B::x);
   cout << "B::C::y = " << B::C::y << endl;

   return 0;
}
/*
// oder:
int main()
{
   using namespace B;
   double x = 0.0;

   x = A::func(B::x);
   cout << "x = " << x << endl;

   B::x = C::func(x);
   cout << "B::x = " << B::x << endl;

   C::y = C::func(B::x);
   cout << "B::C::y = " << B::C::y << endl;

   return 0;
}
*/
/*
// oder:
int main()
{
   using namespace B::C;
   double x = 0.0;

   x = A::func(B::x);
   cout << "x = " << x << endl;

   B::x = func(x);
   cout << "B::x = " << B::x << endl;

   y = func(B::x);
   cout << "B::C::y = " << B::C::y << endl;

   return 0;
}
*/