// ------------------------------------------------------
// ex25_06.cpp
// Klasse MyData testen. 
// ------------------------------------------------------
#include "myData.h"

void testFunc( MyData d);               // Call by value!

int main()
{
    MyData db;

    db.insertX(1.77);
    db.insertS("Ein Test!");
    double x = -0.07;
    db.insertX(x);

    db.printData();

    cout << "Kopierkonstruktor testen!" << endl;
    testFunc(db);
    cout << "Wieder in der Funktion main()" << endl;
    cin.get();

    cout << "Zuweisung testen!" << endl;
    MyData *pDB = new MyData;
    pDB->insertS("Hallo");   // Ein Element, das durch die
                             // Zueweisung wieder geloescht wird.
    *pDB = db;               // Zuweisung.
    pDB->printData();
    cout << "Im neuen Objekt ein Element loschen." << endl;
    if( pDB->erase(x))                    // Ein Element loeschen
       cout << "Element mit Wert " << x << " geloescht!" << endl;
    pDB->printData();
    delete pDB;
    cout << "Das neue Objekt wurde zerstoert!" << endl;
    cin.get();

    cout << "Und noch ein String-Element loeschen:" << endl;
    if( db.erase("Ein"))
        cout << "\"Ein ...\" geloescht." << endl;
    else
        cout << "String \"Ein ...\" nicht gefunden!" << endl;

    db.printData();
    cout << "Ende der Funktion main()" << endl;
    return 0;
}

void testFunc( MyData d)               // Call by value!
{
    cout << "In der Funktion testFunc()" << endl;  
    cout << "--- Daten der Kopie:  ---" << endl;
    d.printData();                     // Daten anzeigen.
    cout << "Kopie wird wieder zerstoert!" << endl;
}
