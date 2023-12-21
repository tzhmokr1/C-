// ---------------------------------------------------
// piggyBank.h 
// Definiert die Klasse PiggyBank mit
// der Methode isLighterThan().
// ---------------------------------------------------
#ifndef _PIGGYBANK_       // Keine Mehrfach-Inkludierung.
#define _PIGGYBANK_

class PiggyBank
{
   private:
     // Anzahl 1-Cent, 10-Cent, 50-Cent und 1-Euro Münzen:
     unsigned int nCent1, nCent10, nCent50, nEuro1;
     unsigned int max;     // Maximale Anzahl Münzen
     bool fBroken;         // Flag für aufgebrochenes Sparschwein

   public:
      PiggyBank( unsigned int c_max);   // Konstruktor

      bool isEmpty();
      bool isFull();
      bool isBroken();

      unsigned int add1Cents(unsigned int n1C);
      unsigned int add10Cents(unsigned int n10C);
      unsigned int add50Cents(unsigned int n50C);
      unsigned int add1Euros(unsigned int n1E);

      bool addCoins(unsigned int& c1,  unsigned int& c10, unsigned int& c50, unsigned int& e1);

      bool addCoins(PiggyBank *ptrPB);

      unsigned long breakInto(unsigned int& c1,  unsigned int& c10, unsigned int& c50, unsigned int& e1);

      bool isLighterThan( const PiggyBank& pb2);
};

#endif   //  _PIGGYBANK_
