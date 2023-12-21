// -------------------------------------------------------
// intArr.h
// Definition der Klassen IntArr.
// -------------------------------------------------------
#ifndef _INTARR_
#define _INTARR_

class IntArr
{
  private:
    int *ptrArr;           // Zeiger auf einen Vektor 
    int len;               // Länge des Vektors 
  public:
    IntArr( int len); 
    ~IntArr();
    int length() const { return len; }
    int& operator[](int i);      // Index-Operator
    void compress();
};

#endif  // _INTARR_