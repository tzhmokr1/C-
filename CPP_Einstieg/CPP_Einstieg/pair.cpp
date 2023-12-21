#include <iostream>
#include <string>
#include <utility>
using namespace std;

int main()
{
   pair<int,string> pa;
   pa = pair<int,string>(10, "Berlin");
   cout << get<0>(pa) << "/" << get<1>(pa) << endl;

   pair<int,string> pb;
   pb = make_pair(20, "Hamburg");
   pb.swap(pa);
   cout << pa.first << "/" << pa.second << endl;

   pair<int,string> pc;
   pc = pb;
   cout << pc.first << "/" << pc.second << endl;

   pair<int,string> pd;
   pd.first = 30;
   pd.second = "Dortmund";
   cout << pd.first << "/" << pd.second << endl;
}
