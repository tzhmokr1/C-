// ----------------------------------------------------
// DayTime.h
// Die Klasse DayTime mit einer Konvertierungsfunktion, 
// die ein Objekt vom Typ DayTime in einen String
// umwandelt.
// ----------------------------------------------------
#ifndef _DAYTIME_
#define _DAYTIME_

#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

class DayTime
{
  private:
    short hour, minute, second;

  public:
    DayTime( int h = 0, int m = 0, int s = 0)
    { 
      if( !setTime( h, m, s)) 
        hour = minute = second = 0;
    }
    
    bool setTime(int hour, int minute, int second = 0)
    {
      if(    hour   >= 0  &&  hour < 24 
          && minute >= 0  &&  minute < 60
          && second >= 0  &&  second < 60 ) 
      {
        this->hour   = (short)hour; 
        this->minute = (short)minute; 
        this->second = (short)second; 
        return true;
      }
      else
        return false;
    }
    
    int getHour()   const { return hour;   }
    int getMinute() const { return minute; };
    int getSecond() const { return second; };

    int asSeconds() const          // Uhrzeit in Sekunden.
    {
      return (60*60*hour + 60*minute + second);
    }

    operator string() const        // Konvertierung in String.
    {
       stringstream strstream;
       strstream << setfill('0')
                 << setw(2) << hour    << ':'
                 << setw(2) << minute  << ':'
                 << setw(2) << second;
       return strstream.str();
    }
};

#endif   // _DAYTIME_
