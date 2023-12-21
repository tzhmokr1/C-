// --------------------------------------------------------
// ex05_09.cpp
// Was gibt das C++-Programm auf dem Bildschirm aus? 
// --------------------------------------------------------
#include <iostream>
using namespace std; 

int main()
{
   int i(-5), j(2); 
   bool flag(false); 

   cout << boolalpha; 
   cout << (i > j && !flag) << endl; 
   cout << (j < -i && j > i || flag) << endl; 
   cout << (!flag && i + j > 0) << endl; 
   cout << (i + j <= j - i) << endl; 

   return 0; 
}
