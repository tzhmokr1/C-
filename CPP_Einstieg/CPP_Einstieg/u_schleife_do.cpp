#include <iostream>
using namespace std;
int main()
{
   int zahl, anzahl = 0;

   do
   {
      cout << "Ungerade Zahl zwischen 50 und 60 eingeben: ";
      cin >> zahl;
      anzahl++;

      if(zahl < 50)
         cout << "Zahl ist zu klein" << endl;
      if(zahl > 60)
         cout << "Zahl ist zu gross" << endl;
      if(zahl%2 == 0)
         cout << "Zahl ist gerade" << endl;
   }
   while(zahl < 50 || zahl > 60 || zahl%2 == 0);
   
   cout << "Ihre Zahl: " << zahl << endl;
   cout << "Das waren " << anzahl << " Versuche" << endl;
}

