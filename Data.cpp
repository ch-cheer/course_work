#include "Data.h"
#define line cout << "________________________________" << endl;

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

	for (int i = 0; i <= 8; i++) {
		sesia.subject[i] = "";
	}
	for (int i = 0; i <= 9; i++) {
		sesia.mark[i] = 0;
		sesia.sesia[i] = 0;
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

	for (int i = 0; i <= 8; i++) {
		sesia.subject[i] = sesia_.subject[i];
	}
	for (int i = 0; i <= 9; i++) {
		sesia.mark[i] = sesia_.mark[i];
		sesia.sesia[i] = sesia_.sesia[i];
	}
}

Data::~Data() {}

void Data::Print() {
	cout << "ФИО: " << fio.surname << " " << fio.name << " " << fio.fathername << endl;
	cout << "Дата рождения: " << birthdate.day << "." << birthdate.month << "." << birthdate.year << endl;
	cout << "Год поступления: " << univeryear.univeryear << endl;
	cout << "Институт (факультет): " << institut.institut << endl;
	cout << "Кафедра: " << kafedra.kafedra << endl;
	cout << "Группа: " << group.group << endl;
	cout << "Номер зачётной книжки: " << exambook.exambook << endl;
	cout << "Пол: " << sex.sex << endl;
	for (int i = 0; i <= sesia.sesia_count; i++) {
		cout << "Сессия: " << sesia.sesia[i] << endl;
		for (int j = 0; j <= sesia.subject_count; j++) {
			cout << "Предмет: " << sesia.subject[j] << " " << "Оценка: " << sesia.mark[j] << endl;
		}
	}
	/*cout << "Сессия номер: " << sesia.sesia << endl;
	cout << "Предмет: " << sesia.subject << endl;
	cout << "Оценка: " << sesia.mark << endl;*/
}

//void Data::Print(int subject_count) {
//	for
//}

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

	for (int i = 0; i <= 8; i++) {
		sesia.subject[i] = sesia_.subject[i];
	}
	for (int i = 0; i <= 9; i++) {
		sesia.mark[i] = sesia_.mark[i];
		sesia.sesia[i] = sesia_.sesia[i];
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

	for (int i = 0; i <= 8; i++) {
		this->sesia.subject[i] = d_o.sesia.subject[i];
	}
	for (int i = 0; i <= 9; i++) {
		this->sesia.mark[i] = d_o.sesia.mark[i];
		this->sesia.sesia[i] = d_o.sesia.sesia[i];
	}
	return *this;
}