#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void ausgebenZeichen(const char &c)
{
   cout << c << " ";
}

int main()
{
   string s = "Hallo Welt";

   cout << "for_each():  ";
   for_each(s.begin(), s.end(), ausgebenZeichen);
   cout << endl;

   if(find(s.begin(), s.end(), 'W') != s.end())
      cout << "find():      Ja" << endl;

   cout << "count():     "
      << count(s.begin(), s.end(), 'l') << endl;

   string sZwei = "Guten Morgen";
   swap(s, sZwei);
   cout << "swap:        " << s << endl;

   replace(s.begin(), s.end(), 'e', 'E');
   cout << "replace():   " << s << endl;

   rotate(s.begin(), s.begin() + 1, s.end());
   cout << "rotate():    " << s << endl;
}
