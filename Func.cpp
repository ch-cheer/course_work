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
	cl->setLabel("Введите количество студентов: ");
	n = cl->getData(editType::onlyDigit, 1, sizeof(n));

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
			sesia.subject_count[n] = cl->getData(editType::onlyDigit, 1, 10);
			sesia.subject_count[n] = sesia.subject_count[n] - 1;
			for (int h = 0; h <= sesia.subject_count[n]; h++) {
				cl->clear();
				cl->setLabel("Введите предмет: ");
				sesia.subject[sesia.sesia[n]][h] = cl->getData(editType::onlyAlpha, 20);
				cl->clear();
				cl->setLabel("Введите тип оценки:\n(1) Дифференцированный зачет (с оценкой) / экзамен\n(2) Зачёт / незачет");
				dif_nodif = cl->getData(editType::onlyDigit, 1, 2);
				switch (dif_nodif) {
				case 1:
					cl->clear();
					cl->setLabel("Введите оценку: ");
					sesia.mark[sesia.sesia[n]][h] = cl->getData(editType::onlyDigit, 2, 5);
					break;
				case 2:
					cl->clear();
					cl->setLabel("Введите значение: зачёт(1) / незачет(2)");
					zath_nozath = cl->getData(editType::onlyDigit, 1, 2);
					switch (zath_nozath) {
					case 1:
						sesia.mark[sesia.sesia[n]][h] = 1;
						sesia.diferens[sesia.sesia[n]][h] = "Зачёт";
						break;
					case 2:
						sesia.mark[sesia.sesia[n]][h] = 0;
						sesia.diferens[sesia.sesia[n]][h] = "Не зачёт";
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
//работает

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
			//Чтение фамилии
			{
				reading.read((char*)&readCount, sizeof(int));
				char* buffer = new char[readCount + 1];
				buffer[readCount] = '\0';
				reading.read(buffer, readCount);
				fio.surname = buffer;
				delete[] buffer;
			}
			//Чтение имени
			{
				reading.read((char*)&readCount, sizeof(int));
				char* buffer = new char[readCount + 1];
				buffer[readCount] = '\0';
				reading.read(buffer, readCount);
				fio.name = buffer;
				delete[] buffer;
			}
			//Чтение отчества
			{
				reading.read((char*)&readCount, sizeof(int));
				char* buffer = new char[readCount + 1];
				buffer[readCount] = '\0';
				reading.read(buffer, readCount);
				fio.fathername = buffer;
				delete[] buffer;
			}

			//Чтение дня рождения
			reading.read((char*)&birthdate.day, sizeof(int));
			//Чтение месяца рождения
			reading.read((char*)&birthdate.month, sizeof(int));
			//Чтение года рождения
			reading.read((char*)&birthdate.year, sizeof(int));

			//Чтение года поступления в университет
			reading.read((char*)&univeryear.univeryear, sizeof(int));

			//Чтение названия института
			{
				reading.read((char*)&readCount, sizeof(int));
				char* buffer = new char[readCount + 1];
				buffer[readCount] = '\0';
				reading.read(buffer, readCount);
				institut.institut = buffer;
				delete[] buffer;
			}

			//Чтение названия кафедры
			{
				reading.read((char*)&readCount, sizeof(int));
				char* buffer = new char[readCount + 1];
				buffer[readCount] = '\0';
				reading.read(buffer, readCount);
				kafedra.kafedra = buffer;
				delete[] buffer;
			}

			//Чтение названия группы
			{
				reading.read((char*)&readCount, sizeof(int));
				char* buffer = new char[readCount + 1];
				buffer[readCount] = '\0';
				reading.read(buffer, readCount);
				group.group = buffer;
				delete[] buffer;
			}

			//Чтение номер зачётной книжки
			{
				reading.read((char*)&readCount, sizeof(int));
				char* buffer = new char[readCount + 1];
				buffer[readCount] = '\0';
				reading.read(buffer, readCount);
				exambook.exambook = buffer;
				delete[] buffer;
			}

			//Чтение пола студента
			{
				reading.read((char*)&readCount, sizeof(int));
				char* buffer = new char[readCount + 1];
				buffer[readCount] = '\0';
				reading.read(buffer, readCount);
				sex.sex = buffer;
				delete[] buffer;
			}

			//Чтение количества сессий
			reading.read((char*)&sesia.sesia_count, sizeof(short unsigned int));

			for (int j = 0; j <= sesia.sesia_count; j++) {
				//Чтение номера сессии
				reading.read((char*)&sesia.sesia[j], sizeof(unsigned int));
				//Чтение количества предметов
				reading.read((char*)&sesia.subject_count[j], sizeof(short unsigned int));
				for (int h = 0; h <= sesia.subject_count[j]; h++) {
					//Чтение предмета
					{
						reading.read((char*)&readCount, sizeof(int));
						char* buffer = new char[readCount + 1];
						buffer[readCount] = '\0';
						reading.read(buffer, readCount);
						sesia.subject[sesia.sesia[j]][h] = buffer;
						delete[] buffer;
					}
					//Получение оценки из файла
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

		cout << "Данные считаны успешно." << endl;
	}

	else { cout << "Ошибка, файл не может быть открыт" << endl; }

	reading.close();
}
//Работает

void Print(Data* d, int n) {
	for (int i = 0; i < n; i++) {
		cout << " Данные о студенте номер: " << i + 1 << endl;

		d[i].Print();
		cout << endl;
		uwu
			cout << endl;
	}
}
//работает

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
	cout << "Введите номер студента (от 1 до " << n << "): ";
	_n = cl->getData(editType::onlyDigit, 1, n);
	_n--;


	if (_n >= 0 && _n < n) {
		cl->clear();
		cl->setLabel("Выберите действие:\n(0) Вернуться\n(1) Изменить ФИО\n(2) Изменить дату рождения\n(3) Изменить год поступления\n(4) Изменить факультет (институт)\n(5) Изменить кафедру\n(6) Изменить группу\n(7) Изменить номер зачётной книжки\n(8) Изменить пол\n(9) Добавить сессию\n(10) Редактор сессии(ий)\nВведите значение: ");
		chm = cl->getData(editType::onlyDigit, 0, 10);
		switch (chm) {
		case 0:
			break;
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
				cout << "Ошибка: Введено неврное значение, введите значение от 0 до 3" << endl;
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
				cout << "Ошибка: Введено неврное значение, введите значение от 0 до 3" << endl;
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
			cl->setLabel("Введите год поступления: ");
			univeryear.univeryear = cl->getData(editType::onlyDigit, 1800, 2100);
			d[_n].DataEntry(univeryear);
			break;
		case 4:
			cl->clear();
			cl->setLabel("Введите институт (факультет): ");
			institut.institut = cl->getData(editType::all);
			d[_n].DataEntry(institut);
			break;
		case 5:
			cl->clear();
			cl->setLabel("Введите кафедру: ");
			kafedra.kafedra = cl->getData(editType::all);
			d[_n].DataEntry(kafedra);
			break;
		case 6:
			cl->clear();
			cl->setLabel("Введите группу: ");
			group.group = cl->getData(editType::all);
			d[_n].DataEntry(group);
			break;
		case 7:
			cl->clear();
			cl->setLabel("Введите номер зачётной книжки: ");
			exambook.exambook = cl->getData(editType::all);
			d[_n].DataEntry(exambook);
			break;
		case 8:
			cl->clear();
			cl->setLabel("Введите пол: ");
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

			if (sesia.sesia_count < 8) { //0 — 8
				sesia.sesia_count++;
				cl->clear();
				cl->setLabel("Введите сессию: ");
				sesia.sesia[sesia.sesia_count] = cl->getData(editType::onlyDigit, 1, 9);

				cl->clear();
				cl->setLabel("Введите количество предметов: ");
				sesia.subject_count[sesia.sesia_count] = cl->getData(editType::onlyDigit, 1, 10);
				sesia.subject_count[sesia.sesia_count] = sesia.subject_count[sesia.sesia_count] - 1;
				for (int h = 0; h <= sesia.subject_count[sesia.sesia_count]; h++) {
					cl->clear();
					cl->setLabel("Введите предмет: ");
					sesia.subject[sesia.sesia[sesia.sesia_count]][h] = cl->getData(editType::onlyAlpha, 20);
					cl->clear();
					cl->setLabel("Введите тип оценки:\n(1) Дифференцированный зачет (с оценкой) / экзамен\n(2) Зачёт / незачет");
					dif_nodif = cl->getData(editType::onlyDigit, 1, 2);
					switch (dif_nodif) {
					case 1:
						cl->clear();
						cl->setLabel("Введите оценку: ");
						sesia.mark[sesia.sesia[sesia.sesia_count]][h] = cl->getData(editType::onlyDigit, 2, 5);
						break;
					case 2:
						cl->clear();
						cl->setLabel("Введите значение: зачёт(1) / незачет(2)");
						zath_nozath = cl->getData(editType::onlyDigit, 1, 2);
						switch (zath_nozath) {
						case 1:
							sesia.mark[sesia.sesia[sesia.sesia_count]][h] = 1;
							sesia.diferens[sesia.sesia[sesia.sesia_count]][h] = "Зачёт";
							break;
						case 2:
							sesia.mark[sesia.sesia[sesia.sesia_count]][h] = 0;
							sesia.diferens[sesia.sesia[sesia.sesia_count]][h] = "Не зачёт";
							break;
						}
						break;
					}
				}
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

			/*system("cls");
			cout << endl;
			d[_n].PrintSes();
			cout << endl << "Введите сессию, в которой необходимо изменить данные: ";*/
			cl->clear();
			cl->setLabel("Введите сессию, в которой необходимо изменить данные: ");
			sesia_num = cl->getData(editType::onlyDigit, 1, 9);
			for (int i = 0; i <= sesia.sesia_count; i++) {
				if (sesia_num == sesia.sesia[i]) {
					system("cls");
					cout << "Выберите действие: " << endl
						<< "(0) Вернуться" << endl
						<< "(1) Изменить предмет " << endl
						<< "(2) Изменить оценку" << endl
						<< "Введите значение: ";
					cin >> chses;
					switch (chses) {
					case 0:
						cl->clear();
						break;
					case 1:
						cl->clear();
						cout << "Выберите действие: " << endl
							<< "(0) Вернуться" << endl
							<< "(1) Ввести номер предмета, который хотите изменить" << endl
							<< "(2) Ввести предмет, который хотите изменить" << endl
							<< "Введите значение: ";
						cin >> chsub;
						switch (chsub) {
						case 0:
							cl->clear();
							break;
						case 1:
							cl->clear();
							cl->setLabel("Введите номер предмета, который хотите изменить: ");
							subject_num = cl->getData(editType::onlyDigit, 1, sesia.subject_count[i] + 1);
							subject_num = subject_num - 1;
							for (int j = 0; j <= sesia.subject_count[i]; j++) {
								sesia.subject[sesia.sesia[i]][j] = d[_n].GetSesia().subject[sesia.sesia[i]][j];
								if (j == subject_num) {
									cl->clear();
									cl->setLabel("Введите новый предмет: ");
									sesia.subject[sesia.sesia[i]][j] = cl->getData(editType::onlyAlpha, 20);
								}
							}
							break;
						case 2:
							cl->clear();
							cl->setLabel("Введите предмет, который хотите изменить: ");
							subject_item = cl->getData(editType::onlyAlpha, 20);
							for (int j = 0; j <= sesia.subject_count[i]; j++) {
								sesia.subject[sesia.sesia[i]][j] = d[_n].GetSesia().subject[sesia.sesia[i]][j];
								if (subject_item == sesia.subject[sesia.sesia[i]][j]) {
									cl->clear();
									cl->setLabel("Введите новый предмет: ");
									sesia.subject[sesia.sesia[i]][j] = cl->getData(editType::onlyAlpha, 20);
								}
							}
							break;
						default:
							cout << "Ошибка: Введено неврное значение, введите значение от 0 до 2" << endl;
							system("pause");
							break;
						}
						break;
					case 2:
						system("cls");
						cout << "Выберите действие: " << endl
							<< "(0) Вернуться" << endl
							<< "(1) Ввести номер предмета, оценку которого хотите изменить" << endl
							<< "(2) Ввести предмет, оценку которого хотите изменить" << endl
							<< "Введите значение: ";
						cin >> chsub;
						switch (chsub) {
						case 0:
							cl->clear();
							break;
						case 1:
							cl->clear();
							cl->setLabel("Введите номер предмета, оценку которого хотите изменить: ");
							subject_num = cl->getData(editType::onlyDigit, 1, sesia.subject_count[i] + 1);
							subject_num = subject_num - 1;
							for (int j = 0; j <= sesia.subject_count[i]; j++) {
								sesia.subject[sesia.sesia[i]][j] = d[_n].GetSesia().subject[sesia.sesia[i]][j];
								if (j == subject_num) {
									cl->clear();
									cl->setLabel("Введите тип оценки:\n(1) Дифференцированный зачет (с оценкой) / экзамен\n(2) Зачёт / незачет");
									dif_nodif = cl->getData(editType::onlyDigit, 1, 2);
									switch (dif_nodif) {
									case 1:
										cl->clear();
										cl->setLabel("Введите оценку: ");
										sesia.mark[sesia.sesia[i]][j] = cl->getData(editType::onlyDigit, 2, 5);
										break;
									case 2:
										cl->clear();
										cl->setLabel("Введите значение: зачёт(1) / незачет(2)");
										zath_nozath = cl->getData(editType::onlyDigit, 1, 2);
										switch (zath_nozath) {
										case 1:
											sesia.mark[sesia.sesia[i]][j] = 1;
											sesia.diferens[sesia.sesia[i]][j] = "Зачёт";
											break;
										case 2:
											sesia.mark[sesia.sesia[i]][j] = 0;
											sesia.diferens[sesia.sesia[i]][j] = "Не зачёт";
											break;
										}
										break;
									}
								}
							}
							break;
						case 2:
							cl->clear();
							cl->setLabel("Введите предмет, оценку которого хотите изменить хотите изменить: ");
							subject_item = cl->getData(editType::onlyAlpha, 20);
							for (int j = 0; j <= sesia.subject_count[i]; j++) {
								sesia.subject[sesia.sesia[i]][j] = d[_n].GetSesia().subject[sesia.sesia[i]][j];
								if (subject_item == sesia.subject[sesia.sesia[i]][j]) {
									cl->clear();
									cl->setLabel("Введите тип оценки:\n(1) Дифференцированный зачет (с оценкой) / экзамен\n(2) Зачёт / незачет");
									dif_nodif = cl->getData(editType::onlyDigit, 1, 2);
									switch (dif_nodif) {
									case 1:
										cl->clear();
										cl->setLabel("Введите оценку: ");
										sesia.mark[sesia.sesia[i]][j] = cl->getData(editType::onlyDigit, 2, 5);
										break;
									case 2:
										cl->clear();
										cl->setLabel("Введите значение: зачёт(1) / незачет(2)");
										zath_nozath = cl->getData(editType::onlyDigit, 1, 2);
										switch (zath_nozath) {
										case 1:
											sesia.mark[sesia.sesia[i]][j] = 1;
											sesia.diferens[sesia.sesia[i]][j] = "Зачёт";
											break;
										case 2:
											sesia.mark[sesia.sesia[i]][j] = 0;
											sesia.diferens[sesia.sesia[i]][j] = "Не зачёт";
											break;
										}
										break;
									}
								}
							}
							break;
						default:
							cout << "Ошибка: Введено неврное значение, введите значение от 0 до 2" << endl;
							system("pause");
							break;
						}
						break;
					default:
						break;
					}
				}
				else {
					cout << endl << "Ошибка: Введена несуществующая сессия" << endl;
				}
			}
			d[_n].DataEntry(sesia);
			break;
		default:
			cout << "Ошибка: Введено неврное значение, введите значение от 0 до 9" << endl;
			system("pause");
			break;
		}
	}
	else {
		cout << "Номер введён неверно" << endl;
		system("pause");
		system("cls");
	}
}
//работает

void Copy(Data* d_n, Data* d_o, int n) {
	for (int i = 0; i < n; i++) {
		d_n[i] = d_o[i];
	}
}
//работает

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
		sesia.subject_count[n] = cl->getData(editType::onlyDigit, 1, 10);
		sesia.subject_count[n] = sesia.subject_count[n] - 1;
		for (int h = 0; h <= sesia.subject_count[n]; h++) {
			cl->clear();
			cl->setLabel("Введите предмет: ");
			sesia.subject[sesia.sesia[n]][h] = cl->getData(editType::onlyAlpha, 20);
			cl->clear();
			cl->setLabel("Введите тип оценки:\n(1) Дифференцированный зачет (с оценкой) / экзамен\n(2) Зачёт / незачет");
			dif_nodif = cl->getData(editType::onlyDigit, 1, 2);
			switch (dif_nodif) {
			case 1:
				cl->clear();
				cl->setLabel("Введите оценку: ");
				sesia.mark[sesia.sesia[n]][h] = cl->getData(editType::onlyDigit, 2, 5);
				break;
			case 2:
				cl->clear();
				cl->setLabel("Введите значение: зачёт(1) / незачет(2)");
				zath_nozath = cl->getData(editType::onlyDigit, 1, 2);
				switch (zath_nozath) {
				case 1:
					sesia.mark[sesia.sesia[n]][h] = 1;
					sesia.diferens[sesia.sesia[n]][h] = "Зачёт";
					break;
				case 2:
					sesia.mark[sesia.sesia[n]][h] = 0;
					sesia.diferens[sesia.sesia[n]][h] = "Не зачёт";
					break;
				}
				break;
			}
		}
	}

	d[size].DataEntry(fio, birthdate, univeryear, institut, kafedra, group, exambook, sex, sesia);

	cout << "Данные добавлены" << endl;
	delete[] buf;
}
//работает

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
//работает

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
//не так работает

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
			//Запись фамилии
			fio.surname = d[i].GetFio().surname;
			count = fio.surname.size();
			record.write((char*)&count, sizeof(int));
			record.write(fio.surname.c_str(), count);
			//Запись имени
			fio.name = d[i].GetFio().name;
			count = fio.name.size();
			record.write((char*)&count, sizeof(int));
			record.write(fio.name.c_str(), count);
			//Запись отчества
			fio.fathername = d[i].GetFio().fathername;
			count = fio.fathername.size();
			record.write((char*)&count, sizeof(int));
			record.write(fio.fathername.c_str(), count);

			//Запись дня рождения
			birthdate.day = d[i].GetBirthdate().day;
			record.write((char*)&birthdate.day, sizeof(int));
			//Запись месяца рождения
			birthdate.month = d[i].GetBirthdate().month;
			record.write((char*)&birthdate.month, sizeof(int));
			//Запись года рождения
			birthdate.year = d[i].GetBirthdate().year;
			record.write((char*)&birthdate.year, sizeof(int));

			//Запись года поступдения в университет
			univeryear.univeryear = d[i].GetUniveryear().univeryear;
			record.write((char*)&univeryear.univeryear, sizeof(int));

			//Запись названия института
			institut.institut = d[i].GetInstitut().institut;
			count = institut.institut.size();
			record.write((char*)&count, sizeof(int));
			record.write(institut.institut.c_str(), count);

			//Запись названия кафедры
			kafedra.kafedra = d[i].GetKafedra().kafedra;
			count = kafedra.kafedra.size();
			record.write((char*)&count, sizeof(int));
			record.write(kafedra.kafedra.c_str(), count);

			//Запись названия группы
			group.group = d[i].GetGroup().group;
			count = group.group.size();
			record.write((char*)&count, sizeof(int));
			record.write(group.group.c_str(), count);

			//Запись номера зачётной книжки
			exambook.exambook = d[i].GetExambook().exambook;
			count = exambook.exambook.size();
			record.write((char*)&count, sizeof(int));
			record.write(exambook.exambook.c_str(), count);

			//Запись пола студента
			sex.sex = d[i].GetSex().sex;
			count = sex.sex.size();
			record.write((char*)&count, sizeof(int));
			record.write(sex.sex.c_str(), count);

			//Запись количества сессий
			sesia.sesia_count = d[i].GetSesia().sesia_count;
			record.write((char*)&sesia.sesia_count, sizeof(short unsigned int));

			for (int j = 0; j <= sesia.sesia_count; j++) {
				//Запсись номера сессии
				sesia.sesia[j] = d[i].GetSesia().sesia[j];
				record.write((char*)&sesia.sesia[j], sizeof(unsigned int));
				//Запись количества предметов
				sesia.subject_count[j] = d[i].GetSesia().subject_count[j];
				record.write((char*)&sesia.subject_count[j], sizeof(short unsigned int));
				for (int h = 0; h <= sesia.subject_count[j]; h++) {
					//Запись предмета
					sesia.subject[sesia.sesia[j]][h] = d[i].GetSesia().subject[sesia.sesia[j]][h];
					count = sesia.subject[sesia.sesia[j]][h].size();
					record.write((char*)&count, sizeof(int));
					record.write(sesia.subject[sesia.sesia[j]][h].c_str(), count);
					//Получение оценки из программы
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
//Работает