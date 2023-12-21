#include <iostream>
#include <deque>
using namespace std;

void ausgeben(deque<int> &x)
{
   deque<int>::iterator position;
   for(position = x.begin(); position != x.end(); position++)
      cout << *position << " ";
   cout << endl;
}

int main()
{
   deque<int> d;
   deque<int>::iterator position;

   for(int i=0; i<3; i++)
      d.push_back(10 * (i+1));
   cout << "push_back():  ";
   ausgeben(d);

   for(int i=0; i<3; i++)
      d.push_front(11 * (i+1));
   cout << "push_front(): ";
   ausgeben(d);

   cout << "back():       " << d.back() << endl;
   cout << "front():      " << d.front() << endl;

   d.pop_back();
   cout << "pop_back():   ";
   ausgeben(d);

   d.pop_front();
   cout << "pop_front():  ";
   ausgeben(d);

   cout << "insert():     ";
   position = d.begin() + 1;
   if(position >= d.begin() && position < d.end())
   {
      d.insert(position, 77);
      ausgeben(d);
   }
   else
      cout << "Position nicht in der Deque" << endl;

   cout << "erase():      ";
   position = d.end() - 2;
   if(position >= d.begin() && position < d.end())
   {
      d.erase(position);
      ausgeben(d);
   }
   else
      cout << "Position nicht in der Deque" << endl;

   d.resize(d.size() + 1);
   d.at(d.size() - 1) = 99;
   cout << "at():         ";
   ausgeben(d);

   d.clear();
   cout << "clear():";
   ausgeben(d);
   
   d = {19, 18, 17};
   cout << "Neue Werte:   ";
   ausgeben(d);
}

