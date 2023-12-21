// ---------------------------------------------------------
// ex29_06.cpp
// Das Programm testet die Exceptions der Klasse MyFstream.
// Es werden einige Zufallszahlen binär in eine Datei
// geschrieben und wieder ausgelesen. Dabei werden Fehler
// provoziert.
// ---------------------------------------------------------
#include <iostream>
#include <iomanip>
#include "myFstream.h"
using namespace std;

int main()
{
    int n, exitcode = 0;
    char numfile[] = "numbers.dat"; 
    try
    {
//      MyFstream fs( numfile, ios::in | ios::out | ios::binary);
                                      // Fehler, falls Datei nicht vorhanden.
        MyFstream fs( numfile, 
                      ios::in | ios::out | ios::binary | ios::trunc);
        cout << "Die Datei " << fs.getFilename()
             << " wurde geoeffnet!" << endl;

        for( int i = 0; i < 3; ++i)   // Einige Zahlen binär speichern.
        {    n = rand();
             fs.write( (char*)&n, sizeof(int));   // Fehler, falls Datei nur
        }                                         // zum Lesen geöffnet wurde.
        // fs.seekg(-1);                          // Fehler!
        fs.seekg(0);

        n = 0;
        while( fs.read((char*)&n, sizeof(int)) )  // Fehler, falls Datei nur
            cout << setw(10) << n;                // zum Schreiben geöffnet wurde.
        cout << endl;
        // fs.read((char*)&n, sizeof(int));       // Fehler:
                                                  // Nochmaliges Lesen am Dateiende.
        cout << "und noch mal die letzte Zahl:" << endl;
        fs.seekg(-(int)sizeof(int), ios::end);
        fs.read((char*)&n, sizeof(int));
        cout << setw(10) << n << endl;

        fs.close();
        cout << "Datei geschlossen." << endl;
        // fs.close();                       // Fehler! Datei schon geschlossen.
    }
    //catch( FileError &e)
    catch (ios::failure &e)             // Basisklasse genügt, wenn die Methode
    {                                   // getFilename() nicht aufgerufen wird.
        cout << e.what() << endl; 
        cout << e.code() << endl;
        exitcode = 1;
    }
 
    cout << "Das Programm wird ";
    if(exitcode == 0)  cout << "erfolgreich beendet." << endl;
    else               cout << "beendet." << endl;
    return exitcode;
}
