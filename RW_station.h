#ifndef _RW_STATION_
#define _RW_STATION_

using std::string;

class Station
{
	string name;		//Название станции
	double averCargo;	//Средний грузопоток
	double averPassngr;	//Средний пассажиропоток

public:
	//Конструктор простой
	Station();

	//Конструктор объекта только с заданным названием
	Station(string const& str);

	//Конструктор объекта со всеми заданными параметрами
	Station(string const& str, double cargoTraf, double passngrTraf);

	//Деструктор
	~Station();

	//Регистрация нового имени
	void nameReg (string const& str);

	//Регистрация среднего грузового потока
	void cargoTrfReg (double cargoTraf);

	//Регистрация среднего пассажирского потока
	void passngrTrfReg (double passngrTraf);

	//Печать всех элементов класса
	void print();

	//Получение приватных значений
	string const& get_name() {return (name);}
	double get_averCargo() {return (averCargo);}
	double get_averPassngr() {return (averPassngr);}
};

#endif
