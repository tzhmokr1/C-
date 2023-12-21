// ------------------------------------------------------
// ex25_08.cpp
// Klassen Shape, Polyline, Polygon, Ellipse, ... testen.
// ------------------------------------------------------

#include "shape.h"

int main()
{
   cout << "\nGeometrische Figuren\n" << endl;

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
   cin.get();

   cout << "Linien testen: " << endl;
   Line line1(0,0,1,1),
        *pLine = new Line(line1);             // Kopierkonstruktor
   cout << line1.toString() << endl;
   pLine->move(-1.0, -1.0);                   // Verschiebung
   cout << pLine->toString() << endl;

   cout << "Laenge der Line: " << pLine->getLength() << endl;
   cout << "Nach der Skalierung mit dem Faktor 2.0" << endl;
   pLine->scale(2.0);
   cout << pLine->toString() << endl;

   line1 = *pLine;                            // Zuweisung
   delete pLine;
   cout << "Nach der Zuweisung:" << endl;
   cout << line1.toString() << endl << endl;

   cout << "Polygone testen: " << endl;
   Polygon *pPolygon = new Polygon,
           triangle( vertices, 3),
           quadrangle( triangle);             // Kopierkonstruktor
   quadrangle += Point(0,-2);

   cout << pPolygon->toString() << endl;      // Ausgabe
   cout << "Dreieck:  " << triangle.toString() << endl;
   cout << "Viereck:  " << quadrangle.toString() << endl;
   cout << "Anzahl Ecken: " << quadrangle.getNumberOfVertices() << endl  
        << "Umfang      : " << quadrangle.getCircumference() << endl;

   cout << "Zuweisung:" << endl;
   *pPolygon = triangle;                      // Zuweisung
   cout << pPolygon->toString() << endl;
   cout << "Umfang des Dreiecks: "
        << pPolygon->getCircumference() << endl << endl;
   delete pPolygon;

   cout << "Rechtecke:" << endl; 
   Rectangle rect1( Point(-2,-1), 2, 1),      // Linke untere Ecke, Breite, Hoehe
             rect2( Point(0,0), Point(1,1));
   cout << rect1.toString() << endl;
   cout << rect2.toString() << endl;
   cout << "Umfang der Rechtecke: "
        << rect1.getCircumference() << " und "
        << rect2.getCircumference() << endl;
   cin.get();

   cout << "Ellipsen und Kreise:" << endl; 
   Ellipse ellipse( Point(0,0), 2, 1);      // Mittelpunk, Halbachsen
   cout << ellipse.toString() << endl;
   cout << "Umfang: " << ellipse.getCircumference() << endl;

   Circle  circle( Point(0,0), 1);
   cout << circle.toString() << endl;
   cout << "Umfang: " << circle.getCircumference() << endl;
   circle.scale(2.0);
   cout << circle.toString() << endl;
   cout << "Umfang: " << circle.getCircumference() << endl;

   return 0;
}
