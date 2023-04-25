#include "Func.h"
#define uwu cout << " ^ W ^			 ^ W ^			 ^ W ^			 ^ W ^ " << endl;

void DataEntry(Data* (&d), int& n) {
	Fio fio;
	Birthdate birthdate;
	Univeryear univeryear;
	Institut institut;
	Kafedra kafedra;
	Group group;
	Exambook exambook;
	Sex sex;
	Sesia sesia;

	Check* cl = new Check();

	cout << "������� ���������� ���������: ";
	cin >> n;

	d = new Data[n];

	for (int i = 0; i < n; i++) {
		cl->clear();
		cl->setLabel("������� �������: ");
		fio.surname = cl->getData(editType::onlyAlpha, 20);
		cl->clear();
		cl->setLabel("������� ���: ");
		fio.name = cl->getData(editType::onlyAlpha, 20);
		cl->clear();
		cl->setLabel("������� ��������: ");
		fio.fathername = cl->getData(editType::onlyAlpha, 20);

		cl->clear();
		cl->setLabel("������� ���� ��������: ");
		birthdate.day = cl->getData(editType::onlyDigit, 1, 31);
		cl->clear();
		cl->setLabel("������� ����� ��������: ");
		birthdate.month = cl->getData(editType::onlyDigit, 1, 12);
		cl->clear();
		cl->setLabel("������� ��� ��������: ");
		birthdate.year = cl->getData(editType::onlyDigit, 1800, 2100);

		cl->clear();
		cl->setLabel("������� ��� �����������: ");
		univeryear.univeryear = cl->getData(editType::onlyDigit, 1800, 2100);

		cl->clear();
		cl->setLabel("������� �������� (���������): ");
		institut.institut = cl->getData(editType::all);

		cl->clear();
		cl->setLabel("������� �������: ");
		kafedra.kafedra = cl->getData(editType::all);

		cl->clear();
		cl->setLabel("������� ������: ");
		group.group = cl->getData(editType::all);

		cl->clear();
		cl->setLabel("������� ����� �������� ������: ");
		exambook.exambook = cl->getData(editType::all);

		cl->clear();
		cl->setLabel("������� ���: ");
		sex.sex = cl->getData(editType::onlyAlpha, 10);

		cl->clear();
		cl->setLabel("������� ���������� ������ (�� 1 �� 9): ");
		sesia.sesia_count = cl->getData(editType::onlyDigit, 1, 9);
		sesia.sesia_count = sesia.sesia_count - 1;
		
		for (int n = 0; n <= sesia.sesia_count; n++) {
			cl->clear();
			cl->setLabel("������� ������: ");
			sesia.sesia[n] = cl->getData(editType::onlyDigit, 1, 9);
			
			cl->clear();
			cl->setLabel("������� ���������� ���������: ");
			sesia.subject_count = cl->getData(editType::onlyDigit, 1, 10);
			sesia.subject_count = sesia.subject_count - 1;
			for (int h = 0; h <= sesia.subject_count; h++) {
				cl->clear();
				cl->setLabel("������� �������: ");
				sesia.subject[h] = cl->getData(editType::onlyAlpha, 20);
				cl->clear();
				cl->setLabel("������� ������: ");
				sesia.mark[h] = cl->getData(editType::onlyDigit, 1, 5);
			}
		}

		d[i].DataEntry(fio, birthdate, univeryear, institut, kafedra, group, exambook, sex, sesia);

		cout << endl;
	}
} 
//��������

void DataRead(Data* (&d), int& n, string FileName) {
	ifstream reading(FileName);

	if (reading) {
		Fio fio;
		Birthdate birthdate;
		Univeryear univeryear;
		Institut institut;
		Kafedra kafedra;
		Group group;
		Exambook exambook;
		Sex sex;
		Sesia sesia;

		reading >> n;

		d = new Data[n];

		for (int i = 0; i < n; i++) {

			reading >> fio.surname >> fio.name >> fio.fathername;
			reading >> birthdate.day >> birthdate.month >> birthdate.year;
			reading >> univeryear.univeryear;
			reading >> institut.institut;
			reading >> kafedra.kafedra;
			reading >> group.group;
			reading >> exambook.exambook;
			reading >> sex.sex;
			/*reading >> sesia.sesia;
			reading >> sesia.subject;
			reading >> sesia.mark;*/

			d[i].DataEntry(fio, birthdate, univeryear, institut, kafedra, group, exambook, sex, sesia);
		}

		cout << "������ ������� �������." << endl;
	}

	else { cout << "������, ���� �� ����� ���� ������" << endl; }

	reading.close();
}
//�� ��������

void Print(Data* d, int n) {
	for (int i = 0; i < n; i++) {
		cout << " ������ � �������� �����: " << i + 1 << endl;

		d[i].Print();
		cout << endl;
		uwu
		cout << endl;
	}
}
//��������

void DataChange(Data* d, int n) {
	Fio fio;
	Birthdate birthdate{0, 0, 0};
	Univeryear univeryear{0};
	Institut institut;
	Kafedra kafedra;
	Group group;
	Exambook exambook;
	Sex sex;
	Sesia sesia;

	int _n;
	int chm;
	int chfio;
	int chbthd; 
	int chses;
	unsigned int sesia_num;
	int chsub;
	unsigned int subject_num;
	string subject_item;


	cout << "������� ����� ������� �������� (�� 1 �� " << n << "): ";
	cin >> _n;
	_n--;
	
	Check* cl = new Check();

	if (_n <= 0 && _n < n) {
		system("cls");
		cout << "�������� ��������: " << endl
			<< "(0) ���������" << endl
			<< "(1) �������� ��� " << endl
			<< "(2) �������� ���� ��������" << endl
			<< "(3) �������� ��� �����������" << endl
			<< "(4) �������� ��������� (��������)" << endl
			<< "(5) �������� �������" << endl
			<< "(6) �������� ������" << endl
			<< "(7) �������� ����� �������� ������" << endl
			<< "(8) �������� ���" << endl
			<< "(9) �������� ������(��)" << endl
			<< "������� ��������: ";
		cin >> chm;
		switch (chm) {
		case 1:
			system("cls");
			cout << "�������� ��������: " << endl
				<< "(0) ���������" << endl
				<< "(1) �������� ������� " << endl
				<< "(2) �������� ���" << endl
				<< "(3) �������� ��������" << endl
				<< "������� ��������: ";
			cin >> chfio;
			switch (chfio) {
			case 0:
				system("cls");
				break;
			case 1:
				cl->clear();
				cl->setLabel("������� �������: ");
				fio.surname = cl->getData(editType::onlyAlpha, 20);
				break;
			case 2:
				cl->clear();
				cl->setLabel("������� ���: ");
				fio.name = cl->getData(editType::onlyAlpha, 20);
				break;
			case 3:
				cl->clear();
				cl->setLabel("������� ��������: ");
				fio.fathername = cl->getData(editType::onlyAlpha, 20);
				break;
			default:
				break;
			}

			if (fio.surname == "") {
				fio.surname = d[_n].GetFio().surname;
			}

			if (fio.name == "") {
				fio.name = d[_n].GetFio().name;
			}

			if (fio.fathername == "") {
				fio.fathername = d[_n].GetFio().fathername;
			}

			d[_n].DataEntry(fio);
			break;
		case 2:
			system("cls");
			cout << "�������� ��������: " << endl
				<< "(0) ���������" << endl
				<< "(1) �������� ���� " << endl
				<< "(2) �������� �����" << endl
				<< "(3) �������� ���" << endl
				<< "������� ��������: ";
			cin >> chbthd;
			switch (chbthd)
			{
			case 0:
				system("cls");
				break;
			case 1:
				cl->clear();
				cl->setLabel("������� ���� ��������: ");
				birthdate.day = cl->getData(editType::onlyDigit, 1, 31);
				break;
			case 2:
				cl->clear();
				cl->setLabel("������� ����� ��������: ");
				birthdate.month = cl->getData(editType::onlyDigit, 1, 12);
				break;
			case 3:
				cl->clear();
				cl->setLabel("������� ��� ��������: ");
				birthdate.year = cl->getData(editType::onlyDigit, 1800, 2100);
				break;
			default:
				break;
			}

			if (birthdate.day == 0) {
				birthdate.day = d[_n].GetBirthdate().day;
			}

			if (birthdate.month == 0) {
				birthdate.month = d[_n].GetBirthdate().month;
			}

			if (birthdate.year == 0) {
				birthdate.year = d[_n].GetBirthdate().year;
			}

			d[_n].DataEntry(birthdate);
			break;
		case 3:
			cl->clear();
			cl->setLabel("������� ��� �����������: ");
			univeryear.univeryear = cl->getData(editType::onlyDigit, 1800, 2100);
			d[_n].DataEntry(univeryear);
			break;
		case 4:
			cl->clear();
			cl->setLabel("������� �������� (���������): ");
			institut.institut = cl->getData(editType::all);
			d[_n].DataEntry(institut);
			break;
		case 5:
			cl->clear();
			cl->setLabel("������� �������: ");
			kafedra.kafedra = cl->getData(editType::all);
			d[_n].DataEntry(kafedra);
			break;
		case 6:
			cl->clear();
			cl->setLabel("������� ������: ");
			group.group = cl->getData(editType::all);
			d[_n].DataEntry(group);
			break;
		case 7:
			cl->clear();
			cl->setLabel("������� ����� �������� ������: ");
			exambook.exambook = cl->getData(editType::all);
			d[_n].DataEntry(exambook);
			break;
		case 8:
			cl->clear();
			cl->setLabel("������� ���: ");
			sex.sex = cl->getData(editType::onlyAlpha, 10);
			d[_n].DataEntry(sex);
			break;
		case 9:
			sesia.sesia_count = d[_n].GetSesia().sesia_count;
			sesia.subject_count = d[_n].GetSesia().subject_count;
			for (int i = 0; i <= sesia.sesia_count; i++) {
				sesia.sesia[i] = d[_n].GetSesia().sesia[i];
				for (int j = 0; j <= sesia.subject_count; j++) {
					sesia.mark[j] = d[_n].GetSesia().mark[j];
					sesia.subject[j] = d[_n].GetSesia().subject[j];
				}
			}

			system("cls");
			cout << "���������� ������: " << sesia.sesia_count + 1 << endl;
			cl->setLabel("������� ������, � ������� ���������� �������� ������");
			sesia_num = cl->getData(editType::onlyDigit, 1, 8);
			for (int i = 0; i <= sesia.sesia_count; i++) {
				if (sesia_num == sesia.sesia[i]) {
					cl->clear();
					cout << "�������� ��������: " << endl
						<< "(0) ���������" << endl
						<< "(1) �������� ������� " << endl
						<< "(2) �������� ������" << endl
						<< "������� ��������: ";
					chses = cl->getData(editType::onlyDigit, 0, 2);
					switch (chses) {
					case 1:
						cl->clear();
						cout << "�������� ��������: " << endl
							<< "(0) ���������" << endl
							<< "(1) ������ ����� ��������, ������� ������ ��������" << endl
							<< "(2) ������ �������, ������� ������ ��������" << endl
							<< "������� ��������: ";
						chsub = cl->getData(editType::onlyDigit, 0, 2);
						switch (chsub) {
						case 0:
							break;
						case 1:
							cl->clear();
							cl->setLabel("������� ����� ��������, ������� ������ ��������: ");
							subject_num = cl->getData(editType::onlyDigit, 1, sesia.subject_count + 1);
							subject_num = subject_num - 1;
							for (int j = 0; j <= sesia.subject_count; j++) {
								sesia.subject[j] = d[_n].GetSesia().subject[j];
								if (j == subject_num) {
									cl->clear();
									cl->setLabel("������� ����� �������: ");
									sesia.subject[j] = cl->getData(editType::onlyAlpha, 20);
								}
								break;
							}
							break;
						case 2:
							cl->clear();
							cl->setLabel("������� �������, ������� ������ ��������: ");
							subject_item = cl->getData(editType::onlyAlpha, 20);
							for (int j = 0; j <= sesia.subject_count; j++) {
								sesia.subject[j] = d[_n].GetSesia().subject[j];
								if (subject_item == sesia.subject[j]) {
									cl->clear();
									cl->setLabel("������� ����� �������: ");
									sesia.subject[j] = cl->getData(editType::onlyAlpha, 20);
								}
								break;
							}
							break;
						default:
							break;
						}
					case 2:
						cl->clear();
						cout << "�������� ��������: " << endl
							<< "(0) ���������" << endl
							<< "(1) ������ ����� ��������, ������ �������� ������ ��������" << endl
							<< "(2) ������ �������, ������ �������� ������ ��������" << endl
							<< "������� ��������: ";
						chsub = cl->getData(editType::onlyDigit, 0, 2);
						switch (chsub) {
						case 0:
							break;
						case 1:
							cl->clear();
							cl->setLabel("������� ����� ��������, ������ �������� ������ ��������: ");
							subject_num = cl->getData(editType::onlyDigit, 1, sesia.subject_count + 1);
							subject_num = subject_num - 1;
							for (int j = 0; j <= sesia.subject_count; j++) {
								sesia.subject[j] = d[_n].GetSesia().subject[j];
								if (j == subject_num) {
									cl->clear();
									cl->setLabel("������� ����� �������: ");
									sesia.mark[j] = cl->getData(editType::onlyDigit, 1, 5);
								}
								break;
							}
							break;
						case 2:
							cl->clear();
							cl->setLabel("������� �������, ������� ������ ��������: ");
							subject_item = cl->getData(editType::onlyAlpha, 20);
							for (int j = 0; j <= sesia.subject_count; j++) {
								sesia.subject[j] = d[_n].GetSesia().subject[j];
								if (subject_item == sesia.subject[j]) {
									cl->clear();
									cl->setLabel("������� ����� �������: ");
									sesia.mark[j] = cl->getData(editType::onlyDigit, 1, 5);
								}
								break;
							}
							break;
						}
					default:
						break;
					}
				}
			}
			d[_n].DataEntry(sesia);
			break;
		default:
			break;
		}
	}
	else {
		cout << "����� ����� �������" << endl;
		system("pause");
		system("cls");
	}
}
//��������

