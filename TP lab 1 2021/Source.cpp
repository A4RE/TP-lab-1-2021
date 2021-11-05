#include "Keeper.h"

void Drums_add(Keeper<Drums>* example)
{
	
	int select;
	do
	{
		system("cls");
        cout << "Addition of drum instrument\n";
		cout << "1.Add\n2.Back\n";
		cin >> select;
		if (select == 1)
		{
			Drums* buffer = new Drums(1);
			cout << "Now in Drums " << example->get_size() << " elements\nEnter position of element\n";
			int i;
			do
			{
				cin >> i;
				if (i <= example->get_size())
				{
					example->add(buffer, i);
				}
				if (i > example->get_size())
				{
					example->resize(i);
					example->add(buffer, i);
				}




				if (i < 0)
				{
					cout << "Index can't be negative!\n";
				}
			} while (i < 0);

		}
		

		if(select != 1 && select != 2 )
		{
			cout << "Wrong action!\n";
		}
	}
		while (select != 2);
}

void Drums_edit(Keeper<Drums>* example)
{
	int select;
	do
	{
		if (example->get_size() == 0)
		{
			system("cls");
			cout << "List with drums is empty!\n";
			system("pause");
			return;
		}
		else
		{
			system("cls");
			cout << "1.Edition element by element\n";
			cout << "2.Edition all fields\n";
			cout << "3.Exit\n";
			cin >> select;
			if (select == 1)
			{
				cout << "Drums List:\n";
				example->show();
				cout << "Choose element for edition:\n";
				int select2;
				do
				{
					cin >> select2;
					if (select2 < 0 || select2 > example->get_size() - 1)
					{
						cout << "Ошибка!\n";
					}
				} while (select2 < 0 || select2 > example->get_size() - 1);
				system("cls");
				cout << "Object: " << example->get_element(select2)->All_fields_to_string() << " выбран" << endl;
				cout << "What edit?\n1.Last name\n2.Name\n3.Middle name\n4.Type\n5.Name of instrument\n6.Price\n7.Count\n8.Nothing\n";
				int select3;
				do
				{
					cin >> select3;
					if (select3 == 1)
					{
						example->get_element(select2)->set_last_name();
					}
					if (select3 == 2)
					{
						example->get_element(select2)->set_name();
					}
					if (select3 == 3)
					{
						example->get_element(select2)->set_middle_name();
					}
					if (select3 == 4)
					{
						example->get_element(select2)->set_type();
					}
					if (select3 == 5)
					{
						example->get_element(select2)->set_title();
					}
					if (select3 == 6)
					{
						example->get_element(select2)->set_price();
					}
					if (select3 == 7)
					{
						example->get_element(select2)->set_count();
					}
					cout << "Object: " << example->get_element(select2)->All_fields_to_string() << " was edited!" << endl;
					system("pause");
					if (select3 != 1 && select3 != 2 && select3 != 3 && select3 != 4 && select3 != 5 && select3 != 6 && select3 != 7 && select3 != 8)
					{
						cout << "Wrong action!\n";
					}
				} while (select3 != 1 && select3 != 2 && select3 != 3 && select3 != 4 && select3 != 5 && select3 != 6 && select3 != 7 && select3 != 8);
			}

			if (select == 2)
			{
				cout << "Drums list:\n";
				example->show();
				cout << "Choose element for edition:\n";
				int select2;
				do
				{
					cin >> select2;
					if (select2 < 0 || select2 > example->get_size())
					{
						cout << "Wrong!\n";
					}
				} while (select2 < 0 || select2 > example->get_size());
				system("cls");
				cout << "Object: " << example->get_element(select2)->All_fields_to_string() << " choosen" << endl;
				example->get_element(select2)->set_last_name();
				example->get_element(select2)->set_name();
				example->get_element(select2)->set_middle_name();
				example->get_element(select2)->set_type();
				example->get_element(select2)->set_title();
				example->get_element(select2)->set_price();
				example->get_element(select2)->set_count();
				cout << "Object: " << example->get_element(select2)->All_fields_to_string() << " Edited!" << endl;
				system("pause");

			}
			if (select != 1 && select != 2 && select != 3)
			{
				cout << "Wrong action!\n";
			}
		}
	}
		while (select != 3);
}

