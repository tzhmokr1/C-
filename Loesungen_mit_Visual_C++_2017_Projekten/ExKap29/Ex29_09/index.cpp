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
