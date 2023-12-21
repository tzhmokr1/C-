// ----------------------------------------------
// file_error.h
// Fehlerklassen für Textdateien
// ----------------------------------------------

#ifndef _FILE_ERROR_
#define _FILE_ERROR_

#include <string>
using namespace std;

class FileError
{
  private:
   string filename;
  public:
   FileError(const string& s){ filename = s; }
   virtual string  what() const { return filename;}
};

class OpenError : public FileError 
{
  public:
   OpenError(const string& s) : FileError(s){}
   string what() const
   {
      return "Fehler beim Oeffnen der Datei " 
              + FileError::what();
   }
};

class ReadError : public FileError 
{
public:
   ReadError(const string& s) : FileError(s){}
   string what() const
   {
      return "Fehler beim Lesen der Datei " 
              + FileError::what();
   }
};

class WriteError : public FileError 
{
public:
   WriteError(const string& s) : FileError(s){}
   string what()const
   {
      return "Fehler beim Schreiben in die Datei "
              + FileError::what();
   }
};

#endif  // _FILE_ERROR_
