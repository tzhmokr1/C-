#include <iostream>
#include <list>
using namespace std;

void ausgeben(list<int> &x)
{
   list<int>::iterator position;
   for(position = x.begin(); position != x.end(); position++)
      cout << *position << " ";
   cout << endl;
}

int main ()
{
   list<int> L;
   list<int>::iterator position;

   for(int i=0; i<3; i++)
      L.push_front(10 * (i+1));
   cout << "push_front(): ";
   ausgeben(L);

   for(int i=0; i<3; i++)
      L.push_back(11 * (i+1));
   cout << "push_back():  ";
   ausgeben(L);

   L.pop_front();
   cout << "pop_front():  ";
   ausgeben(L);

   L.pop_back();
   cout << "pop_back():   ";
   ausgeben(L);

   position = L.begin();
   position++;
   cout << "insert():     ";
   L.insert(position, 77);
   ausgeben(L);

   position = L.end();
   position--;
   L.erase(position);
   cout << "erase():      ";
   ausgeben(L);
   cout << endl;

   L.sort();
   cout << "sort():       ";
   ausgeben(L);

   list<int> LZwei = {10, 20, 60, 70};
   cout << "Andere Liste: ";
   ausgeben(LZwei);
   L.merge(LZwei);
   cout << "merge():      ";
   ausgeben(L);
   cout << "Andere Liste: ";
   ausgeben(LZwei);
   cout << endl;

   L.unique();
   cout << "unique():     ";
   ausgeben(L);
   
   LZwei = {10, 40, 40};
   cout << "Andere Liste: ";
   ausgeben(LZwei);
   position = L.end();
   position--;
   L.splice(position, LZwei);
   cout << "splice():     ";
   ausgeben(L);
   cout << "Andere Liste: ";
   ausgeben(LZwei);
   cout << endl;

   L.remove(10);
   cout << "remove():     ";
   ausgeben(L);

   L.reverse();
   cout << "reverse():    ";
   ausgeben(L);

   L.clear();
   cout << "clear():";
   ausgeben(L);
}

