//--------------------------------------------------
// listel.h
// Definition der Klassen Cell, ListEl und ExtListEl
//--------------------------------------------------
#ifndef _LISTEL_
#define _LISTEL_

#include <string>
#include <iostream>
using namespace std;

class Cell
{
  private:
    Cell* next;
  
  public:
    Cell( Cell* p) { next = p; }

    Cell* getNext() const { return next; }
    void  setNext(Cell* p){ next = p; }

    virtual int   getPrio() const = 0;
    virtual const string& getName() const = 0;
    virtual const string& getAnam() const = 0;
    virtual void  display() =0;
};

class ListEl : public Cell
{
  private:
    int prio;              // Prioritaet
    string name;           // Name des Patienten
  
  public:
    ListEl( int pr, const string& s, Cell* p = NULL) 
           : Cell(p), prio(pr), name(s){ }

    int  getPrio() const { return prio; }
    void setPrio(int pr){ prio = pr; }

    const string& getName() const { return name; }
    void  setName(const string& s) { name = s; }

    const string& getAnam() const
        { static string a(""); return a;}

    void display()
    {
      cout << "\n\n\tPrioritaet: " << prio;
      cout << "\n\tName: " << name ;
    }
};

class ExtListEl : public ListEl
{
  private:
    string anam;    // Anamanese

  public:
    ExtListEl(int pr, const string& s, const string& a, 
              Cell* p = NULL)
    : ListEl(pr, s, p), anam(a) {}

    const string& getAnam() const { return anam; }
    void  setAnam( const string& s) { anam = s; }
    void display()
    {
      ListEl::display();
      cout << "\n\tAnamnese: " << anam;
    }
};

#endif   // _LISTEL_
