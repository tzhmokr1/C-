#include <iostream>
#include <string>
using namespace std;

class figur
{
   private:
      double x,y;
      string farbe;
   public:
      figur();
      figur(const double&, const double&, const string&);
      void ausgeben();
      ~figur();
};

figur::figur()
{
   cout << "figur-Konstruktor ohne Parameter" << endl;
}

figur::figur(const double &xPos,
   const double &yPos, const string &f)
{
   cout << "figur-Konstruktor mit Parametern" << endl;
   x = xPos;
   y = yPos;
   farbe = f;
}

void figur::ausgeben()
{
   cout << "Figur: " << x << " / " << y << " " << farbe;
}

figur::~figur()
{
   cout << "figur-Destruktor" << endl << endl;
}

class rechteck:public figur
{
   private:
      double hoehe, breite;
   public:
      rechteck();
      rechteck(const double&, const double&,
         const string&, const double&, const double&);
      void ausgeben();
      ~rechteck();
};

rechteck::rechteck()
{
   cout << "rechteck-Konstruktor ohne Parameter" << endl;
}

rechteck::rechteck(
   const double &xPos, const double &yPos, const string &f,
   const double &h, const double &b):figur(xPos, yPos, f)
{
   cout << "rechteck-Konstruktor mit Parametern" << endl;
   hoehe = h;
   breite = b;
}

void rechteck::ausgeben()
{
   figur::ausgeben();
   cout << " Rechteck: " << hoehe << " / " << breite << endl;
}

rechteck::~rechteck()
{
   cout << "rechteck-Destruktor" << endl;
}

int main()
{
   rechteck ra(7.4, 2.3, "Blau", 4.0, 2.6);
   ra.ausgeben();
   cout << endl;
   
   rechteck rb;
   cout << endl;
}

