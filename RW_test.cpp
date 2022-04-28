#include <iostream>
#include <string>
#include <cassert>
#include "RW_objects.h"

#include <cmath>
#include <cstdlib>
#include <limits>
//#include <typeinfo>

using std::cout;
using std::endl;

void Platform::print() const
{
	cout << "=======================================" << endl;
	cout << "Object name: " << name << endl;
//	cout << "Object  type: " << typeid(*this).name() << endl;
	cout << "Average passenger traffic: " << averPassngr << endl;

}

void Station::print() const
{
	this->Platform::print();
	cout << "Average   cargo   traffic: " << averCargo << endl;
}

void Connection::print() const
{
	cout << "+++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "Connection between " << left.get_name() << " and " <<
		right.get_name() << endl;
	cout << "Passengers: " << maxPassngr << endl;
	cout << "     Cargo: " << maxCargo << endl;
}

//Сравнение двух double
bool is_equal_double(double x, double y)
{
	return (std::fabs(x - y) < std::numeric_limits<double>::epsilon());
}

bool PlatformModuleTest()
{
	//Конструктор без параметров
	Platform P1;
	assert(P1.get_name().compare("NoName") == 0);
	assert(is_equal_double(P1.get_averPassngr(), 0.0));

	//Регистрация имени
	string name1 = "Новодачная";
        P1.nameReg(name1);
        assert(P1.get_name().compare(name1) == 0);

        //Регистрация пассажиропотока
        double passngrTraf = 12.78;
        P1.passngrTrfReg(passngrTraf);
        assert(is_equal_double(P1.get_averPassngr(), passngrTraf));

	//Конструктор с 1 параметром (название)
	Platform P2(name1);
        assert(P2.get_name().compare(name1) == 0);
        assert(is_equal_double(P2.get_averPassngr(), 0.0));

        //Регистрация нового имени
        string name2 = "Novodachnaya";
        P2.nameReg(name2);
        assert(P2.get_name().compare(name2) == 0);

	//Конструктор со всеми параметрами
	string name3 = "NovoДачная";
        Platform P3(name3, passngrTraf);
        assert(P3.get_name().compare(name3) == 0);
        P3.passngrTrfReg(passngrTraf);
        assert(is_equal_double(P3.get_averPassngr(), passngrTraf));

	P1.print();
	P2.print();
	P3.print();

	return true;
}

bool StationModuleTest()
{
	//Создание станции без аргументов
        Station S1;
	assert(S1.get_name().compare("NoName") == 0);
        assert(is_equal_double(S1.get_averCargo(), 0.0));
        assert(is_equal_double(S1.get_averPassngr(), 0.0));

        //Регистрация имени
        string name1 = "Москва-Товарная-3";
        S1.nameReg(name1);
        assert(S1.get_name().compare(name1) == 0);

        //Регистрация грузопотока
        double cargoTraf = 15.09;
        S1.cargoTrfReg(cargoTraf);
        assert(is_equal_double(S1.get_averCargo(), cargoTraf));

        //Регистрация пассажиропотока
        double passngrTraf = 12.78;
        S1.passngrTrfReg(passngrTraf);
        assert(is_equal_double(S1.get_averPassngr(), passngrTraf));

        //Создание станции с одним параметром -- именем
        Station S2(name1);
        assert(S2.get_name().compare(name1) == 0);
        assert(is_equal_double(S2.get_averCargo(), 0.0));
        assert(is_equal_double(S2.get_averPassngr(), 0.0));

        //Регистрация нового имени
        string name2 = "Saint Petersburg Glavn";
        S2.nameReg(name2);
        assert(S2.get_name().compare(name2) == 0);

        //Создание станции со всеми параметрами (имя, пассажиро- и грузопоток)
        string name3 = "Горемыкино горе";
        Station S3(name3, cargoTraf, passngrTraf);
        assert(S3.get_name().compare(name3) == 0);
        S3.cargoTrfReg(cargoTraf);
        assert(is_equal_double(S3.get_averCargo(), cargoTraf));
        S3.passngrTrfReg(passngrTraf);
        assert(is_equal_double(S3.get_averPassngr(), passngrTraf));

	S1.print();
	S2.print();
	S3.print();

	return true;
}
bool ConnectionModuleTest()
{
	//Конструктор без параметров
	Platform P1("Ключики", 7.12);
	Station S1("Большие Ключики", 15.1);
	Connection C1(P1, S1, 0.0, 7.12, 10);
	C1.print();
	return true;
}
bool TrainModuleTest()
{return true;}
bool NetworkModuleTest()
{return true;}


int main()
{
	if (!PlatformModuleTest())
		return 20;
	if (!StationModuleTest())
		return 30;
	if (!ConnectionModuleTest())
		return 40;
	if (!TrainModuleTest())
		return 50;
	if (!NetworkModuleTest())
		return 60;

	return 0;
}
/*
	//Создание платформы
	Platform A;
	Platform B("Полустанок");
	Platform C("55 км", 12.78);

	A.print();
	B.print();
	C.print();

	Station S1;
	S1.print();

	Station S;
        //assert(S.get_name().empty());
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
	S.print();
	return 0;
}
*/
