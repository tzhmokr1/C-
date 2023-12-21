#include <iostream>
using namespace std;
int main()
{
   int monat;
   cout << "Monat: ";
   cin >> monat;

   switch(monat)
   {
      case 1:
      case 2:
      case 3:
         cout << "1. Quartal" << endl;
         break;
      case 4:
      case 5:
      case 6:
         cout << "2. Quartal" << endl;
         break;
      case 7:
      case 8:
      case 9:
         cout << "3. Quartal" << endl;
         break;
      case 10:
      case 11:
      case 12:
         cout << "4. Quartal" << endl;
         break;
      default:
         cout << "Das ist kein Monat" << endl;
   }
}

