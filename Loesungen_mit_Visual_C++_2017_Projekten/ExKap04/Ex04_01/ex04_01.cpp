// --------------------------------------------------------
// ex04_01.cpp
// Das Programm gibt die Zahl 255 aus, und zwar
//     mit positivem Vorzeichen,
//     als Hexadezimalzahl mit Groﬂbuchstaben,
//     als Hexadezimalzahl mit Kleinbuchstaben,
//     als Dezimalzahl ohne Vorzeichen.
// --------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
   cout << showpos           << 255 << "    "
        << uppercase  << hex << 255 << "    "
        << nouppercase       << 255 << "    "
        << noshowpos  << dec << 255 << endl;

   return 0;
}
