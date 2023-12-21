#include "sparQuelle.h"

#include "sparManager.h"

// Konstruktoren ---
SparQuelle::SparQuelle( SparManager *parent, size_t &id, string &name, VerteilKonfiguration *verteilKonfiguration )
: parent( parent )
, id( id )
, name( name )
, verteilKonfiguration( dynamic_cast<VerteilKonfiguration*>( verteilKonfiguration ) )
{
}

SparQuelle::~SparQuelle()
{
	delete this->verteilKonfiguration;
}
// ---

// Methoden ---
bool SparQuelle::setVerteilAnteil( size_t &kassenId, float &verteilAnteil )
{
	bool verteilAnteilGesetzt = false;

	Kasse *kasse = dynamic_cast<SparManager*>(this->parent)->findeKasse( kassenId );
	if( kasse != nullptr )
	{
		verteilAnteilGesetzt = this->verteilKonfiguration->setVerteilAnteil( kasse, verteilAnteil );
	}

	return verteilAnteilGesetzt;
}

bool SparQuelle::einsparen( long double betrag )
{
	return this->verteilKonfiguration->einsparen( betrag );
}
// ---

// Getter
size_t& SparQuelle::getId() 
{
	return this->id;
}

string& SparQuelle::getName() 
{
	return this->name;
}

VerteilKonfiguration *SparQuelle::getVerteilKonfiguration() 
{
	return this->verteilKonfiguration;
}
//


// Setter ---
void SparQuelle::setName( string &name )
{
	this->name = name;
}
// ---