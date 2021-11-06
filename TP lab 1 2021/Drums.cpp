#include "Drums.h"
Drums::Drums() : Base()
{
	type = "Empty";
	cout << "Class Drums made\n";
}
Drums::Drums(int a) : Base(1)
{
	set_type();
	cout << "Class Drums made\n";
}
void Drums::set_type()
{
	cout << "Enter type of drum instrument:\n";
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
	cout << "Class Drums deleted\n";
}
string Drums::All_fields_to_string()
{
	return "Owner: " + this->get_last_name() + " " + this->get_name() + " " + this->get_middle_name() + " Type: " + this->get_type() + " Name of instrument: " + this->get_title() + " Price: " + to_string(this->get_price()) + " Count: " + to_string(this->get_count()) + "\n";
}string Drums::All_fields_to_string_to_save()
{
	return  "<" + this->get_last_name() + "~" + this->get_name() + "~" + this->get_middle_name() + "~" +  this->get_type() + "~" + this->get_title()+ "~" + to_string(this->get_price()) + "~" + to_string(this->get_count()) + ">\n";
}
ostream& operator << (ostream& out, Drums& example)
{
	out << example.All_fields_to_string();
	return out;
}