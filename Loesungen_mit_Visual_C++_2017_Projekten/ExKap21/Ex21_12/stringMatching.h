// -----------------------------------------------------------
// stringMatching.h
// Definition der Klasse StringMatching, die den schnellen
// Boyer-Moore Algorithmus implementiert.
// -----------------------------------------------------------
#ifndef _STRINGMATCHING_
#define _STRINGMATCHING_

#include <string>
using namespace std;

class StringMatching
{
  private:
    string pattern;         // Suchstring
    int *deltaTable1;       // Entfernungstabellen
    int *deltaTable2;       //

  public:
    StringMatching( const string& pat);
    ~StringMatching()
    { delete [] deltaTable1;  delete [] deltaTable2;}

    void print() const;  
    int findIn( const string& str, int start=0) const;
};

#endif   // _STRINGMATCHING_
