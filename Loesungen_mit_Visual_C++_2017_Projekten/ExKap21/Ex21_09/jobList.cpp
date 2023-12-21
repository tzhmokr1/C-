// ---------------------------------------------------------
// jobList.cpp
// Implementierung der Klassen Job und JobList.
// ---------------------------------------------------------

#include "JobList.h"

// -------------------------------------------------------
// Klasse JobList

long Job::curID = 10000;

// Der Operator << zur Ausgabe:
ostream& operator<<( ostream& os, const Job& job)
{ 
   cout << setw(10) << job.getID() << " : " << job.getDescription();
   return os;
}

// -------------------------------------------------------
// Klasse JobList

JobList::~JobList()
{
   ListEl *ptr = first, *next;
   for( ; ptr!= NULL; ptr = next)
   {
      next = ptr->next;
      delete ptr;
   }
}

void JobList::pushBack( const Job& job)
{
   ListEl *pEl = new ListEl(job);
   if( count == 0)
      first = last = pEl;
   else
       last->next = pEl,  last = pEl;
   ++count;
}

bool JobList::popFront( Job& job)
{
   if( count > 0)              // Falls nicht leer
   {
      ListEl *pEl = first;     // Zeiger sichern.
      job = first->job;
      first = first->next;     // first versetzen.
      delete pEl;              // 1. Element loeschen.
      --count;
      if( first == NULL)       // jetzt leer?
        last = NULL;
      return true;
   }
   else
      return false;
}

void JobList::print() const
{
   for( ListEl *p = first;  p != NULL; p = p->next)
      cout << p->job << endl;
}
