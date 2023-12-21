// ------------------------------------------------------
// ex23_06.cpp
// Klasse MyString verwenden.
// ------------------------------------------------------
#include "myString.h"
#include <iostream>
using namespace std;

int main()
{
    MyString str1 = "What a wonderful world!",
             line(60, '-');              // String mit 60 ' '

    cout << str1 << endl
         << str1.toUpper() << endl
         << str1.toLower() << endl;

    MyString str2( str1.toUpper(), 7);   // Teilstrin ab Index 7 
    cout << line << endl
         << str2.center(60) << endl
         << line << endl;

    MyString str3 = "\n\t String mit Zwischenraumzeichen \t"; 
    cout << '>' << str3 << '<' << endl;

    str3.eraseLeadingWS();
    str3.eraseTrailingWS();
    cout << "\nDer String ohne fuehrende und abschliessende Zwischenraumzeichen:\n"
         << '>' << str3 << '<' << endl;           

    return 0;
}
