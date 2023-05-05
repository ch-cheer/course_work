#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>

using namespace std;

enum class editType : char { onlyDigit, onlyAlpha, all };

struct Fio {
	string surname, name, fathername;
};

struct Birthdate {
	int day, month, year;
};

struct Univeryear {
	int univeryear;
};

struct Institut {
	string institut;
};

struct Kafedra {
	string kafedra;
};

struct Group {
	string group;
};

struct Exambook {
	string exambook;
};

struct Sex {
	string sex;
};

struct Sesia {
	string subject[10][10];
	unsigned int mark[10][10], sesia[10];
	short unsigned int subject_count[10], sesia_count;
	string diferens[10][10];
};

class Data {
private:
	Fio fio;
	Birthdate birthdate;
	Univeryear univeryear;
	Institut institut;
	Kafedra kafedra;
	Group group;
	Exambook exambook;
	Sex sex;
	Sesia sesia;
public:
	Data();
	Data(Fio fio_, Birthdate birthdate_, Univeryear univeryear_, Institut institut_, Kafedra kafedra_, Group group_, Exambook exambook_, Sex sex_, Sesia sesia_);
	~Data();

	void Print();
	void DataEntry(Fio fio_, Birthdate birthdate_, Univeryear univeryear_, Institut institut_, Kafedra kafedra_, Group group_, Exambook exambook_, Sex sex_, Sesia sesia_);

	void DataEntry(Fio fio_);
	void DataEntry(Birthdate birthdate_);
	void DataEntry(Univeryear univeryear_);
	void DataEntry(Institut institut_);
	void DataEntry(Kafedra kafedra_);
	void DataEntry(Group group_);
	void DataEntry(Exambook exambook_);
	void DataEntry(Sex sex_);
	void DataEntry(Sesia sesia_);

	Fio GetFio() { return fio; }
	Birthdate GetBirthdate() { return birthdate; }
	Univeryear GetUniveryear() { return univeryear; }
	Institut GetInstitut() { return institut; }
	Kafedra GetKafedra() { return kafedra; }
	Group GetGroup() { return group; }
	Exambook GetExambook() { return exambook; }
	Sex GetSex() { return sex; }
	Sesia GetSesia() { return sesia; }

	Data& operator = (Data d_o);
};

class Check {
private:
	string label;
	string data;
public:
	Check() {
		label = "";
		data = "";
	}
	void setLabel(string _label = "Введите значение") {
		if (_label.length() > 1)
			this->label = _label;
		else
			label = "";
	}
	bool isDigit(char ch) {
		if (ch >= 48 and ch <= 57)
			return true;
		else
			return false;
	}
	bool isStringDigit(string _str) {
		for (int i = 0; i < _str.length(); i++)
			if (not isDigit(_str[i]))
				return false;
		if (_str.length() == 0)
			return false;
		return true;
	}
	bool isAlpha(int ch) {
		if (ch >= 65 and ch <= 90)
			return true;
		if (ch >= 97 and ch <= 122)
			return true;
		if (ch >= -200 and ch <= -1)
			return true;
		return false;
	}
	bool isSpace(char ch) {
		if (ch == 32)
			return true;
		else
			return false;
	}
	bool isSpec(char ch) {
		if (ch >= 33 and ch <= 47)
			return true;
		else
			return false;
	}
	void clear(string _data = "") {
		system("cls");
		data = _data;
	}

	string getData(enum class editType et) {
		char ch = 0;
		cout << label << endl << data;
		while (ch != 13) {
			ch = _getch();
			if (ch == 8) {
				if (data.length() > 0) {
					data.pop_back();
					system("cls");
					cout << label << endl << data;
				}
				continue;
			}
			if (et == editType::onlyDigit)
				if (isDigit(ch)) {
					cout << ch;
					data = data + ch;
				}
			if (et == editType::onlyAlpha)
				if (isAlpha(ch)) {
					cout << ch;
					data = data + ch;
				}
			if (et == editType::all) {
				cout << ch;
				data = data + ch;
			}
		}
		return data;
	}
	int getData(enum class editType et, int min, int max) {
		if (et == editType::onlyDigit) {
			getData(et);
			int num = max + 1;
			if (isStringDigit(data))
				num = atoi(data.c_str());
			if (not (num >= min and num <= max)) {
				cout << endl << "Ошибка: Число которое вы ввели: " << num << " Выходит из диапазона (" << min << "; " << max << ") " << endl;
				system("pause");
				clear();
				getData(et, min, max);
			}
			if (isStringDigit(data))
				num = atoi(data.c_str());
			return num;
		}
	}
	string getData(enum class editType et, int len) {
		if (et == editType::onlyAlpha) {
			getData(et);
			if (data.length() > len) {
				cout << endl << "Ошибка: Длина строки больше чем допускается: " << data.length() << " Разрешено: " << len << " " << endl;
				system("pause");
				clear();
				getData(et, len);
			}
			return data;
		}
	}
};