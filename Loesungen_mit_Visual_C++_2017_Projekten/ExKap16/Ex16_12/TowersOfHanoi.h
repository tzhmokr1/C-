// ------------------------------------------------------
// towersOfHanoi.h
// Definiert die Klasse TowersOfHanoi.
// ------------------------------------------------------
#ifndef _TOWERSOFHANOI_
#define _TOWERSOFHANOI_

#include <iostream>
using namespace std;

#define MAX_DISKS  16

class TowersOfHanoi
{
  private:
    short tower[3][MAX_DISKS],     // Drei Türme
          nDisks[3],               // Akuelle Anzahl Scheiben pro Turm
          nTotal;                  // Gesamtzahl Scheiben

    void moveTower( int nDisks, int from, int to);

  public:
    TowersOfHanoi( int n); 
    
    bool isFinished()
    { return  nDisks[1] == nTotal || nDisks[2] == nTotal; }
    bool move( int from, int to);
    void display();

    void autoPlay()  {  moveTower( nDisks[0], 0, 2); }
};

#endif // _TOWERSOFHANOI_
