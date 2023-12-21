#include <iostream>
using namespace std;
int main()
{
   int anzahl;

   do
   {
      cout << "Anzahl eingeben, min. 1, max. 10: ";
      cin >> anzahl;
   }
   while(anzahl < 1 || anzahl > 10);

   cout << "Anzahl: " << anzahl << endl;
}

