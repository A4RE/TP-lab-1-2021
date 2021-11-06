#pragma once
#include "Node.h"
#include "Drums.h"
#include "Stringed_instruments.h"
#include "Wind_instruments.h"
#include <fstream>
#pragma warning(disable : 4996)
template <typename T>
class Keeper
{
	int size;

	T* data;
public:
	Keeper();

	Keeper(int size);
	~Keeper();
	
	int get_size();
	void delete_all_elements();


    T& operator[](int index);


	void reallocate(int newlength);
	void show();
	void resize(int newlength);
	T* get_element(int i);
	void add(T* value, int index);

	void delete_element(int index);

	void save_drums();
	void save_stringed();
	void save_wind();

	void load_drums();
	void load_stringed();
	void load_wind();


	};

template <typename T>
Keeper<T>::Keeper()
{
	size = 0;

	data = nullptr;
	cout << "Контейнер создан!\n";
}
template <typename T>
Keeper<T>::Keeper(int size)
{
	this->size = size;
	if (size >= 0)
	{
		data = new T[size];
		cout << "Контейнер создан!\n";
	}
	else
	{
		data = nullptr;
		cout << "Контейнер не может быть отрицательной длины!\n";
		system("pause");
		exit(1);
	}
}
template <typename T>
Keeper<T>::~Keeper()
{
	delete_all_elements();
	size = 0;
	free(data);
	cout << "Контейнер удален!\n";
}

template <typename T>
int Keeper<T>::get_size()
{
	return size;
}
template <typename T>
void Keeper<T>::delete_all_elements() // 
{
	delete[] data;
	data = nullptr;
	size = 0;
}

template <typename T>
T& Keeper<T>::operator[](int index)
{

	return data[index];
}
template <typename T>
void Keeper<T>::reallocate(int newlength)
{
	delete_all_elements();
	if (newlength <= 0)
	{
		return;
	}
	data = new T[newlength];
	size = newlength;

}
template <typename T>
void Keeper<T>::resize(int newlength)
{
	if (newlength == size)
	{
		return;
	}
	if (newlength < 0)
	{
		delete_all_elements();
		return;
	}
	T* buffer_data = new T[newlength];
	if (size >= 0)
	{
		int point = 0;
		if (newlength > size)
		{
			point = size;
		}
		else
		{
			point = newlength;
		}
		for (int index = 0; index < point; index++)
		{
			buffer_data[index] = data[index];
		}
		delete[] data;
		data = buffer_data;
		size = newlength;

	}
}
template <typename T>
void Keeper<T>::add(T* value, int index)
{
	if (index < 0 || index > size)
	{
		cout << "Позиция в классе Keeper отсутствует!\n";

	}

	T* buffer = new T[size + 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = data[i];
	}
	buffer[index] = *value;
	for (int j = index; j < size; j++)
	{
		buffer[j + 1] = data[j];
	}
	delete[] data;
	data = buffer;
	size++;

}
template <typename T>
void Keeper<T>::delete_element(int index)
{
	if (index < 0 || index > size)
	{
		cout << "Позиция в классе Keeper отсутствует!\n";

	}

	if (size == 1)
	{
		delete_all_elements();
		return;
	}
	T* buffer = new T[size - 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = data[i];
	}
	for (int j = index + 1; j < size; j++)
	{
		buffer[j - 1] = data[j];
	}
	delete[] data;
	data = buffer;
	size--;
}
template <typename T>
void Keeper<T>::show()
{
	for (int i = 0; i != size; i++)
	{
		cout << i << ". " << data[i].All_fields_to_string() << endl;
	}
}

template <typename T>
T* Keeper<T>::get_element(int i)
{
	return &data[i];
}

