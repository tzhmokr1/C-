#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
   const int FINGER = 5;
   // FINGER = 6;
   cout << "Finger: " << FINGER << endl;

   const double PI = 3.1415926;
   double radius = 3.8;
   double kreisUmfang = 2 * PI * radius;

   cout << fixed << setprecision(3);
   cout << "Kreisumfang: " << kreisUmfang << endl;
}

