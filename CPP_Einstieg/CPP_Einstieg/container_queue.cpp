#include <iostream>
#include <queue>
using namespace std;

int main()
{
   queue<int> q;

   for(int i=0; i<5; i++)
      q.push(10 * (i+1));

   while(!q.empty())
   {
      cout << q.front() << " ... " << q.back() << endl;
      q.pop();
   }
}
