#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class figur
{
   private:
      double x,y;
      string farbe;
   public:
      void werteZuweisen(const double&,
         const double&, const string&);
      void verschieben(const double &, const double&);
      void faerben(const string&);
      void ausgeben();
};

void figur::werteZuweisen(const double &xPos,
   const double &yPos, const string &f)
{
   x = xPos;
   y = yPos;
   farbe = f;
}

void figur::verschieben(const double &xDelta, const double &yDelta)
{
   x += xDelta;
   y += yDelta;
}

void figur::faerben(const string &f)
{
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
      void werteZuweisen(const double&, const double&,
         const string&, const double&, const double&);
      void skalieren(const double&, const double&);
      double flaeche();
      void ausgeben();
};

void rechteck::werteZuweisen(
   const double &xPos, const double &yPos,
   const string &f, const double &h, double const &b)
{
   figur::werteZuweisen(xPos, yPos, f);
   hoehe = h;
   breite = b;
}

void rechteck::skalieren(
   const double &hoeheFaktor, const double &breiteFaktor)
{
   hoehe *= hoeheFaktor;
   breite *= breiteFaktor;
}

double rechteck::flaeche()
{
   return hoehe * breite;
}

void rechteck::ausgeben()
{
   figur::ausgeben();
   cout << " Rechteck: " << hoehe << " / " << breite << endl;
}

class kreis:public figur
{
   private:
      double radius;
   public:
      void werteZuweisen(const double&,
         const double&, const string&, const double&);
      void skalieren(const double&);
      double flaeche();
      void ausgeben();
};

void kreis::werteZuweisen(const double &xPos,
   const double &yPos, const string &f, const double &r)
{
   figur::werteZuweisen(xPos, yPos, f);
   radius = r;
}

void kreis::skalieren(const double &radiusFaktor)
{
   radius *= radiusFaktor;
}

double kreis::flaeche()
{
   return 4 * atan(1.0) * radius * radius;
}

void kreis::ausgeben()
{
   figur::ausgeben();
   cout << " Kreis: " << radius << endl;
}

int main()
{
   // Rechteck
   rechteck ra;
   ra.werteZuweisen(7.4, 2.3, "Blau", 4.0, 2.6);
   ra.ausgeben();

   ra.skalieren(0.5, 3.0);
   ra.verschieben(2.8, 4.2);
   ra.faerben("Schwarz");
   ra.ausgeben();

   cout << "Rechteck, Flaeche: " << ra.flaeche() << endl << endl;

   // Kreis
   kreis ka;
   ka.werteZuweisen(4.6, 1.7, "Blau", 2.3);
   ka.ausgeben();

   ka.skalieren(2.0);
   ka.verschieben(3.3, 2.4);
   ka.faerben("Weiss");
   ka.ausgeben();

   cout << "Kreis, Flaeche: " << ka.flaeche() << endl;
}