void Copy(Data* d_n, Data* d_o, int n) {
	for (int i = 0; i < n; i++) {
		d_n[i] = d_o[i];
	}
}

void DataAdd(Data* (&d), int& n) {
	Fio fio;
	Birthdate birthdate;
	Univeryear univeryear;
	Institut institut;
	Kafedra kafedra;
	Group group;
	Exambook exambook;
	Sex sex;
	Sesia sesia;
	Data* buf = new Data[n];
	int size = n, new_size = ++n;

	Copy(d, buf, size);

	d = new Data[new_size];

	Copy(d, buf, size);

	cout << "������� ����� ���: ";
	cin >> fio.surname >> fio.name >> fio.fathername;

	cout << "������� ����� ���� ��������: ";
	cin >> birthdate.day >> birthdate.month >> birthdate.year;

	cout << "������� ����� ��� �����������: ";
	cin >> univeryear.univeryear;

	cout << "������� ����� ���������: ";
	cin >> institut.institut;

	cout << "������� ����� �������: ";
	cin >> kafedra.kafedra;

	cout << "������� ����� ������: ";
	cin >> group.group;

	cout << "������� ����� ����� �������� ������: ";
	cin >> exambook.exambook;

	cout << "������� ����� ���: ";
	cin >> sex.sex;

	/*cout << "������� ���������� ������: ";
	cin >> sesia.sesia;


	cout << "������� �������: ";
	cin >> sesia.subject;

	cout << "������� ������: ";
	cin >> sesia.mark;*/

	d[size].DataEntry(fio, birthdate, univeryear, institut, kafedra, group, exambook, sex, sesia);

	cout << "������ ���������" << endl;
	delete[] buf;
}