template <typename T>
void Keeper<T>::save_drums()
{
	string filename;
	cout << "Список поддерживаемых разрешений - txt,doc. Важно - в название файла должна быть надпись drums\n";
	cout << "Введите полный путь к файлу:\n";
	cin >> filename;
	const char* filename2 = filename.c_str();
	char* buffer = (char*)calloc(4, 4 * sizeof(char*));
	buffer[0] = filename2[(strlen(filename2) - 3)];
	buffer[1] = filename2[(strlen(filename2) - 2)];
	buffer[2] = filename2[(strlen(filename2) - 1)];
	const char* my_exception = "Не удается открыть файл для сохранения.\n";
	if (strstr(filename.c_str(), "drums") != 0)
	{
		if (strcmp(buffer, "txt") == 0 || strcmp(buffer, "doc"))
		{
			ofstream mywrite;
			mywrite.open(filename, ios::out);
			try
			{
				if (!mywrite.is_open())
				{
					throw my_exception;
				}

				mywrite << "Drums start\n";
				for (int i = 0; i != size; i++)
				{
					mywrite << data[i].All_fields_to_string_to_save();

				}
				mywrite << "Drums end";
			}
			catch (const char* my_exception)
			{
				cout << "Не удается открыть файл для сохранения.\n" << " " << " !" << filename << "!\n";
			}
		}
	}
	else
	{
		cout << "Разрешение не поддерживается!\n";
		system("pause");

	}

}
template <typename T>
void Keeper<T>::load_drums()
{
	string filename;
	cout << "Список поддерживаемых разрешений - txt,doc. Важно - в название файла должна быть надпись drums\n";
	cout << "Введите полный путь к файлу:\n";
	cin >> filename;
	const char* filename2 = filename.c_str();
	char* buffer = (char*)calloc(4, 4 * sizeof(char*));
	buffer[0] = filename2[(strlen(filename2) - 3)];
	buffer[1] = filename2[(strlen(filename2) - 2)];
	buffer[2] = filename2[(strlen(filename2) - 1)];
	const char* my_exception = "Не удается открыть файл для чтения.\n";
	const char* my_exception2 = "Ой! Что то пошло не так! Похоже, файл содержит лишнюю информацию!\n";
	if (strstr(filename.c_str(), "drums") != 0)
	{
		if (strcmp(buffer, "txt") == 0 || strcmp(buffer, "doc") == 0)
		{
			ifstream myread;
			myread.open(filename, ios::in);
			try
			{
				if (!myread.is_open())
				{
					throw my_exception;
				}
				string stroka;
				int i = 0;
				int flag = 0;
				while (getline(myread, stroka))
				{
					int cnt_open = 0;
					int cnt_close = 0;
					try
					{
						int cnt_tilda = 0;
						int cnt_open2 = 0;
						int cnt_close2 = 0;

						if (i == 0)
						{
							if (stroka == "Drums start")
							{
								flag++;
								i++;
								continue;
							}
							else
							{
								throw my_exception2;
							}
						}

						if (stroka == "Drums end")
						{
							flag++;
							break;

						}
						


						const char* temp = stroka.c_str();
						char* buffer2 = (char*)calloc(strlen(temp), strlen(temp) * sizeof(char*));
						strcpy(buffer2, stroka.c_str());
						for (int i = 0; i != strlen(buffer2); i++)
						{
							if (buffer2[i] == '<')
							{
								cnt_open2++;
							}
							if (buffer2[i] == '>')
							{
								cnt_close2++;
							}
							if (buffer2[i] == '~')
							{
								cnt_tilda++;
							}
						}
						
						if (cnt_open2 == 1 && cnt_close2 == 1 && cnt_tilda == 6)
						{
							Drums* example = new Drums();
							char* pointer = strtok(buffer2, "~");
							char* buffer_last_name = (char*)calloc(strlen(pointer), strlen(pointer) * sizeof(char*));
							strcpy(buffer_last_name, pointer);
							for (int i = 0, j = 1; j !=strlen(pointer)+1; j++, i++)
							{
								buffer_last_name[i] = pointer[j];
							}
							example->set_last_name(buffer_last_name);
							pointer = strtok(NULL, "~");
							example->set_name(pointer);
							pointer = strtok(NULL, "~");
							example->set_middle_name(pointer);
							pointer = strtok(NULL, "~");
							example->set_type(pointer);
							pointer = strtok(NULL, "~");
							example->set_title(pointer);
							pointer = strtok(NULL, "~");
							example->set_price(pointer);
							pointer = strtok(NULL, "~");
							example->set_count(pointer);
							add(example, size);
							resize(size);
							free(buffer_last_name);
							free(buffer2);

						}
						else
						{
							throw my_exception2;
						}


					}
					catch (const char* my_exception2)
					{
						cout << my_exception2 << filename << endl;
						system("pause");
					}
				}
				try
				{
					if (flag != 2)
					{
						delete_all_elements();
						throw my_exception2;
					}
					cout << "Файл успешно загружен!\n";
					system("pause");
				}
				catch (const char* my_exception2)
				{
					cout << my_exception2 << filename << endl;
					system("pause");
				}

			}
			catch (const char* my_exception)
			{
				cout << "Не удается открыть файл для загрузки.\n" << " " << " !" << filename << "!\n";
				system("pause");
			}
		}
	}
	else
	{
		cout << "Разрешение не поддерживается!\n";
		system("pause");

	}
}

