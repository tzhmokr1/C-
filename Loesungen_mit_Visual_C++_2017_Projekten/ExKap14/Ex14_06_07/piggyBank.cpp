// --------------------------------------------------------
// piggyBank.cpp
// Definiert die Methoden der Klasse PiggyBank.
// --------------------------------------------------------

#include "piggyBank.h"                // Klassendefinition 


PiggyBank::PiggyBank( unsigned int c_max)   // Konstruktor
{
    max = c_max;                 // Maximale Anzahl Münzen
    nCent1 = nCent10 = nCent50 = nEuro1 = 0;
    fBroken = false;
}

bool PiggyBank::isEmpty()
{
    unsigned int cur = nCent1 + nCent10 + nCent50 + nEuro1;
    return cur == 0;
}

bool PiggyBank::isFull()
{ 
    unsigned int cur = nCent1 + nCent10 + nCent50 + nEuro1;
    return cur >= max;
}

bool PiggyBank::isBroken() { return fBroken; }

// Die Methoden add1Cents(), add10Cents() usw. "werfen" eine
// gegebene Anzahl Münzen ins Sparschwein. Der Return-Wert
// ist die Anzahl Münzen, die nicht ins Sparschwein passen.
unsigned int PiggyBank::add1Cents(unsigned int n1C)
{
    unsigned int cur = nCent1 + nCent10 + nCent50 + nEuro1;

    if( n1C <= max - cur)      // Falls alle Münzen ins
    {                          // Sparschwein passen.
       nCent1 += n1C;
       return 0;
    }
    else                       // Das Sparschwein nimmt
    {                          // soviele Münzen wie möglich:
       nCent1 += (max - cur);
       return n1C - (max - cur);     // Anzahl übrige Münzen.
    }
}

unsigned int PiggyBank::add10Cents(unsigned int n10C)
{
    unsigned int cur = nCent1 + nCent10 + nCent50 + nEuro1;

    if( n10C <= max - cur)     // Falls alle Münzen ins
    {                          // Sparschwein passen.
       nCent10 += n10C;
       return 0;
    }
    else                       // Das Sparschwein nimmt
    {                          // soviele Münzen wie möglich:
       nCent10 += (max - cur);
       return n10C - (max - cur);     // Anzahl übrige Münzen.
    }
}

unsigned int PiggyBank::add50Cents(unsigned int n50C)
{
    unsigned int cur = nCent1 + nCent10 + nCent50 + nEuro1;

    if( n50C <= max - cur)    // Falls alle Münzen ins
    {                         // Sparschwein passen.
       nCent50 += n50C;
       return 0;
    }
    else                      // Das Sparschwein nimmt
    {                         // soviele Münzen wie möglich:
       nCent50 += (max - cur);
       return n50C - (max - cur);     // Anzahl übrige Münzen.
    }
}

unsigned int PiggyBank::add1Euros(unsigned int n1E)
{
    unsigned int cur = nCent1 + nCent10 + nCent50 + nEuro1;

    if( n1E <= max - cur)     // Falls alle Münzen ins
    {                         // Sparschwein passen.
       nEuro1 += n1E;
       return 0;
    }
    else                      // Das Sparschwein nimmt
    {                         // soviele Münzen wie möglich:
       nEuro1 += (max - cur);
       return n1E - (max - cur);     // Anzahl übrige Münzen.
    }
}

// Die Methode breakInto() bricht das Sparschwein auf und  kopiert
// die Anzahl gefundener Muenzen in in die Parameter c1, c10, c50, e1. 
// Der Return-Wert ist der Geldbetrag in Cents.
unsigned long PiggyBank::breakInto(unsigned int& c1,  unsigned int& c10, 
                                   unsigned int& c50, unsigned int& e1)
{
    fBroken = true;                        // Bricht das Sparschwein auf
                                           // und entnimmt alle Münzen:
    c1 = nCent1, c10 = nCent10, c50 = nCent50, e1 = nEuro1; 
    nCent1 = nCent10 = nCent50 = nEuro1 = 0;

    unsigned long sum = c1 + c10 * 10UL + c50 * 50UL + e1 * 100UL; 
    return sum;
}
 
// Die Methode addCoins() "wirft" eine gegebene Anzahl Münzen ins Sparschwein.
// Die Anzahl Münzen, die nicht ins Sparschwein passen, werden in die 
// Referenz-Parameter zurückgeschrieben.
bool PiggyBank::addCoins( unsigned int& c1,  unsigned int& c10, 
                          unsigned int& c50, unsigned int& e1)
{
    // Wirft Euro-Münzen zuerst ein, dann 50-Cent Stücke usw.:
    if( (e1  = add1Euros(e1)) > 0)   return false;
    if( (c50 = add50Cents(c50)) > 0) return false;
    if( (c10 = add10Cents(c10)) > 0) return false;
    if( (c1  = add1Cents(c1)) > 0)   return false;

    return true;
}

// Die Methode addCoins() bricht ein anderes Sparschwein auf
// und wirft die gefundenen Münzen ins aktuelle Sparschwein.
bool PiggyBank::addCoins(PiggyBank *ptrPB)
{
    if( ptrPB == this || this->isFull() )
       return false;

    unsigned int c1=0, c10=0, c50=0, e1=0;
    ptrPB->breakInto( c1, c10, c50, e1);      // Bricht das Sparschwein *ptrPB auf und
                                              // wirft die Münzen ins aktuelle Sparschwein:
    if( this->addCoins( c1, c10, c50, e1))
        return true;                          // Alle Münzen passen ins Sparschwein.
    else
    {   // Falls das Sparschwein "überläuft", bleiben überzählige Münzen in *ptrPB.
        // c1, c10, c50 und e1 speichern dann die überzähligen Münzen. 
        ptrPB->addCoins( c1, c10, c50, e1);
        return false;
    }
}
