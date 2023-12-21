#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void ausgeben(vector<int> &x)
{
   vector<int>::iterator position;
   for(position = x.begin(); position != x.end(); position++)
      cout << *position << " ";
   cout << endl;
}

int main()
{
   vector<int> va = {3, 18, 5, 17, 12};
   vector<int> vb = {19, 3, 8, 17};
   vector<int> v1, v2, v3, v4, v5;

   sort(va.begin(), va.end());
   cout << "Menge A:      ";
   ausgeben(va);

   sort(vb.begin(), vb.end());
   cout << "Menge B:      ";
   ausgeben(vb);

   merge(va.begin(), va.end(),
      vb.begin(), vb.end(), inserter(v1, v1.begin()));
   cout << "merge():      ";
   ausgeben(v1);

   if(includes(v1.begin(), v1.end(), va.begin(), va.end()))
      cout << "includes:     Ja" << endl;
   cout << endl;

   set_intersection(va.begin(), va.end(),
      vb.begin(), vb.end(), inserter(v2, v2.begin()));
   cout << "set_inter..:  ";
   ausgeben(v2);

   set_union(va.begin(), va.end(),
      vb.begin(), vb.end(), inserter(v3, v3.begin()));
   cout << "set_union():  ";
   ausgeben(v3);

   set_difference(va.begin(), va.end(),
      vb.begin(), vb.end(), inserter(v4, v4.begin()));
   cout << "set_diff...:  ";
   ausgeben(v4);

   set_symmetric_difference(va.begin(), va.end(),
      vb.begin(), vb.end(), inserter(v5, v5.begin()));
   cout << "set_symm...:  ";
   ausgeben(v5);
}
