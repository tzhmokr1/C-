// ---------------------------------------------------------
// ex29_04.cpp
// Das Programm merkt sich die Anzahl und die Anfangspositionen 
// der Sprüche in der Datei sprueche.txt.
// Mit jedem Return, das der Anwender eingibt, wird zufällig
// ein Spruch ausgewählt und angezeigt.
// ---------------------------------------------------------
#include <iostream>
#include <fstream> 
#include <string>
#include <vector>     // Templateklasse vector<T>.
#include <cstdlib>    // Für srand() und rand().
#include <ctime>      // Für time().
using namespace std;

int main()
{
    char datei[] = "sprueche.txt";
    string zeile;
    vector<ios::pos_type> positionen;

    ifstream ifs( datei);
    if( !ifs) 
    {  cerr << "Fehler beim Oeffnen der Datei " << datei << endl;
       return 1;
    }
    while( true)
    {
        ios::pos_type pos = ifs.tellg();
        if( !getline( ifs, zeile))
            break;
        if( zeile.size() > 0 && zeile[0] != '#')
            positionen.push_back(pos);
    }
    if( !ifs.eof())
    {  cerr << "Fehler beim Lesen der Datei " << datei << endl;
       return 2;
    }
    ifs.clear();

    int anz = positionen.size(),
        nr0 = -1, nr = 0;                  // Zeilennummern.
    if( anz == 0)
    {  cout << "Die Datei " << datei 
            << " enthaelt keinen Spruch."<< endl;
       return 0;
    }

    cout << "Der nächste Spruch: Return-Taste\n"
         << "Ende des Programms: Taste Q\n" 
         << "--------------------------------" << endl;
    char c = 0;                     // Zeichen von der Tastatur.
    srand( (unsigned)time(NULL));
    do {
        nr = rand() % anz;
        if( nr == nr0) nr = (++nr % anz);  // Damit nicht hintereinander
        nr0 = nr;                          // derselbe Spruch kommt.
        ifs.seekg(positionen[nr]);
        if( !getline( ifs, zeile))
        { 
           cerr << "Fehler beim Lesen der Datei " << datei << endl;
           return 2;
        }
        cout << zeile << endl;
        if( anz == 1)
        {   cout << "\nDie Datei " << datei 
                 << " enthaelt nur einen Spruch." << endl;
            return 0;
        }
        // Return oder Q von der Tastatur lesen:   
        while( cin.get(c) && c!='\n' && c != 'Q' && c != 'q')
            ;
    } while( c == '\n'); 
    return 0;
}
