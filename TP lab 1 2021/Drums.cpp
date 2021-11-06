#include "Drums.h"
Drums::Drums() : Base()
{
	type = "Empty";
	cout << "Класс Drums создан\n";
}
Drums::Drums(int a) : Base(1)
{
	set_type();
	cout << "Класс Drums создан\n";
}
void Drums::set_type()
{
	cout << "Введите тип ударного инструмента:\n";
	cin.ignore(32767, '\n');
	cin >> type;

}
void Drums::set_type(char* buffer)
{
	type = (string)buffer;
}
string Drums::get_type()
{
	return type;
}
Drums::~Drums()
{
	cout << "Класс Drums удален\n";
}
string Drums::All_fields_to_string()
{
	return "Владелец: " + this->get_last_name() + " " + this->get_name() + " " + this->get_middle_name() + " Тип: " + this->get_type() + " Название: " + this->get_title() + " Стоимость: " + to_string(this->get_price()) + " К-во: " + to_string(this->get_count()) + "\n";
}string Drums::All_fields_to_string_to_save()
{
	return  "<" + this->get_last_name() + "~" + this->get_name() + "~" + this->get_middle_name() + "~" +  this->get_type() + "~" + this->get_title()+ "~" + to_string(this->get_price()) + "~" + to_string(this->get_count()) + ">\n";
}
ostream& operator << (ostream& out, Drums& example)
{
	out << example.All_fields_to_string();
	return out;
}