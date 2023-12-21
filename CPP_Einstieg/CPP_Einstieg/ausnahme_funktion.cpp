#include <iostream>
#include <string>
using namespace std;

void ausnahmeBehandeln()
{
   try
   {
      throw;
   }
   catch(exception &e)
   {
      cout << "Fehler: " << e.what() << endl;
   }
}

int main()
{
   string s = "Hallo Welt";
   int position;

   try
   {
      cout << "Position: ";
      cin >> position;
      s.at(position) = 'X';
   }
   catch(exception &e)
   {
      ausnahmeBehandeln();
   }

   cout << s << endl;
}

