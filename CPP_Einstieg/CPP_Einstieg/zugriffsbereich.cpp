#include <iostream>
#include <string>
using namespace std;

class figur
{
   private:
      double x,y;
   protected:
      string farbe;
   public:
      void werteZuweisen(const double&,
         const double&, const string&);
      void ausgeben();
};

void figur::werteZuweisen(const double &xPos, const double &yPos, const string &f)
{
   x = xPos;
   y = yPos;
   farbe = f;
}

void figur::ausgeben()
{
   cout << "Figur: " << x << " / " << y << " " << farbe;
}

class rechteck:public figur
{
   private:
      double hoehe, breite;
   public:
      void werteZuweisen(const double&, const double&, const string&, const double&, const double&);
      void ausgeben();
      void ausgebenFarbe();
};

void rechteck::werteZuweisen(const double &xPos, const double &yPos, const string &f, const double &h, const double &b)
{
   figur::werteZuweisen(xPos, yPos, f);
   hoehe = h;
   breite = b;
}

void rechteck::ausgeben()
{
   figur::ausgeben();
   cout << " Rechteck: " << hoehe << " / " << breite << endl;
}

void rechteck::ausgebenFarbe()
{
   cout << "Farbe: " << farbe << endl;
}

int main()
{
   rechteck ra;
   ra.werteZuweisen(7.4, 2.3, "Blau", 4.0, 2.6);
   ra.ausgeben();
   ra.ausgebenFarbe();
   // cout << ra.farbe << endl;
}

