#include "Keeper.h"

void Drums_add(Keeper<Drums>* example)
{
	
	int select;
	do
	{
		system("cls");
        cout << "���������� �������� �����������\n";
		cout << "1.��������\n2.�����\n";
		cin >> select;
		if (select == 1)
		{
			Drums* buffer = new Drums(1);
			cout << "������ � ���������� Drums " << example->get_size() << " ���������\n������� ������� ��� ����� ���������� ����� �������\n";
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
					cout << "������ �� ����� ���� �������������!\n";
				}
			} while (i < 0);

		}
		

		if(select != 1 && select != 2 )
		{
			cout << "������! ������� �������� ��������\n";
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
			cout << "������ � ���������� ����!\n";
			system("pause");
			return;
		}
		else
		{
			system("cls");
			cout << "1.�������������� ��-���������\n";
			cout << "2.�������������� ���� �����\n";
			cout << "3.�����\n";
			cin >> select;
			if (select == 1)
			{
				cout << "������ ���������:\n";
				example->show();
				cout << "�������� ������� ��� ��������������:\n";
				int select2;
				do
				{
					cin >> select2;
					if (select2 < 0 || select2 > example->get_size() - 1)
					{
						cout << "������!\n";
					}
				} while (select2 < 0 || select2 > example->get_size() - 1);
				system("cls");
				cout << "������: " << example->get_element(select2)->All_fields_to_string() << " ������" << endl;
				cout << "��� ����� �������������?\n1.������� ���������\n2.��� ���������\n3.�������� ���������\n4.���\n5.��������\n6.���������\n7.������ � ��������\n8.������\n";
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
					cout << "������: " << example->get_element(select2)->All_fields_to_string() << " ��������������!" << endl;
					system("pause");
					if (select3 != 1 && select3 != 2 && select3 != 3 && select3 != 4 && select3 != 5 && select3 != 6 && select3 != 7 && select3 != 8)
					{
						cout << "������!������� �������� ��������!\n";
					}
				} while (select3 != 1 && select3 != 2 && select3 != 3 && select3 != 4 && select3 != 5 && select3 != 6 && select3 != 7 && select3 != 8);
			}

			if (select == 2)
			{
				cout << "������ ���������:\n";
				example->show();
				cout << "�������� ������� ��� ��������������:\n";
				int select2;
				do
				{
					cin >> select2;
					if (select2 < 0 || select2 > example->get_size())
					{
						cout << "������!\n";
					}
				} while (select2 < 0 || select2 > example->get_size());
				system("cls");
				cout << "������: " << example->get_element(select2)->All_fields_to_string() << " ������" << endl;
				example->get_element(select2)->set_last_name();
				example->get_element(select2)->set_name();
				example->get_element(select2)->set_middle_name();
				example->get_element(select2)->set_type();
				example->get_element(select2)->set_title();
				example->get_element(select2)->set_price();
				example->get_element(select2)->set_count();
				cout << "������: " << example->get_element(select2)->All_fields_to_string() << " ��������������!" << endl;
				system("pause");

			}
			if (select != 1 && select != 2 && select != 3)
			{
				cout << "������! ������� �������� ��������\n";
			}
		}
	}
		while (select != 3);
}

void Drums_remove(Keeper<Drums>* example)
{
	if (example->get_size() == 0)
	{
		cout << "������ � ���������� ����!\n";

	}
	else
	{
		
		example->show();
		cout << "����� ������� ����� �������?\n";


		int select;
		do
		{
			cin >> select;
			if (select < 0 || select > example->get_size() - 1)
			{
				cout << "������!�������� ������ �������!\n";
			}
		} while (select < 0 || select > example->get_size() - 1);
		example->delete_element(select);
		cout << "������� ������!\n";
	}
	system("pause");
}

void Drums_all_show(Keeper < Drums>* example)
{
	if (example->get_size() == 0)
	{
		cout << "������ � ���������� ����!\n";

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
		cout << "1.�������� �������\n2.��������������� �������\n3.������� �������\n4.�������� ��� ��������\n5.������������ ������ �� �����\n6.��������� ������ � ����\n7.�����\n";
		
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
			cout << "������! ������� �������� ��������\n";
		}
	} while (select != 7);
}

