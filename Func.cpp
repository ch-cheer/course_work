#include "Func.h"

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

	cout << "Введите количество студентов: ";
	cin >> n;

	d = new Data[n];

	for (int i = 0; i < n; i++) {
		cl->clear();
		cl->setLabel("Введите фамилию: ");
		fio.surname = cl->getData(editType::onlyAlpha, 20);
		cl->clear();
		cl->setLabel("Введите имя: ");
		fio.name = cl->getData(editType::onlyAlpha, 20);
		cl->clear();
		cl->setLabel("Введите отчество: ");
		fio.fathername = cl->getData(editType::onlyAlpha, 20);

		cl->clear();
		cl->setLabel("Введите день рождения: ");
		birthdate.day = cl->getData(editType::onlyDigit, 1, 31);
		cl->clear();
		cl->setLabel("Введите месяц рождения: ");
		birthdate.month = cl->getData(editType::onlyDigit, 1, 12);
		cl->clear();
		cl->setLabel("Введите год рождения: ");
		birthdate.year = cl->getData(editType::onlyDigit, 1800, 2100);

		cl->clear();
		cl->setLabel("Введите год поступления: ");
		univeryear.univeryear = cl->getData(editType::onlyDigit, 1800, 2100);

		cl->clear();
		cl->setLabel("Введите институт (факультет): ");
		institut.institut = cl->getData(editType::all);

		cl->clear();
		cl->setLabel("Введите кафедру: ");
		kafedra.kafedra = cl->getData(editType::all);

		cl->clear();
		cl->setLabel("Введите группу: ");
		group.group = cl->getData(editType::all);

		cl->clear();
		cl->setLabel("Введите номер зачётной книжки: ");
		exambook.exambook = cl->getData(editType::all);

		cl->clear();
		cl->setLabel("Введите пол: ");
		sex.sex = cl->getData(editType::onlyAlpha, 10);

		cl->clear();
		cl->setLabel("Введите количество сессий (от 1 до 9): ");
		sesia.sesia_count = cl->getData(editType::onlyDigit, 1, 9);
		sesia.sesia_count = sesia.sesia_count - 1;
		
		for (int n = 0; n <= sesia.sesia_count; n++) {
			cl->clear();
			cl->setLabel("Введите сессию: ");
			sesia.sesia[n] = cl->getData(editType::onlyDigit, 1, 9);
			
			cl->clear();
			cl->setLabel("Введите количество предметов: ");
			sesia.subject_count = cl->getData(editType::onlyDigit, 1, 10);
			sesia.subject_count = sesia.subject_count - 1;
			for (int h = 0; h <= sesia.subject_count; h++) {
				cl->clear();
				cl->setLabel("Введите предмет: ");
				sesia.subject[h] = cl->getData(editType::all);
				cl->clear();
				cl->setLabel("Введите оценку: ");
				sesia.mark[h] = cl->getData(editType::onlyDigit, 1, 5);
			}
		}

		cl->clear();
		cl->setLabel("Введите сессию: ");
		/*sesia.sesia = cl->getData(editType::onlyDigit, 1, 9);
		cl->clear();
		cl->setLabel("Введите предмет: ");
		sesia.subject = cl->getData(editType::all);
		cl->clear();
		cl->setLabel("Введите оценку: ");
		sesia.mark = cl->getData(editType::onlyDigit, 1, 5);*/

		d[i].DataEntry(fio, birthdate, univeryear, institut, kafedra, group, exambook, sex, sesia);

		cout << "___________________________\n";
	}
}

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

		cout << "Данные считаны успешно." << endl;
	}

	else { cout << "Ошибка, файл не может быть открыт" << endl; }

	reading.close();
}

void Print(Data* d, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Данные номер: " << i + 1 << endl;

		d[i].Print();
		cout << "________________________\n";
	}
}

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

