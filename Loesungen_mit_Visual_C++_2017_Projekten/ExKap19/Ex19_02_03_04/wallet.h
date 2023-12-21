// ---------------------------------------------------------
// wallet.h
// Definiert die Klasse Wallet.
// Bestimmen Sie die Fehler in der Klassendefinition.
// ---------------------------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;
/*
class Wallet
{
  private:
    long amount;            // Geldbetrag in Cents
    
  public:
    Wallet(long cents=0) : amount(cents) {}
    
    long getAmount() const { return amount; }

    // Geld in die Geldbörse legen:
    Wallet& operator+=( const Wallet& w1, long cents)
    {
       w1.amount = w1.amount + cents;
       return *this; 
    }

    // Das Geld aus einer anderen Geldbörse hinzufügen:
    Wallet& operator+=( Wallet& w)
    {
       Wallet* this;
       this->amount += w.amount;
       return *this; 
    }

    // Geld aus der Geldbörse entnehmen:
    Wallet& operator-=( long& cents) const
    {
       if( amount >= cents)
          amount -= cents;
       else
           cents = 0L;
       return *this; 
    }

    // Den Inhalt von zwei Geldbörsen vergleichen:
    friend bool operator==( const Wallet& w) const;
    friend Wallet::operator<(const Wallet& w1, const Wallet& w2);
};

// Die globalen Operatorfunktionen:
inline bool operator==( const Wallet& w1, const Wallet& w2)
{
   return (this.amount == w2.amount);
}

friend bool operator<(const Wallet& w1, const Wallet& w2)
{
   return ( w1.amount < w2.amount);
}
*/

// ----- Richtige Version: -----

class Wallet
{
  private:
    long amount;                         // Geldbetrag in Cents
    
  public:
    Wallet(long cents=0) : amount(cents) {}
    
    long getAmount() const { return amount; }

    Wallet& operator+=( long cents)      // Geld hinzufügen
    {
       amount += cents;
       return *this; 
    }

    Wallet& operator+=( Wallet& w)       // Geld aus einer anderen 
    {                                    // Geldbörse hinzufügen.
       this->amount += w.amount;
       w.amount = 0L;
       return *this; 
    }

    Wallet& operator-=( long& cents)    // Geld entnehmen
    {
       if( amount >= cents)
          amount -= cents;
       else
           cents = 0L;
       return *this; 
    }

    // Inhalt von zwei Geldbörsen vergleichen:
    friend bool operator==(const Wallet& w1, const Wallet& w2);
    friend bool operator<( const Wallet& w1, const Wallet& w2);
};

// Globale Operatorfunktionen:
inline bool operator==( const Wallet& w1, const Wallet& w2)
{
   return (w1.amount == w2.amount);
}

inline bool operator<(const Wallet& w1, const Wallet& w2)
{
   return ( w1.amount < w2.amount);
}

inline ostream& operator<<(ostream& os, const Wallet& w)
{
   double euro = w.getAmount()/100.0;     // Geldbetrag in Euros.
   long osFlags = os.flags();             // Flags sichern.
   os << fixed << setprecision(2) << setw(8)
      << euro << " EUR";
   os.flags(osFlags);                     // Flags wiederherstellen. 
   return os;
}
