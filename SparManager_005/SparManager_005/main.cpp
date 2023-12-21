#include "sparManager.h"

#include <iostream>
using std::cerr;
using std::endl;

int main()
{
	setlocale( LC_ALL, "" );

	try
	{
		SparManager manager;
		manager.start();
	}
	catch( ... )
	{
		cerr << "Unbekannter Fehler!" << endl;
	}

	return 0;
}