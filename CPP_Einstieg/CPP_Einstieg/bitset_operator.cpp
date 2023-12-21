#include <iostream>
#include <bitset>
using namespace std;
 
int main()
{
   bitset<8> b(12);
   cout << "b:       " << b << endl;

   bitset<8> c;
   c = b << 2;
   cout << "b << 2:  " << c << endl;
   c = b >> 2;
   cout << "b >> 2:  " << c << endl;

   b <<= 2;
   cout << "b <<= 2: " << b << endl;
   b >>= 2;
   cout << "b >>= 2: " << b << endl << endl;

   bitset<8> d(24);
   cout << "b:       " << b << endl;
   cout << "d:       " << d << endl;

   bitset<8> e;
   e = b & d;
   cout << "b & d    " << e << endl;

   e = b | d;
   cout << "b | d    " << e << endl;

   e = b ^ d;
   cout << "b ^ d    " << e << endl;

   e = ~b;
   cout << "~b       " << e << endl;
}
