// ------------------------------------------------------
// random.cpp
// Definiert die Methoden der Klasse Random.
// ------------------------------------------------------
#include "random.h"
#include <ctime>
#include <cstdlib>
//using namespace std;

// Die Methode init() weist den Datenelementen min 
// und max die übergebenen Anfangswerte zu und ruft 
// die Funktion randomSeed() auf.
void Random::init(int i_min, int i_max)
{
    min  = i_min;
    max  = i_max;

    static bool bFirst = true;
    if( bFirst)
    {
       randomSeed();
       bFirst = false;
    }
}

// Die Methode randomSeed() setzt den Keim des Zufalls- 
// zahlengenerators mithilfe der aktuellen Zeit.
void Random::randomSeed()
{
    unsigned int seed = (unsigned int)time(NULL);
    srand(seed);
}

// Die Methode random() liefert die nächste Zufallszahl.
int Random::random()
{
    return min + rand()%(max+1 - min);
}
