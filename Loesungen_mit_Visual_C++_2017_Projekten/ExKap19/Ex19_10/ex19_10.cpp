// ---------------------------------------------------------
// ex19_10.cpp
// Testet die Klasse NameValueArr mit den Umgebungsvariablen. 
//
// Zunächst wird das Kommando "set > file" ausgeführt, um
// die Tabelle mit den Umgebunsvariablen in eine Datei zu 
// schreiben. Diese Tabelle wird in ein Objekt vom Typ
// NameValueArr eingelesen und ausgegeben. Anschließend sucht
// das Programm jeden Namen, den der Benutzer eingibt und
// gibt den entsprechenden Wert aus.
// ---------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS     // Für VC++ und strcat()
#include <iostream>
#include <fstream>
#include <string>
#include "nameValue.h"
using namespace std;

char filename[] = "myEnviron.txt";

inline void openError( char* s)
{  cerr << "Fehler beim Oeffnen der Datei " << s << endl; exit(1); }

inline void readError(char* s)
{  cerr << "Fehler beim Lesen der Datei " << s << endl; exit(2); }

int main()
{
    NameValueArr myEnviroment;

    cout << "\n\t  ***** Tabelle der Umgebungsvariablen *****\n" << endl;

    // Erzeugt eine Datei mit den Umgebungsvariablen:
    char cmd[80] = "set > ";
    strcat( cmd, filename);
    system( cmd);        // Führt das Kommando "set > file" aus.

    // Liest die Datei in das Objekt myEnviroment:
    ifstream infile(filename);
    if( !infile)
        openError(filename);

    while( infile >> myEnviroment)
        ;
    if( !infile.eof())
        readError(filename);
    infile.close();

    // Gibt die Umgebungsvariablen aus:
    cout << myEnviroment;

    // Durchsucht die Tabelle der Umgebungsvariablen nach bestimmten Eintraegen:
    string name;
    while( true)
    {
      cout << "\nGeben Sie den Namen eines Eintrags ein:"
              "\n(Abbruch mit Leerzeile)\n";
      if( !getline( cin, name) || name == "")
          break;
      
      cout << name << ": " << myEnviroment[name] << endl;
    }

    return 0;
}
