#include <iostream>
#include <tuple>
using namespace std;
int main()
{
   tuple<int,string,int,double> ta;
   ta = tuple<int,string,int,double>(5, "Berlin", 42, 7.52);
   cout << "Werte: " << get<string>(ta) << " "
      << get<double>(ta) << endl << endl;
}
