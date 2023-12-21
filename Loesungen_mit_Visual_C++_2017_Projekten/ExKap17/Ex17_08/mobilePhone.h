// ------------------------------------------------------
// mobilePhone.h 
// Definiert die Klasse MobilePhone.
// ------------------------------------------------------
#ifndef _MOBILEPHONE_
#define _MOBILEPHONE_

#include <string>
#include <iostream>
using namespace std;

class MobilePhone
{
  private:
    string device, owner, number; 

  public:
    MobilePhone( const string& dev,
                 const string& own="Nobody",
                 const string& num="0")
    {
       device = dev;   owner  = own;   number = num;
    }

    const string& getDevice() const { return device; }
    const string& getOwner() const  { return owner;  }
    const string& getNumber() const { return number; }

    bool setDevice(const string& dev) 
    {
        if( dev != "") { device = dev;  return true; }
        else  return false;
    }
    bool setOwner(const string& own)
    {
        if( own != "") { owner = own;   return true; }
        else  return false;
    }
    bool setNumber(const string& num)
    {
        if( num != "") { number = num;  return true; }
        else  return false;
    }

    void display()
    {
        cout << "--------------------------------------"
             << "\nHandy:    " << device
             << "\nBesitzer: " << owner
             << "\nTel.-Nr.: " << number << endl;
    }
};

#endif   // _MOBILEPHONE_
