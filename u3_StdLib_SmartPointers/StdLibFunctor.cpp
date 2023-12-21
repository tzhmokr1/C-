//==============================================================================
//        * Letsch Informatik *       www.LetsInfo.ch       CH-8636 Wald
//          Beratung, Ausbildung und Realisation in Software-Engineering
//==============================================================================
// Project   : Master of Advanced Studies in Software-Engineering MAS-SE 2019
// Modul     : C++
// Title     : Übung "Standard-Bibliothek und Funktoren"
// Author    : Thomas Letsch
// Tab-Width : 2
/*///===========================================================================
* Description: Andwendung der Standard-Bibliothek und Funktoren.
* $Revision  : 1.12 $  $Date: 2019/11/06 17:04:33 $
/*///===========================================================================
//       1         2         3         4         5         6         7         8
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//==============================================================================

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <climits>

using namespace std;


class Person {

  friend ostream& operator<<(ostream& pOS, const Person& pPerson);

  public:

    Person(const string& pName, int pAge) : mName(pName), mAge(pAge) {
    }

    bool operator<(const Person& pOtherPerson) const {
      return mName < pOtherPerson.mName;
    }

    int getAge() const {
      return mAge;
    }

  private:

    string mName;
    int mAge;

};


ostream& operator<<(ostream& pOS, const Person& pPerson) {
  pOS << setw(10) << left << pPerson.mName << ":" << setw(3)
      << right << pPerson.mAge;
  return pOS;
}


void printPersons(const vector<Person>& pPersonen) {
  for (vector<Person>::const_iterator pos = pPersonen.begin(); 
  	   pos != pPersonen.end();
       pos++) {
    cout << *pos << endl;
  }
}
 

class AgeMinMaxFunctor {

  public:

    AgeMinMaxFunctor() : minAge("<undef>", INT_MAX), maxAge("<undef>", INT_MIN) {
    }

    void operator()(const Person& pPerson) {
      if (pPerson.getAge() < minAge.getAge()) {
        minAge = pPerson;
      }
      if (pPerson.getAge() > maxAge.getAge()) {
        maxAge = pPerson;
      }
    }

    Person getMin() {
      return minAge;
    }

    Person getMax() {
      return maxAge;
    }

  private:

    Person minAge;
    Person maxAge;

};
 

int main() {

  vector<Person> persons;
  persons.push_back(Person("Marianne", 71));
  persons.push_back(Person("Oliver",    8));
  persons.push_back(Person("Anna",     44));
  persons.push_back(Person("Dorian",   10));

  cout << endl << "Unsorted:" << endl;
  printPersons(persons);

  cout << endl << "Sorted by Name:" << endl;
  sort(persons.begin(), persons.end());
  printPersons(persons);

  cout << endl << "AgeMinMaxFunctor:" << endl;
  AgeMinMaxFunctor ageMinMax;
  ageMinMax = for_each(persons.begin(), persons.end(), ageMinMax);
  cout << "Minimal Age = " << ageMinMax.getMin() << endl;
  cout << "Maximal Age = " << ageMinMax.getMax() << endl;

  return 0;

}
 

/* Session-Log:

Unsorted:
Marianne  : 71
Oliver    :  8
Anna      : 44
Dorian    : 10

Sorted by Name:
Anna      : 44
Dorian    : 10
Marianne  : 71
Oliver    :  8

AgeMinMaxFunctor:
Minimal Age = Oliver    :  8
Maximal Age = Marianne  : 71

*/
