#include "Wind_instruments.h"
Wind_instruments::Wind_instruments() : Base()
{
	manufacturer = "Empty";
	defects = "Empty";
	cout << "����� Wind_instruments ������\n";
}
Wind_instruments::Wind_instruments(int a) : Base(1)
{
	set_manufacturer();
	set_defects();
	cout << "����� Wind_instruments ������\n";
}
void Wind_instruments::set_manufacturer()
{
	cout << "������� �������� �������������:\n";
	cin.ignore();
	getline(cin, manufacturer);
}
void Wind_instruments::set_manufacturer(char* buffer)
{
	manufacturer = (string)buffer;
}

void Wind_instruments::set_defects()
{
	cout << "������� ������� �����������\n������� ������� ����� �������, ��� ���������� ����� ������� ������� Enter:\n";
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
	cout << "����� Wind_instruments ������\n";
}
string Wind_instruments::All_fields_to_string()
{
	return "��������: " + this->get_last_name() + " " + this->get_name() + " " + this->get_middle_name() + " " + "��������: " + this->get_title() + " ����: " + to_string(this->get_price()) + " �-��: " + to_string(this->get_count()) + " �������������: " + this->get_manufacturer() + " ������� " + this->get_defects() + "\n";
}
string Wind_instruments::All_fields_to_string_to_save()
{
	return "<" + this->get_last_name() + "~" + this->get_name() + "~" + this->get_middle_name() + "~" + this->get_title() + "~" + to_string(this->get_price()) + "~" + to_string(this->get_count()) + "~" + this->get_manufacturer() + "~" + this->get_defects() + ">" + "\n";
}