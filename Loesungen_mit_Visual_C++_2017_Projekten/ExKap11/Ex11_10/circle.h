// --------------------------------------------------------
// circle.h
// Definition des Namensbereichs Circle.
// --------------------------------------------------------
namespace Circle
{
   static double r = 1.0;
   static const double pi = 3.1415927;

   void   setRadius( double rd){ r = rd;}
   double getCircumference() { return 2*pi*r;}
   double getArea(){ return pi*r*r;}
}
