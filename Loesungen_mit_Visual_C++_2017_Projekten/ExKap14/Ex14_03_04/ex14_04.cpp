// ---------------------------------------------------------
// ex14_04.cpp
// Definiert und testet die Funktion exchangeMobilePhones().
// ---------------------------------------------------------
#include "mobilePhone.h"
#include <iostream>
using namespace std;

void exchangeMobilePhones(MobilePhone& m1, MobilePhone& m2);

int main()
{
    MobilePhone mobile1("Nokia 6510"),
                mobile2("iPhone 3G", "Bonny"),
                mobile3("Samsung Galaxy S", "Clyde", "123-456789");

    mobile1.display();
    mobile2.display();
    mobile3.display();

    mobile1.setOwner("Mary");
    cout << "\nDer Besitzer des Handies " << mobile1.getDevice()
         << " ist " << mobile1.getOwner() << endl;

    cout << "\nJetzt werden zwei Handies ausgetauscht!" << endl;
    exchangeMobilePhones( mobile2, mobile3);
    mobile2.display();
    mobile3.display();

    return 0;
}

void exchangeMobilePhones(MobilePhone& m1, MobilePhone& m2)
{
    string own1 = m1.getOwner(),
           num1 = m1.getNumber();

    m1.setOwner( m2.getOwner());
    m1.setNumber( m2.getNumber());

    m2.setOwner( own1);
    m2.setNumber( num1);
}
