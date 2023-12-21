// --------------------------------------------------------
// ex04_06.cpp
// Was gibt das C++-Program auf dem Bildschirm aus? 
// --------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
   cout.fill('*');

   cout.width(4);  cout << 9    << endl;
   cout.width(4);  cout << 99   << endl;
   cout.width(4);  cout << "+++++" << endl 
                        << 108  << endl;
   return 0;
}
