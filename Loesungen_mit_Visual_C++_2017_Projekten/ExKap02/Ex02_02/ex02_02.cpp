// ---------------------------------------------------------
// ex02_02.cpp
// Gibt die kleinsten und größten Werte 
// für die Datentypen char and wchar_t aus.
// ---------------------------------------------------------

#include <iostream>
#include <climits>
using namespace std;

int main()
{
   cout << "Wertebereich der Typen char und wchar_t" << endl << endl;
   cout << "Typ        Minimum      Maximum"         << endl;
   cout << "--------------------------------"
        << endl;
   cout << "char        " <<  CHAR_MIN << "         " 
                          <<  CHAR_MAX << endl;
   cout << "wchar_t     " << WCHAR_MIN << "            " 
                          << WCHAR_MAX << endl;
   return 0;
}
