#include <iostream>
#include "funcBook.h" 

#define templateForCout                      \
			if (list[i].sex == 0) {           \
		cout << "\n\nПол: \t\t" << "Женский";  \
		}                                       \
		else if (list[i].sex == 1) {             \
			cout << "\n\nПол: \t\t" << "Мужской"; \
		}                                          \
		cout << "\nAge: \t\t " << list[i].datta.age - list[i].datta.year; \
		cout << "\nФамилия: \t" << list[i].surname << "\nИмя: \t\t" << list[i].name << "\nОтчество: \t" << list[i].patronymic <<  \
			"\nДата рождения:  " << list[i].datta.day << "/" << list[i].datta.month << "/" << list[i].datta.year <<  \
			"\nНомер телефона: " << list[i].phone << "\nАдресс: \t" << list[i].adress << endl; 
// для многострочных дэфайнов нужно в конце каждой строки писать "\" и главное чтобы после слэша не было ничего даже пробела. а не то ошибки		  
// ну а насчет содержимого то это просто вывод контакта в цикле

namespace fenix {
	// func.cpp пишем здесь все функции


	void PhoneBook::contact_list(std::vector<PhoneBook>& list) { // если функция обьявлена в структуре или классе, то обязательно перед названием функции надо писать имя структуры и через :: имя функции
		//vector<phoneBook>& list;
		list.push_back(PhoneBook({ 1, "Пятижопкин", "Тимофей", "Григорьевич", "+7(707)526-19-00", "Улица Пушкина 142", {9, 12, 1989} }));
		list.push_back(PhoneBook({ 1, "Забабашкин", "Олег", "Михайлович",  "+7(727)634-44-50", "Проспект Жамбыла 223" , {11, 5, 1991} }));
		list.push_back(PhoneBook({ 1, "Грызидуб", "Вячеслав", "Сергеевич", "+7(707)149-10-79", "Улица ленина 56", {22, 7, 1991} }));
		list.push_back(PhoneBook({ 0, "Непейпиво", "Людмила", "Олеговна", "+7(777)854-55-77", "Проспект Абая 136", {30, 1, 1996} }));
		list.push_back(PhoneBook({ 0, "Брехунова", "Елена", "Николаевна", "+7(707)157-69-90", "Улица Ленина 44", {21, 11, 1991} }));
		list.push_back(PhoneBook({ 0, "Мозгоедова", "Анастасия", "Никитина", "+7(777)321-75-14", "Проспект Сейфулина 231", {1, 7, 1989} }));
		list.push_back(PhoneBook({ 0, "Гугловская", "Алиса", "Яндексова", "+7(700)745-16-15", "Улица Ломоносова 62", {24, 10, 1999} }));
		list.push_back(PhoneBook({ 1, "Бляблин", "Денис", "Владимирович", "+7(702)864-12-47", "Улица Дулина 56", {23, 7, 1995} }));

	} // *Данные фамилии реально существуют и были взяты с открытых источников **хотя насчет гугловской не уверен

	void PhoneBook::show_contacts(std::vector<PhoneBook>& list) {
		cout << "Список Контактов" << endl;
		for (size_t i = 0; i < list.size(); i++) {
			templateForCout;
		}
	}


	void PhoneBook::add_contact(vector<PhoneBook>& list) {
		list.push_back(PhoneBook());
		int tmp;

		cout << "Введите Пол (1 - Мужчина, 0 - Женщина):  ";
		cin >> tmp; list.back().sex = tmp;
		cout << "Введите Имя:  ";
		cin >> list.back().name;
		cout << "Введите Фамилию:  ";
		cin >> list.back().surname;
		cout << "Введите Отчество:  ";
		cin >> list.back().patronymic;

		cout << "Введите Дату рождения: (Пример дд мм гггг)" << endl;
		cout << "Введите день ";
		cin >> tmp; list.back().datta.day = tmp;
		cout << "Введите месяц  ";
		cin >> tmp; list.back().datta.month = tmp;
		cout << "Введите год  ";
		cin >> tmp; list.back().datta.year = tmp;

		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // для очистки буфера
		cout << "Введите Номер телефона: (Пример: +7(747)664-02-15)" << endl;
		getline(cin, list.back().phone);
		cout << "Введите Адресс: (Пример: Улица Петушкова 33)" << endl;
		getline(cin, list.back().adress);
		
	}

	void PhoneBook::del_contact(vector<PhoneBook>& list) {
	
		int id = NULL;
		printf("\nВведите фамилию для удаления ");
		//scanf_s("%d", &id);

		string surDel;
		cin >> surDel;

		for (size_t i = 0; i < list.size(); i++) {
			if (list[i].surname == surDel) {
				id = i;
				list.erase(list.begin() + (id));
				cout << "\n\nКонтакт успешно удален\n\n";
				system("pause");
				break;
			}
			
		}
		if (id == NULL) {
			cout << "\n\nВведенная фамилия не найдена!\n\n";
		}

	}



