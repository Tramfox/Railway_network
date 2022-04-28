#include <iostream>
#include <string>
#include "RW_objects.h"

Platform::Platform()
{
	name = "NoName";
	averPassngr = 0.0;
}

Platform::Platform(string const& str)
{
	name = str;
	averPassngr = 0.0;
}

Platform::Platform(string const& str, double passngrTraf)
{
	name = str;
	averPassngr = passngrTraf;
}

Platform::~Platform(){};

void Platform::nameReg (string const& str)
{
	name = str;
}

void Platform::passngrTrfReg (double passngrTraf)
{
	averPassngr = passngrTraf;
}




//Station::Station(): Platform()
Station::Station()
{
	averCargo = 0.0;
}

Station::Station(string const& str): Platform(str)
{
	averCargo = 0.0;
}

Station::Station(string const& str, double cargoTraf, double passngrTraf):
Platform(str, passngrTraf)
{
	averCargo = cargoTraf;
}

Station::~Station(){};

/*void Station::nameReg (string const& str)
{
	name = str;
}*/

void Station::cargoTrfReg (double cargoTraf) 
{
	averCargo = cargoTraf;
}

/*void Station::passngrTrfReg (double passngrTraf)
{
	averPassngr = passngrTraf;
}*/
