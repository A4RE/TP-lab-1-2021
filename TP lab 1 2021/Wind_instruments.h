#pragma once
#include "Base.h"
class Wind_instruments : public Base
{
private:
	string manufacturer;
	string defects;
public:
	Wind_instruments();
	
	Wind_instruments(int a);
	
	void set_manufacturer();
	
	void set_manufacturer(char* buffer);


	void set_defects();
	
	void set_defects(char* buffer);
	
	string get_manufacturer();
	string get_defects();
	string All_fields_to_string() override;
	string All_fields_to_string_to_save() override;
	~Wind_instruments();
	
};