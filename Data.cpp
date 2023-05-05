#include "Data.h"
#include <iomanip>
#define line cout << "-----------------------------------------------------------------------------------------------------" << endl;

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
	for (int i = 0; i <= 9; i++) {
		sesia.sesia[i] = 0;
		for (int j = 0; j <= 9; j++) {
			sesia.subject[i][j] = "";
			sesia.subject_count[j] = 0;
			sesia.mark[i][j] = 0;
			sesia.diferens[i][j] = "";
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
	for (int i = 0; i <= 9; i++) {
		sesia.sesia[i] = sesia_.sesia[i];
		for (int j = 0; j <= 9; j++) {
			sesia.subject[i][j] = sesia_.subject[i][j];
			sesia.mark[i][j] = sesia_.mark[i][j];
			sesia.subject_count[j] = sesia_.subject_count[j];
			sesia.diferens[i][j] = sesia_.diferens[i][j];
		}
	}
}

Data::~Data() {}

void Data::Print() {
	line
	cout << "   | " << left << setw(25) << "ФИО: " << "| " << fio.surname << " " << fio.name << " " << fio.fathername << endl;
	cout << "   | " << left << setw(25) << "Дата рождения: " << "| " << birthdate.day << "." << birthdate.month << "." << birthdate.year << endl;
	cout << "   | " << left << setw(25) << "Год поступления: " << "| " << univeryear.univeryear << endl;
	cout << "   | " << left << setw(25) << "Институт (факультет): " << "| " << institut.institut << endl;
	cout << "   | " << left << setw(25) << "Кафедра: " << "| " << kafedra.kafedra << endl;
	cout << "   | " << left << setw(25) << "Группа: " << "| " << group.group << endl;
	cout << "   | " << left << setw(25) << "Номер зачётной книжки: " << "| " << exambook.exambook << endl;
	cout << "   | " << left << setw(25) << "Пол: " << "| " << sex.sex << endl;
	line
	for (int i = 0; i <= sesia.sesia_count; i++) {
		cout << " Сессия: " << left << sesia.sesia[i] << endl;
		line
		cout << left << setw(2) << " № " << "| " << left << setw(85) << "Предмет: " << " | " << left << setw(8) << "Оценка: " << endl << endl;
		for (int j = 0; j <= sesia.subject_count[i]; j++) {
			cout << " " << left << setw(2) << j + 1 << "| " << left << setw(85) << sesia.subject[sesia.sesia[i]][j] << " | ";
			if (sesia.mark[sesia.sesia[i]][j] == 0) {
				cout << left << setw(8) << sesia.diferens[sesia.sesia[i]][j] << endl;
			}
			else if (sesia.mark[sesia.sesia[i]][j] == 1) {
				cout << left << setw(8) << sesia.diferens[sesia.sesia[i]][j] << endl;
			}
			else {
				cout << left << setw(8) << sesia.mark[sesia.sesia[i]][j] << endl;
			}
		}
		line
	}
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
	
	for (int i = 0; i <= 9; i++) {
		sesia.sesia[i] = sesia_.sesia[i];
		for (int j = 0; j <= 9; j++) {
			sesia.subject[i][j] = sesia_.subject[i][j];
			sesia.mark[i][j] = sesia_.mark[i][j];
			sesia.subject_count[j] = sesia_.subject_count[j];
			sesia.diferens[i][j] = sesia_.diferens[i][j];
		}
	}
}

void Data::DataEntry(Fio fio_) {
	fio.surname = fio_.surname;
	fio.name = fio_.name;
	fio.fathername = fio_.fathername;
}

void Data::DataEntry(Birthdate birthdate_) {
	birthdate.day = birthdate_.day;
	birthdate.month = birthdate_.month;
	birthdate.year = birthdate_.year;
}

void Data::DataEntry(Univeryear univeryear_) {
	univeryear.univeryear = univeryear_.univeryear;
}

void Data::DataEntry(Institut institut_) {
	institut.institut = institut_.institut;
}

void Data::DataEntry(Kafedra kafedra_) {
	kafedra.kafedra = kafedra_.kafedra;
}

void Data::DataEntry(Group group_) {
	group.group = group_.group;
}

void Data::DataEntry(Exambook exambook_) {
	exambook.exambook = exambook_.exambook;
}

void Data::DataEntry(Sex sex_) {
	sex.sex = sex_.sex;
}

void Data::DataEntry(Sesia sesia_) {
	sesia.sesia_count = sesia_.sesia_count;
	for (int i = 0; i <= 9; i++) {
		sesia.sesia[i] = sesia_.sesia[i];
		for (int j = 0; j <= 9; j++) {
			sesia.subject[i][j] = sesia_.subject[i][j];
			sesia.mark[i][j] = sesia_.mark[i][j];
			sesia.subject_count[j] = sesia_.subject_count[j];
			sesia.diferens[i][j] = sesia_.diferens[i][j];
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
	for (int i = 0; i <= 9; i++) {
		this->sesia.sesia[i] = d_o.sesia.sesia[i];
		for (int j = 0; j <= 9; j++) {
			this->sesia.subject[i][j] = d_o.sesia.subject[i][j];
			this->sesia.mark[i][j] = d_o.sesia.mark[i][j];
			this->sesia.diferens[i][j] = d_o.sesia.diferens[i][j];
			this->sesia.subject_count[j] = d_o.sesia.subject_count[j];
		}
	}
	return *this;
}