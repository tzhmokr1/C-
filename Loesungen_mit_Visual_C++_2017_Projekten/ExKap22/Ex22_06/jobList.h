// -------------------------------------------------------
// jobList.h
// Definition der Klassen Job und JobList.
// Version mit Iteratoren.
// -------------------------------------------------------
#ifndef _JOBLIST_
#define _JOBLIST_

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// -------------------------------------------------------
// Definition der Klasse Job
class Job
{
  private: 
    long id;
    string description;
    static long curID;

  public:
    Job( const string& todo)
    : id(++curID), description(todo) {}

    // Zugriffsmethoden:
    unsigned long getID() const { return id; }
    const string& getDescription() const { return description; }
    void  setDescription( const string& d) { description = d; }
};

// Deklaration der Operatorfunktion:
ostream& operator<<( ostream& os, const Job& job);

// -------------------------------------------------------
// Definition der Klasse JobList
class JobList
{
  private:
    struct ListEl
    {
      Job job;
      ListEl *next;
      ListEl(const Job& j) : job(j), next(NULL) {}
    };
    ListEl *first, *last;
    int count;

  public:
    JobList() : first(NULL), last(NULL), count(0) {}
    JobList(const JobList& src);       // Kopierkonstruktor 
     ~JobList();

    JobList& operator=(const JobList& src);   // Zuweisung

    void pushBack( const Job& job);
    bool popFront( Job& job);

    int getCount() const { return count; };
    void print() const;

    class Iterator              // Alle Methoden sind inline.
    {
      private:
        ListEl* ptrCurrent;     // Zeiger auf das aktuelle 
                                // Listenelement.
      public:
        Iterator( ListEl* ptrEl = NULL) : ptrCurrent(ptrEl) {}

        Job& operator*() {  return ptrCurrent->job; }

        bool operator==( const Iterator& i2) const
        {  return ptrCurrent == i2.ptrCurrent; }

        bool operator!=( const Iterator& i2) const
        {  return ptrCurrent != i2.ptrCurrent; }

        Iterator& operator++()        // präfix
        {
            if( ptrCurrent != NULL)   // Zeiger versetzen:
                ptrCurrent = ptrCurrent->next;
            return *this;
        }

        Iterator operator++(int)      // postfix
        {
            Iterator temp( *this);    // Kopie vor der Operation
            if( ptrCurrent != NULL) 
                ptrCurrent = ptrCurrent->next;
            return temp;
        }
    };  // Ende Klasse Iterator

    Iterator begin() const { return Iterator(first); }
    Iterator end() const   { return Iterator(); }
};

#endif   // _JOBLIST_
