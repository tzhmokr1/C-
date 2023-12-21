#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <array>
using namespace std;
int main()
{
   time_t jetzt;
   struct tm jetztLokal;

   jetzt = time(0);
   cout << "Sekunden seit 1.1.1970 00:00 Uhr UTC: "
      << jetzt << endl;

   jetztLokal = *localtime(&jetzt);

   cout << setfill('0');
   cout << setw(2) << jetztLokal.tm_mday << ".";
   cout << setw(2) << jetztLokal.tm_mon + 1 << ".";
   cout << jetztLokal.tm_year + 1900 << " ";
   cout << setw(2) << jetztLokal.tm_hour << ":";
   cout << setw(2) << jetztLokal.tm_min << ":";
   cout << setw(2) << jetztLokal.tm_sec << endl;

   cout << "Tag im Jahr: " << jetztLokal.tm_yday + 1 << endl;

   array<string,7> tagFeld = {"Sonntag", "Montag", "Dienstag",
      "Mittwoch", "Donnerstag", "Freitag", "Samstag"};
   cout << tagFeld.at(jetztLokal.tm_wday) << endl;
}

