// ------------------------------------------------------
// towersOfHanoi.cpp
// Implementiert die Methoden der Klasse TowersOfHanoi.
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

   for( int j = 0; j < n; ++j)  // tower[0] mit n Scheiben
      tower[0][j] = n-j;        // n : die groesste Scheibe,
}                               // 1 : die kleinste Scheibe.

bool TowersOfHanoi::move( int from, int to)
{
   if( from == to || from < 0 || from > 2 
                  || to < 0   || to > 2)
      return false;

   if( nDisks[from] == 0)       // Keine Scheibe auf tower[from]
      return false;

   int jf = nDisks[from] - 1,   // Indizes der letzten Scheiben
       jt = nDisks[to] - 1;

   if( nDisks[to] > 0  &&  tower[from][jf] > tower[to][jt])
      return false;
   else
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
    for( int j = nTotal-1; j >= 0;  --j)
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

void TowersOfHanoi::moveTower( int nDisks, int from, int to)
{
   if( nDisks > 0)
   {
      int help = 0;                         // Bestimmt den dritten Index.
      while( help == from || help == to)
          ++help;
      moveTower( nDisks-1, from, help);
      move( from, to);                      // Bewegt die groesste Scheibe.
      display();
      cout << "Weiter mit Return "; cin.get();
      moveTower( nDisks-1, help, to);
   }
}
   
