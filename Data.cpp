#include "Data.h"

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

	sesia.subject = "";
	sesia.mark = 0;
	sesia.sesia = 0;
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

	sesia.subject = sesia_.subject;
	sesia.mark = sesia_.mark;
	sesia.sesia = sesia_.sesia;
}

Data::~Data() {}

void Data::Print() {
	cout << "���: " << fio.surname << " " << fio.name << " " << fio.fathername << endl;
	cout << "���� ��������: " << birthdate.day << "." << birthdate.month << "." << birthdate.year << endl;
	cout << "��� �����������: " << univeryear.univeryear << endl;
	cout << "�������� (���������): " << institut.institut << endl;
	cout << "�������: " << kafedra.kafedra << endl;
	cout << "������: " << group.group << endl;
	cout << "����� �������� ������: " << exambook.exambook << endl;
	cout << "���: " << sex.sex << endl;
	cout << "������ �����: " << sesia.sesia << endl;
	cout << "�������: " << sesia.subject << endl;
	cout << "������: " << sesia.mark << endl;
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

	sesia.subject = sesia_.subject;
	sesia.mark = sesia_.mark;
	sesia.sesia = sesia_.sesia;
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

	this->sesia.subject = d_o.sesia.subject;
	this->sesia.mark = d_o.sesia.mark;
	this->sesia.sesia = d_o.sesia.sesia;

	return *this;
}