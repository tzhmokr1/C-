// ------------------------------------------------------
// ex25_10.cpp
// Inhomogene Liste fuer Shape-Objekte (2. Version).
// ------------------------------------------------------
#include <iostream>
#include "shapeList.h"
using namespace std;

int main()
{
   cout << "\n\t ***  Eine Liste geometrischer Figuren  ***\n"
        << endl;
   ShapePtrList myShapes;
   cout << myShapes.toString() << endl;         // Liste anzeigen

   cout << "Elemente in die Liste einfuegen: " << endl;
   // Am Ende anhaengen:
   myShapes.push_back( new Line( Point(0,0), Point(2,2)) );
   myShapes.push_back( new Rectangle( Point(-1,-1), 2, 2) );

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
   cout << myShapes.toString() << endl;         // Liste anzeigen

   cout << "Figur vor dem Kreis loeschen ... " << endl;
   myShapes.erase(--pos);

   cout << "und die zweite Figur (das Polygon) verschieben: " << endl;
   pos = myShapes.begin();
   ptr = *(++pos);   // Zweites Element = Zeiger auf das Polygon
   ptr->move(0, 3);  // Nach oben verschieben.

   cout << "Die veraenderte Liste: " << endl
        << myShapes.toString();                 // Liste anzeigen
   cin.get();

   cout << "Kopie der Liste anlegen "
           "und Groesse der Figuren verdoppeln:" << endl;
   ShapePtrList yourShapes(myShapes);           // Kopierkonstruktor!
   yourShapes.scale(2.0);                       // Groesse der Figuren verdoppeln.
   cout << yourShapes.toString() << endl;       // Neue Liste anzeigen

   cout << "Die urspruengliche Liste ist unveraendert:\n"
        << myShapes.toString() << endl;         // Urspründliche Liste anzeigen.

   cout << "Zuweisung von Listen testen!\n"
        << "Erste Figur (Ellipse) in der neuen Liste loeschen"
        << endl;
   yourShapes.pop_front();
   cout << "und die Liste der urspruengliche Liste zuweisen:" << endl;
   myShapes = yourShapes;                       // Zuweisung

   cout << myShapes.toString();                 // Ergebnis anzeigen.
   cin.get();

   return 0;
}
