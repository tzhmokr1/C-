#include <iostream>
#include <forward_list>
using namespace std;

void ausgeben(forward_list<int> &x)
{
   forward_list<int>::iterator position;
   for(position = x.begin(); position != x.end(); position++)
      cout << *position << " ";
   cout << endl;
}

int main()
{
   forward_list<int> f;
   forward_list<int>::iterator position;

   for(int i=0; i<5; i++)
      f.push_front(10 * (i+1));
   cout << "push_front():   ";
   ausgeben(f);

   f.pop_front();
   cout << "pop_front():    ";
   ausgeben(f);

   position = f.begin();
   f.insert_after(position, 77);
   cout << "insert_after(): ";
   ausgeben(f);

   position = f.begin();
   f.erase_after(position);
   cout << "erase_after():  ";
   ausgeben(f);
   cout << endl;

   f.sort();
   cout << "sort():         ";
   ausgeben(f);

   forward_list<int> fZwei = {10, 20, 60, 70};
   cout << "Andere Liste:   ";
   ausgeben(fZwei);
   f.merge(fZwei);
   cout << "merge():        ";
   ausgeben(f);
   cout << "Andere Liste:   ";
   ausgeben(fZwei);
   cout << endl;

   f.unique();
   cout << "unique():       ";
   ausgeben(f);
   
   fZwei = {10, 40, 40};
   cout << "Andere Liste:   ";
   ausgeben(fZwei);
   position = f.begin();
   position++;
   f.splice_after(position, fZwei);
   cout << "splice_after(): ";
   ausgeben(f);
   cout << "Andere Liste:   ";
   ausgeben(fZwei);
   cout << endl;

   f.remove(40);
   cout << "remove():       ";
   ausgeben(f);

   f.reverse();
   cout << "reverse():      ";
   ausgeben(f);

   f.clear();
   cout << "clear():";
   ausgeben(f);
}
