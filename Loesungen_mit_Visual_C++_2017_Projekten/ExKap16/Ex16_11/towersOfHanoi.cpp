// ------------------------------------------------------
// towersOfHanoi.cpp
// Definition der Methoden der Klasse TowersOfHanoi.
// ------------------------------------------------------
#include <iostream>
#include <iomanip>
#include "towersOfHanoi.h"
using namespace std;

TowersOfHanoi::TowersOfHanoi( int n) 
{ 
   if( n > MAX_DISKS)  n = MAX_DISKS;
   nDisks[0] = nTotal = n;
   nDisks[1] = nDisks[2] = 0;

   for( int j = 0; j < n; ++j)  // tower[0] mit n Scheiben:
      tower[0][j] = n-j;        // n kennzeichnet die größte, 
}                               // 1 die kleinste Scheibe.

bool TowersOfHanoi::move( int from, int to)
{
   if( from == to || from < 0 || from > 2 
                  || to < 0   || to > 2)
      return false;

   if( nDisks[from] == 0)       // tower[from] ist leer
      return false;

   int jf = nDisks[from] - 1,   // Index der letzten Scheibe 
                                // auf tower[from].
       jt = nDisks[to] - 1;     // Index der letzten Scheibe
                                // auf tower[to].

   if( nDisks[to] > 0  &&  tower[from][jf] > tower[to][jt])
      return false;
   else                         // Scheibe transferieren:
   {
      tower[to][jt+1] = tower[from][jf];
      --nDisks[from];
      ++nDisks[to];
      return true;
   }
}

void TowersOfHanoi::display()
{
    cout << endl;
    for( int j = nTotal-1;  j >= 0;  --j)
    {
       for( int i = 0; i < 3; ++i)
          if( j < nDisks[i])
             cout << setw(10) << tower[i][j];
          else
             cout << setw(10) << '|';
       cout << endl;
    }
    cout << "----------------------------------------\n"
         << "        (1)       (2)       (3)" << endl;
}
