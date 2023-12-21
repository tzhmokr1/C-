// --------------------------------------------------------
// ex08_09.cpp
// Was gibt das folgende Programm auf dem Bildschirm aus?
// --------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
   int n = 1, m = 2;

   cout << n/m << endl;
   cout << (double)n/m   << endl;
   cout << (double)(n/m) << endl;
   cout << n / (double)m << endl;

   return 0;
}