void Stringed_all_show(Keeper<Stringed_instruments>* example)
{
	if (example->get_size() == 0)
	{
		cout << "������ � ��������� ������������� ����!\n";

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
		cout << "������ � ��������� ������������� ����!\n";

	}
	else
	{

		example->show();
		cout << "����� ������� ����� �������?\n";


		int select;
		do
		{
			cin >> select;
			if (select < 0 || select > example->get_size() - 1)
			{
				cout << "������!�������� ������ �������!\n";
			}
		} while (select < 0 || select > example->get_size() - 1);
		example->delete_element(select);
		cout << "�������� ���������� ������!\n";
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
			cout << "������ � ��������� ������������� ����!\n";
			system("pause");
			return;
		}
		else
		{
			system("cls");
			cout << "1.�������������� ��-���������\n";
			cout << "2.�������������� ���� �����\n";
			cout << "3.�����\n";
			cin >> select;
			if (select == 1)
			{

				cout << "������ �������� ���������:\n";
				example->show();
				cout << "�������� ������� ��� ��������������:\n";
				int select2;
				do
				{
					cin >> select2;
					if (select2 < 0 || select2 > example->get_size() - 1)
					{
						cout << "������!\n";
					}
				} while (select2 < 0 || select2 > example->get_size() - 1);
				system("cls");
				cout << "������: " << example->get_element(select2)->All_fields_to_string() << " ������" << endl;
				cout << "��� ����� �������������?\n1.������� ���������\n2.��� ���������\n3.�������� ���������\n4.������������ �������������\n5.��������\n6.���������\n7.������ � ��������\n8.������� ���������� ��������\n9.������\n";
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
					cout << "������: " << example->get_element(select2)->All_fields_to_string() << " ��������������!" << endl;
					system("pause");
					if (select3 != 1 && select3 != 2 && select3 != 3 && select3 != 4 && select3 != 5 && select3 != 6 && select3 != 7 && select3 != 8 && select3 != 9)
					{
						cout << "������!������� �������� ��������!\n";
					}
				} while (select3 != 1 && select3 != 2 && select3 != 3 && select3 != 4 && select3 != 5 && select3 != 6 && select3 != 7 && select3 != 8);
			}

			if (select == 2)
			{
				cout << "������ ���������:\n";
				example->show();
				cout << "�������� ������� ��� ��������������:\n";
				int select2;
				do
				{
					cin >> select2;
					if (select2 < 0 || select2 > example->get_size())
					{
						cout << "������!\n";
					}
				} while (select2 < 0 || select2 > example->get_size());
				system("cls");
				cout << "������: " << example->get_element(select2)->All_fields_to_string() << " ������" << endl;
				example->get_element(select2)->set_last_name();
				example->get_element(select2)->set_name();
				example->get_element(select2)->set_middle_name();
				example->get_element(select2)->set_manufacturer();
				example->get_element(select2)->set_title();
				example->get_element(select2)->set_price();
				example->get_element(select2)->set_count();
				example->get_element(select2)->set_description();
				cout << "������: " << example->get_element(select2)->All_fields_to_string() << " ��������������!" << endl;
				system("pause");

			}
			if (select != 1 && select != 2 && select != 3)
			{
				cout << "������! ������� �������� ��������\n";
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
		cout << "���������� ��������� �����������\n";
		cout << "1.��������\n2.�����\n";
		cin >> select;
		if (select == 1)
		{
			Stringed_instruments* buffer = new Stringed_instruments(1);
			cout << "������ � ���������� Stringed_instruments " << example->get_size() << " ���������\n������� ������� ��� ����� ���������� ����� �������\n";
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
					cout << "������ �� ����� ���� �������������!\n";
				}
			} while (i < 0);

		}


		if (select != 1 && select != 2)
		{
			cout << "������! ������� �������� ��������\n";
		}
	} while (select != 2);
}

void Stringed_menu(Keeper<Stringed_instruments>* example)
{
	int select;
	do {
		system("cls");
		cout << "1.�������� �������\n2.��������������� �������\n3.������� �������\n4.�������� ��� ��������\n5.������������ ������ �� �����\n6.��������� ������ � ����\n7.�����\n";
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
			cout << "������! ������� �������� ��������\n";
		}
	} while (select != 7);
}

