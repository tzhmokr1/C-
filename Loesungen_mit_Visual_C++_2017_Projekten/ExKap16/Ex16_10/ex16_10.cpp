// --------------------------------------------------------
// ex16_10.cpp 
// Berechnet das Pascalsche Dreieck.
// --------------------------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;

#define MAX 16

int main()
{
   unsigned matrix[MAX][MAX] = {0};
   int i,j;

   cout << "\t\t  ****  Pascalsches Dreieck  ****\n" << endl;

   matrix[0][0] = matrix[1][0] = matrix[1][1] = 1;
   for(i = 2; i < MAX; ++i)    // Pascal's Dreieck berechnen:
   {
      matrix[i][0] = 1;
      for(j = 1; j <= i; ++j)
         matrix[i][j] = matrix[i-1][j-1] + matrix[i-1][j];
   }
                               // Pascal's Dreieck ausgeben:
   for( i = 0; i < MAX; i++)
   {
       for(j = 0; j < i+1; j++)
       {
           cout << setw(5) << matrix[i][j];
       }
       cout << endl;
   }
   return 0;
}
