#include <iostream>
using namespace std;
int main()
{
   #ifdef __unix
      cout << "Unix" << endl;
   #elif _WIN32
      cout << "Win32" << endl;
   #endif
}

