// ----------------------------------------------------
// piggyBank.h 
// Definiert die Klasse PiggyBank.
// ----------------------------------------------------
#ifndef _PIGGYBANK_       
#define _PIGGYBANK_

class PiggyBank
{
  private:
    // Anzahl 1-Cent, 10-Cent, 50-Cent und 1-Euro Stücke:
    unsigned int nCent1, nCent10, nCent50, nEuro1;
    unsigned int max;     // Maximale Anzahl Münzen
    bool fBroken;         // Flag für aufgebrochenes 
                          // Sparschwein
  public:
    void init( unsigned int m);
    bool isEmpty();
    bool isFull();
    bool isBroken();

    unsigned int add1Cents(unsigned int n1C);
    unsigned int add10Cents(unsigned int n10C);
    unsigned int add50Cents(unsigned int n50C);
    unsigned int add1Euros(unsigned int n1E);

    unsigned long breakInto( unsigned int& c1,
                             unsigned int& c10,
                             unsigned int& c50,
                             unsigned int& e1);
};
#endif   //  _PIGGYBANK_