void Drums_remove(Keeper<Drums>* example)
{
	if (example->get_size() == 0)
	{
		cout << "Drums list is empty!\n";

	}
	else
	{
		
		example->show();
		cout << "Which element delete?\n";


		int select;
		do
		{
			cin >> select;
			if (select < 0 || select > example->get_size() - 1)
			{
				cout << "Wrong! Choose another element!\n";
			}
		} while (select < 0 || select > example->get_size() - 1);
		example->delete_element(select);
		cout << "Element deleted!\n";
	}
	system("pause");
}

void Drums_all_show(Keeper < Drums>* example)
{
	if (example->get_size() == 0)
	{
		cout << "Drums list is empty!\n";

	}
	else
	{
		example->show();
	}
	system("pause");
}

void Drums_menu(Keeper<Drums>* example)
{
	int select;
	do {
		system("cls");
		cout << "1.Add element\n2.Edit element\n3.Delete element\n4.Show list\n5.Load from file\n6.Save to file\n7.Exit\n";
		
		cin >> select;
		if (select == 1)
		{
			system("cls");
			Drums_add(example);
		}
		if (select == 2)
		{
			Drums_edit(example);
		}
		if (select == 3)
		{
			Drums_remove(example);

		}
		if (select == 4)
		{
			Drums_all_show(example);
		}
		if (select == 5)
		{
			example->load_drums();
		}
		if (select == 6)
		{
			example->save_drums();
		}

		if (select != 1 && select != 2 && select != 3 && select != 4 && select != 5 && select != 6 && select != 7)
		{
			cout << "Wrong action!\n";
		}
	} while (select != 7);
}

void Stringed_all_show(Keeper<Stringed_instruments>* example)
{
	if (example->get_size() == 0)
	{
		cout << "Instruments list is empty!\n";

	}
	else
	{
		example->show();
	}
	system("pause");
}

void Stringed_remove(Keeper<Stringed_instruments>* example)
{
	if (example->get_size() == 0)
	{
		cout << "List with stringed instruments is empty!\n";

	}
	else
	{

		example->show();
		cout << "Which element delete?\n";


		int select;
		do
		{
			cin >> select;
			if (select < 0 || select > example->get_size() - 1)
			{
				cout << "Wrong! Choose another element!\n";
			}
		} while (select < 0 || select > example->get_size() - 1);
		example->delete_element(select);
		cout << "Element was deleted!\n";
	}
	system("pause");
}

