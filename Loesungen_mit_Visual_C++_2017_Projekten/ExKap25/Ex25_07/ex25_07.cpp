// ------------------------------------------------------
// ex25_07.cpp
// Klassen Shape und Polyline testen.
// ------------------------------------------------------
#include "shape.h"

int main()
{
   cout << "\nGeometrische Figuren: Linienzuege\n" << endl;

   Point vertices[] = { Point(-1,0), Point(0,2), Point(1,0) };

   Polyline poly1,
            poly2( Point(1,2), Point(2,0)),
            poly3( vertices, 3),
            poly4( poly3);                  // Kopierkonstruktor

   cout << "Die Punkte der vier Linienzuege: \n"    // Ausgabe
        << poly1.toString() << endl
        << poly2.toString() << endl
        << poly3.toString() << endl
        << poly4.toString() << endl;
   cin.get();

   cout << "Zuweisungen testen:" << endl;   // Zuweisung testen
   poly1 = poly4;
   cout << poly1.toString() << endl;
   poly1 = Polyline();
   cout << poly1.toString() << endl << endl;

   cout << "Punkte anhaengen:" << endl;     // Punkte anhängen.
   poly1 += Point(0.5, 2.5);
   cout << poly1.toString() << endl;
   poly4 += Point(2, 2);
   cout << poly4.toString() << endl;
   cout << "Anzahl Linien: " << poly4.getNumberOfLines() << endl  
        << "Laenge       : " << poly4.getLength() << endl;

   cout << "Nach der Skalierung mit dem Faktor 2.0" << endl;
   poly4.scale(2.0);
   cout << poly4.toString() << endl << endl;

   cout << "Linienzuege anhaengen:" << endl;  // Linienzüge
   poly2 += poly1;                            // anhängen.
   cout << poly2.toString() << endl;
   poly4 += poly3;
   cout << poly4.toString() << endl << endl;
 
   cout << "Linienzug verschieben:" << endl;  // Verschieben
   poly4.move(1,0);
   cout << poly4.toString() << endl;
   cout << "Neuer Anker: " << poly4.getAnchor() << endl; 

   return 0;
}
