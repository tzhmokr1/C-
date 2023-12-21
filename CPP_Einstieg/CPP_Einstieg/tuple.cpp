#include <iostream>
#include <string>
#include <tuple>
using namespace std;

int main()
{
   tuple<int,string,int,double> ta;
   ta = tuple<int,string,int,double>(5, "Berlin", 42, 7.52);
   cout << get<0>(ta) << " " << get<1>(ta)
      << " " << get<2>(ta) << " " << get<3>(ta) << endl;

   int x, y;
   string s;
   double d;
   tie(x, s, y, d) = ta;
   cout << x << " " << s << " " << y << " " << d << endl;   

   tuple<int,string,int,double> tb;
   tb = make_tuple(7, "Dortmund", 72, 1.51);
   cout << get<0>(tb) << " " << get<1>(tb)
      << " " << get<2>(tb) << " " << get<3>(tb) << endl;

   tuple<int,string> tc;
   tc = make_tuple(12, "Hamburg");

   tuple<int,double> td;
   td = make_tuple(4, 3.85);

   tuple<int,string,int,double> te;
   te = tuple_cat(tc, td);
   cout << get<0>(te) << " " << get<1>(te)
      << " " << get<2>(te) << " " << get<3>(te) << endl;
}
