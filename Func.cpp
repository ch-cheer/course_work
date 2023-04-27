#include "Func.h"
#define uwu cout << "	^ W ^			 ^ W ^			 ^ W ^			 ^ W ^	" << endl;

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
	short unsigned int dif_nodif = 1, zath_nozath = 1;

	Check* cl = new Check();

	cl->setLabel("������� ���������� ���������: ");
	n = cl->getData(editType::onlyDigit, 1, sizeof(n));

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
			sesia.subject_count[n] = cl->getData(editType::onlyDigit, 1, 10);
			sesia.subject_count[n] = sesia.subject_count[n] - 1;
			for (int h = 0; h <= sesia.subject_count[n]; h++) {
				cl->clear();
				cl->setLabel("������� �������: ");
				sesia.subject[sesia.sesia[n]][h] = cl->getData(editType::onlyAlpha, 20);
				cl->clear();
				cl->setLabel("������� ��� ������:\n(1) ������������������ ����� (� �������) / �������\n(2) ����� / �������");
				dif_nodif = cl->getData(editType::onlyDigit, 1, 2);
				switch (dif_nodif) {
				case 1:
					cl->clear();
					cl->setLabel("������� ������: ");
					sesia.mark[sesia.sesia[n]][h] = cl->getData(editType::onlyDigit, 2, 5);
					break;
				case 2:
					cl->clear();
					cl->setLabel("������� ��������: �����(1) / �������(2)");
					zath_nozath = cl->getData(editType::onlyDigit, 1, 2);
					switch (zath_nozath) {
					case 1:
						sesia.mark[sesia.sesia[n]][h] = 1;
						sesia.diferens[sesia.sesia[n]][h] = "�����";
						break;
					case 2:
						sesia.mark[sesia.sesia[n]][h] = 0;
						sesia.diferens[sesia.sesia[n]][h] = "�� �����";
						break;
					}
					break;
				}
			}
		}

		d[i].DataEntry(fio, birthdate, univeryear, institut, kafedra, group, exambook, sex, sesia);

		cout << endl;
	}
} 
//��������

