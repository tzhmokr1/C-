// ---------------------------------------------------
// proxy.h
// Definition der Klassen Subject, RealSubject, Proxy.
// ---------------------------------------------------
#ifndef _PROXY_
#define _PROXY_

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

class Subject
{
  public:
    virtual void request(string name) = 0;
};

class RealSubject : public Subject
{
  public:
    void request(string name) 
    { 
      cout << "Zugriff fuer " << name << " erlaubt." << endl;
    }
};

class Proxy : public Subject
{
   private:
     Subject* realSubject;
     bool find(string name);

   public:
    Proxy() : realSubject(NULL){}
    ~Proxy(){ delete realSubject; }

    void request(string name);             
};

#endif  // _PROXY_
