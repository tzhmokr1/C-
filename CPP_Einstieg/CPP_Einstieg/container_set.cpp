#include <iostream>
#include <set>
#include <ctime>
using namespace std;

void ausgeben(set<int> &x)
{
   set<int>::iterator pos;
   for(pos = x.begin(); pos != x.end(); pos++)
      cout << *pos << " ";
   cout << endl;
}

int main()
{
   set<int> s;

   srand((unsigned)time(NULL));
   cout << "insert():      ";
   for(int i=0; i<8; i++)
   {
      int zz = rand() % 6 + 1;
      cout << zz << " ";
      s.insert(zz);
   }
   cout << endl;
   cout << "set:           ";
   ausgeben(s);

   cout << "count(6):      " << s.count(6) << endl;

   if(s.find(3) != s.end())
      cout << "find():        3" << endl;
   if(s.find(4) != s.end())
      cout << "find():        4" << endl;

   set<int>::iterator pos;
   pos = s.lower_bound(6);
   if(pos != s.end())
      cout << "lower_bound(): "  << *pos << endl;
   pos = s.upper_bound(1);
   if(pos != s.end())
      cout << "upper_bound(): "  << *pos << endl;

   s.erase(3);
   s.erase(4);
   cout << "erase():       ";
   ausgeben(s);

   s.clear();
   cout << "clear():";
   ausgeben(s);
}

