// ---------------------------------------------------
// ex12_03.cpp
// Definiert und testet die Funktion replaceAll().
// ---------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

// Prototyp:
int replaceAll( string& s, const string& oldStr, const string& newStr);

int main()
{
    string text("Julia is so pretty, so pretty!");
    int count = 0;

    cout << "\nAufruf der Funktion replaceAll()." << endl;

    cout << "\nDer urspruengliche String:\n" << text << endl;

    count = replaceAll( text, "pretty", "beautiful");

    cout << "\nDer Ergebnisstring:\n"
         << text << endl;
    cout << count << " Teilstrings wurden ersetzt!\n" << endl;

    return 0;
}

// ------- Die Funktion replaceAll -------

int replaceAll( string& s, const string& oldStr, const string& newStr)
{
    int oldLen = oldStr.length(),
        newLen = newStr.length(),
        pos   = 0,
        count = 0;

    while( (pos = s.find( oldStr, pos)) != string::npos)
    {
        s.replace( pos, oldLen, newStr);
        pos += newLen;
        ++count;
    }
    return count;
}
