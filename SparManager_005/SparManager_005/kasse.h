#ifndef KASSE_H
#define KASSE_H

#include <string>
using std::string;

class Kasse
{
public:
	// Konstruktoren ---
	Kasse( size_t &id, string &name, long double &betrag );
	~Kasse();
	// ---

	// Methoden ---
	bool einzahlen( long double &betrag );
	// ---

	// Getter ---
	size_t& getId() ;
	string& getName() ;
	long double& getBetrag() ;
	// ---

	// Setter ---
	void setName( string &name );
	// ---

private:
	// Deletes ---
	Kasse() = delete;
	Kasse( Kasse &obj ) = delete;
	Kasse& operator=( Kasse &obj ) = delete;
	// ---

	// Eigenschaften ---
	size_t id;
	string name;
	long double betrag;
	// ---
};

#endif