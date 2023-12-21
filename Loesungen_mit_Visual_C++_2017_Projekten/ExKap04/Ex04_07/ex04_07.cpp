// --------------------------------------------------------
// ex04_07.cpp
// Das Programm liest im Dialog
//    ein Zeichen 
//    ein Wort 
//    eine Oktalzahl 
//    eine Hexadezimalzahl 
// ein und gibt sie auf dem Bildschirm aus.
// --------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

int main()
{
    char c;
    int n1, n2;
    string s;

    cout << "Geben Sie ein Zeichen ein:          ";    cin >> c;
    cout << "Geben Sie ein Wort ein:             ";    cin >> s;
    cout << "Geben Sie eine Oktalzahl ein:       ";    cin >> oct >> n1;
    cout << "Geben Sie eine Hexadezimalzahl ein: ";    cin >> hex >> n2;

    cout <<  endl << "Your input: " << endl;
    cout << "Das Zeichen:         " << c   << endl;
    cout << "Das Wort:            " << s   << endl;
    cout << "Die Oktalzahl:       " << oct << n1 << endl;
    cout << "Die Hexadezimalzahl: " << hex << n2 << endl;

    return 0;
}
