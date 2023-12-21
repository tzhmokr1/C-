#include <iostream>
#include <memory>
using namespace std;
int main()
{
   unique_ptr<int> zi;
   zi = make_unique<int>(42);
   cout << "Wert: " << *zi << endl;
}
