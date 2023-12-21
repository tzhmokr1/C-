//==============================================================================
//        * Letsch Informatik *       www.LetsInfo.ch       CH-8636 Wald
//          Beratung, Ausbildung und Realisation in Software-Engineering
//==============================================================================
// Project   : Master of Advanced Studies in Software-Engineering MAS-SE 2019
// Modul     : C++
// Title     : Übung "SmartPointer"
// Author    : Thomas Letsch
// Tab-Width : 2
/*///===========================================================================
* Description: Demonstration der Smart-Pointers 'unique_ptr' und 'smart_ptr' der
*              Standard-Bibliothek.
* $Revision  : 1.12 $  $Date: 2019/11/09 10:51:47 $
/*///===========================================================================
//       1         2         3         4         5         6         7         8
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//==============================================================================

#include <memory>
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::unique_ptr;
using std::shared_ptr;



class TestClass {

  public:

    TestClass(const string& pStr) : mStr(pStr) {
      cout << "TestClass::TestClass()  : " << pStr << endl;
    }

    string getString() {
      return mStr;
    }

    ~TestClass() {
      cout << "TestClass::~TestClass() : " << mStr << endl;
    }

  private:
    string mStr;

};
 

int main() {

  cout << "Code-Segement:" << endl;
  {
    TestClass myTestObj("Bla bla.");
    cout << "Inhalt von Test-Objekt  : " << myTestObj.getString() << endl;
  }


  cout << endl << "unique_ptr:" << endl;
  try {
    unique_ptr<TestClass> uniquePtr(new TestClass("Test mit unique_ptr"));
    cout << "uniquePtr->getString()  : " <<  uniquePtr->getString() << endl;
    cout << "Gleich wird eine Exception geworfen." << endl;
    cout << "Kommt jetzt der Destruktor?" << endl;
    throw 4711;
  }
  catch(int nr) {
    cout << "catch(): " << nr << endl;
  }


  cout << endl << "shared_ptr:" << endl;
  
    shared_ptr<TestClass> sharedPtr1(new TestClass("Test mit sharedPtr1"));
    cout << "sharedPtr1->getString() : " << sharedPtr1->getString() << endl;
    cout << "sharedPtr1.use_count()  : " << sharedPtr1.use_count() << endl;
    {
      cout << "Neuer Gueltigkeitsbereich mit sharedPtr2:" << endl;
      shared_ptr<TestClass> sharedPtr2(sharedPtr1);
      cout << "sharedPtr1.use_count()  : " << sharedPtr1.use_count() << endl;
      cout << "sharedPtr2.use_count()  : " << sharedPtr2.use_count() << endl;
      cout << "sharedPtr2->getString() : " << sharedPtr2->getString() << endl;
      cout << "sharedPtr1.get() == sharedPtr2.get() : "
           << (sharedPtr1.get() == sharedPtr2.get() ? "true" : "false") << endl;
      cout << "Ende Gueltigkeitsbereich sharedPtr2." << endl;
	}
    cout << "sharedPtr1.use_count()  : " << sharedPtr1.use_count() << endl;
    shared_ptr<TestClass> sharedPtr3(new TestClass("Test mit sharedPtr3"));
    cout << "sharedPtr1 = sharedPtr3: wird Obj von sharedPtr1 geloescht?" << endl;
    sharedPtr1 = sharedPtr3;
    cout << "Ende Gueltigkeitsbereich sharedPtr1 u. sharedPtr3." << endl;
    cout << "Kommt jetzt der Destruktor?" << endl;
  

  return 0;

}
 

/* Session-Log:

Code-Segement:
TestClass::TestClass()  : Bla bla.
Inhalt von Test-Objekt  : Bla bla.
TestClass::~TestClass() : Bla bla.

unique_ptr:
TestClass::TestClass()  : Test mit unique_ptr
uniquePtr->getString()  : Test mit unique_ptr
Gleich wird eine Exception geworfen.
Kommt jetzt der Destruktor?
TestClass::~TestClass() : Test mit unique_ptr
catch(): 4711

shared_ptr:
TestClass::TestClass()  : Test mit sharedPtr1
sharedPtr1->getString() : Test mit sharedPtr1
sharedPtr1.use_count()  : 1
Neuer Gueltigkeitsbereich mit sharedPtr2:
sharedPtr1.use_count()  : 2
sharedPtr2.use_count()  : 2
sharedPtr2->getString() : Test mit sharedPtr1
sharedPtr1.get() == sharedPtr2.get() : true
Ende Gueltigkeitsbereich sharedPtr2.
sharedPtr1.use_count()  : 1
TestClass::TestClass()  : Test mit sharedPtr3
sharedPtr1 = sharedPtr3: wird Obj von sharedPtr1 geloescht?
TestClass::~TestClass() : Test mit sharedPtr1
Ende Gueltigkeitsbereich sharedPtr1 u. sharedPtr3.
Kommt jetzt der Destruktor?
TestClass::~TestClass() : Test mit sharedPtr3

*/
