// ---------------------------------------------------------
// ex29_01.cpp
// Das Programm liest eine ganze Zahl aus einer Textdatei.
// Ein Fehler löst eine Exception aus, die aufgefangen wird.
// ---------------------------------------------------------
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int ivalue = -1, exitcode = 0;
    char inputfile[] = "input.txt"; 
    try
    {
        ifstream ifs( inputfile);
        ifs.exceptions(ios::failbit | ios::badbit);
        cout << "Die Datei " << inputfile
             << " wurde geoeffnet!" << endl;
        ifs >> ivalue;
        cout << "Die eingelesene Zahl " << ivalue <<  endl;
        // Datei wird beim Verlassen des Blocks geschlossen.
    }
    catch (ios::failure &e)
    {
        cout << inputfile << ":  " << e.what() << endl; 
        cout << "Fehlercode: " << e.code() << endl;
        exitcode = 1;
    }
 
    cout << "Das Programm wird ";
    if(exitcode == 0)  cout << "erfolgeich beendet." << endl;
    else               cout << "beendet." << endl;
    return exitcode;
}
