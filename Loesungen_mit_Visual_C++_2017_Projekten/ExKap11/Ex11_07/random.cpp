// --------------------------------------------------------
// random.cpp
// Definiert die Funktionen randInt() und randDouble().
// --------------------------------------------------------

#include <time.h>

namespace myLib
{
  static long m = 32768;
  static long b = 9757;
  static long c = 6925;

  // --------------------------------------------------------
  // Function randInt() 
  // Liefert eine ganze Pseudo-Zufallszahl zwischen 0 und m-1. 
  //
  int randInt()
  {
     static int n = (int)(time(0) % m);  // Der Keim

     n = (int)((n * b + c) % m);

     return n;
  }

  // -------------------------------------------------------------
  // Funktion randDouble() 
  // Liefert eine gebrochene Pseudo-Zufallszahl im Intervall [0,1) 
  //
  double randDouble()
  {
      return (double)randInt() / m;
  }

} // namespace myLib
