#include <iostream>
#include <string>
#include <cassert>
#include "RW_station.h"

#include <cmath>
#include <cstdlib>
#include <limits>

using std::cout;
using std::endl;

void Station::print() const
{
	cout << "==================================" << endl;
	cout << "Station name: " << name << ";" << endl;
	cout << "Average   cargo   traffic: " << averCargo << ";" << endl;
	cout << "Average passenger traffic: " << averPassngr << "." << endl;
}

//Сравнение двух double
bool is_equal_double(double x, double y)
{
	return (std::fabs(x - y) < std::numeric_limits<double>::epsilon());
}

int main()
{
	//Создание станции без аргументов
	Station S;
	assert(S.get_name().empty());
	assert(is_equal_double(S.get_averCargo(), 0.0));
	assert(is_equal_double(S.get_averPassngr(), 0.0));

	//Регистрация имени
	string name1 = "Москва-Товарная-3";
	S.nameReg(name1);
	assert(S.get_name().compare(name1) == 0);

	//Регистрация грузопотока
	double cargoTraf = 15.09;
	S.cargoTrfReg(cargoTraf);
	assert(is_equal_double(S.get_averCargo(), cargoTraf));

	//Регистрация пассажиропотока
	double passngrTraf = 12.78;
	S.passngrTrfReg(passngrTraf);
	assert(is_equal_double(S.get_averPassngr(), passngrTraf));


	//Создание станции с одним параметром -- именем
	Station SPB(name1);
	assert(SPB.get_name().compare(name1) == 0);
	assert(is_equal_double(SPB.get_averCargo(), 0.0));
	assert(is_equal_double(SPB.get_averPassngr(), 0.0));

	//Регистрация нового имени
	string name2 = "Saint Petersburg Glavn";
	S.nameReg(name2);
	assert(S.get_name().compare(name2) == 0);


	//Создание станции со всеми параметрами (имя, пассажиро- и грузопоток)
	string name3 = "Горемыкино горе";
	S.nameReg(name3);
	assert(S.get_name().compare(name3) == 0);
	S.cargoTrfReg(cargoTraf);
	assert(is_equal_double(S.get_averCargo(), cargoTraf));
	S.passngrTrfReg(passngrTraf);
	assert(is_equal_double(S.get_averPassngr(), passngrTraf));

	return 0;
}
