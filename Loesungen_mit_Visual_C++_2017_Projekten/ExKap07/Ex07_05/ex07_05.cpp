// -------------------------------------------------------
// ex07_05.cpp
// Testet den Standard-Makro assert().
// -------------------------------------------------------

#include <iostream>
#include <cassert>
using namespace std;

int main()
{
   int n = 0;

   cout << "Geben Sie eine Ganzzahl ein: ";
   cin >> n;

   assert(n > 0 && n < 10);

   cout << "Alles okay!" << endl;

   return 0;
}
