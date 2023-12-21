#include <iostream>
#include <string>
using namespace std;
int main()
{
   string s = "HALLO WELT";
   string::iterator position;

   position = s.begin();
   cout << "Beginn:  " << *position << endl;

   position++;
   cout << "++:      " << *position << endl;

   position = next(position,3);
   cout << "next(3): " << *position << endl;

   position -= 4;
   cout << "-= 4:    " << *position << endl;

   position = s.end();
   position = prev(position,1);
   cout << "Ende, dann prev(1): " << *position << endl;

   for(position=s.begin(); position!=s.end(); position++)
      cout << *position << " ";
   cout << endl;
}
