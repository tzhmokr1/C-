#include <iostream>
#include <string>
using namespace std;

int main()
{
   string s = "Hallo Welt";
   bool fehler;
   int position;

   do
   {
      fehler = true;
      try
      {
         cout << "Position: ";
         cin >> position;
         s.at(position) = 'X';
         fehler = false;
      }
      catch(exception &e)
      {
         cout << "Fehler: " << e.what() << endl;
      }
   }
   while(fehler);

   cout << s << endl;
}

