#include <iostream>
#include <bitset>
using namespace std;
 
int main()
{
   bitset<8> b(12);

   cout << "Index:   ";
   for(int i=b.size()-1; i>=0; i--)
      cout << i;
   cout << endl;

   cout << "Werte:   ";
   for(int i=b.size()-1; i>=0; i--)
      cout << b.test(i);
   cout << endl;

   b.set(0);
   cout << "set():   ";
   cout << b << endl;

   b.flip(0);
   b.flip(1);
   cout << "flip():  ";
   cout << b << endl;

   b.reset(1);
   cout << "reset(): ";
   cout << b << endl << endl;

   cout << "all():   " << b.all() << endl;
   cout << "any():   " << b.any() << endl;
   cout << "none():  " << b.none() << endl;
   cout << "count(): " << b.count() << endl;
}
