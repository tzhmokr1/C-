// ---------------------------------------------------------
// tail.cpp (Lösung zur 3. Aufgabe im Kapitel 29)
// Das Programm gibt die Zeilen im letzten 512-Byte-Block
// einer Textdatei aus und die Dateilänge.
// ---------------------------------------------------------
#include <iostream>
#include <fstream> 
#include <string>
using namespace std;

int main(int argc, char **argv)
{
    ifstream fs;
    long long filesize;
    string zeile;
    bool neueZeile = false;

    if( argc != 2 )
    {
       cerr << "Benutzung: Tail Dateiname\n";
       return 1;
    }
    fs.open( argv[1], ios::in | ios::binary);
    if( !fs.is_open())
    {
       cerr << "Fehler beim Oeffnen der Datei " << argv[1]
            << endl;
       return 2;
    }

    fs.seekg(0,ios::end);          // An das Ende der Datei gehen
    filesize = fs.tellg();
    if( filesize > 512 )           // und dann 512 Bytes zurueck.
        fs.seekg( -512, ios::end);
    else
    {   fs.seekg(0);  neueZeile = true;
    }
    if( fs.fail())
    {
       cerr << "Fehler beim Positionieren in der Datei "
            << argv[1] << endl;
       return 3;
    }
    while( getline( fs, zeile) )
        if(neueZeile)                       // Ausgabe erst mit Beginn 
           cout << zeile << endl;           // einer neuen Zeile.
        else
           neueZeile = true;

    if( !fs.eof())
    {
       cerr << "Fehler beim Lesen in der Datei "
            << argv[1] << endl;
       return 3;
    }

    cout << "\n------------------------\n"
         << "Dateilaenge: " << filesize << " Byte" << endl;
    return 0;
}
