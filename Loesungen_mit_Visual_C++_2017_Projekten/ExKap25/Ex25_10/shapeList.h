// ---------------------------------------------------------
// shapeList.h
// Definition der Klassen ShapeList
// Inhomogene Liste mit Figuren vom Typ Shape
// ---------------------------------------------------------
#ifndef _SHAPELIST_
#define _SHAPELIST_

#include "shape.h"
#include <cstdlib>        // Prototyp exit()
#include <list>           // Klassen-Template list<T>
                          // T ist der Typ der Listenelemente.
using namespace std;

class ShapePtr
{
  private:
    Shape *ptr;
  public:
    ShapePtr( Shape* p = NULL) : ptr(p) {}   // Konstruktoren
    ShapePtr( const ShapePtr& sp) { ptr = sp->clone(); }

    ~ShapePtr() { delete ptr; }              // Destruktor

    ShapePtr& operator=(Shape* p)            // Zuweisungen
    {
       delete ptr;
       ptr = p->clone();
       return *this;
    }

    ShapePtr& operator=(ShapePtr& a)
    {
       delete ptr;
       ptr = a->clone();
       return *this;
    }

    Shape& operator*() const                 // Verweisoperator
    {
       if( !ptr)
       { cerr << "ShapePtr::operator* : Kein Objekt!" << endl;
         exit(100);
       }
       return *ptr;
    }

    Shape* operator->() const                // Pfeiloperator 
    {
       if( !ptr)
       { cerr << "ShapePtr::operator-> : Kein Objekt!" << endl;
         exit(101);
       }
       return ptr;
    }

    operator Shape*() const { return ptr; }  // Konvertierungsfunktion
};

class ShapePtrList : public list<ShapePtr>
{
  public:
    void scale( double scalingFactor)
    {
       ShapePtrList::iterator pos;
       for( pos = begin();  pos != end();  ++pos)
          (*pos)->scale( scalingFactor);
    }

    string toString() const
    {
       stringstream sstream;
       if( empty())
         sstream << "Die Liste ist leer!"; 
       else
       {
         ShapePtrList::const_iterator pos;
         for( pos = begin();  pos != end();  ++pos)
         {
            sstream.width(20);
            sstream << left << typeid(**pos).name();
            sstream << (*pos)->toString() << endl;
         }
       }
       return sstream.str();
    }
};

#endif  // _SHAPELIST_