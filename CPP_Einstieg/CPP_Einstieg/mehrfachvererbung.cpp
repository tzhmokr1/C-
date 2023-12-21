#include <iostream>
#include <string>
using namespace std;

class figur
{
   private:
      double x,y;
      string farbe;
   public:
      figur(const double&, const double&, const string&);
      void ausgeben();
};

figur::figur(const double &xPos, const double &yPos, const string &f)
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
      rechteck(const double&, const double&, const string&, const double&, const double&);
      void ausgeben();
};

rechteck::rechteck(const double &xPos, const double &yPos, const string &f, const double &h, const double &b):figur(xPos, yPos, f)
{
   hoehe = h;
   breite = b;
}

void rechteck::ausgeben()
{
   figur::ausgeben();
   cout << " Rechteck: " << hoehe << " / " << breite << endl;
}

class textzeile
{
   private:
      string inhalt;
      string art;
      string farbe;
      double groesse;
   public:
      textzeile(const string&, const string&,
         const string &, const double&);
      void ausgeben();
};

textzeile::textzeile(const string &i, const string &a,
   const string &f, const double &g)
{
   inhalt = i;
   art = a;
   farbe = f;
   groesse = g;
}

void textzeile::ausgeben()
{
   cout << "Textzeile: " << inhalt << " " << art
      << " " << farbe << " " << groesse << endl;
}

class rechteckTextzeile:public rechteck, public textzeile
{
   private:
      string ausrichtung;
   public:
      rechteckTextzeile(
         const double&, const double&, const string&,
            const double&, const double&,
         const string&, const string&, const string&, const double&,
         const string&);
      void ausgeben();
};

rechteckTextzeile::rechteckTextzeile(
      const double &xPos, const double &yPos, const string &fr,
         const double &h, const double &b,
      const string &tx, const string &art,
         const string &ft, const double &groesse,
      const string &aus):
   rechteck(xPos, yPos, fr, h, b),
   textzeile(tx, art, ft, groesse)
{
   ausrichtung = aus;
}

void rechteckTextzeile::ausgeben()
{
   rechteck::ausgeben();
   textzeile::ausgeben();
   cout << "Rechteck-Textzeile: " << ausrichtung << endl;
}

int main()
{
   textzeile ta("Guten Morgen", "Tahoma", "Schwarz", 12);
   ta.ausgeben();
   cout << endl;

   rechteckTextzeile rta(
      5.2, 1.8, "Blau", 1.2, 3.5,
      "Hallo Welt", "Arial", "Rot", 8.5,
      "Zentriert");
   rta.ausgeben();
}

