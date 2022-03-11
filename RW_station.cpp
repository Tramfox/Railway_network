#include <iostream>
#include <string>
#include "RW_station.h"

Station::Station()
{
	averCargo = 0.0;
	averPassngr = 0.0;
}

Station::Station(string const& str)
{
	name = str;
	averCargo = 0.0;
	averPassngr = 0.0;
}

Station::Station(string const& str, double cargoTraf, double passngrTraf)
{
	name = str;
	averCargo = cargoTraf;
	averPassngr = passngrTraf;
}

Station::~Station(){};

void Station::nameReg (string const& str)
{
	name = str;
}

void Station::cargoTrfReg (double cargoTraf) 
{
	averCargo = cargoTraf;
}

void Station::passngrTrfReg (double passngrTraf)
{
	averPassngr = passngrTraf;
}
