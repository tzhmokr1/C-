#include <iostream>
#include <stack>
using namespace std;

int main()
{
   stack<int> s;

   for(int i=0; i<5; i++)
      s.push(10 * (i+1));

   while(!s.empty())
   {
      cout << s.top() << " ";
      s.pop();
   }
   cout << endl;
}

