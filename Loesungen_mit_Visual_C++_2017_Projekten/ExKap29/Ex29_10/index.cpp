// ------------------------------------------------------
// index.cpp: Implementiert Methoden der Klasse IndexFile.
// ------------------------------------------------------
#include "index.h"

IndexFile::IndexFile(const string& file)
{ 
   open(file, mode);    // �ffnen, falls Datei existiert.
   if( fail())          // Neue Datei erzeugen,
   {                    // falls Datei nicht vorhanden.
      clear();
      open(file, mode|ios::trunc);
   }
   if(!fail())
      name = file;
}

// Neuen Eintrag (key,pos) in die Indexdatei einf�gen.
// Return-Wert: true, im Fehlerfall false.
bool IndexFile::insert(unsigned long key, long long pos)
{
    IndexEntry entry;
    long long ip = search( key, entry);
    if( ip < 0 || key == entry.getKey() ) // Lesefehler oder 
        return false;                     // key schon vorhanden.

    seekg(0, ios::end);
    // Anzahl Eintr�ge vor und nach der Einf�geposition:
    long long n1 = ip / (long long)sizeof(entry),
              n2 = (tellg() / (long long)sizeof(entry)) - n1;

    if( n2 <= n1*0.1)      // F�r kleine n2, neuen Eintrag direkt
    {                      // in bestehender Datei einf�gen.
        if( _insert( key, pos) ) return true;
        else                     return false;
    }

    // In neue Indexdatei kopieren und dabei neuen Eintrag einf�gen:
    string tempname(name + ".tmp");
    fstream fs( tempname, ios::out | ios::binary);
    if( !fs.is_open())
        return false;
    seekg(0);                         // In der Quelldatei
    for( long long i=0; i < n1; ++i)  // 1. Teil kopieren.
    {
        entry.read(*this);
        entry.write(fs);
    }
    IndexEntry(key,pos).write(fs);    // Neuer Eintrag.
    for( long long i=0; i < n2; ++i)  // 2. Teil kopieren.
    {
        entry.read(*this);
        entry.write(fs);
    }
    fs.close();
    if( fs.fail()) 
    {
        remove( tempname.c_str());
        return false;
    }
    close();
    remove( name.c_str());
    rename( tempname.c_str(), name.c_str());

    open( name, mode);
    if( is_open()) return true;
    else           return false; 
}

// Hilfsfunktion f�r das Einf�gen nahe dem Ende der Datei:
bool IndexFile::_insert(unsigned long key, long long pos)
{
    IndexEntry entry;
    int size = (int)sizeof(entry);  // L�nge eines Index-Eintrags.

    clear(); 
    seekg(0, ios::end);
    long long ip = tellg();   // Postion in der Indexdatei.
                              // Dateil�nge. 0, falls Datei leer.
    if( fail()) return false;

    ip-= size;                        // Letzter Eintrag.
    bool found = false;
    while( ip >= 0 && !found )        // Position zum Einf�gen suchen
    {
       if(!entry.read_at(*this, ip))
           return false;
       if( key <= entry.getKey())   // Shiften, um Platz zu machen.
       {
          if( !entry.write_at(*this, ip + size))
              return false;
          ip -= size;
       }
       else                         // Einf�geposition gefunden.
       {
         found = true;
       }
    }
    entry.setKey(key);  entry.setPos(pos);   // Einfuegen.
    if( !entry.write_at(*this, ip + size))
        return false;
    return true;
}

// Eintrag mit dem Schl�ssel key suchen.
// Return-Wert: Position in der Indexdatei oder -1.
long long IndexFile::search(unsigned long key)
{
   IndexEntry entry;
   long long pos = search( key, entry);
   if( pos >= 0 && key == entry.getKey() )
       return pos;
   else return -1;
}

// Einf�geposition f�r key suchen und vorhandenen Eintrag
// auf dieser Position in das zweite Argument kopieren, falls
// Einf�geposition nicht das Dateiende ist.
// Return-Wert: Einf�geposition oder -1 im Fehlerfall.
// (Externes bin�res Suchenverfahren.)
long long IndexFile::search(unsigned long key, IndexEntry &indEntry)
{
   IndexEntry entry;                    // Ein Indexeintrag und
   int entrysize = (int)sizeof(entry);  // und seine L�nge.
   long long mid, begin = 0, end;       // Datensatznummern.
   long long filesize;                  // Dateil�nge.

   clear();
   seekg(0L, ios::end);                 // Dateil�nge holen.
   filesize = tellg();
   if( fail())
       return -1;

   end = filesize / entrysize;
   while( begin < end )
   {
       mid = (begin + end)/2;
       entry.read_at(*this, mid*entrysize);
       if( fail())
         return -1;

       if( key < entry.getKey())
           end = mid;
       else if( key > entry.getKey())
           begin = mid+1;
       else 
       {   begin = mid; break; }        // gefunden
   }

   if( begin * entrysize == filesize)
      indEntry = IndexEntry();
   else
      indEntry.read_at(*this, begin * entrysize);
   
   if( fail())
      return -1;
   else
      return begin * entrysize;
 }

void IndexFile::display()
{
    IndexEntry entry;

    seekg(0L);
    if(fail())
        return;
    cout << "\nDer Index: " << endl;
    while( true)
    {
       if( !entry.read(*this))
           break;
       entry.display();
    }
    if( eof())        // Dateiende wurde erreicht.
       clear(); 
}
