#include "Func.h"
#define uwu cout << " ^ W ^ " << endl;

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
		cout << "������ � �������� �����: " << i + 1 << endl;

		d[i].Print();
		uwu
	}
}
//��������

void DataChange(Data* d, int n) {
	Fio fio;
	Birthdate birthdate;
	Univeryear univeryear;
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
	int sesia_num;
	int chsub;
	int subject_num;
	string subject_item;

	cout << sesia.sesia_count << " " << sesia.subject_count << endl << sesia.mark << " " << sesia.sesia << " " << sesia.subject << endl << fio.name << endl;
r3:cout << "������� ����� ������� �������� (�� 1 �� " << n << "): ";
	cin >> _n;
	_n--;

	Check* cl = new Check();

	if (_n <= 0 && _n < n) {
		system("cls");
		cout << "�������� ��������: " << endl
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
				goto r3;
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
				goto r3;
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
			break;
		case 3:
			cl->clear();
			cl->setLabel("������� ��� �����������: ");
			univeryear.univeryear = cl->getData(editType::onlyDigit, 1800, 2100);
			break;
		case 4:
			cl->clear();
			cl->setLabel("������� �������� (���������): ");
			institut.institut = cl->getData(editType::all);
			break;
		case 5:
			cl->clear();
			cl->setLabel("������� �������: ");
			kafedra.kafedra = cl->getData(editType::all);
			break;
		case 6:
			cl->clear();
			cl->setLabel("������� ������: ");
			group.group = cl->getData(editType::all);
			break;
		case 7:
			cl->clear();
			cl->setLabel("������� ����� �������� ������: ");
			exambook.exambook = cl->getData(editType::all);
			break;
		case 8:
			cl->clear();
			cl->setLabel("������� ���: ");
			sex.sex = cl->getData(editType::onlyAlpha, 10);
			break;
		case 9: //�� �������
		r2:cl->clear();
			cl->setLabel("������� ������");
			sesia_num = cl->getData(editType::onlyDigit, 1, 9);
			for (int h = 0; h <= 8; h++) {
				if (sesia_num == sesia.sesia[h]) {
					system("cls");
					cout << "�������� ��������: " << endl
						<< "(0) ���������" << endl
						<< "(1) �������� ������� " << endl
						<< "(2) �������� ������" << endl
						<< "������� ��������: ";
					chses = cl->getData(editType::onlyDigit, 0, 2);
					switch (chses) {
					case 0:
						system("cls");
						goto r3;
						break;
					case 1:
						system("cls");
						cout << "�������� ��������: " << endl
							<< "(0) ���������" << endl
							<< "(1) ������ ����� ��������, ������� ������ ��������" << endl
							<< "(2) ������ �������, ������� ������ ��������" << endl
							<< "������� ��������: ";
						chsub = cl->getData(editType::onlyDigit, 0, 2);
						switch (chsub)
						{
						case 0:
							system("cls");
							goto r2;
							break;
						case 1:
							cl->clear();
							cl->setLabel("������� ����� ��������, ������� ������ ��������: ");
							subject_num = cl->getData(editType::onlyDigit, 1, 10);
							cout << endl;
							subject_num = subject_num - 1;
							cl->setLabel("������� ����� �������: ");
							sesia.subject[subject_num] = cl->getData(editType::onlyAlpha, 20);
							break;
						case 2:
							cl->clear();
							cl->setLabel("������� �������, ������� ������ ��������: ");
							subject_item = cl->getData(editType::onlyAlpha, 20);
							cout << endl;
							for (int i = 0; i <= 9; i++) {
								if (subject_item == sesia.subject[i]) {
									cl->setLabel("������� ����� �������: ");
									sesia.subject[i] = cl->getData(editType::onlyAlpha, 20);
									break;
								}
								else {
									cout << "������: ������: " << subject_item << " ������� �����������" << endl;
									system("pause");
									goto r2;
								}
							}
						default:
							break;
						}
						break;
					case 2:
						system("cls");
						cout << "�������� ��������: " << endl
							<< "(0) ���������" << endl
							<< "(1) ������ ����� ��������, ������ �������� ������ ��������" << endl
							<< "(2) ������ �������, ������ �������� ������ ��������" << endl
							<< "������� ��������: ";
						chsub = cl->getData(editType::onlyDigit, 0, 2);
						switch (chsub)
						{
						case 0:
							system("cls");
							goto r2;
							break;
						case 1:
							cl->clear();
							cl->setLabel("������� ����� ��������, ������ �������� ������ ��������: ");
							subject_num = cl->getData(editType::onlyDigit, 1, 10);
							cout << endl;
							subject_num = subject_num - 1;
							cl->setLabel("������� ����� ������: ");
							sesia.mark[subject_num] = cl->getData(editType::onlyDigit, 1, 5);
							break;
						case 2:
							cl->clear();
							cl->setLabel("������� �������, ������� ������ ��������: ");
							subject_item = cl->getData(editType::onlyAlpha, 20);
							cout << endl;
							for (int i = 0; i <= 9; i++) {
								if (subject_item == sesia.subject[i]) {
									cl->setLabel("������� ����� ������: ");
									sesia.mark[i] = cl->getData(editType::onlyDigit, 1, 5);
									break;
								}
								else {
									cout << "������: ������: " << subject_item << " ������� �����������" << endl;
									system("pause");
									goto r2;
								}
							}
						default:
							break;
						}
						break;
					default:
						break;
					}
				}
				else {
					cout << "������: �������� ��������: " << sesia_num << " ������� �� ��������� (1, " << sesia.sesia_count << ")" << endl;
					system("Pause");
					goto r2;
				}
			}
			break;
		default:
			break;
		}

		d[_n].DataEntry(fio, birthdate, univeryear, institut, kafedra, group, exambook, sex, sesia); //����������� ����� ���������
	}
	else {
		cout << "����� ����� �������" << endl;
		system("pause");
		system("cls");
		goto r3;
	}
}
//�������� �����

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