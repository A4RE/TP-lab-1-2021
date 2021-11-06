#include "Keeper.h"

void Drums_add(Keeper<Drums>* example)
{
	
	int select;
	do
	{
		system("cls");
        cout << "Добавление удраного инструмента\n";
		cout << "1.Добавить\n2.Выйти\n";
		cin >> select;
		if (select == 1)
		{
			Drums* buffer = new Drums(1);
			cout << "Сейчас в контейнере Drums " << example->get_size() << " элементов\nВведите позицию где будет находиться новый элемент\n";
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
					cout << "Индекс не может быть отрицательным!\n";
				}
			} while (i < 0);

		}
		

		if(select != 1 && select != 2 )
		{
			cout << "Ошибка! Выбрано неверное действие\n";
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
			cout << "Список с барабанами пуст!\n";
			system("pause");
			return;
		}
		else
		{
			system("cls");
			cout << "1.Редактирование по-элементно\n";
			cout << "2.Редактирование всех полей\n";
			cout << "3.Выйти\n";
			cin >> select;
			if (select == 1)
			{
				cout << "Список барабанов:\n";
				example->show();
				cout << "Выберите элемент для редактирования:\n";
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
				cout << "Объект: " << example->get_element(select2)->All_fields_to_string() << " выбран" << endl;
				cout << "Что будем редактировать?\n1.Фамилию владельца\n2.Имя владельца\n3.Отчество владельца\n4.Тип\n5.Название\n6.Стоимость\n7.Единиц в оркестре\n8.Ничего\n";
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
					cout << "Объект: " << example->get_element(select2)->All_fields_to_string() << " отредактирован!" << endl;
					system("pause");
					if (select3 != 1 && select3 != 2 && select3 != 3 && select3 != 4 && select3 != 5 && select3 != 6 && select3 != 7 && select3 != 8)
					{
						cout << "Ошибка!Выбрано неверное действие!\n";
					}
				} while (select3 != 1 && select3 != 2 && select3 != 3 && select3 != 4 && select3 != 5 && select3 != 6 && select3 != 7 && select3 != 8);
			}

			if (select == 2)
			{
				cout << "Список барабанов:\n";
				example->show();
				cout << "Выберите элемент для редактирования:\n";
				int select2;
				do
				{
					cin >> select2;
					if (select2 < 0 || select2 > example->get_size())
					{
						cout << "Ошибка!\n";
					}
				} while (select2 < 0 || select2 > example->get_size());
				system("cls");
				cout << "Объект: " << example->get_element(select2)->All_fields_to_string() << " выбран" << endl;
				example->get_element(select2)->set_last_name();
				example->get_element(select2)->set_name();
				example->get_element(select2)->set_middle_name();
				example->get_element(select2)->set_type();
				example->get_element(select2)->set_title();
				example->get_element(select2)->set_price();
				example->get_element(select2)->set_count();
				cout << "Объект: " << example->get_element(select2)->All_fields_to_string() << " отредактирован!" << endl;
				system("pause");

			}
			if (select != 1 && select != 2 && select != 3)
			{
				cout << "Ошибка! Выбрано неверное действие\n";
			}
		}
	}
		while (select != 3);
}

void Drums_remove(Keeper<Drums>* example)
{
	if (example->get_size() == 0)
	{
		cout << "Список с барабанами пуст!\n";

	}
	else
	{
		
		example->show();
		cout << "Какой элемент будем удалять?\n";


		int select;
		do
		{
			cin >> select;
			if (select < 0 || select > example->get_size() - 1)
			{
				cout << "Ошибка!Выберите другой элемент!\n";
			}
		} while (select < 0 || select > example->get_size() - 1);
		example->delete_element(select);
		cout << "Барабан удален!\n";
	}
	system("pause");
}

void Drums_all_show(Keeper < Drums>* example)
{
	if (example->get_size() == 0)
	{
		cout << "Список с барабанами пуст!\n";

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
		cout << "1.Добавить элемент\n2.Отредактировать элемент\n3.Удалить элемент\n4.Показать все элементы\n5.Восставовить данные из файла\n6.Сохранить данные в файл\n7.Выход\n";
		
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
			cout << "Ошибка! Выбрано неверное действие\n";
		}
	} while (select != 7);
}

