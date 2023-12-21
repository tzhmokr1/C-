// ---------------------------------------------------------
// myFstream.h
// Definition der Klassen FileError und MyFstream.
// FileError ist von der Standardklasse ios::failure abgeleitet.
// MyFstream ist von fstream abgeleitet. Konstruktoren und Methoden
// können Exceptions vom Typ FileError auswerfen.
// ---------------------------------------------------------
#pragma warning( disable : 4250 )               // Für VS 2012
#include <fstream>
#include <string>
using std::fstream;
using std::string;

class FileError : public std::ios::failure
{
    string filename;
  public:
    FileError( const string& fname, const string& message)
    : failure( fname + ": " + message), filename(fname)
    { }
    const char* getFilename() const
    {  return filename.c_str();  }
};

class MyFstream : public fstream
{
    string filename;
    openmode omode; 
  public:
    MyFstream() : omode(0) {}
    MyFstream( const string& fname, openmode mode = in | out )
    : fstream(fname, mode), filename(fname), omode(mode)
// Für ältere Compiler:
//  : fstream(fname.c_str(), mode), filename(fname), omode(mode)
    { 
        if( fail())
        { 
            throw FileError( filename, "Fehler beim Oeffnen");
        }
    }
    const char* getFilename() const
    {  return filename.c_str();  }

    void open( const string& fname, openmode mode = in | out )
    { 
        fstream::open(fname, mode);
        if( good())
        {
            filename = fname;
            omode = mode;
        }
        else 
            throw FileError( filename, "Fehler beim Oeffnen");
    }

    void close()
    {
        fstream::close();
        filename.clear();
        omode = 0;
        if( fail())
            throw FileError( filename, "Fehler beim Schliessen.");
    }

    MyFstream& read( char* s, std::streamsize count )
    {
        if( !(omode & in))
            throw FileError( filename, "Nicht zum Lesen geoeffnet.");
        if( !good()
            || (!fstream::read( s, count) && !eof()) )
            throw FileError( filename, "Fehler beim Lesen.");
        return *this;
    }
    MyFstream& write( const char* s, std::streamsize count )
    {
        if( !(omode & out))
            throw FileError( filename, "Nicht zum Schreiben geoeffnet.");
        if( !fstream::write( s, count))
            throw FileError( filename, "Fehler beim Schreiben.");
        return *this;
    }

    MyFstream& seekg( pos_type pos )
    {
        if( !bad()) clear();   // evtl. gesetztes eof-Bit bzw. fail-Bit löschen.
        if( !fstream::seekg(pos))
            throw FileError( filename, "Fehler beim Positionieren.");
        return *this;
    }

    MyFstream& seekg( off_type off, seekdir dir)
    {
        if( !bad()) clear();   // evtl. gesetztes eof-Bit bzw. fail-Bit löschen.
        if( !fstream::seekg( off, dir))
            throw FileError( filename, "Fehler beim Positionieren.");
        return *this;
    }
    MyFstream& seekp( pos_type pos )
    {
        if( !bad()) clear(); 
        if( !fstream::seekp(pos))
            throw FileError( filename, "Fehler beim Positionieren.");
        return *this;
    }

    MyFstream& seekp( off_type off, seekdir dir)
    {
        if( !bad()) clear();
        if( !fstream::seekp( off, dir))
            throw FileError( filename, "Fehler beim Positionieren.");
        return *this;
    }
};
