#include <iostream>
#include <string>
#include "RW_objects.h"

//Platform class
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


//Station class
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

void Station::cargoTrfReg (double cargoTraf)
{
	averCargo = cargoTraf;
}


//Connection class
Connection::Connection(L const& left_, R const& right_)
{
	if (!left_.get_name.empty() && !right_.get_name.empty())
	{
		left = left_;
		right = right_;
	}
	else
		left = right = "NONE!";
}

Connection::Connection(L const& left_, R const& right_
                double cargoTraf, double passngrTraf, size_t t)
{
	if (!left_.get_name.empty() && !right_.get_name.empty())
	{
		left = left_;
		right = right_;
		setTime(t);
		set(passngrTraf, cargoTraf);
	}
}

void Connection::changeTime(size_t t)
{
	time = (t >= 0 ? t : 0);
}

void Connection::set(double passngrTraf, double cargoTraf)
{
	maxCargo = (cargoTraf >= 0.0 ? cargoTraf : 0.0);
	maxPassngr = (passngrTraf >= 0.0 ? passngrTraf : 0.0);
}
