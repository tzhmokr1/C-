#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

class figur
{
   private:
      double x,y;
      string farbe;
   public:
      figur(const double&, const double&, const string&);
      void verschieben(const double&, const double&);
      void faerben(const string&);
      virtual double flaeche(){return 0.0;};
      virtual void ausgeben();
};

figur::figur(const double &xPos, const double &yPos, const string &f)
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

void figur::faerben(const string &farbeNeu)
{
   farbe = farbeNeu;
}

void figur::ausgeben()
{
   cout << "Figur: " << x << " / " << y << " " << farbe << endl;
}

class rechteck:public figur
{
   private:
      double hoehe, breite;
   public:
      rechteck(const double&, const double&, const string&, const double&, const double&);
      void skalieren(const double&, const double&);
      double flaeche();
      void ausgeben();
};

rechteck::rechteck(const double &xPos, const double &yPos, const string &f, const double &h, const double &b):figur(xPos, yPos, f)
{
   hoehe = h;
   breite = b;
}

void rechteck::skalieren(const double &hoeheFaktor, const double &breiteFaktor)
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
   cout << "   Rechteck: " << hoehe << " / " << breite << endl;
}

class kreis:public figur
{
   private:
      double radius;
   public:
      kreis(const double&, const double&, const string&, const double&);
      void skalieren(const double&);
      double flaeche();
      void ausgeben();
};

kreis::kreis(const double &xPos, const double &yPos, const string &f, const double &r):figur(xPos, yPos, f)
{
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
   cout << "   Kreis: " << radius << endl;
}

int main()
{
   figur fa(2.9, 1.2, "Schwarz");
   rechteck ra(7.4, 2.3, "Blau", 4.0, 2.6);
   kreis ka(4.6, 1.7, "Rot", 2.3);
   kreis kb(3.8, 0.5, "Gelb", 3.5);

   vector<figur *> figurZeigerFeld;
   figurZeigerFeld.push_back(&fa);
   figurZeigerFeld.push_back(&ra);
   figurZeigerFeld.push_back(&ka);
   figurZeigerFeld.push_back(&kb);

   double summeFlaeche = 0;
   for(figur *fz:figurZeigerFeld)
   {
      (*fz).verschieben(1.0, 1.0);
      (*fz).ausgeben();
      summeFlaeche += (*fz).flaeche();
   }
   cout << "Summe: " << summeFlaeche << endl;
}

