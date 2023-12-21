#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void ausgabe(time_t *ttz)
{
   struct tm stx = *localtime(ttz);

   cout << setfill('0');
   cout << setw(2) << stx.tm_mday << ".";
   cout << setw(2) << stx.tm_mon + 1 << ".";
   cout << stx.tm_year + 1900 << " ";
   cout << setw(2) << stx.tm_hour << ":";
   cout << setw(2) << stx.tm_min << ":";
   cout << setw(2) << stx.tm_sec << endl;
}

int main()
{
   struct tm st;
   time_t tt;

   st.tm_mday = 27;  st.tm_mon = 1;  st.tm_year = 117;
   st.tm_hour = 22;  st.tm_min = 55;  st.tm_sec = 30;
   tt = mktime(&st);
   cout << tt << endl;
   ausgabe(&tt);

   st.tm_sec += -10;
   st.tm_min += 190;
   st.tm_mday += 1;
   tt = mktime(&st);
   cout << tt << endl;
   ausgabe(&tt);
}

