// ---------------------------------------------------
// random.h 
// Definiert die Klasse Random.
// ---------------------------------------------------
#ifndef _RANDOM_
#define _RANDOM_

#include <cstdlib >
//using namespace std;

class Random
{
  private:
    int min, max;
    void randomSeed();
    void init(int i_min, int i_max);

  public:
    Random()      { init(0, RAND_MAX);  }
    Random(int m) { init(-m, +m);  }
    Random(int min, int max) { init( min, max);  }

    int random(); 
};

#endif   // _RANDOM_
