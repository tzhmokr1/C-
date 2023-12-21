#include <iostream>
using namespace std;
int main()
{
   double preis;
   cout << "Preis: ";
   cin >> preis;

   if(preis >= 1.0)
   {
      if(preis >= 2.0)
         cout << "sehr teuer" << endl;
      else
         cout << "teuer" << endl;
   }
   else
   {
      if(preis < 0.5)
         cout << "sehr preiswert" << endl;
      else
         cout << "preiswert" << endl;
   }

   if(preis < 0.5)
      cout << "sehr preiswert" << endl;
   else if(preis < 1.0)
      cout << "preiswert" << endl;
   else if(preis < 2.0)
      cout << "teuer" << endl;
   else
      cout << "sehr teuer" << endl;
}

