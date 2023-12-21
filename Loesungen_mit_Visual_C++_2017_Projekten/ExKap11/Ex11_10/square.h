// --------------------------------------------------------
// circle.h
// Definition des Namensbereichs Square.
// --------------------------------------------------------
namespace Square
{
   static double s = 1.0;

   void   setSide( double sd){ s = sd;}
   double getCircumference(){ return 4*s;}
   double getArea(){ return s*s;}
}
