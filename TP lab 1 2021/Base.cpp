#include "Base.h"
Base::Base()
{
	last_name = "Empty";
	middle_name = "Empty";
	name = "Empty";
	title = "Empty";
	price = -500;
	count = -600;
	cout << "������� ����� ������!\n";
}
Base::Base(int parametr)
{
	set_last_name();
	set_middle_name();
	set_name();
	set_title();
	set_price();
	set_count();
	cout << "������� ����� ������!\n";
}
void Base::set_last_name()
{
	cout << "������� ������� ���������:\n";
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
	cout << "������� �������� ���������:\n";
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
	cout << "������� ��� ���������:\n";
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
	cout << "������� �������� �����������:\n";
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
	cout << "������� ���� �����������\n�������, ���� �� ����� ���� ������ ����:\n";
	float buffer;
	do
	{
		cin >> buffer;
		if (buffer < 0)
		{
			cout << "���� �� ����� ���� �������������!������� ��� ���\n";
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
	cout << "������� ���������� ������������ � ��������\n�������, ���������� �� ����� ���� �������������:\n";
	float buffer = 0;
	do
	{
		cin >> buffer;
		if (buffer < 0)
		{
			cout << "���������� �� ����� ���� �������������!������� ��� ���\n";
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
	cout << "������� ������ ������!\n";
}