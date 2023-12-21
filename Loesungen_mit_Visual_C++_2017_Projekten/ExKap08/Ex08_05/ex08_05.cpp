// -----------------------------------------------------------
// ex08_05.cpp
// Bestimmen Sie die Typumwandlungen in folgenden Anweisungen:
// -----------------------------------------------------------
#include <iostream>
#include <climits>
using namespace std;

int main()
{
// a)
   unsigned char c = 255;
   cout << c + 1 << endl;

// b)
   int n = INT_MIN;
   cout << n - 1.0 << endl; 

   return 0;
}
