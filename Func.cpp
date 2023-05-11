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

	cl->clear();
	cl->setLabel("������� ���������� ���������: ");
	n = cl->getDataDigit(editType::onlyDigit, 1);

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

		errorBirthday:cl->clear();
		cl->setLabel("������� ��� �����������: ");
		univeryear.univeryear = cl->getData(editType::onlyDigit, 1800, 2100);

		if (birthdate.year >= univeryear.univeryear) {
			system("cls");
			cout << "������: �������� ��������� (��� ��������) " << birthdate.year << " ������ ��� �������� (��� �����������) " << univeryear.univeryear << endl;
			system("pause");
			goto errorBirthday;
		}

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
		cl->setLabel("�������� ���:\n(� / �) �������\n(� / �) �������");
		string sex_input = cl->getData(editType::sex, 1);
		if (sex_input == "�" or sex_input == "�")
			sex.sex = "�������";
		else if (sex_input == "�" or sex_input == "�")
			sex.sex = "�������";

		cl->clear();
		cl->setLabel("������� ���������� ������ (�� 1 �� 9): ");
		sesia.sesia_count = cl->getData(editType::onlyDigit, 1, 9);
		sesia.sesia_count = sesia.sesia_count - 1;

		for (int n = 0; n <= sesia.sesia_count; n++) {
			error_ses:cl->clear();
			cl->setLabel("������� ������: ");
			sesia.sesia[n] = cl->getData(editType::onlyDigit, 1, 9);

			if ((n != 0) && (sesia.sesia[n] == sesia.sesia[n - 1])) {
				system("cls");
				cout << "������: ������� 2 ���������� ������" << endl;
				system("pause");
				goto error_ses;
			}

			cl->clear();
			cl->setLabel("������� ���������� ���������: ");
			sesia.subject_count[n] = cl->getData(editType::onlyDigit, 1, 10);
			sesia.subject_count[n] = sesia.subject_count[n] - 1;
			for (int h = 0; h <= sesia.subject_count[n]; h++) {
				cl->clear();
				cl->setLabel("������� �������: ");
				sesia.subject[sesia.sesia[n]][h] = cl->getData(editType::subject, 85);
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

void DataRead(Data* (&d), int& n, string FileName) {
	ifstream reading;
	reading.open(FileName, ios::binary);

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
		int readCount;

		reading.read((char*)&n, sizeof(int));

		d = new Data[n];

		for (int i = 0; i < n; i++) {
			//������ �������
			{
				reading.read((char*)&readCount, sizeof(int));
				char* buffer = new char[readCount + 1];
				buffer[readCount] = '\0';
				reading.read(buffer, readCount);
				fio.surname = buffer;
				delete[] buffer;
			}
			//������ �����
			{
				reading.read((char*)&readCount, sizeof(int));
				char* buffer = new char[readCount + 1];
				buffer[readCount] = '\0';
				reading.read(buffer, readCount);
				fio.name = buffer;
				delete[] buffer;
			}
			//������ ��������
			{
				reading.read((char*)&readCount, sizeof(int));
				char* buffer = new char[readCount + 1];
				buffer[readCount] = '\0';
				reading.read(buffer, readCount);
				fio.fathername = buffer;
				delete[] buffer;
			}

			//������ ��� ��������
			reading.read((char*)&birthdate.day, sizeof(int));
			//������ ������ ��������
			reading.read((char*)&birthdate.month, sizeof(int));
			//������ ���� ��������
			reading.read((char*)&birthdate.year, sizeof(int));

			//������ ���� ����������� � �����������
			reading.read((char*)&univeryear.univeryear, sizeof(int));

			//������ �������� ���������
			{
				reading.read((char*)&readCount, sizeof(int));
				char* buffer = new char[readCount + 1];
				buffer[readCount] = '\0';
				reading.read(buffer, readCount);
				institut.institut = buffer;
				delete[] buffer;
			}

			//������ �������� �������
			{
				reading.read((char*)&readCount, sizeof(int));
				char* buffer = new char[readCount + 1];
				buffer[readCount] = '\0';
				reading.read(buffer, readCount);
				kafedra.kafedra = buffer;
				delete[] buffer;
			}

			//������ �������� ������
			{
				reading.read((char*)&readCount, sizeof(int));
				char* buffer = new char[readCount + 1];
				buffer[readCount] = '\0';
				reading.read(buffer, readCount);
				group.group = buffer;
				delete[] buffer;
			}

			//������ ����� �������� ������
			{
				reading.read((char*)&readCount, sizeof(int));
				char* buffer = new char[readCount + 1];
				buffer[readCount] = '\0';
				reading.read(buffer, readCount);
				exambook.exambook = buffer;
				delete[] buffer;
			}

			//������ ���� ��������
			{
				reading.read((char*)&readCount, sizeof(int));
				char* buffer = new char[readCount + 1];
				buffer[readCount] = '\0';
				reading.read(buffer, readCount);
				sex.sex = buffer;
				delete[] buffer;
			}

			//������ ���������� ������
			reading.read((char*)&sesia.sesia_count, sizeof(short unsigned int));

			for (int j = 0; j <= sesia.sesia_count; j++) {
				//������ ������ ������
				reading.read((char*)&sesia.sesia[j], sizeof(unsigned int));
				//������ ���������� ���������
				reading.read((char*)&sesia.subject_count[j], sizeof(short unsigned int));
				for (int h = 0; h <= sesia.subject_count[j]; h++) {
					//������ ��������
					{
						reading.read((char*)&readCount, sizeof(int));
						char* buffer = new char[readCount + 1];
						buffer[readCount] = '\0';
						reading.read(buffer, readCount);
						sesia.subject[sesia.sesia[j]][h] = buffer;
						delete[] buffer;
					}
					//��������� ������ �� �����
					reading.read((char*)&sesia.mark[sesia.sesia[j]][h], sizeof(unsigned int));
					if ((sesia.mark[sesia.sesia[j]][h] == 0) || (sesia.mark[sesia.sesia[j]][h] == 1)) {
						{
							reading.read((char*)&readCount, sizeof(int));
							char* buffer = new char[readCount + 1];
							buffer[readCount] = '\0';
							reading.read(buffer, readCount);
							sesia.diferens[sesia.sesia[j]][h] = buffer;
							delete[] buffer;
						}
					}
				}
			}
			d[i].DataEntry(fio, birthdate, univeryear, institut, kafedra, group, exambook, sex, sesia);
		}

		cout << "������ ������� �������." << endl;
	}

	else { cout << "������, ���� �� ����� ���� ������" << endl; }

	reading.close();
}

void Print(Data* d, int n) {
	for (int i = 0; i < n; i++) {
		cout << " ������ � �������� �����: " << i + 1 << endl;

		d[i].Print();
		cout << endl;
		uwu
			cout << endl;
	}
}

void DataChange(Data* d, int n) {
	Fio fio;
	Birthdate birthdate{ 0, 0, 0 };
	Univeryear univeryear{ 0 };
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
	cl->setLabelNumStud(n);
	_n = cl->getData(editType::onlyDigit, 1, n);
	_n--;

	string sex_input;


	if (_n >= 0 && _n < n) {
		cl->clear();
		cl->setLabel("�������� ��������:\n(0) ���������\n(1) �������� ���\n(2) �������� ���� ��������\n(3) �������� ��� �����������\n(4) �������� ��������� (��������)\n(5) �������� �������\n(6) �������� ������\n(7) �������� ����� �������� ������\n(8) �������� ���\n(9) �������� ������\n(10) �������� ������(��)\n������� ��������: ");
		chm = cl->getData(editType::onlyDigit, 0, 10);
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
				univeryear.univeryear = d[_n].GetUniveryear().univeryear;
				errorBirthday1:cl->clear();
				cl->setLabel("������� ��� ��������: ");
				birthdate.year = cl->getData(editType::onlyDigit, 1800, 2100);
				if (birthdate.year >= univeryear.univeryear) {
					system("cls");
					cout << "������: �������� ��������� (��� ��������) " << birthdate.year << " ������ ��� �������� (��� �����������) " << univeryear.univeryear << endl;
					system("pause");
					goto errorBirthday1;
				}
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
			birthdate.year = d[_n].GetBirthdate().year;
			errorBirthday2:cl->clear();
			cl->setLabel("������� ��� �����������: ");
			univeryear.univeryear = cl->getData(editType::onlyDigit, 1800, 2100);
			if (univeryear.univeryear <= birthdate.year) {
				system("cls");
				cout << "������: �������� ��������� (��� �����������) " << univeryear.univeryear << " ������ ��� �������� (��� ��������) " << birthdate.year << endl;
				system("pause");
				goto errorBirthday2;
			}
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
			cl->setLabel("�������� ���:\n(� / �) �������\n(� / �) �������");
			sex_input = cl->getData(editType::sex, 1);
			if (sex_input == "�" or sex_input == "�")
				sex.sex = "�������";
			else if (sex_input == "�" or sex_input == "�")
				sex.sex = "�������";
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

			if (sesia.sesia_count < 8) { //0 � 8
				sesia.sesia_count++;
				error_ses:cl->clear();
				cl->setLabel("������� ������: ");
				sesia.sesia[sesia.sesia_count] = cl->getData(editType::onlyDigit, 1, 9);

				for (int k = 0; k <= sesia.sesia_count; k++) {
					if (sesia.sesia[k] == sesia.sesia[k - 1]) {
						system("cls");
						cout << "������: ������� 2 ���������� ������" << endl;
						system("pause");
						goto error_ses;
					}
				}

				cl->clear();
				cl->setLabel("������� ���������� ���������: ");
				sesia.subject_count[sesia.sesia_count] = cl->getData(editType::onlyDigit, 1, 10);
				sesia.subject_count[sesia.sesia_count] = sesia.subject_count[sesia.sesia_count] - 1;
				for (int h = 0; h <= sesia.subject_count[sesia.sesia_count]; h++) {
					cl->clear();
					cl->setLabel("������� �������: ");
					sesia.subject[sesia.sesia[sesia.sesia_count]][h] = cl->getData(editType::subject, 85);
					cl->clear();
					cl->setLabel("������� ��� ������:\n(1) ������������������ ����� (� �������) / �������\n(2) ����� / �������");
					dif_nodif = cl->getData(editType::onlyDigit, 1, 2);
					switch (dif_nodif) {
					case 1:
						cl->clear();
						cl->setLabel("������� ������: ");
						sesia.mark[sesia.sesia[sesia.sesia_count]][h] = cl->getData(editType::onlyDigit, 2, 5);
						break;
					case 2:
						cl->clear();
						cl->setLabel("������� ��������: �����(1) / �������(2)");
						zath_nozath = cl->getData(editType::onlyDigit, 1, 2);
						switch (zath_nozath) {
						case 1:
							sesia.mark[sesia.sesia[sesia.sesia_count]][h] = 1;
							sesia.diferens[sesia.sesia[sesia.sesia_count]][h] = "�����";
							break;
						case 2:
							sesia.mark[sesia.sesia[sesia.sesia_count]][h] = 0;
							sesia.diferens[sesia.sesia[sesia.sesia_count]][h] = "�� �����";
							break;
						}
						break;
					}
				}
			}

			else {
				cl->clear();
				cl->setLabel("������: ������� ������������ ���������� ������");
				system("pause");
				break;
			}

			d[_n].DataEntry(sesia);
			break;
		case 10:
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

			cl->clear();
			cl->setLabel("������� ������, � ������� ���������� �������� ������: ");
			sesia_num = cl->getData(editType::onlyDigit, 1, 9);
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
									sesia.subject[sesia.sesia[i]][j] = cl->getData(editType::subject, 85);
								}
							}
							break;
						case 2:
							cl->clear();
							cl->setLabel("������� �������, ������� ������ ��������: ");
							subject_item = cl->getData(editType::subject, 85);
							for (int j = 0; j <= sesia.subject_count[i]; j++) {
								sesia.subject[sesia.sesia[i]][j] = d[_n].GetSesia().subject[sesia.sesia[i]][j];
								if (subject_item == sesia.subject[sesia.sesia[i]][j]) {
									cl->clear();
									cl->setLabel("������� ����� �������: ");
									sesia.subject[sesia.sesia[i]][j] = cl->getData(editType::subject, 85);
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
							subject_item = cl->getData(editType::subject, 85);
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
	errorBirthday:cl->clear();
	cl->setLabel("������� ��� ��������: ");
	birthdate.year = cl->getData(editType::onlyDigit, 1800, 2100);

	cl->clear();
	cl->setLabel("������� ��� �����������: ");
	univeryear.univeryear = cl->getData(editType::onlyDigit, 1800, 2100);

	if (birthdate.year >= univeryear.univeryear) {
		system("cls");
		cout << "������: �������� ��������� (��� ��������) " << birthdate.year << " ������ ��� �������� (��� �����������) " << univeryear.univeryear << endl;
		system("pause");
		goto errorBirthday;
	}

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
	cl->setLabel("�������� ���:\n(� / �) �������\n(� / �) �������");
	string sex_input = cl->getData(editType::sex, 1);
	if (sex_input == "�" or sex_input == "�")
		sex.sex = "�������";
	else if (sex_input == "�" or sex_input == "�")
		sex.sex = "�������";

	cl->clear();
	cl->setLabel("������� ���������� ������ (�� 1 �� 9): ");
	sesia.sesia_count = cl->getData(editType::onlyDigit, 1, 9);
	sesia.sesia_count = sesia.sesia_count - 1;

	for (int n = 0; n <= sesia.sesia_count; n++) {
		error_ses:cl->clear();
		cl->setLabel("������� ������: ");
		sesia.sesia[n] = cl->getData(editType::onlyDigit, 1, 9);

		if ((n != 0) && (sesia.sesia[n] == sesia.sesia[n - 1])) {
			system("cls");
			cout << "������: ������� 2 ���������� ������" << endl;
			system("pause");
			goto error_ses;
		}

		cl->clear();
		cl->setLabel("������� ���������� ���������: ");
		sesia.subject_count[n] = cl->getData(editType::onlyDigit, 1, 10);
		sesia.subject_count[n] = sesia.subject_count[n] - 1;
		for (int h = 0; h <= sesia.subject_count[n]; h++) {
			cl->clear();
			cl->setLabel("������� �������: ");
			sesia.subject[sesia.sesia[n]][h] = cl->getData(editType::subject, 85);
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
	Check* cl = new Check();

	Sesia sesia;
	unsigned int buf_mark;
	string buf_diferens;
	string buf_subject;
	int _n;
	int mini_menu;

	cl->clear();
	cl->setLabelNumStud(n);
	_n = cl->getData(editType::onlyDigit, 1, n);
	_n--;

	sesia.sesia_count = d[_n].GetSesia().sesia_count;
	for (int i = 0; i <= sesia.sesia_count; i++) {
		sesia.sesia[i] = d[_n].GetSesia().sesia[i];
		sesia.subject_count[i] = d[_n].GetSesia().subject_count[i];
		for (int j = 0; j <= sesia.subject_count[i] - 1; j++) {
			for (int h = j + 1; h <= sesia.subject_count[i]; h++) {
				sesia.mark[sesia.sesia[i]][j] = d[_n].GetSesia().mark[sesia.sesia[i]][j];
				sesia.mark[sesia.sesia[i]][h] = d[_n].GetSesia().mark[sesia.sesia[i]][h];
				sesia.subject[sesia.sesia[i]][j] = d[_n].GetSesia().subject[sesia.sesia[i]][j];
				sesia.subject[sesia.sesia[i]][h] = d[_n].GetSesia().subject[sesia.sesia[i]][h];
				sesia.diferens[sesia.sesia[i]][j] = d[_n].GetSesia().diferens[sesia.sesia[i]][j];
				sesia.diferens[sesia.sesia[i]][h] = d[_n].GetSesia().diferens[sesia.sesia[i]][h];
			}
		}
	}

	cl->clear();
	cl->setLabel("�������� ��������:\n(0) ���������\n(1) ���������� ���� ��������� � �������\n(2) ������� ������, � ������� ���������� ������������� ��������");
	mini_menu = cl->getData(editType::onlyDigit, 0, 2);
	cout << endl;

	switch (mini_menu) {
	case 0:
		break;
	case 1:
		for (int i = 0; i <= sesia.sesia_count; i++) {
			if (sesia.subject_count[i] > 0) {
				for (int j = 0; j <= sesia.subject_count[i] - 1; j++) {
					for (int h = j + 1; h <= sesia.subject_count[i]; h++) {
						if (sesia.mark[sesia.sesia[i]][j] > sesia.mark[sesia.sesia[i]][h]) {
							buf_mark = sesia.mark[sesia.sesia[i]][j];
							sesia.mark[sesia.sesia[i]][j] = sesia.mark[sesia.sesia[i]][h];
							sesia.mark[sesia.sesia[i]][h] = buf_mark;
							if ((sesia.mark[sesia.sesia[i]][j] == 0) || (sesia.mark[sesia.sesia[i]][j] == 1)) {
								buf_diferens = sesia.diferens[sesia.sesia[i]][j];
								sesia.diferens[sesia.sesia[i]][j] = sesia.diferens[sesia.sesia[i]][h];
								sesia.diferens[sesia.sesia[i]][h] = buf_diferens;
							}
							buf_subject = sesia.subject[sesia.sesia[i]][j];
							sesia.subject[sesia.sesia[i]][j] = sesia.subject[sesia.sesia[i]][h];
							sesia.subject[sesia.sesia[i]][h] = buf_subject;
						}
					}
				}
			}
			else {
				for (int j = 0; j <= sesia.subject_count[i]; j++) {
					sesia.mark[sesia.sesia[i]][j] = d[_n].GetSesia().mark[sesia.sesia[i]][j];
					sesia.subject[sesia.sesia[i]][j] = d[_n].GetSesia().subject[sesia.sesia[i]][j];
					sesia.diferens[sesia.sesia[i]][j] = d[_n].GetSesia().diferens[sesia.sesia[i]][j];
				}
			}
		}
		d[_n].DataEntry(sesia);
		break;
	case 2:
		cl->clear();
		cl->setLabel("������� ������:");
		int sesia_select = cl->getData(editType::onlyDigit, 1, 9);
		cout << endl;

		for (int i = 0; i <= sesia.sesia_count; i++) {
			if (sesia_select == sesia.sesia[i]) {
				for (int j = 0; j <= sesia.subject_count[i] - 1; j++) {
					for (int h = j + 1; h <= sesia.subject_count[i]; h++) {
						if (sesia.mark[sesia.sesia[i]][j] > sesia.mark[sesia.sesia[i]][h]) {
							buf_mark = sesia.mark[sesia.sesia[i]][j];
							sesia.mark[sesia.sesia[i]][j] = sesia.mark[sesia.sesia[i]][h];
							sesia.mark[sesia.sesia[i]][h] = buf_mark;
							if ((sesia.mark[sesia.sesia[i]][j] == 0) || (sesia.mark[sesia.sesia[i]][j] == 1)) {
								buf_diferens = sesia.diferens[sesia.sesia[i]][j];
								sesia.diferens[sesia.sesia[i]][j] = sesia.diferens[sesia.sesia[i]][h];
								sesia.diferens[sesia.sesia[i]][h] = buf_diferens;
							}
							buf_subject = sesia.subject[sesia.sesia[i]][j];
							sesia.subject[sesia.sesia[i]][j] = sesia.subject[sesia.sesia[i]][h];
							sesia.subject[sesia.sesia[i]][h] = buf_subject;
						}
					}
				}
			}
			else {
				for (int j = 0; j <= sesia.subject_count[i]; j++) {
					sesia.mark[sesia.sesia[i]][j] = d[_n].GetSesia().mark[sesia.sesia[i]][j];
					sesia.subject[sesia.sesia[i]][j] = d[_n].GetSesia().subject[sesia.sesia[i]][j];
					sesia.diferens[sesia.sesia[i]][j] = d[_n].GetSesia().diferens[sesia.sesia[i]][j];
				}
			}
		}
		d[_n].DataEntry(sesia);
		break;
	}
}

void DataSave(Data* d, int n, string FileName) {

	ofstream record;
	record.open(FileName, ios::binary);

	record.write((char*)&n, sizeof(int));

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
		unsigned int count;

		for (int i = 0; i < n; i++) {
			//������ �������
			fio.surname = d[i].GetFio().surname;
			count = fio.surname.size();
			record.write((char*)&count, sizeof(int));
			record.write(fio.surname.c_str(), count);
			//������ �����
			fio.name = d[i].GetFio().name;
			count = fio.name.size();
			record.write((char*)&count, sizeof(int));
			record.write(fio.name.c_str(), count);
			//������ ��������
			fio.fathername = d[i].GetFio().fathername;
			count = fio.fathername.size();
			record.write((char*)&count, sizeof(int));
			record.write(fio.fathername.c_str(), count);

			//������ ��� ��������
			birthdate.day = d[i].GetBirthdate().day;
			record.write((char*)&birthdate.day, sizeof(int));
			//������ ������ ��������
			birthdate.month = d[i].GetBirthdate().month;
			record.write((char*)&birthdate.month, sizeof(int));
			//������ ���� ��������
			birthdate.year = d[i].GetBirthdate().year;
			record.write((char*)&birthdate.year, sizeof(int));

			//������ ���� ����������� � �����������
			univeryear.univeryear = d[i].GetUniveryear().univeryear;
			record.write((char*)&univeryear.univeryear, sizeof(int));

			//������ �������� ���������
			institut.institut = d[i].GetInstitut().institut;
			count = institut.institut.size();
			record.write((char*)&count, sizeof(int));
			record.write(institut.institut.c_str(), count);

			//������ �������� �������
			kafedra.kafedra = d[i].GetKafedra().kafedra;
			count = kafedra.kafedra.size();
			record.write((char*)&count, sizeof(int));
			record.write(kafedra.kafedra.c_str(), count);

			//������ �������� ������
			group.group = d[i].GetGroup().group;
			count = group.group.size();
			record.write((char*)&count, sizeof(int));
			record.write(group.group.c_str(), count);

			//������ ������ �������� ������
			exambook.exambook = d[i].GetExambook().exambook;
			count = exambook.exambook.size();
			record.write((char*)&count, sizeof(int));
			record.write(exambook.exambook.c_str(), count);

			//������ ���� ��������
			sex.sex = d[i].GetSex().sex;
			count = sex.sex.size();
			record.write((char*)&count, sizeof(int));
			record.write(sex.sex.c_str(), count);

			//������ ���������� ������
			sesia.sesia_count = d[i].GetSesia().sesia_count;
			record.write((char*)&sesia.sesia_count, sizeof(short unsigned int));

			for (int j = 0; j <= sesia.sesia_count; j++) {
				//������� ������ ������
				sesia.sesia[j] = d[i].GetSesia().sesia[j];
				record.write((char*)&sesia.sesia[j], sizeof(unsigned int));
				//������ ���������� ���������
				sesia.subject_count[j] = d[i].GetSesia().subject_count[j];
				record.write((char*)&sesia.subject_count[j], sizeof(short unsigned int));
				for (int h = 0; h <= sesia.subject_count[j]; h++) {
					//������ ��������
					sesia.subject[sesia.sesia[j]][h] = d[i].GetSesia().subject[sesia.sesia[j]][h];
					count = sesia.subject[sesia.sesia[j]][h].size();
					record.write((char*)&count, sizeof(int));
					record.write(sesia.subject[sesia.sesia[j]][h].c_str(), count);
					//��������� ������ �� ���������
					sesia.mark[sesia.sesia[j]][h] = d[i].GetSesia().mark[sesia.sesia[j]][h];
					record.write((char*)&sesia.mark[sesia.sesia[j]][h], sizeof(unsigned int));
					if ((sesia.mark[sesia.sesia[j]][h] == 0) || (sesia.mark[sesia.sesia[j]][h] == 1)) {
						sesia.diferens[sesia.sesia[j]][h] = d[i].GetSesia().diferens[sesia.sesia[j]][h];
						count = sesia.diferens[sesia.sesia[j]][h].size();
						record.write((char*)&count, sizeof(int));
						record.write(sesia.diferens[sesia.sesia[j]][h].c_str(), count);
					}
				}
			}
		}
		record.close();
	}
}