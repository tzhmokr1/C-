// Mit GCC 7.1: g++ -std=c++17 beta.cpp -o beta
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
   for(int n=1; n<10; n++)
   {
      cout << string(20-n*2, ' ');
      for(int k=1; k<n; k++)
         cout << setw(3) << 1 / ((n+1) * beta(n-k+1, k+1)) << " ";
      cout << endl;
   }
}
