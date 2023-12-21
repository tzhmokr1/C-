// ------------------------------------------------
// phoneCall.h
// Klassen zur Darstellung von Telefonverbindungen 
// ------------------------------------------------
#pragma warning( disable : 4996)             // Für ctime() und VS 2012
#include <string>
#include <ctime>
using namespace std;

class TimeStamp
{
  private:
   time_t zeit;
public:
   TimeStamp() : zeit(0){}

   void   setTime() { time(&zeit);}
   void   setTime(const time_t t){ zeit = t; }
   time_t getTime() const { return zeit; }
   string getTimeStr()const 
          {return (string)ctime(&zeit); }
};

class PhoneNr
{
   private:
     string nr;
   public:
     PhoneNr()  :  nr("0"){}
     const string& getNr() const { return nr; }
     void setNr(const string& n) { nr = n; }
};

class OutCall : public PhoneNr, public TimeStamp
{
     bool flag;
   public:
     OutCall() : flag(false) {}
     bool getFlag() const { return flag; }
     void setFlag(bool fl) { flag = fl; }
};

class InCall : public PhoneNr, public TimeStamp
{
     bool flag;
   public:
     InCall() : flag(false) {}
     bool getFlag() const { return flag; }
     void setFlag(bool fl) { flag = fl; }
};

class PhoneCall : public OutCall, public InCall
{
  private:
   long dauer;
  
  public:
   PhoneCall() : dauer(0) {}
   long getDauer() { return dauer; }
   bool initCall(const string& n); 
   bool dial(const string& n);
   bool answerCall();
   bool hangUp();
};