template <typename T>
void Keeper<T>::save_stringed()
{
	string filename;
	cout << "Список поддерживаемых разрешений - txt,doc. Важно - в имени файла должно быть написано stringed\n";
	cout << "Введите полный путь к файлу:\n";
	cin >> filename;
	const char* filename2 = filename.c_str();
	char* buffer = (char*)calloc(4, 4 * sizeof(char*));
	buffer[0] = filename2[(strlen(filename2) - 3)];
	buffer[1] = filename2[(strlen(filename2) - 2)];
	buffer[2] = filename2[(strlen(filename2) - 1)];

	const char* my_exception = "Не удается открыть файл для сохранения.\n";
	if (strstr(filename.c_str(), "stringed") != 0)
	{
		if (strcmp(buffer, "txt") == 0 || strcmp(buffer, "doc"))
		{
			ofstream mywrite;
			mywrite.open(filename, ios::out);
			try
			{
				if (!mywrite.is_open())
				{
					throw my_exception;
				}

				mywrite << "Stringed start\n";
				for (int i = 0; i != size; i++)
				{
					mywrite << data[i].All_fields_to_string_to_save();

				}
				mywrite << "Stringed end" << endl;
			}
			catch (const char* my_exception)
			{
				cout << "Не удается открыть файл для сохранения.\n" << " " << " !" << filename << "!\n";
			}
		}
	}
	else
	{
		cout << "Разрешение не поддерживается!\n";
		system("pause");

	}
}

