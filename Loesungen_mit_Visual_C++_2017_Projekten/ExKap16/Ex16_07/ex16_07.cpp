// --------------------------------------------------------------
// ex16_05.cpp
// Speichert Objekte der Klasse Customer in einem Vektor. 
// --------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

class Customer
{
  private:
    long id;
    string name;

  public:
    Customer(long n = 0, const string& s = "")
    : id(n), name(s) {}

    void  setId(long n){ id = n;}
    long  getId() const { return id;}

    void  setName( const string& s){ name = s; }
    const string& getName() const { return name; }
};

int main()
{
// a)
    Customer arrCustomer[4] = { Customer(43210, "Tom Jones"), 
                                Customer(23456, "Chris Burg"),
                                Customer(34567, "Neill Diamond") };

// b)
    arrCustomer[3].setId(12345);
    arrCustomer[3].setName("Jim Croce");

// c) 
    cout << "\n----- Alle Kunden ----" << endl;
    for( int i = 0;  i < 4;  ++i)
    {
      cout << "\nID:     " << arrCustomer[i].getId() 
           << "\nName:   " << arrCustomer[i].getName()
           << endl;
    }

    return 0;
}
