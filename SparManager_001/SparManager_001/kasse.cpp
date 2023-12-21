#include "kasse.h"

// Konstruktoren ---
Kasse::Kasse( size_t &id, string &name, long double &betrag )
: id( id )
, name( name )
, betrag( betrag )
{
}

Kasse::~Kasse()
{
}
// ---

// Methoden ---
bool Kasse::einzahlen( long double &betrag )
{
	bool eingezahlt = false;

	if( betrag >= 0.0 )
	{
		eingezahlt = true;
		this->betrag += betrag;
	}

	return eingezahlt;
}
// ---

// Getter ---
size_t& Kasse::getId() 
{
	return this->id;
}

string& Kasse::getName() 
{
	return this->name;
}

long double& Kasse::getBetrag() 
{
	return this->betrag;
}
// ---

// Setter ---
void Kasse::setName( string &name )
{
	this->name = name;
}
// ---