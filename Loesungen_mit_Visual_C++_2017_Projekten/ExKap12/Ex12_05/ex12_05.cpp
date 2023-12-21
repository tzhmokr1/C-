// --------------------------------------------------------
// ex12_05.cpp
// Testet die Funktion strReverse().
// --------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

const string& strReverse(const string& s);   // Prototyp

int main()
{
    const string str("LAGER"); 
    cout << "Der String: " << str << endl;

    string rev = strReverse(str);
    cout << "Der String in umgekehrter Reihenfolge: " << rev << endl; 
    cout << "Und seine Laenge: " << rev.length() << endl;

    return 0;
}