void Stringed_all_show(Keeper<Stringed_instruments>* example)
{
	if (example->get_size() == 0)
	{
		cout << "Список с струнными инструментами пуст!\n";

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
		cout << "Список с струнными инструментами пуст!\n";

	}
	else
	{

		example->show();
		cout << "Какой элемент будем удалять?\n";


		int select;
		do
		{
			cin >> select;
			if (select < 0 || select > example->get_size() - 1)
			{
				cout << "Ошибка!Выберите другой элемент!\n";
			}
		} while (select < 0 || select > example->get_size() - 1);
		example->delete_element(select);
		cout << "Струнный инструмент удален!\n";
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
			cout << "Список с струнными инструментами пуст!\n";
			system("pause");
			return;
		}
		else
		{
			system("cls");
			cout << "1.Редактирование по-элементно\n";
			cout << "2.Редактирование всех полей\n";
			cout << "3.Выйти\n";
			cin >> select;
			if (select == 1)
			{

				cout << "Список струнных элементов:\n";
				example->show();
				cout << "Выберите элемент для редактирования:\n";
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
				cout << "Объект: " << example->get_element(select2)->All_fields_to_string() << " выбран" << endl;
				cout << "Что будем редактировать?\n1.Фамилию владельца\n2.Имя владельца\n3.Отчество владельца\n4.Наименование производителя\n5.Название\n6.Стоимость\n7.Единиц в оркестре\n8.Краткое текстовоео описание\n9.Ничего\n";
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
					cout << "Объект: " << example->get_element(select2)->All_fields_to_string() << " отредактирован!" << endl;
					system("pause");
					if (select3 != 1 && select3 != 2 && select3 != 3 && select3 != 4 && select3 != 5 && select3 != 6 && select3 != 7 && select3 != 8 && select3 != 9)
					{
						cout << "Ошибка!Выбрано неверное действие!\n";
					}
				} while (select3 != 1 && select3 != 2 && select3 != 3 && select3 != 4 && select3 != 5 && select3 != 6 && select3 != 7 && select3 != 8);
			}

			if (select == 2)
			{
				cout << "Список барабанов:\n";
				example->show();
				cout << "Выберите элемент для редактирования:\n";
				int select2;
				do
				{
					cin >> select2;
					if (select2 < 0 || select2 > example->get_size())
					{
						cout << "Ошибка!\n";
					}
				} while (select2 < 0 || select2 > example->get_size());
				system("cls");
				cout << "Объект: " << example->get_element(select2)->All_fields_to_string() << " выбран" << endl;
				example->get_element(select2)->set_last_name();
				example->get_element(select2)->set_name();
				example->get_element(select2)->set_middle_name();
				example->get_element(select2)->set_manufacturer();
				example->get_element(select2)->set_title();
				example->get_element(select2)->set_price();
				example->get_element(select2)->set_count();
				example->get_element(select2)->set_description();
				cout << "Объект: " << example->get_element(select2)->All_fields_to_string() << " отредактирован!" << endl;
				system("pause");

			}
			if (select != 1 && select != 2 && select != 3)
			{
				cout << "Ошибка! Выбрано неверное действие\n";
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
		cout << "Добавление струнного инструмента\n";
		cout << "1.Добавить\n2.Выйти\n";
		cin >> select;
		if (select == 1)
		{
			Stringed_instruments* buffer = new Stringed_instruments(1);
			cout << "Сейчас в контейнере Stringed_instruments " << example->get_size() << " элементов\nВведите позицию где будет находиться новый элемент\n";
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
					cout << "Индекс не может быть отрицательным!\n";
				}
			} while (i < 0);

		}


		if (select != 1 && select != 2)
		{
			cout << "Ошибка! Выбрано неверное действие\n";
		}
	} while (select != 2);
}

void Stringed_menu(Keeper<Stringed_instruments>* example)
{
	int select;
	do {
		system("cls");
		cout << "1.Добавить элемент\n2.Отредактировать элемент\n3.Удалить элемент\n4.Показать все элементы\n5.Восставовить данные из файла\n6.Сохранить данные в файл\n7.Выход\n";
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
			cout << "Ошибка! Выбрано неверное действие\n";
		}
	} while (select != 7);
}

