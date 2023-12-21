#include <iostream>
#include <climits>
using namespace std;
int main()
{
   cout << "char: " << sizeof(char) << " Byte, ";
   cout << "von " << CHAR_MIN << " bis " << CHAR_MAX << endl;

   cout << "unsigned char: " << sizeof(unsigned char) << " Byte, ";
   cout << "von 0 bis " << UCHAR_MAX << endl;

   cout << "short: " << sizeof(short) << " Byte, ";
   cout << "von " << SHRT_MIN << " bis " << SHRT_MAX << endl;

   cout << "unsigned short: "
      << sizeof(unsigned short) << " Byte, ";
   cout << "von 0 bis " << USHRT_MAX << endl;

   cout << "int: " << sizeof(int) << " Byte, ";
   cout << "von " << INT_MIN << " bis " << INT_MAX << endl;

   cout << "unsigned int: " << sizeof(unsigned int) << " Byte, ";
   cout << "von 0 bis " << UINT_MAX << endl;

   cout << "long: " << sizeof(long) << " Byte, ";
   cout << "von " << LONG_MIN << " bis " << LONG_MAX << endl;

   cout << "unsigned long: " << sizeof(unsigned long) << " Byte, ";
   cout << "von 0 bis " << ULONG_MAX << endl;
}

