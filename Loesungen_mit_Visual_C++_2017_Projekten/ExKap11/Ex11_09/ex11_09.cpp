// ------------------------------------------------
// ex11_09.cpp
// Gibt die Werte verschiedener gleichnamiger
// Variablen aus.
// ------------------------------------------------
#include <iostream>
using namespace std;

int n = 5;
namespace A
{
   int n = 9;
}

int main()
{
   int n = 3;

   cout << n << endl;
   cout << ::n << endl;
   cout << A::n << endl;

   return 0;
}
