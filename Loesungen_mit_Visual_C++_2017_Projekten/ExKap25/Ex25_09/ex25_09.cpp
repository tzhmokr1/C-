// ------------------------------------------------------
// ex25_09.cpp
// Inhomogene Liste fuer Shape-Objekte.
// ------------------------------------------------------
#include <iostream>
#include <typeinfo>
#include <list>           // Klassen-Template list<T>
                          // T ist der Typ der Listenelemente.
#include "shape.h"
using namespace std;

typedef list<Shape*> ShapePtrList;

void printShapeList( const ShapePtrList& spl);

int main()
{
   cout << "\n\t ***  Eine Liste geometrischer Figuren  ***\n"
        << endl;
   ShapePtrList myShapes;
   printShapeList( myShapes);

   cout << "\nElemente in die Liste einfuegen: " << endl;
   // Am Ende anhaengen:
   myShapes.push_back(new Line( Point(0,0), Point(2,2)) );
   myShapes.push_back(new Rectangle( Point(-1,-1), 2, 2) );

   // Ein Ellipse am Anfang einfuegen:
   myShapes.push_front( new Ellipse( Point(0,0), 3, 1));

   Point vertices[] = { Point(0,-3), Point(-3,0), Point(0,3), Point(3,0) };
   Shape *ptr = new Polygon( vertices, 4);      // Ein Rombus
   // Das Polygon als zweites Element einfuegen:
   myShapes.insert( ++myShapes.begin(), ptr);

   // Ein Kreis als vorletztes Element:
   ShapePtrList::iterator pos =        // Position des Kreises   
     myShapes.insert(--myShapes.end(), new Circle( Point(0,0), 5));
   (*pos)->scale(0.7);                 // Dieses Element verkleinern

   cout << "Anzahl Elemente in der Liste: "
        << myShapes.size() << endl;
   printShapeList( myShapes);         // Liste anzeigen

   cout << "Figur vor dem Kreis loeschen ... " << endl;
   myShapes.erase(--pos);

   cout << "und die zweite Figur (das Polygon) verschieben: " << endl;
   pos = myShapes.begin();
   ptr = *(++pos);   // Zweites Element = Zeiger auf das Polygon
   ptr->move(0, 3);  // Nach oben verschieben.

   cout << "Die veraenderte Liste: " << endl;
   printShapeList( myShapes);         // Liste anzeigen

   return 0;
}

void printShapeList( const ShapePtrList& spl)
{
   if( spl.empty())
   {
     cout << "Die Liste ist leer!" << endl;
     return;
   }
   ShapePtrList::const_iterator pos = spl.begin();
   for( ; pos != spl.end();  ++pos)
   {
      cout.width(20);
      cout << left << typeid(**pos).name();
      cout << (*pos)->toString() << endl;
   }
   cout << endl;
}