void Wind_all_show(Keeper<Wind_instruments>* example)
{
	if (example->get_size() == 0)
	{
		cout << "������ � �������� ������������� ����!\n";

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
		cout << "������ � �������� ������������� ����!\n";

	}
	else
	{

		example->show();
		cout << "����� ������� ����� �������?\n";


		int select;
		do
		{
			cin >> select;
			if (select < 0 || select > example->get_size() - 1)
			{
				cout << "������!�������� ������ �������!\n";
			}
		} while (select < 0 || select > example->get_size() - 1);
		example->delete_element(select);
		cout << "������� ���������� ������!\n";
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
			cout << "������ � �������� ������������� ����!\n";
			system("pause");
			return;
		}
		else
		{
			system("cls");
			cout << "1.�������������� ��-���������\n";
			cout << "2.�������������� ���� �����\n";
			cout << "3.�����\n";
			cin >> select;
			if (select == 1)
			{
				cout << "������ ������� ������������:\n";
				example->show();
				cout << "�������� ������� ��� ��������������:\n";
				int select2;
				do
				{
					cin >> select2;
					if (select2 < 0 || select2 > example->get_size() - 1)
					{
						cout << "������!\n";
					}
				} while (select2 < 0 || select2 > example->get_size() - 1);
				system("cls");
				cout << "������: " << example->get_element(select2)->All_fields_to_string() << " ������" << endl;
				cout << "��� ����� �������������?\n1.������� ���������\n2.��� ���������\n3.�������� ���������\n4.�������������\n5.��������\n6.���������\n7.������ � ��������\n8.�������\n9.������\n";
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
					cout << "������: " << example->get_element(select2)->All_fields_to_string() << " ��������������!" << endl;
					system("pause");
					if (select3 != 1 && select3 != 2 && select3 != 3 && select3 != 4 && select3 != 5 && select3 != 6 && select3 != 7 && select3 != 8 && select3 != 9)
					{
						cout << "������!������� �������� ��������!\n";
					}
				} while (select3 != 1 && select3 != 2 && select3 != 3 && select3 != 4 && select3 != 5 && select3 != 6 && select3 != 7 && select3 != 8 && select3 != 9);
			}

			if (select == 2)
			{
				cout << "������ ������� ������������:\n";
				example->show();
				cout << "�������� ������� ��� ��������������:\n";
				int select2;
				do
				{
					cin >> select2;
					if (select2 < 0 || select2 > example->get_size())
					{
						cout << "������!\n";
					}
				} while (select2 < 0 || select2 > example->get_size());
				system("cls");
				cout << "������: " << example->get_element(select2)->All_fields_to_string() << " ������" << endl;
				example->get_element(select2)->set_last_name();
				example->get_element(select2)->set_name();
				example->get_element(select2)->set_middle_name();
				example->get_element(select2)->set_manufacturer();
				example->get_element(select2)->set_title();
				example->get_element(select2)->set_price();
				example->get_element(select2)->set_count();
				example->get_element(select2)->set_defects();
				cout << "������: " << example->get_element(select2)->All_fields_to_string() << " ��������������!" << endl;
				system("pause");

			}
			if (select != 1 && select != 2 && select != 3)
			{
				cout << "������! ������� �������� ��������\n";
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
		cout << "���������� �������� �����������\n";
		cout << "1.��������\n2.�����\n";
		cin >> select;
		if (select == 1)
		{
			Wind_instruments* buffer = new Wind_instruments(1);
			cout << "������ � ���������� Stringed_instruments " << example->get_size() << " ���������\n������� ������� ��� ����� ���������� ����� �������\n";
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
					cout << "������ �� ����� ���� �������������!\n";
				}
			} while (i < 0);

		}


		if (select != 1 && select != 2)
		{
			cout << "������! ������� �������� ��������\n";
		}
	} while (select != 2);
}

void Wind_menu(Keeper<Wind_instruments>* example)
{
	int select;
	do {
		system("cls");
		cout << "1.�������� �������\n2.��������������� �������\n3.������� �������\n4.�������� ��� ��������\n5.������������ ������ �� �����\n6.��������� ������ � ����\n7.�����\n";
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
			cout << "������! ������� �������� ��������\n";
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
		cout << "������� ������ ����������:\n";
		cin >> size;
		if (size < 0)
		{
			cout << "��������� �� ����� ���� �������������� �������!\n";
		}
	}
		while (size < 0);
	Keeper<Drums>* instrument1 = new Keeper<Drums>(size);
	Keeper<Stringed_instruments>* instrument2 = new Keeper<Stringed_instruments>(size);
	Keeper<Wind_instruments>* instrument3 = new Keeper<Wind_instruments>(size);

	do
	{
		system("cls");
		cout << "1.���� ������ � �������� �������������\n2.���� ������ �� ��������� �������������\n3.���� ������ � �������� �������������\n4.�����\n";
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
			cout << "������! ������� �������� ��������\n";
		}
	} while (select != 4);
}



int main(void)
{
	setlocale(LC_ALL, "Russian");
	const char* password = "0000";
	cout << "��� ������ ������ � ���������� ������� ���-���:\n";
	
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
			cout << "�������� ������!\n";
		}
		
	}
	Orkester_menu();
	
	
		return 0;
}