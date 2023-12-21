#include <string>
class postenTyp
{
   private:
      int anzahl;
      double preis;
      string bezeichnung;
   public:
      void werteZuweisen(const int&, const double&, const string&);
      void ausgeben();
};

