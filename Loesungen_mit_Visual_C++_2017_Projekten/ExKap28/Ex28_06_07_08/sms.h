// ----------------------------------------------
// sms.h
// Definition der Klasse SMS
// ----------------------------------------------

#ifndef _SMS_
#define _SMS_

#include <cstring>
#include <fstream>
using namespace std;

#include "file_error.h"

class SMS
{
  private:
   string filename;
   int len;

  public:
   SMS(const string& s): filename(s), len(0) {}
   
   void write(const char* mes)  
    { 
      len = strlen(mes);
      
      ofstream ofs(filename, ios::binary);
      if(!ofs)
        throw OpenError(filename);
      
      len++;        // Laenge der Kurznachricht 
                    // mit Stringendezeichen
                    // Laenge in Datei schreiben:
      if(!ofs.write((char*)&len, sizeof(int)))  
          throw WriteError(filename);
                    // Kurznachricht schreiben:
      if(!ofs.write(mes, len))                  
          throw WriteError(filename);
      
      ofs.close();
      
   }

   void read(char* mes)
   { 
      ifstream ifs(filename, ios::binary);
      if(!ifs)                                   
          throw OpenError(filename);            
                         // Dateilaenge einlesen:
      if(!ifs.read((char*)&len, sizeof(int)))  
          throw ReadError(filename);
                         // Kurznachricht einlesen:
      if(!ifs.read(mes, len))                  
          throw ReadError(filename);
      ifs.close();                              
   }
};
   
#endif // _SMS_
