#include <iostream>
using namespace std;
int main()
{
   int x = 5;
   cout << "int: " << x << endl;
   int &rx = x;
   cout << "Referenz auf int: " << rx << endl;
   auto y = rx;
   cout << "int: " << y << endl;
   decltype(auto) ry = rx;
   cout << "C++14, Referenz auf int: " << ry << endl << endl;
   
   const int k = 7;
   cout << "int-Konstante: " << k << endl;
   auto ka = k;
   cout << "int: " << ka << endl;
   decltype(auto) kb = k;
   cout << "C++14, int-Konstante: " << kb << endl;
}
