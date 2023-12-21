// ---------------------------------------------------------
// mail.h
// Definition der Klassen Address und Mail.
// ---------------------------------------------------------
#ifndef _MAIL_
#define _MAIL_

#include <iostream>
#include <string>
using namespace std;

class Address                // Hilfsklasse für Mail
{
  private:
    string name,
           street,           // Strasse incl. Hausnummer
           city,             // PLZ und Stadt
           country;          // Land
  public:
    Address() {}
    Address( const string& n, const string& s, const string& ci,
            const string& co="Deutschland")
    : name(n), street(s), city(ci), country(co) {}

    const string& getName()    const { return name; }
    const string& getStreet()  const { return street; }
    const string& getCity()    const { return city; }
    const string& getCountry() const { return name; }

    bool isValid() const
    { return (name != "" && street != "" && city != ""); }

    bool scan();
    ostream& print( ostream& os) const;
};

inline ostream& operator<<( ostream& os, const Address& adr)
{  return adr.print(os);  }


// -----  Klasse Mail  -----
class Mail
{
  protected:
    unsigned long id;
    Address from, to;       // Absender und Empfaenger
    bool delivered;         // true, falls Post ausgeliefert wurde.

  public:
    Mail(unsigned long i) : id(i), delivered(false) {}
    Mail(unsigned long i, const Address& adrTo, const Address& adrFrom)
    : id(i), to(adrTo), from( adrFrom), delivered(false)
    {}

    unsigned long getID()    const { return id; }
    const Address& getFrom() const { return from; }
    const Address& getTo()   const { return to; }

    void getID(unsigned long i)  { id = i; }
    bool setFrom(const Address& adr)
    {
       if( !adr.isValid())
          return false;
       from = adr;
       return true;
    }
    bool setTo(const Address& adr) 
    {
       if( !adr.isValid())
          return false;
       to = adr; 
       return true;
    }

    bool isDelivered() const { return delivered; }
    bool deliver()
    { 
       if( to.isValid() )
       {
          delivered = true; 
          return true;
       }
       else
          return false;
    }

    bool scanFrom() { return from.scan();  }
    bool scanTo()   { return to.scan();  }

    ostream& print( ostream& os) const;
};

inline ostream& operator<<( ostream& os, const Mail& m)
{  return m.print(os);  }

#endif  // _MAIL_