void Stringed_edit(Keeper<Stringed_instruments>* example)
{
	int select;
	do
	{
		if (example->get_size() == 0)
		{
			system("cls");
			cout << "List with stringed instruments is empty!\n";
			system("pause");
			return;
		}
		else
		{
			system("cls");
			cout << "1.Edition on element by element\n";
			cout << "2.Edition all fields\n";
			cout << "3.Back\n";
			cin >> select;
			if (select == 1)
			{

				cout << "List of stringed instruments:\n";
				example->show();
				cout << "Choose element for edition:\n";
				int select2;
				do
				{
					cin >> select2;
					if (select2 < 0 || select2 > example->get_size() - 1)
					{
						cout << "Ошибка!\n";
					}
				} while (select2 < 0 || select2 > example->get_size() - 1);
				system("cls");
				cout << "Objects: " << example->get_element(select2)->All_fields_to_string() << " выбран" << endl;
				cout << "What to edit?\n1.Last name\n2.Name\n3.Middle name\n4.Manufacture name\n5.Instrument name\n6.Price\n7.Count\n8.Short description\n9.Nothing\n";
				int select3;
				do
				{
					cin >> select3;
					if (select3 == 1)
					{
						example->get_element(select2)->set_last_name();
					}
					if (select3 == 2)
					{
						example->get_element(select2)->set_name();
					}
					if (select3 == 3)
					{
						example->get_element(select2)->set_middle_name();
					}
					if (select3 == 4)
					{
						example->get_element(select2)->set_manufacturer();
					}
					if (select3 == 5)
					{
						example->get_element(select2)->set_title();
					}
					if (select3 == 6)
					{
						example->get_element(select2)->set_price();
					}
					if (select3 == 7)
					{
						example->get_element(select2)->set_count();
					}

					if (select3 == 8)
					{
						example->get_element(select2)->set_description();
					}
					cout << "Object: " << example->get_element(select2)->All_fields_to_string() << " Edited!" << endl;
					system("pause");
					if (select3 != 1 && select3 != 2 && select3 != 3 && select3 != 4 && select3 != 5 && select3 != 6 && select3 != 7 && select3 != 8 && select3 != 9)
					{
						cout << "Wrong action!\n";
					}
				} while (select3 != 1 && select3 != 2 && select3 != 3 && select3 != 4 && select3 != 5 && select3 != 6 && select3 != 7 && select3 != 8);
			}

			if (select == 2)
			{
				cout << "list of stringed instruments:\n";
				example->show();
				cout << "Choose element for eddition:\n";
				int select2;
				do
				{
					cin >> select2;
					if (select2 < 0 || select2 > example->get_size())
					{
						cout << "Wrong!\n";
					}
				} while (select2 < 0 || select2 > example->get_size());
				system("cls");
				cout << "Object: " << example->get_element(select2)->All_fields_to_string() << " choosen" << endl;
				example->get_element(select2)->set_last_name();
				example->get_element(select2)->set_name();
				example->get_element(select2)->set_middle_name();
				example->get_element(select2)->set_manufacturer();
				example->get_element(select2)->set_title();
				example->get_element(select2)->set_price();
				example->get_element(select2)->set_count();
				example->get_element(select2)->set_description();
				cout << "Object: " << example->get_element(select2)->All_fields_to_string() << " Edited!" << endl;
				system("pause");

			}
			if (select != 1 && select != 2 && select != 3)
			{
				cout << "Wrong action!\n";
			}
		}
	} while (select != 3);
}

void Stringed_add(Keeper<Stringed_instruments>* example)
{
	int select;
	do
	{
		system("cls");
		cout << "Addition of stringed instrument\n";
		cout << "1.Add\n2.Back\n";
		cin >> select;
		if (select == 1)
		{
			Stringed_instruments* buffer = new Stringed_instruments(1);
			cout << "Now in Keeper Stringed_instruments " << example->get_size() << " elements\nEnter position of instrument in orchestre\n";
			int i;
			do
			{
				
				cin >> i;
				if (i <= example->get_size())
				{
					example->add(buffer, i);
				}
				if (i > example->get_size())
				{
					example->resize(i);
					example->add(buffer, i);
				}




				if (i < 0)
				{
					cout << "Index can't be negative!\n";
				}
			} while (i < 0);

		}


		if (select != 1 && select != 2)
		{
			cout << "Wrong Action!\n";
		}
	} while (select != 2);
}

void Stringed_menu(Keeper<Stringed_instruments>* example)
{
	int select;
	do {
		system("cls");
		cout << "1.Add element\n2.Edit element\n3.Delete element\n4.Show list\n5.Load from file\n6.Save to file\n7.Exit\n";
		cin >> select;
	
		if (select == 1)
		{
			system("cls");
			Stringed_add(example);
		}
		if (select == 2)
		{
			Stringed_edit(example);
		}
		if (select == 3)
		{
			Stringed_remove(example);
			system("pause");
		}

		if (select == 4)
		{
			Stringed_all_show(example);
		}
		if (select == 5)
		{
			example->load_stringed();
		}
		if (select == 6)
		{
			example->save_stringed();
		}
		if (select != 1 && select != 2 && select != 3 && select != 4 && select != 5 && select != 6 && select != 7)
		{
			cout << "Wrong action!\n";
		}
	} while (select != 7);
}

