//==============================================================================
//        * Letsch Informatik *       www.LetsInfo.ch       CH-8636 Wald
//          Beratung, Ausbildung und Realisation in Software-Engineering
//==============================================================================
// Project   : Master of Advanced Studies in Software-Engineering MAS-SE 2019
// Title     : Klasse "Bruch"
// Author    : Thomas Letsch
// Tab-Width : 4
/*///===========================================================================
* Description: Implementations-File zu Beispiel-Klasse "Bruch" (Musterlösung).
* $Revision  : 1.30 $  $Date: 2019/10/30 17:23:07 $
/*///===========================================================================
//       1         2         3         4         5         6         7         8
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//==============================================================================

#include "Bruch.h"

Bruch::Bruch() : mZaehler(0), mNenner(1) {
    ;
}


Bruch::Bruch(int pZahl) : mZaehler(pZahl), mNenner(1) {
    ;
}


Bruch::Bruch(int pZaehler, int pNenner) : mZaehler(pZaehler), mNenner(pNenner) {
    ;
}


void Bruch::drucke() {
    cout << "Bruch (" <<  mZaehler <<  "/" <<  mNenner <<  ")" << "\n";
}


Bruch Bruch::operator*(Bruch b) {
    return Bruch(mZaehler * b.mZaehler, mNenner * b.mNenner);

    // Wir sehen spaeter das dieser Operator besser mit einem Friend-Operator
    // realisiert wuerde (wie nachfolgender operator<<).
}


Bruch Bruch::operator/(Bruch b) {
    return Bruch(mZaehler * b.mNenner, mNenner * b.mZaehler);
}


Bruch Bruch::operator+(Bruch b) {
    return Bruch(mZaehler * b.mNenner + mNenner * b.mZaehler, mNenner * b.mNenner);
}


Bruch Bruch::operator-(Bruch b) {
    return Bruch(mZaehler * b.mNenner - mNenner * b.mZaehler, mNenner * b.mNenner);
}


Bruch Bruch::operator!() {
    return Bruch(mNenner, mZaehler);
}


Bruch Bruch::kuerze() {
    int theGGT = ggt(mZaehler, mNenner);
    mZaehler = mZaehler / theGGT;
    mNenner  = mNenner / theGGT;
    return *this;
}


int Bruch::ggt(int i1, int i2) {
    if (i2 == 0)
        return i1;
    return ggt(i2, i1 % i2);
}


ostream& operator<<(ostream& os , const Bruch& b) {
    os << "Bruch (" <<  b.mZaehler <<  "/" <<  b.mNenner <<  ")" << "\n";
    return os;
}
