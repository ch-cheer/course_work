# course_work.cpp

	#include "Func.h"

	int _Menu;
	
	void Menu() {
		cout << "Выберите действие: " << endl
			<< "(0) Выход из программы" << endl
			<< "(1) Ввод данных" << endl
			<< "(2) Вывод данных" << endl
			<< "(3) Изменение данных" << endl
			<< "(4) Добавление данных" << endl
			<< "(5) Удаление данных" << endl
			<< "(6) Сортировка данных" << endl
			<< "(7) Сохранение данных" << endl
			<< "Введите значение: ";
		cin >> _Menu;
	}
	
	void Return() {
		system("cls");
		cout << "Введён некоректный номер" << endl
			<< "(1) Вернуться в меню" << endl
			<< "(2) Вернуть к прошлому шагу" << endl
			<< "Введите значение: ";
	}
	
	int main() {
		setlocale(LC_ALL, "Russian");
		int oldCPin, oldCPout;
		oldCPin = GetConsoleCP();
		oldCPout = GetConsoleOutputCP();
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
	
		Menu();
		int _actions;
		int _actions_return;
		string FileName;
		string bin = ".txt";
	
		int _size = 0;
		Data* d = new Data[_size];
	
		while (_Menu != 0) {
			switch (_Menu)
			{
			case 1:
			d1:system("cls");
	
				cout << "(0) Вернуться в меню" << endl
					<< "(1) Внести данные вручную" << endl
					<< "(2) Считать из файла" << endl
					<< "Введите значение: ";
				cin >> _actions;
	
				if (_actions == 1) {
					DataEntry(d, _size);
				}
				else if (_actions == 2) {
					cout << "Введите название файла: ";
					cin >> FileName;
					FileName += bin;
					DataRead(d, _size, FileName);
				}
				else if (_actions == 0) { system("cls"); Menu(); break; }
				else {
				d2:system("cls");
					Return();
					cin >> _actions_return;
					system("cls");
					if (_actions_return == 1) { system("cls"); Menu(); break; }
					else if (_actions_return == 2) { goto d1; }
					else { goto d2; }
				}
				system("pause");
				system("cls");
				Menu();
				break;
			case 2:
				system("cls");
	
				if (_size != 0) { Print(d, _size); }
				else { cout << "Данные пусты" << endl; }
	
				system("pause");
				system("cls");
				Menu();
				break;
			case 3:
				system("cls");
	
				if (_size != 0) { DataChange(d, _size); }
				else { cout << "Данные пусты" << endl; }
	
				system("pause");
				system("cls");
				Menu();
				break;
			case 4:
				system("cls");
	
				if (_size != 0) { DataAdd(d, _size); }
				else { cout << "Данные пусты" << endl; }
	
				system("pause");
				system("cls");
				Menu();
				break;
			case 5:
				system("cls");
	
				if (_size != 0) { DataDel(d, _size); }
				else { cout << "Данные пусты" << endl; }
	
				system("pause");
				system("cls");
				Menu();
				break;
			case 6:
				system("cls");
	
				if (_size != 0) { DataSort(d, _size); }
				else { cout << "Данные пусты" << endl; }
	
				system("pause");
				system("cls");
				Menu();
				break;
			case 7:
				system("cls");
	
				if (_size != 0) {
					cout << "Введите название файла: ";
					cin >> FileName;
					FileName += bin;
					DataSave(d, _size, FileName);
				}
				else { cout << "Данные пусты" << endl; }
	
				system("pause");
				system("cls");
				Menu();
				break;
			default:
				cout << "Пункт меню введён не верно" << endl;
				system("cls");
				Menu();
				break;
			}
		}
	
		system("cls");
		cout << "Работа завершена" << endl;
		system("Pause");
	}
