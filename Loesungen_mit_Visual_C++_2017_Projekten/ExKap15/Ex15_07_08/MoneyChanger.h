// --------------------------------------------------------
// MoneyChanger.h
// Definiert die Klasse MoneyChanger.
// --------------------------------------------------------
#include <iostream>
using namespace std;

class MoneyChanger
{
  private:
    double amount;            // in Euro
    static double rateCND;    // e.g.   1.561  (= 1 EUR)
    static double rateYEN;    // e.g. 121.2    (= 1 EUR)

  public:
    MoneyChanger( double a = 0.0)
    { 
      if( !setAmount(a))
      {  cerr << "Kein negativer Geldbetrag!" << endl;
         amount = 0.0;
      }
    }
    bool setAmount( double a)
    { 
       if( a >= 0.0) { amount = round(a);  return true; }
       else  return false;
    }
    double getEUR() const { return amount; }
    double getCND() const { return round(amount * rateCND); }
    double getYEN() const { return round(amount * rateYEN); }

    // Statische Methoden
    static double round( double x);
    static double getRateCND() { return rateCND;}
    static double getRateYEN() { return rateYEN;}
    static void   setRateCND(double r) { rateCND = r; }
    static void   setRateYEN(double r) { rateYEN = r; }
};
