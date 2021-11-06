#include "Base.h"
Base::Base()
{
	last_name = "Empty";
	middle_name = "Empty";
	name = "Empty";
	title = "Empty";
	price = -500;
	count = -600;
	cout << "Базовый класс создан!\n";
}
Base::Base(int parametr)
{
	set_last_name();
	set_middle_name();
	set_name();
	set_title();
	set_price();
	set_count();
	cout << "Базовый класс создан!\n";
}
void Base::set_last_name()
{
	cout << "Введите фамилию владельца:\n";
	cin.ignore(32767, '\n');
	cin >> last_name;
}
void Base::set_last_name(char* buffer)
{
	last_name = (string)buffer;
}
string Base::get_last_name()
{
	return last_name;
}

void Base::set_middle_name()
{
	cout << "Введите отчество владельца:\n";
	cin.ignore(32767, '\n');
	cin >> middle_name;
}
void Base::set_middle_name(char* buffer)
{
	middle_name = (string)buffer;
}
string Base::get_middle_name()
{
	return middle_name;
}

void Base::set_name()
{
	cout << "Введите имя владельца:\n";
	cin.ignore(32767, '\n');
	cin >> name;
}

void Base::set_name(char* buffer)
{
	name = (string)buffer;
}
string Base::get_name()
{
	return name;
}
void Base::set_title()
{
	cout << "Введите название инструмента:\n";
	cin.ignore(32767, '\n');
	cin >> title;
}

void Base::set_title(char* buffer)
{
	title = (string)buffer;
}
string Base::get_title()
{
	return title;
}

void Base::set_price()
{
	cout << "Введите цену инструмента\nПомните, цена не может быть меньше нуля:\n";
	float buffer;
	do
	{
		cin >> buffer;
		if (buffer < 0)
		{
			cout << "Цена не может быть отрицательной!Введите еще раз\n";
		}
	} while (buffer < 0);
	price = buffer;
}
void Base::set_price(char* buffer)
{
	price = atoi(buffer);
}
float Base::get_price()
{
	return price;
}
void Base::set_count()
{
	cout << "Введите количество инструментов в оркестре\nПомните, количество не может быть отрицательным:\n";
	float buffer = 0;
	do
	{
		cin >> buffer;
		if (buffer < 0)
		{
			cout << "Количество не может быть отрицательным!Введите еще раз\n";
		}
	} while (buffer < 0);
	count = buffer;
}
void Base::set_count(char* buffer)
{
	count = atoi(buffer);
}
int Base::get_count()
{
	return count;
}
Base::~Base()
{
	cout << "Базовый объект удален!\n";
}