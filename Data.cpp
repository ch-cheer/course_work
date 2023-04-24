#include "Data.h"
#include <iomanip>
#define line cout << "--------------------------------------------------" << endl;

Data::Data() {
	fio.surname = "";
	fio.name = "";
	fio.fathername = "";

	birthdate.day = 0;
	birthdate.month = 0;
	birthdate.year = 0;

	univeryear.univeryear = 0;

	institut.institut = "";

	kafedra.kafedra = "";

	group.group = "";

	exambook.exambook = "";

	sex.sex = "";

	sesia.sesia_count = 0;
	sesia.subject_count = 0;
	for (int i = 0; i <= 8; i++) {
		sesia.sesia[i] = 0;
		for (int j = 0; j <= 9; j++) {
			sesia.subject[j] = "";
			sesia.mark[j] = 0;
		}
	}
}

Data::Data(Fio fio_, Birthdate birthdate_, Univeryear univeryear_, Institut institut_, Kafedra kafedra_, Group group_, Exambook exambook_, Sex sex_, Sesia sesia_) {
	fio.surname = fio_.surname;
	fio.name = fio_.name;
	fio.fathername = fio_.fathername;

	birthdate.day = birthdate_.day;
	birthdate.month = birthdate_.month;
	birthdate.year = birthdate_.year;

	univeryear.univeryear = univeryear_.univeryear;

	institut.institut = institut_.institut;

	kafedra.kafedra = kafedra_.kafedra;

	group.group = group_.group;

	exambook.exambook = exambook_.exambook;

	sex.sex = sex_.sex;

	sesia.sesia_count = sesia_.sesia_count;
	sesia.subject_count = sesia_.subject_count;
	for (int i = 0; i <= 8; i++) {
		sesia.sesia[i] = sesia_.sesia[i];
		for (int j = 0; j <= 9; j++) {
			sesia.subject[j] = sesia_.subject[j];
			sesia.mark[j] = sesia_.mark[j];
		}
	}
}

Data::~Data() {}

void Data::Print() {
	line
	cout << "   | " << "ФИО: " << fio.surname << " " << fio.name << " " << fio.fathername << endl;
	cout << "   | " << "Дата рождения: " << birthdate.day << "." << birthdate.month << "." << birthdate.year << endl;
	cout << "   | " << "Год поступления: " << univeryear.univeryear << endl;
	cout << "   | " << "Институт (факультет): " << institut.institut << endl;
	cout << "   | " << "Кафедра: " << kafedra.kafedra << endl;
	cout << "   | " << "Группа: " << group.group << endl;
	cout << "   | " << "Номер зачётной книжки: " << exambook.exambook << endl;
	cout << "   | " << "Пол: " << sex.sex << endl;
	line
	for (int i = 0; i <= sesia.sesia_count; i++) {
		cout << "Сессия: " << left << sesia.sesia[i] << endl;
		line
		cout << left << setw(2) << "№" << " | " << left << setw(35) << "Предмет: " << " | " << left << setw(8) << "Оценка: " << endl;
		for (int j = 0; j <= sesia.subject_count; j++) {
			cout << left << setw(2) << j+1 << " | " << left << setw(35) << sesia.subject[j] << " | " << left << setw(8) << sesia.mark[j] << endl;
		}
		line
	}
}

void DataChange() {

}

void Data::DataEntry(Fio fio_, Birthdate birthdate_, Univeryear univeryear_, Institut institut_, Kafedra kafedra_, Group group_, Exambook exambook_, Sex sex_, Sesia sesia_) {
	fio.surname = fio_.surname;
	fio.name = fio_.name;
	fio.fathername = fio_.fathername;

	birthdate.day = birthdate_.day;
	birthdate.month = birthdate_.month;
	birthdate.year = birthdate_.year;

	univeryear.univeryear = univeryear_.univeryear;

	institut.institut = institut_.institut;

	kafedra.kafedra = kafedra_.kafedra;

	group.group = group_.group;

	exambook.exambook = exambook_.exambook;

	sex.sex = sex_.sex;

	sesia.sesia_count = sesia_.sesia_count;
	sesia.subject_count = sesia_.subject_count;
	for (int i = 0; i <= 8; i++) {
		sesia.sesia[i] = sesia_.sesia[i];
		for (int j = 0; j <= 9; j++) {
			sesia.subject[j] = sesia_.subject[j];
			sesia.mark[j] = sesia_.mark[j];
		}
	}
}

Data& Data::operator=(Data d_o) {
	this->fio.surname = d_o.fio.surname;
	this->fio.name = d_o.fio.name;
	this->fio.fathername = d_o.fio.fathername;

	this->birthdate.day = d_o.birthdate.day;
	this->birthdate.month = d_o.birthdate.month;
	this->birthdate.year = d_o.birthdate.year;

	this->univeryear.univeryear = d_o.univeryear.univeryear;

	this->institut.institut = d_o.institut.institut;

	this->kafedra.kafedra = d_o.kafedra.kafedra;

	this->group.group = d_o.group.group;

	this->exambook.exambook = d_o.exambook.exambook;

	this->sex.sex = d_o.sex.sex;

	this->sesia.sesia_count = d_o.sesia.sesia_count;
	this->sesia.subject_count = d_o.sesia.subject_count;
	for (int i = 0; i <= 8; i++) {
		this->sesia.sesia[i] = d_o.sesia.sesia[i];
		for (int j = 0; j <= 9; j++) {
			this->sesia.subject[j] = d_o.sesia.subject[j];
			this->sesia.mark[j] = d_o.sesia.mark[j];
		}
	}
	return *this;
}