void Wind_all_show(Keeper<Wind_instruments>* example)
{
	if (example->get_size() == 0)
	{
		cout << "Список с духовыми инструментами пуст!\n";

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
		cout << "Список с духовыми инструментами пуст!\n";

	}
	else
	{

		example->show();
		cout << "Какой элемент будем удалять?\n";


		int select;
		do
		{
			cin >> select;
			if (select < 0 || select > example->get_size() - 1)
			{
				cout << "Ошибка!Выберите другой элемент!\n";
			}
		} while (select < 0 || select > example->get_size() - 1);
		example->delete_element(select);
		cout << "Духовой инструмент удален!\n";
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
			cout << "Список с духовыми инструментами пуст!\n";
			system("pause");
			return;
		}
		else
		{
			system("cls");
			cout << "1.Редактирование по-элементно\n";
			cout << "2.Редактирование всех полей\n";
			cout << "3.Выйти\n";
			cin >> select;
			if (select == 1)
			{
				cout << "Список духовых инструментов:\n";
				example->show();
				cout << "Выберите элемент для редактирования:\n";
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
				cout << "Объект: " << example->get_element(select2)->All_fields_to_string() << " выбран" << endl;
				cout << "Что будем редактировать?\n1.Фамилию владельца\n2.Имя владельца\n3.Отчество владельца\n4.Производитель\n5.Название\n6.Стоимость\n7.Единиц в оркестре\n8.Дефекты\n9.Ничего\n";
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
					cout << "Объект: " << example->get_element(select2)->All_fields_to_string() << " отредактирован!" << endl;
					system("pause");
					if (select3 != 1 && select3 != 2 && select3 != 3 && select3 != 4 && select3 != 5 && select3 != 6 && select3 != 7 && select3 != 8 && select3 != 9)
					{
						cout << "Ошибка!Выбрано неверное действие!\n";
					}
				} while (select3 != 1 && select3 != 2 && select3 != 3 && select3 != 4 && select3 != 5 && select3 != 6 && select3 != 7 && select3 != 8 && select3 != 9);
			}

			if (select == 2)
			{
				cout << "Список духовых инструментов:\n";
				example->show();
				cout << "Выберите элемент для редактирования:\n";
				int select2;
				do
				{
					cin >> select2;
					if (select2 < 0 || select2 > example->get_size())
					{
						cout << "Ошибка!\n";
					}
				} while (select2 < 0 || select2 > example->get_size());
				system("cls");
				cout << "Объект: " << example->get_element(select2)->All_fields_to_string() << " выбран" << endl;
				example->get_element(select2)->set_last_name();
				example->get_element(select2)->set_name();
				example->get_element(select2)->set_middle_name();
				example->get_element(select2)->set_manufacturer();
				example->get_element(select2)->set_title();
				example->get_element(select2)->set_price();
				example->get_element(select2)->set_count();
				example->get_element(select2)->set_defects();
				cout << "Объект: " << example->get_element(select2)->All_fields_to_string() << " отредактирован!" << endl;
				system("pause");

			}
			if (select != 1 && select != 2 && select != 3)
			{
				cout << "Ошибка! Выбрано неверное действие\n";
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
		cout << "Добавление духового инструмента\n";
		cout << "1.Добавить\n2.Выйти\n";
		cin >> select;
		if (select == 1)
		{
			Wind_instruments* buffer = new Wind_instruments(1);
			cout << "Сейчас в контейнере Stringed_instruments " << example->get_size() << " элементов\nВведите позицию где будет находиться новый элемент\n";
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
					cout << "Индекс не может быть отрицательным!\n";
				}
			} while (i < 0);

		}


		if (select != 1 && select != 2)
		{
			cout << "Ошибка! Выбрано неверное действие\n";
		}
	} while (select != 2);
}

void Wind_menu(Keeper<Wind_instruments>* example)
{
	int select;
	do {
		system("cls");
		cout << "1.Добавить элемент\n2.Отредактировать элемент\n3.Удалить элемент\n4.Показать все элементы\n5.Восставовить данные из файла\n6.Сохранить данные в файл\n7.Выход\n";
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
			cout << "Ошибка! Выбрано неверное действие\n";
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
		cout << "Введите размер контейнера:\n";
		cin >> size;
		if (size < 0)
		{
			cout << "Контейнер не может быть отрицательного размера!\n";
		}
	}
		while (size < 0);
	Keeper<Drums>* instrument1 = new Keeper<Drums>(size);
	Keeper<Stringed_instruments>* instrument2 = new Keeper<Stringed_instruments>(size);
	Keeper<Wind_instruments>* instrument3 = new Keeper<Wind_instruments>(size);

	do
	{
		system("cls");
		cout << "1.Меню работы с ударными инструментами\n2.Меню работы со струнными инструментами\n3.Меню работы с духовыми инструментами\n4.Выход\n";
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
			cout << "Ошибка! Выбрано неверное действие\n";
		}
	} while (select != 4);
}



int main(void)
{
	setlocale(LC_ALL, "Russian");
	const char* password = "0000";
	cout << "Для начала работы с программой введите пин-код:\n";
	
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
			cout << "Неверный пароль!\n";
		}
		
	}
	Orkester_menu();
	
	
		return 0;
}