// --------------------------------------------------------
// ex08_04.cpp
// Welcher Wert wird der Variablen z zugewiesen?
// --------------------------------------------------------
#include <iostream>
using namespace std;
#include <climits>

int main()
{
    cout << showbase << hex;
// a)
    {
      long  n = 0x54321;
      short z = (short)n; 
      cout << z << endl;
    }
// b)
    {
      long  n = -1;
      unsigned short z = (unsigned short)n; 
      cout << z << endl;
    }

// c)
    {
      double x = 1.6;
      int z = (int)x; 
      cout << z << endl;
    }

    return 0;
}
