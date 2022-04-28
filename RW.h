#ifndef _RW_
#define _RW_

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
	void print() const;

	//Получение приватных значений
	string const& get_name() const {return (name);}
	double get_averCargo() const {return (averCargo);}
	double get_averPassngr() const {return (averPassngr);}
};

class Platform
{

};

#endif
