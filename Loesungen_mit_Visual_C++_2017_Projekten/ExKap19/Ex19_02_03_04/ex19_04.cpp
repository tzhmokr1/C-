// ---------------------------------------------------------
// ex19_04.cpp
// Testet die Klasse Wallet. 
// ---------------------------------------------------------

#include <iostream>
#include <string>
#include "wallet.h"
using namespace std;

int main()
{
    Wallet myWallet, yourWallet(12345);
    cout << "\nDer Inhalt von myWallet: "  << myWallet 
         << "\n         und yourWallet: "  << yourWallet
         << endl;

    myWallet += 20000;
    long cents = 345;
    yourWallet -= cents;
    cout << "\nDer Inhalt von myWallet: "  << myWallet 
         << "\n         und yourWallet: "  << yourWallet
         << endl;

    if( myWallet < yourWallet)
        cout << "Du bist reich!" << endl;
    else
        cout << "Ich bin reich!" << endl;

    cout << "Ich gebe Dir mein Geld!" << endl;
    yourWallet += myWallet; 
    cout << "\nDer Inhalt von myWallet: "  << myWallet 
         << "\n         und yourWallet: "  << yourWallet
         << endl;

    return 0;
}