template <typename T>
void Keeper<T>::load_stringed()
{
	string filename;
	cout << "Список поддерживаемых разрешений - txt,doc. Важно - в название файла должна быть надпись stringed\n";
	cout << "Введите полный путь к файлу:\n";
	cin >> filename;
	const char* filename2 = filename.c_str();
	char* buffer = (char*)calloc(4, 4 * sizeof(char*));
	buffer[0] = filename2[(strlen(filename2) - 3)];
	buffer[1] = filename2[(strlen(filename2) - 2)];
	buffer[2] = filename2[(strlen(filename2) - 1)];
	const char* my_exception = "Не удается открыть файл для чтения.\n";
	const char* my_exception2 = "Ой! Что то пошло не так! Похоже, файл содержит лишнюю информацию!\n";
	if (strstr(filename.c_str(), "stringed") != 0)
	{
		if (strcmp(buffer, "txt") == 0 || strcmp(buffer, "doc") == 0)
		{
			ifstream myread;
			myread.open(filename, ios::in);
			try
			{
				if (!myread.is_open())
				{
					throw my_exception;
				}
				string stroka;
				int i = 0;
				int flag = 0;
				while (getline(myread, stroka))
				{
					int cnt_open = 0;
					int cnt_close = 0;
					try
					{
						int cnt_tilda = 0;
						int cnt_open2 = 0;
						int cnt_close2 = 0;

						if (i == 0)
						{
							if (stroka == "Stringed start")
							{
								flag++;
								i++;
								continue;
							}
							else
							{
								throw my_exception2;
							}
						}

						if (stroka == "Stringed end")
						{
							flag++;
							break;

						}
					


						const char* temp = stroka.c_str();
						char* buffer2 = (char*)calloc(strlen(temp), strlen(temp) * sizeof(char*));
						strcpy(buffer2, stroka.c_str());
						for (int i = 0; i != strlen(buffer2); i++)
						{
							if (buffer2[i] == '<')
							{
								cnt_open2++;
							}
							if (buffer2[i] == '>')
							{
								cnt_close2++;
							}
							if (buffer2[i] == '~')
							{
								cnt_tilda++;
							}
						}
						if (cnt_open2 == 1 && cnt_close2 == 1 && cnt_tilda == 7)
						{
							Stringed_instruments* example = new Stringed_instruments();
							char* pointer = strtok(buffer2, "~");
							char* buffer_last_name = (char*)calloc(strlen(pointer), strlen(pointer) * sizeof(char*));
							strcpy(buffer_last_name, pointer);
							for (int i = 0, j = 1; j != strlen(pointer)+1; j++, i++)
							{
								buffer_last_name[i] = pointer[j];
							}
							example->set_last_name(buffer_last_name);
							pointer = strtok(NULL, "~");
							example->set_name(pointer);
							pointer = strtok(NULL, "~");
							example->set_middle_name(pointer);
							
							pointer = strtok(NULL, "~");
							example->set_title(pointer);
							pointer = strtok(NULL, "~");
							example->set_price(pointer);
							pointer = strtok(NULL, "~");
							example->set_count(pointer);
							pointer = strtok(NULL, "~");
							example->set_manufacturer(pointer);
							pointer = strtok(NULL, "~");
							
							char* buffer3 = (char*)calloc(strlen(pointer), strlen(pointer) * sizeof(char*));
							for (int i = 0, j = 0; j != strlen(pointer)-1; j++, i++)
							{
								buffer3[i] = pointer[j];
							}
						
							example->set_description(buffer3);
							add(example, size);
							resize(size);
							free(buffer_last_name);
							free(buffer2);
							free(buffer3);

						}
						else
						{
							throw my_exception2;
						}


					}
					catch (const char* my_exception2)
					{
						cout << my_exception2 << filename << endl;
						system("pause");
					}
				}
				try
				{
					if (flag != 2)
					{
						delete_all_elements();
						throw my_exception2;
					}
					cout << "Файл успешно загружен!\n";
					system("pause");
				}
				catch (const char* my_exception2)
				{
					cout << my_exception2 << filename << endl;
					system("pause");
				}
			}
			catch (const char* my_exception)
			{
				cout << "Не удается открыть файл для загрузки.\n" << " " << " !" << filename << "!\n";
				system("pause");
			}
		}
	}
	else
	{
		cout << "Разрешение не поддерживается!\n";
		system("pause");

	}
}

template <typename T>
void Keeper<T>::save_wind()
{
	string filename;
	cout << "Список поддерживаемых разрешений - txt,doc. Важно - в имени файла должно быть написано wind\n";
	cout << "Введите полный путь к файлу:\n";
	cin >> filename;
	const char* filename2 = filename.c_str();
	char* buffer = (char*)calloc(4, 4 * sizeof(char*));
	buffer[0] = filename2[(strlen(filename2) - 3)];
	buffer[1] = filename2[(strlen(filename2) - 2)];
	buffer[2] = filename2[(strlen(filename2) - 1)];

	const char* my_exception = "Не удается открыть файл для сохранения.\n";
	if (strstr(filename.c_str(), "wind") != 0)
	{
		if (strcmp(buffer, "txt") == 0 || strcmp(buffer, "doc"))
		{
			ofstream mywrite;
			mywrite.open(filename, ios::out);
			try
			{
				if (!mywrite.is_open())
				{
					throw my_exception;
				}

				mywrite << "Wind start\n";
				for (int i = 0; i != size; i++)
				{
					mywrite << data[i].All_fields_to_string_to_save();

				}
				mywrite << "Wind end" << endl;
			}
			catch (const char* my_exception)
			{
				cout << "Не удается открыть файл для сохранения.\n" << " " << " !" << filename << "!\n";
			}
		}
	}
	else
	{
		cout << "Разрешение не поддерживается!\n";
		system("pause");

	}
}

