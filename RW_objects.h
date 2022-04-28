#ifndef _RW_OBJECTS_
#define _RW_OBJECTS_

using std::string;

class Platform
{
private:
	string name;		//Название платформы (станции при наследовании)
	double averPassngr;	//Средний пассажиропоток
public:
	//Конструктор простой
	Platform();
	//Конструктор объекта только с заданным названием
	Platform(string const& str);
	//Конструктор объекта со всеми заданными параметрами
	Platform(string const& str, double passngrTraf);
	//Деструктор
	~Platform();

	//Регистрация нового имени
	void nameReg (string const& str);
	//Регистрация среднего пассажирского потока
	void passngrTrfReg (double passngrTraf);
	//Печать всех элементов класса
	void print() const;
	//Получение приватных значений
	string const& get_name() const {return (name);}
	double get_averPassngr() const {return (averPassngr);}
};

class Station: public Platform
{
private:
	double averCargo;	//Средний грузопоток
public:
	//Конструктор простой
	Station();
	//Конструктор объекта только с заданным названием
	Station(string const& str);
	//Конструктор объекта со всеми заданными параметрами
	Station(string const& str, double cargoTraf, double passngrTraf);
	//Деструктор
	~Station();

	//Регистрация среднего грузового потока
	void cargoTrfReg (double cargoTraf);
	//Печать всех элементов класса
	void print() const;
	//Получение приватных значений
	double get_averCargo() const {return (averCargo);}
};

#endif
