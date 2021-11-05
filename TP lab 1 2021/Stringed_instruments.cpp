#include "Stringed_instruments.h"
Stringed_instruments::Stringed_instruments() : Base()
{
	manufacturer = "Empty";
	description = "Empty";
	cout << "Class Stringed_instruments made\n";
}
Stringed_instruments::Stringed_instruments(int a) : Base(1)
{
	set_manufacturer();
	set_description();
	cout << "Class Stringed_instruments made\n";
}
void Stringed_instruments::set_manufacturer()
{
	cout << "Enter manufacture:\n";
	cin.ignore();
	getline(cin, manufacturer);

}
void Stringed_instruments::set_manufacturer(char* buffer)
{
	manufacturer = (string)buffer;
}
string Stringed_instruments::get_manufacturer()
{
	return manufacturer;
}
void Stringed_instruments::set_description()
{

	cout << "Enter short description\nWrite in one string, after push Enter\n";
	cin.ignore();
	getline(cin, description);


}

void Stringed_instruments::set_description(char* buffer)
{
	description = (string)buffer;
}
string Stringed_instruments::get_description()
{
	return description;
}
Stringed_instruments::~Stringed_instruments()
{
	cout << "Class Stringed_instruments was deleted\n";
}
string Stringed_instruments::All_fields_to_string()
{
	return "Owner: " + this->get_last_name() + " " + this->get_name() + " " + this->get_middle_name() + " " + "Name of instrument: "+  this->get_title() + " Price: " + to_string(this->get_price()) + " Count: " + to_string(this->get_count()) + " Manufacture: " + this->get_manufacturer() + " Description: " + this->get_description() + "\n";
}
string Stringed_instruments::All_fields_to_string_to_save()
{
	return "<" + this->get_last_name() + "~" + this->get_name() + "~" + this->get_middle_name() + "~" + this->get_title() + "~" +   to_string(this->get_price()) + "~" + to_string(this->get_count()) + "~" + this->get_manufacturer() + "~" + this->get_description() + ">" + "\n";
}