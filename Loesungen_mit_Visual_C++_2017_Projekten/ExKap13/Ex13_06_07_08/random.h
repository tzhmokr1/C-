// ------------------------------------------------------
// random.h 
// Definiert die Klasse Random.
// ------------------------------------------------------

#ifndef _RANDOM_
#define _RANDOM_

class Random
{
  private:
    int min, max;
    void randomSeed();

  public:
    void init( int i_min, int i_max);
    int random(); 
};

#endif   // _RANDOM_
