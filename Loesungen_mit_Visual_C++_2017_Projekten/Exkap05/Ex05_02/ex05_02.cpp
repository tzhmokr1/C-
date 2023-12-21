// -------------------------------------------------------
// ex05_02.cpp
// Das Pogramm liest drei Gleitpunktzahlen im Dialog ein
// und gibt ihre Summe und den Durchschnitt aus.
// -------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
   double x, y, z, result;

   cout<< endl;
   cout << "Geben Sie drei Gleitpunktzahlen ein: ";
   cin >> x >> y >> z;

   result = x + y + z;
   cout << "Die Summe:        " << result << endl;

   result /= 3;
   cout << "Der Durchschnitt: " << result << endl;

   return 0;
}
