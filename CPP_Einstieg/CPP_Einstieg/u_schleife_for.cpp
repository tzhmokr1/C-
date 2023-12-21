#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
   double zahl;

   cout << "Zahl eingeben: ";
   cin >> zahl;

   cout << fixed << setprecision(3);
   for(int i=1; i<=5; i++)
      cout << setw(10) << i * zahl << endl;
}

