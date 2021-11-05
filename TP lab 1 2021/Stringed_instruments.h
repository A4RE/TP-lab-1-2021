#pragma once
#include "Base.h"

class Stringed_instruments : public Base
{
private:
	string manufacturer;
	string description;
public:
	Stringed_instruments();

	Stringed_instruments(int a);
	
	void set_manufacturer();

	void set_manufacturer(char* buffer);

	string get_manufacturer();
	
	void set_description();

	void set_description(char* buffer);
	
	string get_description();
	
	string All_fields_to_string() override;
	string All_fields_to_string_to_save() override;
	~Stringed_instruments();

};