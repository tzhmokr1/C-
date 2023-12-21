//==============================================================================
//        * Letsch Informatik *       www.LetsInfo.ch       CH-8636 Wald
//          Beratung, Ausbildung und Realisation in Software-Engineering
//==============================================================================
// Project   : Master of Advanced Studies in Software-Engineering MAS-SE 2019
// Title     : Klasse "Bruch"
// Author    : Thomas Letsch
// Tab-Width : 4
/*///===========================================================================
* Description: Header-File zu Beispiel-Klasse "Bruch" (Musterlösung).
* $Revision  : 1.30 $  $Date: 2019/10/30 17:23:07 $
/*///===========================================================================
//       1         2         3         4         5         6         7         8
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//==============================================================================

#include <iostream>

using std::cout;
using std::ostream;

class Bruch {

    // Bruch ausgeben (via Friend):
    friend ostream& operator<<(ostream&, const Bruch&);

    public:
                Bruch();                            // Default-Konstruktor
                Bruch(int pZahl);                   // Konstruktor mit ganzer Zahl
                Bruch(int pZaehler, int pNenner);   // Konstruktor: Zaehler, Nenner
        void    drucke();                           // Bruch ausgeben (via Methode)
        Bruch   operator*(Bruch);                   // Operator Multiplikation
        Bruch   operator/(Bruch);                   // "        Divison
        Bruch   operator+(Bruch);                   // "        Addition
        Bruch   operator-(Bruch);                   // "        Subtraktion
        Bruch   operator!();                        // Operator Kehrwert
        Bruch   kuerze();                           // Bruch kuerzen

  protected:
        int     ggt(int i1, int i2);                // Groesster gemeinsamer Teiler

    private:
        int     mZaehler;       // Zaehler als Ganzzahl
        int     mNenner;        // Nenner als Ganzzahl

};
