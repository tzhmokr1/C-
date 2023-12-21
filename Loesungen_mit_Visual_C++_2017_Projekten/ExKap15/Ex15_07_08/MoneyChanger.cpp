// --------------------------------------------------------
// MoneyChanger.cpp
// Definiert die statischen Datenelemente und die
// Methode round() der Klasse MoneyChanger.
// --------------------------------------------------------

#include <math.h>
#include "MoneyChanger.h"

double MoneyChanger::rateCND = 1.561;
double MoneyChanger::rateYEN = 121.2;

double MoneyChanger::round( double x)
{
    return floor(x*100.0 + 0.5) / 100.0;
}
