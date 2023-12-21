// --------------------------------------------------------
// ex08_03.cpp
// Was gibt das Programm auf dem Bildschirm aus?
// --------------------------------------------------------
#include <iostream>
using namespace std;

#define square(x) ((x)*(x))

int main()
{
   float x = (float)square(0.1);
   cout << x << endl;

   int n = (int)square( 0.9);
   cout << n <<  endl;

   char m = (char)square(16);
   cout << m + 1 << endl;

   return 0;
}
