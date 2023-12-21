#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
   for(int i=1; i<=5; i++)
   {
      for(int k=1; k<=10; k++)
         cout << setw(3) << i*k;
      cout << endl;
   }
}

