// ----------------------------------------------------------  
// index.h:  Enthält die Definition der Klassen
//           IndexEntry zur Darstellung eines Indexeintrags, 
//           IndexFile  zur Darstellung einer Indexdatei.
// ----------------------------------------------------------  
#ifndef _INDEX_H
#define _INDEX_H

#pragma warning( disable : 4250 )               // Für VS 2012
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class IndexEntry
{
  private:
    unsigned long key;
    long long position;      //Byteposition in der Primärdatei
  public:
    IndexEntry(unsigned long k=0, long long pos=0)
    : key(k), position(pos)
    { }

    void setKey(unsigned long k) { key = k; }
    unsigned long getKey() const { return key; }
    void setPos(long long pos)   { position = pos; }
    long long getPos() const     { return position; }

    fstream& write(fstream& ind ) const
    {
       ind.write((char*)this, sizeof(IndexEntry) );
       return ind;
    }
    fstream& read( fstream& ind)
    {
       ind.read((char*)this, sizeof(IndexEntry) );
       return ind;
    }
    fstream& write_at(fstream& ind, long long pos ) const
    {
       ind.seekp(pos);
       return write(ind);
    }
    fstream& read_at( fstream& ind, long long pos)
    {
       ind.seekg(pos);
       return read(ind);
    }
    void display() const
    {
       cout << "Schluessel: " << key
            << "\tPosition: " << position << endl;
    }
};

// Operator < für zwei Indexeinträge:
inline bool operator<(const IndexEntry& ie1, const IndexEntry& ie2)
{
    return ie1.getKey() < ie2.getKey();
}

// ----------------------------------------------------------  
// Definition der Klasse IndexFile:

class IndexFile : public fstream
{
  private:
    string name;                       // Name der Indexdatei
    // Hilfsfunktion für das Einfügen nahe dem Ende der Datei:
    bool _insert( unsigned long key, long long pos);

  public:
    static const ios::openmode mode    // Eröffnungsmodus
                 = ios::in | ios::out | ios::binary;

    IndexFile(const string& s);        // Konstruktor

    const string& getName() const { return name; }

    // Neuen Eintrag (key,pos) in die Indexdatei einfügen.
    // Return-Wert: true, im Fehlerfall false.
    bool insert( unsigned long key, long long pos);

    // Schlüssel key in der Indexdatei suchen.
    // Return-Wert: Position in der Indexdatei 
    //              oder -1, falls nicht gefunden. 
    long long search( unsigned long key);

    // Position für den Schlüssel key in der Indexdatei suchen.
    // Return-Wert: Position des ersten Eintrags, dessen Schlüssel
    // größer oder gleich dem Schlüssel key ist. -1 im Fehlerfall.
    // Der Eintrag auf dieser Position wird in das zweite Argument 
    // kopiert, falls die Position nicht das Dateiende ist.
    // Falls der Schlüssel key schon vorhanden ist, sind also 
    // die Schlüssel key und entry.getKey() gleich. 
    long long search( unsigned long key, IndexEntry& entry);

    void display();
};

#endif
