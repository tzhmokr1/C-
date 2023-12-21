#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
   cout << RAND_MAX << endl;

   srand((unsigned int)time(0));
 
   for(int i=1; i<=10; i++)
      cout << rand() % 6 + 1 << " ";
   cout << endl;
}

