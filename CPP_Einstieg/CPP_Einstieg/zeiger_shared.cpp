#include <iostream>
#include <memory>
using namespace std;
int main()
{
   shared_ptr<int> z1(new int);
   *z1 = 42;

   shared_ptr<int> z2(z1);
   cout << "Variable: " << *z1 << endl;
   cout << "Variable: " << *z2 << endl;
}

