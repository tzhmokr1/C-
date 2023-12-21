// ---------------------------------------------------------
// mail.h
// Definition der Klassen
// Address, Mail, Letter, Parcel, TraceParcel und NailService.
// ---------------------------------------------------------
#ifndef _MAIL_
#define _MAIL_

#include <iostream>
#include <string>
#include <ctime>             // Für deb Zeitstempel
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

// -----  Klasse Letter  -----
class Letter : public Mail
{
  public:
    enum category { STANDARD, EXPRESS };
  private:
    category ctg;
  public:
    Letter( unsigned long id, category c = STANDARD)
    : Mail(id), ctg(c) {}
      
    Letter( unsigned long id,
            const Address& adrTo, const Address& adrFrom=Address(),
            category c = STANDARD)
    : Mail(id, adrTo, adrFrom), ctg(c) {}

    category getCategory() const { return ctg; }
    void setCategory(category c) { ctg = c; }

    ostream& print( ostream& os) const;
};

inline ostream& operator<<( ostream& os, const Letter& l)
{  return l.print(os);  }

// -----  Klasse Parcel  -----
class Parcel : public Mail
{
  private:
     float weight;
     bool  insured;
  public:
    Parcel( unsigned long id, float w, bool ins = false)
    : Mail(id), weight(w), insured(ins) {}
      
    Parcel( unsigned long id, float w,
            const Address& adrTo, const Address& adrFrom=Address(),
            bool ins = false)
    : Mail(id, adrTo, adrFrom), weight(w), insured(ins) {}

    float getWeight() const { return weight; }
    void setWeight(float w) { weight = w; }

    bool isInsured() const { return insured; }
    void setInsured( bool ins)  { insured = ins; }

    ostream& print( ostream& os) const;
};

inline ostream& operator<<( ostream& os, const Parcel& p)
{  return p.print(os);  }

// -----  Klasse TraceParcel  -----
class TraceParcel : public Parcel      // Paket mit 
{                                      // Sendeverfolgung
private:
   struct Stamp       // Private Hilfsklasse
   { 
      time_t timestamp;  string place;    // Zeit und Ort
      Stamp() : timestamp(0) {};
      void setStamp( const string& plc = "")
      { timestamp = time(NULL);           // Aktuelle Zeit
        place = plc;
      }
   };
   Stamp arrStamps[10];       // Platz füe 10 Zeitstempel
   int iCur;                  // Einfuegeposition

   public:
    TraceParcel( const Parcel& aParcel)
    : Parcel(aParcel)
    {  arrStamps[0].setStamp( from.getCity());  iCur = 1; }

    int setNextStamp( const string& place)
    {  arrStamps[iCur].setStamp( place);  return ++iCur;  }

    void printStamps() const;
};

// -----  Klasse MailService  -----

class MailService                      // Versandservice
{
  private:
    enum { ARR_LENGTH = 100} ;
    Letter *arrPtrLetter[ARR_LENGTH];
    Parcel *arrPtrParcel[ARR_LENGTH];
    TraceParcel *arrPtrTraceParcel[ARR_LENGTH];
    int iCurL, iCurP, iCurTP;         // Einfügepositionen

    // Kopien und Zuweisungen nicht zulassen:
    MailService( const MailService&);
    void operator=( const MailService&);

public:
    MailService();
    ~MailService();     // Zerstört dynamisch erzeugte Objekte

    bool newLetter();
    bool newParcel();
    void printLetters();
    void printParcels();

    Letter* getLetter( unsigned long id) const;
    Parcel* getParcel( unsigned long id) const;
    TraceParcel* getTraceParcel( unsigned long id) const;

    bool setNextStamp( unsigned long id, const string& place);
};

#endif  // _MAIL_
