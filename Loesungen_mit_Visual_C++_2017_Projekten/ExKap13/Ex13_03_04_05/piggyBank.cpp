// ------------------------------------------------------
// piggyBank.cpp
// Definiert die Methoden der Klasse PiggyBank.
// ------------------------------------------------------
#include "piggyBank.h"              // Klassendefinition 

// Die Methode init() initialisiert jedes Datenelement.
void PiggyBank::init( unsigned int i_max)
{
   max = i_max;         // Maximale Anzahl M�nzen
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

unsigned int PiggyBank::add1Cents(unsigned int n1C)
{
   unsigned int cur = nCent1 + nCent10 + nCent50 + nEuro1;

   if( n1C <= max - cur)      // Falls alle M�nzen ins
   {                          // Sparschwein passen:
      nCent1 += n1C;
      return 0;
   }
   else                      // Das Sparschwein nimmt so
   {                         // viele M�nzen wie m�glich:
      nCent1 += (max - cur);
      return n1C - (max - cur);   // Anzahl �brige M�nzen.
   }
}

unsigned int PiggyBank::add10Cents(unsigned int n10C)
{
   unsigned int cur = nCent1 + nCent10 + nCent50 + nEuro1;

   if( n10C <= max - cur)      // Falls alle M�nzen ins
   {                           // Sparschwein passen:
      nCent10 += n10C;
      return 0;
   }
   else                      // Das Sparschwein nimmt so
   {                         // viele M�nzen wie m�glich:
      nCent10 += (max - cur);
      return n10C - (max - cur);  // Anzahl �brige M�nzen.
   }
}

unsigned int PiggyBank::add50Cents(unsigned int n50C)
{
   unsigned int cur = nCent1 + nCent10 + nCent50 + nEuro1;

   if( n50C <= max - cur)      // Falls alle M�nzen ins
   {                           // Sparschwein passen:
      nCent50 += n50C;
      return 0;
   }
   else                      // Das Sparschwein nimmt so
   {                         // viele M�nzen wie m�glich:
      nCent50 += (max - cur);
      return n50C - (max - cur);  // Anzahl �brige M�nzen.
   }
}

unsigned int PiggyBank::add1Euros(unsigned int n1E)
{
   unsigned int cur = nCent1 + nCent10 + nCent50 + nEuro1;

   if( n1E <= max - cur)      // Falls alle M�nzen ins
   {                          // Sparschwein passen:
      nEuro1 += n1E;
      return 0;
   }
   else                      // Das Sparschwein nimmt so
   {                         // viele M�nzen wie m�glich:
      nEuro1 += (max - cur);
      return nEuro1 - (max - cur);  // Anzahl �brige M�nzen.
   }
}

// ---------------------------------------------------------
// Die Methode breakInto() bricht das Sparschwein auf und 
// schreibt die Anzahl gefundener M�nzen in die Referenz- 
// Parameter c1, c10, c50, e1. 
// Der Return-Wert ist der Geldbetrag in Cents.

unsigned long PiggyBank::breakInto( unsigned int& c1, unsigned int& c10, 
                                    unsigned int& c50, unsigned int& e1)
{
   fBroken = true;           // Bricht das Sparschwein auf
                             // und entnimmt alle M�nzen:
   c1 = nCent1, c10 = nCent10, c50 = nCent50, e1 = nEuro1; 
   nCent1 = nCent10 = nCent50 = nEuro1 = 0;

   unsigned long sum = c1 + c10*10UL + c50*50UL + e1*100UL; 
   return sum;
}
