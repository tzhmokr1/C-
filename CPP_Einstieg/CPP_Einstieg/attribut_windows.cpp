#include <iostream>
#include <iomanip>
#include <sys/stat.h>
#include <ctime>
using namespace std;

int main()
{
   struct stat attr;
   if(stat("C:/Temp/hallo.cpp", &attr))
   {
      cout << "Kein Zugriff auf Dateiattribute" << endl;
      return 1;
   }
   
   if(attr.st_mode & S_IFREG)
      cout << "Datei" << endl;
   else if(attr.st_mode & S_IFDIR)
      cout << "Verzeichnis" << endl;

   if(attr.st_mode & S_IREAD)
      cout << "Leserecht" << endl;
   if(attr.st_mode & S_IWRITE)
      cout << "Schreibrecht" << endl;

   cout << "Byte: " << attr.st_size << endl;
   cout << "Letzter Zugriff: " << attr.st_atime << " = ";

   struct tm zugriff = *localtime(&attr.st_atime);

   cout << setfill('0');
   cout << setw(2) << zugriff.tm_mday << ".";
   cout << setw(2) << zugriff.tm_mon + 1 << ".";
   cout << zugriff.tm_year + 1900 << " ";
   cout << setw(2) << zugriff.tm_hour << ":";
   cout << setw(2) << zugriff.tm_min << ":";
   cout << setw(2) << zugriff.tm_sec << endl;
}

