#pragma once
#include <iostream>
#include <string.h>
#include <string>
using namespace std;
class Base
{
private:
	string last_name;
	string middle_name;
	string name;
	string title;
	float price;
	int count;
public:
	Base();
	Base(int parametr);
	void set_last_name();
	void set_last_name(char* buffer);
	string get_last_name();

	void set_middle_name();
	void set_middle_name(char* buffer);
	string get_middle_name();

	void set_name();

	void set_name(char* buffer);
	string get_name();
	void set_title();

	void set_title(char* buffer);
	string get_title();

	void set_price();
	void set_price(char* buffer);
	float get_price();
	void set_count();
	void set_count(char* buffer);
	int get_count();

	virtual string All_fields_to_string() = 0;
	virtual string All_fields_to_string_to_save() = 0;
	
	virtual ~Base();
	

};