void Wind_all_show(Keeper<Wind_instruments>* example)
{
	if (example->get_size() == 0)
	{
		cout << "List with wind instruments is empty!\n";

	}
	else
	{
		example->show();
	}
	system("pause");
}

void Wind_remove(Keeper<Wind_instruments>* example)
{
	if (example->get_size() == 0)
	{
		cout << "List with wind instruments is empty!\n";

	}
	else
	{

		example->show();
		cout << "Which element delete?\n";


		int select;
		do
		{
			cin >> select;
			if (select < 0 || select > example->get_size() - 1)
			{
				cout << "Wrong! Choose another element!\n";
			}
		} while (select < 0 || select > example->get_size() - 1);
		example->delete_element(select);
		cout << "Wind instrument deleted!\n";
	}
	system("pause");
}

void Wind_edit(Keeper<Wind_instruments>* example)
{
	int select;
	do
	{
		if (example->get_size() == 0)
		{
			system("cls");
			cout << "List with wind instruments is empty!\n";
			system("pause");
			return;
		}
		else
		{
			system("cls");
			cout << "1.Edition element by element\n";
			cout << "2.Edition all fields\n";
			cout << "3.Back\n";
			cin >> select;
			if (select == 1)
			{
				cout << "List with wind instruments:\n";
				example->show();
				cout << "Choose element for edition:\n";
				int select2;
				do
				{
					cin >> select2;
					if (select2 < 0 || select2 > example->get_size() - 1)
					{
						cout << "Wrong!\n";
					}
				} while (select2 < 0 || select2 > example->get_size() - 1);
				system("cls");
				cout << "Object: " << example->get_element(select2)->All_fields_to_string() << " choosen" << endl;
				cout << "What edit?\n1.Last name\n2.Name\n3.Middle name\n4.Manufacture name\n5.Instrument name\n6.Price\n7.Count in orchestre\n8.Defects\n9.Nothing\n";
				int select3;
				do
				{
					cin >> select3;
					if (select3 == 1)
					{
						example->get_element(select2)->set_last_name();
					}
					if (select3 == 2)
					{
						example->get_element(select2)->set_name();
					}
					if (select3 == 3)
					{
						example->get_element(select2)->set_middle_name();
					}
					if (select3 == 4)
					{
						example->get_element(select2)->set_manufacturer();
					}
					if (select3 == 5)
					{
						example->get_element(select2)->set_title();
					}
					if (select3 == 6)
					{
						example->get_element(select2)->set_price();
					}
					if (select3 == 7)
					{
						example->get_element(select2)->set_count();
					}
					if (select3 == 8)
					{
						example->get_element(select2)->set_defects();
					}
					cout << "Objects: " << example->get_element(select2)->All_fields_to_string() << " was edited!" << endl;
					system("pause");
					if (select3 != 1 && select3 != 2 && select3 != 3 && select3 != 4 && select3 != 5 && select3 != 6 && select3 != 7 && select3 != 8 && select3 != 9)
					{
						cout << "Wrong action!\n";
					}
				} while (select3 != 1 && select3 != 2 && select3 != 3 && select3 != 4 && select3 != 5 && select3 != 6 && select3 != 7 && select3 != 8 && select3 != 9);
			}

			if (select == 2)
			{
				cout << "List with wind instruments:\n";
				example->show();
				cout << "Choose element for edition:\n";
				int select2;
				do
				{
					cin >> select2;
					if (select2 < 0 || select2 > example->get_size())
					{
						cout << "Wrong!\n";
					}
				} while (select2 < 0 || select2 > example->get_size());
				system("cls");
				cout << "Object: " << example->get_element(select2)->All_fields_to_string() << " choosen" << endl;
				example->get_element(select2)->set_last_name();
				example->get_element(select2)->set_name();
				example->get_element(select2)->set_middle_name();
				example->get_element(select2)->set_manufacturer();
				example->get_element(select2)->set_title();
				example->get_element(select2)->set_price();
				example->get_element(select2)->set_count();
				example->get_element(select2)->set_defects();
				cout << "Object: " << example->get_element(select2)->All_fields_to_string() << " edited!" << endl;
				system("pause");

			}
			if (select != 1 && select != 2 && select != 3)
			{
				cout << "Wrong action!\n";
			}
		}
	} while (select != 3);
}

