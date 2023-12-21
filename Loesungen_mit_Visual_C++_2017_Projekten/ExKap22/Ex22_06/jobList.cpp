// ---------------------------------------------------------
// jobList.cpp
// Implementierung der Klassen Job und JobList.
// ---------------------------------------------------------

#include "jobList.h"

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

JobList::JobList(const JobList& src)       // Kopierkonstruktor 
{
   first = last = NULL;
   count = 0;
   ListEl *ptr = src.first;
   for( ; ptr!= NULL; ptr = ptr->next)
      pushBack( ptr->job);
}

JobList::~JobList()
{
   ListEl *ptr = first, *next;
   for( ; ptr!= NULL; ptr = next)
   {
      next = ptr->next;
      delete ptr;
   }
}

JobList& JobList::operator=(const JobList& src)   // Zuweisung
{
   if( this != &src)                // Keine Selbstzuweisung
   {
      ListEl *ptr = first, *next;   // Alle Elemente löschen
      for( ; ptr!= NULL; ptr = next)
      {
         next = ptr->next;
         delete ptr;
      }
      first = last = NULL;          // und die Elemente von src
      count = 0;                    // einfügen.
      for( ptr = src.first;  ptr!= NULL; ptr = ptr->next)
         pushBack( ptr->job);
   }
   return *this;
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
