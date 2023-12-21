// --------------------------------------------------------
// ex05_04.cpp
// Was gibt das C++-Programm auf dem Bildschirm aus? 
// --------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
   int n(15);

   n += 25;   cout << n << endl; 
   n %= 9;    cout << n << endl;
   n = 5;     cout << n++ << endl;
   n *= n;    cout << n << endl;

   return 0;
}
