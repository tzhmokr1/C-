#include <iostream>
#include <string>
using namespace std;

template <typename T>
class meineKlasse
{
   private:
      T wert;
   public:
      meineKlasse(const T&);
      void verdoppeln();
      void ausgeben();
};

template <typename T>
meineKlasse<T>::meineKlasse(const T &neuerWert)
{
   wert = neuerWert;
}

template <typename T>
void meineKlasse<T>::verdoppeln()
{
   wert = wert + wert;
}

template <typename T>
void meineKlasse<T>::ausgeben()
{
   cout << wert << endl;
}

int main()
{
   meineKlasse<int> x(5);
   x.verdoppeln();
   x.ausgeben();

   meineKlasse<string> s("Hallo");
   s.verdoppeln();
   s.ausgeben();
}

