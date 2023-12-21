// -------------------------------------------------
// prioQueue.cpp
// Definition von Methoden der Klasse PrioQueue
// -------------------------------------------------

#include "prioQueue.h"
#include <typeinfo>
using namespace std;

void PrioQueue::deleteAll()
{
   while( first != NULL )  // Vom Anfang her alles löschen.
   {
       Cell* temp = first;
       first = first->getNext();
       delete temp;
   }

   first = NULL;
}

void PrioQueue::copyAll( const PrioQueue& pq)
{
  Cell* temp = pq.first;

  if( first == NULL )    // Falls Priority Queue leer 
  {
     while( temp!= NULL )
     {
       if( typeid(*temp) == typeid(ListEl))
          insert(temp->getPrio(), temp->getName());
       else
          insert(temp->getPrio(), temp->getName(), 
                 temp->getAnam());
            
       temp = temp->getNext();
     }
  }
}

Cell* PrioQueue::prior(int pr)     // Einfügeposition suchen.
{
    Cell *next = first, *last = NULL;
       
    while(next != NULL && next->getPrio() >= pr )
    {
       last = next;
       next = next->getNext();
    }

    return last;
}

bool PrioQueue::insert(int pr, const string& s)
{
/*
  if( first == NULL)                     // Liste leer
  {                                    
    first = new ListEl(pr, s);
    return true;
  }
  else                                   // Liste nich leer:
  {
*/  
    Cell *temp = prior(pr),     // Einfügeposition bestimmen.
         *ptr;

    if( temp == NULL)           // Liste noch leer oder 
    {                           // vor allen anderen einfügen. 
      first = new ListEl(pr, s, first);
      return true;
    }
    
    if(temp->getPrio() == pr)   // Keine doppelten Prioritäten.
       return false;
    else                 // In der Mitte oder am Ende einfügen.
    {
       ptr = new ListEl(pr, s, temp->getNext());
       temp->setNext(ptr);
       return true;
    }
}

bool PrioQueue::insert(int pr, const string& s,
                       const string& a)
{
    Cell *temp = prior(pr),   // Einfügeposition bestimmen.
         *ptr;

    if( temp == NULL)           // Liste noch leer oder 
    {                           // vor allen anderen einfügen. 
      first = new ExtListEl(pr, s, a, first);
      return true;
    }
    
    if(temp->getPrio() == pr)   // Keine doppelten Prioritäten.
       return false;
    else                 // In der Mitte oder am Ende einfügen.
    {
       ptr = new ExtListEl(pr, s, a, temp->getNext());
       temp->setNext(ptr);
       return true;
    }
}

void PrioQueue::deleteMax(string& s)
{
   if( first != NULL)
   {
       s = first->getName();
       first = first->getNext();
   }
   else 
       s = "";
}

void PrioQueue::display()
{
    Cell* temp = first;

    if( temp == NULL )
        cout << "\n\tKein Patient da." << endl;
    else
      while( temp != NULL)
      {
        temp->display();
        temp = temp->getNext();
      }
}
