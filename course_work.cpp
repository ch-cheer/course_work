#include "Func.h"
#include "ListMenu.h"

int switch_mainMenu = 0;
void mainMenu() {
	Menu mainMenu;
	mainMenu.clearItem();
	mainMenu.addItem("Выход из программы");
	mainMenu.addItem("Ввод данных");
	mainMenu.addItem("Вывод данных");
	mainMenu.addItem("Изменение данных");
	mainMenu.addItem("Добавление данных");
	mainMenu.addItem("Удаление данных");
	mainMenu.addItem("Сортировка данных");
	mainMenu.addItem("Сохранение данных");
	switch_mainMenu = mainMenu.entryItem(0, 7);
};

int switch_menuCase1 = 0;
void menuCase1() {
	Menu menuCase1;
	menuCase1.clearItem();
	menuCase1.addItem("Вернуться в главное меню");
	menuCase1.addItem("Внести данные о студенте вручную");
	menuCase1.addItem("Внести данные о студенте из файла");
	switch_menuCase1 = menuCase1.entryItem(0, 2);
};

int main() {
	setlocale(LC_ALL, "Russian");
	int oldCPin, oldCPout;
	oldCPin = GetConsoleCP();
	oldCPout = GetConsoleOutputCP();
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string FileName;
	string bin = ".bin";

	int _size = 0;
	Data* d = new Data[_size];

	Check* cl = new Check();
	
	mainMenu();
	while (switch_mainMenu != 0) {
		switch (switch_mainMenu) {
		case 1:
			menuCase1();
			while (switch_menuCase1 != 0) {
				switch (switch_menuCase1) {
				case 1:
					switch_menuCase1 = 0;
					DataEntry(d, _size);
					break;
				case 2:
					switch_menuCase1 = 0;
					cl->clear();
					cl->setLabel("Введите название файла: ");
					FileName = cl->getData(editType::onlyAlpha, 10);
					FileName += bin;
					DataRead(d, _size, FileName);
					break;
					mainMenu();
					break;
				}
			}
			system("pause");
			mainMenu();
			break;
		case 2:
			system("cls");
			if (_size != 0) { Print(d, _size); }
			else { cout << "Данные пусты" << endl; }
			system("pause");
			mainMenu();
			break;
		case 3:
			system("cls");
			if (_size != 0) { DataChange(d, _size); }
			else { cout << "Данные пусты" << endl; }
			system("pause");
			mainMenu();
			break;
		case 4:
			system("cls");
			if (_size != 0) { DataAdd(d, _size); }
			else { cout << "Данные пусты" << endl; }
			system("pause");
			mainMenu();
			break;
		case 5:
			system("cls");
			if (_size != 0) { DataDel(d, _size); }
			else { cout << "Данные пусты" << endl; }
			system("pause");
			mainMenu();
			break;
		case 6:
			system("cls");
			if (_size != 0) { DataSort(d, _size); }
			else { cout << "Данные пусты" << endl; }
			system("pause");
			mainMenu();
			break;
		case 7:
			cl->clear();
			if (_size != 0) {
				cl->setLabel("Введите название файла: ");
				FileName = cl->getData(editType::onlyAlpha, 10);
				FileName += bin;
				DataSave(d, _size, FileName);
			}
			else {cout << "Данные пусты" << endl;}
			mainMenu();
			break;
		}
	}
	
	system("cls");
	cout << "Работа завершена" << endl;
	system("Pause");
	SetConsoleCP(oldCPin);
	SetConsoleOutputCP(oldCPout);
	return 0;
}