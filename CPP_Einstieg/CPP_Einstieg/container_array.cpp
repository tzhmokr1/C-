#include <iostream>
#include <array>
using namespace std;

void ausgeben(array<int,5> &x)
{
   array<int,5>::iterator position;
   for(position = x.begin(); position != x.end(); position++)
      cout << *position << " ";
   cout << endl;
}

int main()
{
   array<int,5> a;

   for(unsigned int i=0; i<a.size(); i++)
      a.at(i) = 10 * (i+1);
   cout << "at():       ";
   ausgeben(a);

   int wert = 11;
   for(int &z:a)
   {
      z = wert;
      wert += 10;
   }
   cout << "for:        ";
   ausgeben(a);

   array<int,5> b;
   b = a;
   cout << "Zuweisung:  ";
   ausgeben(b);

   b.fill(42);
   cout << "fill():     ";
   ausgeben(b);

   array<int,5> c;
   c = {15, 12, 19, 16, 11};
   b.swap(c);
   cout << "swap():     ";
   ausgeben(b);

   array<int,5> d;
   d = {15, 12, 19, 16, 11};
   if(d == b)
      cout << "array-Felder sind gleich" << endl;
   if(d != c)
      cout << "array-Felder sind ungleich" << endl;
}

