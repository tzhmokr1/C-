// ------------------------------------------------
// phoneCall.h
// Klassen PhoneNr, InCall, OutCall und PhoneCall
// ------------------------------------------------

#include <string>
using namespace std;

class PhoneNr
{
   private:
     string nr;
   public:
     PhoneNr()  :  nr("0"){}
     const string& getNr() const { return nr; }
     void setNr(const string& n) { nr = n; }
};

class OutCall : public PhoneNr
{
     bool flag;
   public:
     OutCall() : flag(false) {}
     bool getFlag() const { return flag; }
     void setFlag(bool fl) { flag = fl; }
};

class InCall : public PhoneNr
{
     bool flag;
   public:
     InCall() : flag(false) {}
     bool getFlag() const { return flag; }
     void setFlag(bool fl) { flag = fl; }
};

class PhoneCall : public OutCall, public InCall
{
   public:
     bool initCall(const string& n); 
     bool dial(const string& n);
     bool answerCall();
     bool hangUp();
};