template <typename T>
void Keeper<T>::load_wind()
{
	string filename;
	cout << "Список поддерживаемых разрешений - txt,doc. Важно - в название файла должна быть надпись wind\n";
	cout << "Введите полный путь к файлу:\n";
	cin >> filename;
	const char* filename2 = filename.c_str();
	char* buffer = (char*)calloc(4, 4 * sizeof(char*));
	buffer[0] = filename2[(strlen(filename2) - 3)];
	buffer[1] = filename2[(strlen(filename2) - 2)];
	buffer[2] = filename2[(strlen(filename2) - 1)];
	const char* my_exception = "Не удается открыть файл для чтения.\n";
	const char* my_exception2 = "Ой! Что то пошло не так! Похоже, файл содержит лишнюю информацию!\n";
	if (strstr(filename.c_str(), "wind") != 0)
	{
		if (strcmp(buffer, "txt") == 0 || strcmp(buffer, "doc") == 0)
		{
			ifstream myread;
			myread.open(filename, ios::in);
			try
			{
				if (!myread.is_open())
				{
					throw my_exception;
				}
				string stroka;
				int i = 0;
				int flag = 0;
				while (getline(myread, stroka))
				{
					int cnt_open = 0;
					int cnt_close = 0;
					try
					{
						int cnt_tilda = 0;
						int cnt_open2 = 0;
						int cnt_close2 = 0;

						if (i == 0)
						{
							if (stroka == "Wind start")
							{
								flag++;
								i++;
								continue;
							}
							else
							{
								throw my_exception2;
							}
						}

						if (stroka == "Wind end")
						{
							flag++;
							break;

						}
						


						const char* temp = stroka.c_str();
						char* buffer2 = (char*)calloc(strlen(temp), strlen(temp) * sizeof(char*));
						strcpy(buffer2, stroka.c_str());
						for (int i = 0; i != strlen(buffer2); i++)
						{
							if (buffer2[i] == '<')
							{
								cnt_open2++;
							}
							if (buffer2[i] == '>')
							{
								cnt_close2++;
							}
							if (buffer2[i] == '~')
							{
								cnt_tilda++;
							}
						}
						if (cnt_open2 == 1 && cnt_close2 == 1 && cnt_tilda == 7)
						{
							Wind_instruments* example = new Wind_instruments();
							char* pointer = strtok(buffer2, "~");
							char* buffer_last_name = (char*)calloc(strlen(pointer), strlen(pointer) * sizeof(char*));
							strcpy(buffer_last_name, pointer);
							for (int i = 0, j = 1; j != strlen(pointer)+1; j++, i++)
							{
								buffer_last_name[i] = pointer[j];
							}
						example->set_last_name(buffer_last_name);
							pointer = strtok(NULL, "~");
							example->set_name(pointer);
							pointer = strtok(NULL, "~");
							example->set_middle_name(pointer);

							pointer = strtok(NULL, "~");
							example->set_title(pointer);
							pointer = strtok(NULL, "~");
							example->set_price(pointer);
							pointer = strtok(NULL, "~");
							example->set_count(pointer);
							pointer = strtok(NULL, "~");
							example->set_manufacturer(pointer);
							pointer = strtok(NULL, "~");
							char* buffer3 = (char*)calloc(strlen(pointer), strlen(pointer) * sizeof(char*));
							for (int i = 0, j = 0; j != strlen(pointer) - 1; j++, i++)
							{
								buffer3[i] = pointer[j];
							}
							example->set_defects(buffer3);
							add(example, size);
							resize(size);
							free(buffer_last_name);
							free(buffer2);
							free(buffer3);

						}
						else
						{
							throw my_exception2;
						}


					}
					catch (const char* my_exception2)
					{
						cout << my_exception2 << filename << endl;
						system("pause");
					}
				}
				try
				{
					if (flag != 2)
					{
						delete_all_elements();
						throw my_exception2;
					}
					cout << "Файл успешно загружен!\n";
					system("pause");
				}
				catch (const char* my_exception2)
				{
					cout << my_exception2 << filename << endl;
					system("pause");
				}
			}
			catch (const char* my_exception)
			{
				cout << "Не удается открыть файл для загрузки.\n" << " " << " !" << filename << "!\n";
				system("pause");
			}
		}
	}
	else
	{
		cout << "Разрешение не поддерживается!\n";
		system("pause");

	}
}
	