	void PhoneBook::upload_to_txt(vector<PhoneBook>& list) {
		fstream contBook("contBook.txt", ios::in | ios::out);
		//contBook.open("contBook.txt");
		if (!contBook) {
			cerr << "Error 404";
			exit(1);
		}
		else {
			cout << "Контакты успешно добавлены";
		}

		contBook << "Телефонная книга ";
		for (size_t i = 0; i < list.size(); i++) {
			if (list[i].sex == 0) {

				contBook << "\n\nПол: \t\t" << "Женский";
			}
			else if (list[i].sex == 1) {

				contBook << "\n\nПол: \t\t" << "Мужской";
			}
			contBook << "\nAge: \t\t " << list[i].datta.age - list[i].datta.year;
			contBook << "\nФамилия: \t" << list[i].surname << "\nИмя: \t\t" << list[i].name << "\nОтчество: \t" << list[i].patronymic <<
				"\nДата рождения:  " << list[i].datta.day << "/" << list[i].datta.month << "/" << list[i].datta.year <<
				"\nНомер телефона: " << list[i].phone << "\nАдресс: \t" << list[i].adress << endl;
		}
		contBook.close();
	
	}

	void PhoneBook::coutFromTxt() {
		ifstream contBook("contBook.txt");
		//contBook.open("contBook.txt");
		if (!contBook) {
			cerr << "Error 424";
			exit(1);
		}
		else {
			cout << "Complete";
		}

		string symb;
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // для очистки буфера
		while (contBook)
		{
			// то перемещаем то, что можем прочитать, в строку, а затем выводим эту строку на экран
			string temp;
			getline(contBook, temp);
			cout << temp << endl;
		}

		contBook.close();

	}

	void PhoneBook::SurSortUp(vector<PhoneBook>& list) {
		for (size_t i = 0; i < list.size() - 1; i++) {
			for (size_t j = i + 1; j < list.size(); j++) {
				if (strcmp(list[i].surname.c_str(), list[j].surname.c_str()) > 0) swap(list[i].surname, list[j].surname);
			}
		}
	}

	void PhoneBook::chooseSearch(vector<PhoneBook>& list) {
		PhoneBook www;
		Back:
		int what = -1;
	    printf("Выберите поиск \n");
	    printf("1. Поиск по фамилии \n2. Поиск по Дате рождения \n3. Поиск по полу");

		cin >> what;

		if (what == 1) {
			www.surnameSearch(list);
		}
		else if (what == 2) {
			www.DateSearch(list);
		}
		else if(what == 3) {
			www.SexSearch(list);
		}
		else {
			cout << "Вы ввели неверное число \n";
			system("Pause");
			goto Back;
		}
	}

	void PhoneBook::SexSearch(vector<PhoneBook>& list) {
		int sx = -1;
		cout << "Введите для поиска: 0 - Женщины, 1 - Мужчины \n";
		cout << "Ввол -> ";
		cin >> sx;

		for (size_t i = 0; i < list.size(); i++) {
			if (sx == list[i].sex) {
				templateForCout;
			}
		}
		
	}

	void PhoneBook::surnameSearch(vector<PhoneBook>& list) {
		string surSrch = "empty";
		int counter = 0;
		cout << "Введите фамилию для поиска \n";
		cout << "Ввод -> ";
		cin >> surSrch;

		for (size_t i = 0; i < list.size(); i++) {
			if (surSrch == list[i].surname) {
				templateForCout;
				counter++;
			}
		}
		if (counter == 0) {
			cout << "Введенная фамилия не найдена";
		}
	}
	void PhoneBook::DateSearch(vector<PhoneBook>& list) {
		int DateSrch;
		cout << "Введите Год рождения для поиска \n";
		cout << "Ввод -> ";
		cin >> DateSrch;

		for (size_t i = 0; i < list.size(); i++) {
			if (DateSrch == list[i].datta.year) {
				templateForCout;
			}
		}
	}


	void PhoneBook::choose_theme() {
		int choise;

		cout << "Выберите оформление консоли: \n" << endl;
		cout << "1. черный фон и зеленый шрифт \n2. Белый фон и красный шрифт \n3. Синий фон и белый шрифт" <<
			"\n4. зеленый фон и светло желтый шрифт \n5. голубой фон и белый шрифт \n6. черный фон и белый шрифт ";

		cout << "\n\nВвод -> ";
		cin >> choise;

		switch (choise) {
		case 1:
			cout << "\nТемная тема применена " << system("Color 0A") << endl;
			break;
		case 2:
			cout << "Светлая тема применена " << system("Color 7C");
			break;
		case 3:
			cout << "Синий экран смерти активирован " << system("Color 1F");
			break;
		case 4:
			cout << "Лаймовая тема применена" << system("Color 2E");
			break;
		case 5:
			cout << "Классическая тема применена" << system("Color 9E");
			break;
		case 6:
			cout << "Классическая тема применена" << system("Color 0F");
			break;

		default:
			cout << "Ошибка! Вы ввели неверный номер";
			break;
		}

	}

	void PhoneBook::showTime() {
		tm newtime;
		time_t long_time;

		time(&long_time);
		localtime_s(&newtime, &long_time);
		std::cout << "      Дата и время\n";
		std::cout << "\t  " << newtime.tm_hour << ":" << newtime.tm_min << std::endl;
		std::cout << "\t" << newtime.tm_mon + 1 << "/" << newtime.tm_mday << "/" << newtime.tm_year + 1900 << std::endl;
	}

}