r3:cout << "Введите номер нужного элемента (от 1 до " << n << "): ";
	cin >> _n;
	_n--;

	Check* cl = new Check();

	if (_n <= 0 && _n < n) {
		system("cls");
		cout << "Выберите действие: " << endl
			<< "(1) Изменить ФИО " << endl
			<< "(2) Изменить дату рождения" << endl
			<< "(3) Изменить год поступления" << endl
			<< "(4) Изменить факультет (институт)" << endl
			<< "(5) Изменить кафедру" << endl
			<< "(6) Изменить группу" << endl
			<< "(7) Изменить номер зачётной книжки" << endl
			<< "(8) Изменить пол" << endl
			<< "(9) Редактор сессии(ий)" << endl
			<< "Введите значение: ";
		cin >> chm;
		switch (chm) {
		case 1:
			system("cls");
			cout << "Выберите действие: " << endl
				<< "(0) Вернуться" << endl
				<< "(1) Изменить фамилию " << endl
				<< "(2) Изменить имя" << endl
				<< "(3) Изменить отчество" << endl
				<< "Введите значение: ";
			cin >> chfio;
			switch (chfio) {
			case 0:
				system("cls");
				goto r3;
				break;
			case 1:
				cl->clear();
				cl->setLabel("Введите фамилию: ");
				fio.surname = cl->getData(editType::onlyAlpha, 20);
				break;
			case 2:
				cl->clear();
				cl->setLabel("Введите имя: ");
				fio.name = cl->getData(editType::onlyAlpha, 20);
				break;
			case 3:
				cl->clear();
				cl->setLabel("Введите отчество: ");
				fio.fathername = cl->getData(editType::onlyAlpha, 20);
				break;
			default:
				break;
			}
			break;
		case 2:
			system("cls");
			cout << "Выберите действие: " << endl
				<< "(0) Вернуться" << endl
				<< "(1) Изменить день " << endl
				<< "(2) Изменить месяц" << endl
				<< "(3) Изменить год" << endl
				<< "Введите значение: ";
			cin >> chbthd;
			switch (chbthd)
			{
			case 0:
				system("cls");
				goto r3;
				break;
			case 1:
				cl->clear();
				cl->setLabel("Введите день рождения: ");
				birthdate.day = cl->getData(editType::onlyDigit, 1, 31);
				break;
			case 2:
				cl->clear();
				cl->setLabel("Введите месяц рождения: ");
				birthdate.month = cl->getData(editType::onlyDigit, 1, 12);
				break;
			case 3:
				cl->clear();
				cl->setLabel("Введите год рождения: ");
				birthdate.year = cl->getData(editType::onlyDigit, 1800, 2100);
				break;
			default:
				break;
			}
			break;
		case 3:
			cl->clear();
			cl->setLabel("Введите год поступления: ");
			univeryear.univeryear = cl->getData(editType::onlyDigit, 1800, 2100);
			break;
		case 4:
			cl->clear();
			cl->setLabel("Введите институт (факультет): ");
			institut.institut = cl->getData(editType::all);
			break;
		case 5:
			cl->clear();
			cl->setLabel("Введите кафедру: ");
			kafedra.kafedra = cl->getData(editType::all);
			break;
		case 6:
			cl->clear();
			cl->setLabel("Введите группу: ");
			group.group = cl->getData(editType::all);
			break;
		case 7:
			cl->clear();
			cl->setLabel("Введите номер зачётной книжки: ");
			exambook.exambook = cl->getData(editType::all);
			break;
		case 8:
			cl->clear();
			cl->setLabel("Введите пол: ");
			sex.sex = cl->getData(editType::onlyAlpha, 10);
			break;
		case 9:
			system("cls");
			cout << "Выберите действие: " << endl
					<< "(0) Вернуться" << endl
					<< "(1) Изменить предмет " << endl
					<< "(2) Изменить оценку" << endl
					<< "Введите значение: ";
			cin >> chses;
			switch (chses)
			{
			case 0:
				system("cls");
				goto r3;
				break;
			case 1:
				cl->clear();
				cl->setLabel("Введите предмет: ");
				//sesia.subject = cl->getData(editType::all);
				break;
			case 2:
				cl->clear();
				cl->setLabel("Введите оценку: ");
				//sesia.mark = cl->getData(editType::onlyDigit, 1, 5);
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}

		d[_n].DataEntry(fio, birthdate, univeryear, institut, kafedra, group, exambook, sex, sesia);
	}
	else {
		cout << "Номер введён неверно" << endl;
		system("pause");
		system("cls");
		goto r3;
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

	Copy(d, buf, size);

	d = new Data[new_size];

	Copy(d, buf, size);

	cout << "Введите новую ФИО: ";
	cin >> fio.surname >> fio.name >> fio.fathername;

	cout << "Введите новую дату рождения: ";
	cin >> birthdate.day >> birthdate.month >> birthdate.year;

	cout << "Введите новый год поступления: ";
	cin >> univeryear.univeryear;

	cout << "Введите новый факультет: ";
	cin >> institut.institut;

	cout << "Введите новую кафедру: ";
	cin >> kafedra.kafedra;

	cout << "Введите новую группу: ";
	cin >> group.group;

	cout << "Введите новый номер зачётной книжки: ";
	cin >> exambook.exambook;

	cout << "Введите новый пол: ";
	cin >> sex.sex;

	/*cout << "Введите количество сессий: ";
	cin >> sesia.sesia;


	cout << "Введите предмет: ";
	cin >> sesia.subject;

	cout << "Введите оценку: ";
	cin >> sesia.mark;*/

	d[size].DataEntry(fio, birthdate, univeryear, institut, kafedra, group, exambook, sex, sesia);

	cout << "Данные добавлены" << endl;
	delete[] buf;
}

void DataDel(Data* (&d), int& n) {
	int _n;
	Data* buf = new Data[n];

	cout << "Введите номер нужного элемента (от 1 до " << n << "): ";
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
		cout << "Данные удалены" << endl;
	}
	else { cout << "Номер введён неверно" << endl; }

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

	cout << "Данные отсортированиы\nКоличество сортировок: " << numOfSored << endl;
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