void Wind_add(Keeper<Wind_instruments>* example)
{
	int select;
	do
	{
		system("cls");
		cout << "Addition of wind instrument\n";
		cout << "1.Add\n2.Back\n";
		cin >> select;
		if (select == 1)
		{
			Wind_instruments* buffer = new Wind_instruments(1);
			cout << "Now in Keeper Stringed_instruments " << example->get_size() << " elements\nChoose position in orchestre\n";
			int i;
			do
			{
				cin >> i;
				if (i <= example->get_size())
				{
					example->add(buffer, i);
				}
				if (i > example->get_size())
				{
					example->resize(i);
					example->add(buffer, i);
				}




				if (i < 0)
				{
					cout << "Index can't be negative!\n";
				}
			} while (i < 0);

		}


		if (select != 1 && select != 2)
		{
			cout << "Wrong action!\n";
		}
	} while (select != 2);
}

void Wind_menu(Keeper<Wind_instruments>* example)
{
	int select;
	do {
		system("cls");
		cout << "1.Add element\n2.Edit element\n3.Delete element\n4.Show all elements\n5.Load from file\n6.Save tof ile\n7.Exit\n";
		cin >> select;
	
		if (select == 1)
		{
			system("cls");
			Wind_add(example);
		}
		if (select == 2)
		{
			Wind_edit(example);
		}
		if (select == 3)
		{
			Wind_remove(example);
		}
		if (select == 4)
		{
			Wind_all_show(example);
		}
		if (select == 5)
		{
			example->load_wind();
		}
		if (select == 6)
		{
			example->save_wind();
		}
		if (select != 1 && select != 2 && select != 3 && select != 4 && select != 5 && select != 6 && select != 7)
		{
			cout << "Wrong action!\n";
		}
	} while (select != 7);
}

void Orkester_menu()
{
	int select;
	system("cls");
	int size = 0;
	do
	{
		cout << "Enter Keeper length:\n";
		cin >> size;
		if (size < 0)
		{
			cout << "Length can't be negative!\n";
		}
	}
		while (size < 0);
	Keeper<Drums>* instrument1 = new Keeper<Drums>(size);
	Keeper<Stringed_instruments>* instrument2 = new Keeper<Stringed_instruments>(size);
	Keeper<Wind_instruments>* instrument3 = new Keeper<Wind_instruments>(size);

	do
	{
		system("cls");
		cout << "1.Menu for drums\n2.Menu for stringed instrument\n3.Menu for wind instruments\n4.Exit\n";
		cin >> select;
		if (select == 1)
		{
			system("cls");
			Drums_menu(instrument1);
		}
		if (select == 2)
		{
			system("cls");
			Stringed_menu(instrument2);
		}
		if (select == 3)
		{
			system("cls");
			Wind_menu(instrument3);
		}


		if (select != 1 && select != 2 && select != 3 && select != 4 )
		{
			cout << "Wrong Action\n";
		}
	} while (select != 4);
}



int main(void)
{
	const char* password = "0000";
	cout << "Enter password:\n";
	
	string entry_password_string;

	while (true)
	{
		cin >> entry_password_string;

		if (strcmp(entry_password_string.c_str(), password) == 0)
		{
			break;
		}
		if (strcmp(entry_password_string.c_str(), password) != 0)
		{
			cout << "Wrong password!\n";
		}
		
	}
	Orkester_menu();
	
	
		return 0;
}