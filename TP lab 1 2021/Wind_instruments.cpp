#include "Wind_instruments.h"
Wind_instruments::Wind_instruments() : Base()
{
	manufacturer = "Empty";
	defects = "Empty";
	cout << "Класс Wind_instruments создан\n";
}
Wind_instruments::Wind_instruments(int a) : Base(1)
{
	set_manufacturer();
	set_defects();
	cout << "Класс Wind_instruments создан\n";
}
void Wind_instruments::set_manufacturer()
{
	cout << "Введите название производителя:\n";
	cin.ignore();
	getline(cin, manufacturer);
}
void Wind_instruments::set_manufacturer(char* buffer)
{
	manufacturer = (string)buffer;
}

void Wind_instruments::set_defects()
{
	cout << "Введите дефекты инструмента\nВводите дефекты через запятую, для завершения ввода нажмите клавишу Enter:\n";
	getline(cin, defects);
}
void Wind_instruments::set_defects(char* buffer)
{
	defects = (string)buffer;
}
string Wind_instruments::get_manufacturer()
{
	return manufacturer;
}
string Wind_instruments::get_defects()
{
	return defects;
}
Wind_instruments::~Wind_instruments()
{
	cout << "Класс Wind_instruments удален\n";
}
string Wind_instruments::All_fields_to_string()
{
	return "Владелец: " + this->get_last_name() + " " + this->get_name() + " " + this->get_middle_name() + " " + "Название: " + this->get_title() + " Цена: " + to_string(this->get_price()) + " К-во: " + to_string(this->get_count()) + " Производитель: " + this->get_manufacturer() + " Дефекты " + this->get_defects() + "\n";
}
string Wind_instruments::All_fields_to_string_to_save()
{
	return "<" + this->get_last_name() + "~" + this->get_name() + "~" + this->get_middle_name() + "~" + this->get_title() + "~" + to_string(this->get_price()) + "~" + to_string(this->get_count()) + "~" + this->get_manufacturer() + "~" + this->get_defects() + ">" + "\n";
}