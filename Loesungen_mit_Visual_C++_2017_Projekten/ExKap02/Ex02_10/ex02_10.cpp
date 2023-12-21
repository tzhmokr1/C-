// ---------------------------------------------------------
// ex02_10.cpp
// Was gibt das folgende C++-Programm aus?
// ---------------------------------------------------------
#include <iostream>
using namespace std;

void test(void);
int x = 10;

int main()
{
   test();
   cout << "Der Wert von x in main() ist "
        << x << endl;
   return 0;
}
void test()
{
   cout << "Der Wert von x in test() ist " 
        << x << endl;
   x = x + 10;
}
