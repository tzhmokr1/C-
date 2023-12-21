#include <iostream>
#include <sys/stat.h>
using namespace std;
int main()
{
   char datei[] = "C:/Temp/hallo.cpp";
   struct stat attr;
   stat(datei, &attr);
   if(attr.st_mode & S_IWRITE)
      cout << "Schreibrecht" << endl;

   chmod(datei, S_IREAD);
   stat(datei, &attr);
   if(!(attr.st_mode & S_IWRITE))
      cout << "Kein Schreibrecht" << endl;

   chmod(datei, S_IREAD | S_IWRITE);
   stat(datei, &attr);
   if(attr.st_mode & S_IWRITE)
      cout << "Schreibrecht" << endl;
}

