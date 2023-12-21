#include <iostream>
#include <string>
using namespace std;

class DiagnoseError
{
    string m;

  public:
     DiagnoseError(string& s) : m(s){ } 
     string what() const { return m; }
};

void checkDiagnose(int e)
{
   string s;

   switch(e)
   {
    case 1 :  s = "Spur verzogen. ";
              throw DiagnoseError(s);
              break;
    case 2 :  s = "Radlager defekt.";
              throw DiagnoseError(s);
              break;
    default : s = "Reifenprofil zu duenn.";
              throw (s);
   }
}

int main()
{
  for(int i = 3; i > 0; i--)
    try 
    {
        checkDiagnose(i);
    }
    catch( DiagnoseError& de)
    { 
      cerr << de.what() << endl;  
    }
    catch( string& se)
    {
      cerr << se << endl;
    }
    catch(...)
    {
      cerr << "Anderer Fehler" << endl;
    }
    return 0;
}
