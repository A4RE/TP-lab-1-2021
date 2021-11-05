#pragma once
#include "Base.h"
#include "string"
class Drums : public Base
{
private:
	string type;
public:
	Drums();
	
	Drums(int a);
	
	void set_type();
	
	void set_type(char* buffer);
	
	string get_type();
	
	friend ostream& operator << (ostream& out, Drums& example);
	string All_fields_to_string() override;
	string All_fields_to_string_to_save() override;
	~Drums();


};