void DataDel(Data* (&d), int& n) {
	int _n;
	Data* buf = new Data[n];

	cout << "������� ����� ������� �������� (�� 1 �� " << n << "): ";
	cin >> _n;
	_n--;
	if (_n >= 0 && _n < n) {
		Copy(buf, d, n);
		int q = 0;
		n--;

		d = new Data[n];

		for (int i = 0; i <= n; i++) {
			if (i != _n) {
				d[q] = buf[i];
				q++;
			}
		}
		cout << "������ �������" << endl;
	}
	else { cout << "����� ����� �������" << endl; }

	delete[] buf;
}

void DataSort(Data* d, int n) {
	Data buf;
	int numOfSored = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (d[i].GetFio().surname > d[j].GetFio().surname) {
				buf = d[i];
				d[i] = d[j];
				d[j] = buf;

				numOfSored++;
			}
		}
	}

	cout << "������ ��������������\n���������� ����������: " << numOfSored << endl;
}

void DataSave(Data* d, int n, string FileName) {
	ofstream record(FileName);

	if (record) {
		record << n << endl;

		for (int i = 0; i < n; i++) {
			record << d[i].GetFio().surname << " " << d[i].GetFio().name << " " << d[i].GetFio().fathername << endl;
			record << d[i].GetBirthdate().day << " " << d[i].GetBirthdate().month << " " << d[i].GetBirthdate().year << endl;
			record << d[i].GetUniveryear().univeryear << endl;
			record << d[i].GetInstitut().institut << endl;
			record << d[i].GetKafedra().kafedra << endl;
			record << d[i].GetGroup().group << endl;
			record << d[i].GetExambook().exambook << endl;
			record << d[i].GetSex().sex << endl;
			record << d[i].GetSesia().sesia << endl;
			record << d[i].GetSesia().subject << endl;
			record << d[i].GetSesia().mark << endl;
		}
	}
}