// ------------------------------------------------------
// ex24_05.cpp
// Klasse MyData verwenden.
// ------------------------------------------------------
#include "myData.h"

int main()
{
    MyData db;

    db.insertX(1.77);
    db.insertS("Ein Test!");
    double x = 2.34;
    if( !db.insertX(x))
       cout << "Kein freier Platz!" << endl;
    else
       cout << x << " eingefuegt!" << endl;

    if( db.insertS())
       cout << "Neuer Text ist eingefuegt!" << endl;

    cout << "... und noch eine Zahl." << endl;
    if( db.insertX())
       cout << "Neue Zahl ist eingefuegt!" << endl;

    db.printData();

    return 0;
}

