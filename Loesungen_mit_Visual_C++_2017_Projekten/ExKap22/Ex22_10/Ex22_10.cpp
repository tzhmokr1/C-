// ---------------------------------------------------------
// ex22_10.cpp
// Verwendet die Klasse SearchTree.
// ---------------------------------------------------------
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "searchTree.h"
using namespace std;

inline void openError( const char* s)
{  cerr << "Fehler beim Oeffnen der Datei " << s << endl; exit(1); }

inline void writeError( const char* s)
{ cerr << "Fehler beim Schreiben in die Datei " << s << endl; exit(2); }

inline void readError( const char* s)
{ cerr << "Fehler beim Lesen der Datei " << s << endl; exit(3);}

int main()
{
   cout << "\t ****  Ein Binaerer Suchbaum  ****\n" << endl;

   SearchTree aTree;                  // Ein binärer Suchbaum
   char filename[] = "Tree.dat";      // Dateiname

   srand((unsigned int)time(NULL));   // Zufallszahlengenerator
                                      // initialisieren.
   for( int i=0; i< 10; ++i)
       aTree.insert( rand()%100);

   cout << "Der Baum:" << endl;
   aTree.printTop();
   cout << "Anzahl Elemente: " << aTree.getCount() << endl;

   cout << "Der Inhalt des Baumes aufsteigend sortiert:" << endl;
   cout << aTree << endl;
   cout << "Weiter mit der Return-Taste ... "; cin.get();

   ofstream oFile(filename);    // Datei zum Schreiben öffnen.
   if( !oFile.is_open())
      openError(filename);

   aTree.printNLR(oFile);       // Daten in die Datei schreiben.
   if( !oFile)
      writeError(filename);
   oFile.close();

   aTree.clear();               // Alle Knoten des Baums löschen.
   cout << "\nDer Inhalt des Baums wurde in die Datei " << filename
        << " geschrieben\nund der Baum geloescht!" << endl;
   cout << "Anzahl Elemente: " << aTree.getCount() << endl;

   ifstream iFile(filename);    // Datei zum Lesen öffnen.
   if( !iFile.is_open())
      openError(filename);

   int n = 0;
   while( iFile >> n)           // Daten aus der Datei lesen
      aTree.insert(n);          // und in den Baum einfügen.

   if( !iFile.eof())
      readError(filename);
   iFile.close();

   cout << "Die Daten wurden wieder aus der Datei in den Baum eingelesen."
        << endl;
   cout << "Anzahl Elemente: " << aTree.getCount() << endl;
   cout << "Der Baum:" << endl;
   aTree.printTop();

   return 0;
}
