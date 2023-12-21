// ------------------------------------------------------
// towersOfHanoi.h
// Definiert die Klasse TowersOfHanoi.
// ------------------------------------------------------
#ifndef _TOWERSOFHANOI_
#define _TOWERSOFHANOI_

#include <iostream>
using namespace std;

#define MAX_DISKS  64

class TowersOfHanoi
{
  private:
    short tower[3][MAX_DISKS],   // Drei Türme,
          nDisks[3],             // aktuelle Anzahl Scheiben
                                 // pro Turm,
          nTotal;                // Gesamtzahl Scheiben.

  public:
    TowersOfHanoi( int n); 
    bool isFinished()
    { return  nDisks[1] == nTotal || nDisks[2] == nTotal; }
    bool move( int from, int to);
    void display();
};
#endif   // _TOWERSOFHANOI_

