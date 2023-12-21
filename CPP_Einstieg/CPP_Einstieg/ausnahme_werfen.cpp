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
         if(position < 0)
            throw 1;
         if(position > 100)
            throw 2;
         s.at(position) = 'X';
         fehler = false;
      }
      catch(int i)
      {
         if(i==1)
            cout << "Fehler: Position ist negativ" << endl;
         else if(i==2)
            cout << "Fehler: Position ist > 100" << endl;
      }
      catch(exception &e)
      {
         cout << "Fehler: " << e.what() << endl;
      }
   }
   while(fehler);

   cout << s << endl;
}

