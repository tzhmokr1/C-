#include <iostream>
#include <vector>
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
   vector<int> v;
   vector<int>::iterator position;

   v.resize(3);
   for(unsigned int i=0; i<v.size(); i++)
      v.at(i) = 10 * (i+1);
   cout << "at():        ";
   ausgeben(v);

   for(int i=0; i<3; i++)
      v.push_back(4 * (i+1));
   cout << "push_back(): ";
   ausgeben(v);

   v.pop_back();
   cout << "pop_back():  ";
   ausgeben(v);

   cout << "insert():    ";
   position = v.begin() + 1;
   if(position >= v.begin() && position < v.end())
   {
      v.insert(position, 77);
      ausgeben(v);
   }
   else
      cout << "Position nicht im vector-Feld" << endl;

   cout << "erase():     ";
   position = v.end() - 2;
   if(position >= v.begin() && position < v.end())
   {
      v.erase(position);
      ausgeben(v);
   }
   else
      cout << "Position nicht im vector-Feld" << endl;

   v.clear();
   cout << "clear():";
   ausgeben(v);

   v = {19, 18, 17};
   cout << "Neue Werte:  ";
   ausgeben(v);
}

