#include <iostream>
using namespace std;

auto summe(auto a, auto b)
{
   return a + b;
}

int main()
{
   cout << summe(4, 9) << endl;
   cout << summe(4.1, 9.6) << endl;

   string x = "Hallo", y = "Welt";
   cout << summe(x, y) << endl;
}
