#include <iostream>
using namespace std;
int main()
{
   int anzahl;
   cout << "Anzahl: ";
   cin >> anzahl;

   int rest = anzahl % 3;
   cout << "Rest bei Teilung durch 3: " << rest << endl;

   if(anzahl % 3 == 0)
      cout << anzahl << " ist durch 3 teilbar" << endl;
   else
      cout << anzahl << " ist nicht durch 3 teilbar" << endl;
}

