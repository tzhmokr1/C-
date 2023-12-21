// -------------------------------------------
// prioQueue.h
// Definition der Klasse PrioQueue
// -------------------------------------------
#ifndef _PRIOQUEUE_
#define _PRIOQUEUE_

#include "listEl.h"

class PrioQueue
{
  private:
    Cell* first;

    void deleteAll();
    void copyAll( const PrioQueue& pq);
    
    Cell* prior(int pr);

  public:
    PrioQueue() {first = NULL; }
    PrioQueue( const PrioQueue& pq) 
        { first = NULL; copyAll(pq); }
    ~PrioQueue() { deleteAll(); }

    PrioQueue& operator=(const PrioQueue& pq)
    { deleteAll(); copyAll(pq); return *this;}

    bool insert(int pr, const string& s);
    bool insert(int pr, const string& s, const string& a);

    void deleteMax(string& s);

    void display();
};

#endif  // _PRIOQUEUE_