void DataRead(Data* (&d), int& n, string FileName) {
	ifstream reading;
	reading.open(FileName, ios_base::binary);

	if (reading.is_open()) {
		Fio fio;
		Birthdate birthdate;
		Univeryear univeryear;
		Institut institut;
		Kafedra kafedra;
		Group group;
		Exambook exambook;
		Sex sex;
		Sesia sesia;

		reading.read((char*)&n, sizeof(int));

		d = new Data[n];

		for (int i = 0; i < n; i++) {

			reading.read((char*)&fio.surname, 20);		
			reading.read((char*)&fio.name, 20);
			reading.read((char*)&fio.fathername, 20);
			//record << d[i].GetFio().surname << " " << d[i].GetFio().name << " " << d[i].GetFio().fathername << endl;
			/*birthdate.day = d[i].GetBirthdate().day;
			birthdate.month = d[i].GetBirthdate().month;
			birthdate.year = d[i].GetBirthdate().year;*/

			reading.read((char*)&birthdate.day, 2);
			reading.read((char*)&birthdate.month, 2);
			reading.read((char*)&birthdate.year, 4);
			//record << d[i].GetBirthdate().day << " " << d[i].GetBirthdate().month << " " << d[i].GetBirthdate().year << endl;
			/*univeryear.univeryear = d[i].GetUniveryear().univeryear;*/
			reading.read((char*)&univeryear.univeryear, 20);
			//record << d[i].GetUniveryear().univeryear << endl;
			/*institut.institut = d[i].GetInstitut().institut;*/
			reading.read((char*)&institut.institut, 20);
			//record << d[i].GetInstitut().institut << endl;
			/*kafedra.kafedra = d[i].GetKafedra().kafedra;*/
			reading.read((char*)&kafedra.kafedra, 20);
			//record << d[i].GetKafedra().kafedra << endl;
			/*group.group = d[i].GetGroup().group;*/
			reading.read((char*)&group.group, 20);
			//record << d[i].GetGroup().group << endl;
			/*exambook.exambook = d[i].GetExambook().exambook;*/
			reading.read((char*)&exambook.exambook, 20);
			//record << d[i].GetExambook().exambook << endl;
			/*sex.sex = d[i].GetSex().sex;*/
			reading.read((char*)&sex.sex, 20);

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
	short unsigned int dif_nodif = 1, zath_nozath = 1;

	Check* cl = new Check();
	
	cl->clear();
	cout << "������� ����� �������� (�� 1 �� " << n << "): ";
	_n = cl->getData(editType::onlyDigit, 1, n);
	_n--;
	

	if (_n >= 0 && _n < n) {
		cl->clear();
		cl->setLabel("�������� ��������:\n(0) ���������\n(1) �������� ���\n(2) �������� ���� ��������\n(3) �������� ��� �����������\n(4) �������� ��������� (��������)\n(5) �������� �������\n(6) �������� ������\n(7) �������� ����� �������� ������\n(8) �������� ���\n(9) �������� ������(��)\n������� ��������: ");
		chm = cl->getData(editType::onlyDigit, 0, 9);
		switch (chm) {
		case 0:
			break;
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
				cout << "������: ������� ������� ��������, ������� �������� �� 0 �� 3" << endl;
				system("pause");
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
				cout << "������: ������� ������� ��������, ������� �������� �� 0 �� 3" << endl;
				system("pause");
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
			for (int i = 0; i <= sesia.sesia_count; i++) {
				sesia.sesia[i] = d[_n].GetSesia().sesia[i];
				sesia.subject_count[i] = d[_n].GetSesia().subject_count[i];
				for (int j = 0; j <= sesia.subject_count[i]; j++) {
					sesia.mark[sesia.sesia[i]][j] = d[_n].GetSesia().mark[sesia.sesia[i]][j];
					sesia.subject[sesia.sesia[i]][j] = d[_n].GetSesia().subject[sesia.sesia[i]][j];
					sesia.diferens[sesia.sesia[i]][j] = d[_n].GetSesia().diferens[sesia.sesia[i]][j];
				}
			}

			system("cls");
			cout << endl;
			d[_n].PrintSes();
			cout << endl << "������� ������, � ������� ���������� �������� ������: ";
			cin >> sesia_num;
			for (int i = 0; i <= sesia.sesia_count; i++) {
				if (sesia_num == sesia.sesia[i]) {
					system("cls");
					cout << "�������� ��������: " << endl
						<< "(0) ���������" << endl
						<< "(1) �������� ������� " << endl
						<< "(2) �������� ������" << endl
						<< "������� ��������: ";
					cin >> chses;
					switch (chses) {
					case 0:
						cl->clear();
						break;
					case 1:
						cl->clear();
						cout << "�������� ��������: " << endl
							<< "(0) ���������" << endl
							<< "(1) ������ ����� ��������, ������� ������ ��������" << endl
							<< "(2) ������ �������, ������� ������ ��������" << endl
							<< "������� ��������: ";
						cin >> chsub;
						switch (chsub) {
						case 0:
							cl->clear();
							break;
						case 1:
							cl->clear();
							cl->setLabel("������� ����� ��������, ������� ������ ��������: ");
							subject_num = cl->getData(editType::onlyDigit, 1, sesia.subject_count[i] + 1);
							subject_num = subject_num - 1;
							for (int j = 0; j <= sesia.subject_count[i]; j++) {
								sesia.subject[sesia.sesia[i]][j] = d[_n].GetSesia().subject[sesia.sesia[i]][j];
								if (j == subject_num) {
									cl->clear();
									cl->setLabel("������� ����� �������: ");
									sesia.subject[sesia.sesia[i]][j] = cl->getData(editType::onlyAlpha, 20);
								}
							}
							break;
						case 2:
							cl->clear();
							cl->setLabel("������� �������, ������� ������ ��������: ");
							subject_item = cl->getData(editType::onlyAlpha, 20);
							for (int j = 0; j <= sesia.subject_count[i]; j++) {
								sesia.subject[sesia.sesia[i]][j] = d[_n].GetSesia().subject[sesia.sesia[i]][j];
								if (subject_item == sesia.subject[sesia.sesia[i]][j]) {
									cl->clear();
									cl->setLabel("������� ����� �������: ");
									sesia.subject[sesia.sesia[i]][j] = cl->getData(editType::onlyAlpha, 20);
								}
							}
							break;
						default:
							cout << "������: ������� ������� ��������, ������� �������� �� 0 �� 2" << endl;
							system("pause");
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
						cin >> chsub;
						switch (chsub) {
						case 0:
							cl->clear();
							break;
						case 1:
							cl->clear();
							cl->setLabel("������� ����� ��������, ������ �������� ������ ��������: ");
							subject_num = cl->getData(editType::onlyDigit, 1, sesia.subject_count[i] + 1);
							subject_num = subject_num - 1;
							for (int j = 0; j <= sesia.subject_count[i]; j++) {
								sesia.subject[sesia.sesia[i]][j] = d[_n].GetSesia().subject[sesia.sesia[i]][j];
								if (j == subject_num) {
									cl->clear();
									cl->setLabel("������� ��� ������:\n(1) ������������������ ����� (� �������) / �������\n(2) ����� / �������");
									dif_nodif = cl->getData(editType::onlyDigit, 1, 2);
									switch (dif_nodif) {
									case 1:
										cl->clear();
										cl->setLabel("������� ������: ");
										sesia.mark[sesia.sesia[i]][j] = cl->getData(editType::onlyDigit, 2, 5);
										break;
									case 2:
										cl->clear();
										cl->setLabel("������� ��������: �����(1) / �������(2)");
										zath_nozath = cl->getData(editType::onlyDigit, 1, 2);
										switch (zath_nozath) {
										case 1:
											sesia.mark[sesia.sesia[i]][j] = 1;
											sesia.diferens[sesia.sesia[i]][j] = "�����";
											break;
										case 2:
											sesia.mark[sesia.sesia[i]][j] = 0;
											sesia.diferens[sesia.sesia[i]][j] = "�� �����";
											break;
										}
										break;
									}
								}
							}
							break;
						case 2:
							cl->clear();
							cl->setLabel("������� �������, ������ �������� ������ �������� ������ ��������: ");
							subject_item = cl->getData(editType::onlyAlpha, 20);
							for (int j = 0; j <= sesia.subject_count[i]; j++) {
								sesia.subject[sesia.sesia[i]][j] = d[_n].GetSesia().subject[sesia.sesia[i]][j];
								if (subject_item == sesia.subject[sesia.sesia[i]][j]) {
									cl->clear();
									cl->setLabel("������� ��� ������:\n(1) ������������������ ����� (� �������) / �������\n(2) ����� / �������");
									dif_nodif = cl->getData(editType::onlyDigit, 1, 2);
									switch (dif_nodif) {
									case 1:
										cl->clear();
										cl->setLabel("������� ������: ");
										sesia.mark[sesia.sesia[i]][j] = cl->getData(editType::onlyDigit, 2, 5);
										break;
									case 2:
										cl->clear();
										cl->setLabel("������� ��������: �����(1) / �������(2)");
										zath_nozath = cl->getData(editType::onlyDigit, 1, 2);
										switch (zath_nozath) {
										case 1:
											sesia.mark[sesia.sesia[i]][j] = 1;
											sesia.diferens[sesia.sesia[i]][j] = "�����";
											break;
										case 2:
											sesia.mark[sesia.sesia[i]][j] = 0;
											sesia.diferens[sesia.sesia[i]][j] = "�� �����";
											break;
										}
										break;
									}
								}
							}
							break;
						default:
							cout << "������: ������� ������� ��������, ������� �������� �� 0 �� 2" << endl;
							system("pause");
							break;
						}
						break;
					default:
						break;
					}
				}
				else {
					cout << endl << "������: ������� �������������� ������" << endl;
				}
			}
			d[_n].DataEntry(sesia);
			break;
		default:
			cout << "������: ������� ������� ��������, ������� �������� �� 0 �� 9" << endl;
			system("pause");
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
//��������

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
	short unsigned int dif_nodif = 1, zath_nozath = 1;

	Check* cl = new Check();

	Copy(buf, d, size);

	d = new Data[new_size];

	Copy(d, buf, size);

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
		sesia.subject_count[n] = cl->getData(editType::onlyDigit, 1, 10);
		sesia.subject_count[n] = sesia.subject_count[n] - 1;
		for (int h = 0; h <= sesia.subject_count[n]; h++) {
			cl->clear();
			cl->setLabel("������� �������: ");
			sesia.subject[sesia.sesia[n]][h] = cl->getData(editType::onlyAlpha, 20);
			cl->clear();
			cl->setLabel("������� ��� ������:\n(1) ������������������ ����� (� �������) / �������\n(2) ����� / �������");
			dif_nodif = cl->getData(editType::onlyDigit, 1, 2);
			switch (dif_nodif) {
			case 1:
				cl->clear();
				cl->setLabel("������� ������: ");
				sesia.mark[sesia.sesia[n]][h] = cl->getData(editType::onlyDigit, 2, 5);
				break;
			case 2:
				cl->clear();
				cl->setLabel("������� ��������: �����(1) / �������(2)");
				zath_nozath = cl->getData(editType::onlyDigit, 1, 2);
				switch (zath_nozath) {
				case 1:
					sesia.mark[sesia.sesia[n]][h] = 1;
					sesia.diferens[sesia.sesia[n]][h] = "�����";
					break;
				case 2:
					sesia.mark[sesia.sesia[n]][h] = 0;
					sesia.diferens[sesia.sesia[n]][h] = "�� �����";
					break;
				}
				break;
			}
		}
	}

	d[size].DataEntry(fio, birthdate, univeryear, institut, kafedra, group, exambook, sex, sesia);

	cout << "������ ���������" << endl;
	delete[] buf;
}
//��������

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
//��������

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
//�� ��� ��������

void DataSave(Data* d, int n, string FileName) {

	ofstream record;
	record.open(FileName, ios_base::binary | ios_base::out);
	/*if (record.is_open()) {
		record.write((char*)&n, sizeof(n));
		for (int i = 0; i < n; i++) {
			record.write((char*)&d[i].GetFio().surname, sizeof());
		}
	}*/
	if (record.is_open()) {
		Fio fio;
		Birthdate birthdate;
		Univeryear univeryear;
		Institut institut;
		Kafedra kafedra;
		Group group;
		Exambook exambook;
		Sex sex;
		Sesia sesia;

		record.write((char*)&n, sizeof(int));
		//record << n << endl;

		for (int i = 0; i < n; i++) {
			fio.surname = d[i].GetFio().surname;
			fio.name = d[i].GetFio().name;
			fio.fathername = d[i].GetFio().fathername;

			record.write((char*)&fio.surname, 20);
			record.write((char*)&fio.name, 20);
			record.write((char*)&fio.fathername, 20);
			//record << d[i].GetFio().surname << " " << d[i].GetFio().name << " " << d[i].GetFio().fathername << endl;
			birthdate.day = d[i].GetBirthdate().day;
			birthdate.month = d[i].GetBirthdate().month;
			birthdate.year = d[i].GetBirthdate().year;

			record.write((char*)&birthdate.day, 2);
			record.write((char*)&birthdate.month, 2);
			record.write((char*)&birthdate.year, 4);
			//record << d[i].GetBirthdate().day << " " << d[i].GetBirthdate().month << " " << d[i].GetBirthdate().year << endl;
			univeryear.univeryear = d[i].GetUniveryear().univeryear;
			record.write((char*)&univeryear.univeryear, 20);
			//record << d[i].GetUniveryear().univeryear << endl;
			institut.institut = d[i].GetInstitut().institut;
			record.write((char*)&institut.institut, 20);
			//record << d[i].GetInstitut().institut << endl;
			kafedra.kafedra = d[i].GetKafedra().kafedra;
			record.write((char*)&kafedra.kafedra, 20);
			//record << d[i].GetKafedra().kafedra << endl;
			group.group = d[i].GetGroup().group;
			record.write((char*)&group.group, 20);
			//record << d[i].GetGroup().group << endl;
			exambook.exambook = d[i].GetExambook().exambook;
			record.write((char*)&exambook.exambook, 20);
			//record << d[i].GetExambook().exambook << endl;
			sex.sex = d[i].GetSex().sex;
			record.write((char*)&sex.sex, 20);
			//record << d[i].GetSex().sex << endl;
			sesia.sesia_count = d[i].GetSesia().sesia_count;
			for (int j = 0; j <= sesia.sesia_count; j++) {
				sesia.sesia[j] = d[i].GetSesia().sesia[j];
				//record.write((char*)&sesia.sesia, )
				record << d[i].GetSesia().sesia[j] << endl;
				sesia.subject_count[j] = d[i].GetSesia().subject_count[j];
				record << d[i].GetSesia().subject_count[j] << endl;
				for (int h = 0; h <= sesia.subject_count[j]; h++) {
					record << d[i].GetSesia().subject[sesia.sesia[j]][h] << endl;
					record << d[i].GetSesia().mark[sesia.sesia[j]][h] << endl;
				}
				/*record << d[i].GetSesia().subject << endl;
				record << d[i].GetSesia().mark << endl;*/
			}
		}
		record.close();
	}
}