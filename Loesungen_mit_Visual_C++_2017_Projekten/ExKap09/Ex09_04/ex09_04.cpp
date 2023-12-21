// --------------------------------------------------------
// ex09_04.cpp 
// Ersetzt Teilstrings.
// --------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1("Today is my birthday!");
    cout << s1 << endl;
   
    int pos = s1.find("Today");      // int pos = 0;
	s1.replace(pos, 5, "Next month");
    cout << s1 << endl;

    pos = s1.find(" is ");
	s1.replace(pos, 4, " will be ");
    cout << s1 << endl; 
    
    pos = s1.rfind("my");
	s1.replace(pos, 2, "your");
    cout << s1 << endl; 

    return 0;
}
