#include "examHeader.h"

void fenix::GuestMode::registarion() {
	cout << "Заполните данные для регистрации" << endl;
	string Login, Pass, Name, Surname, Patronomic, Phone, Adress;
	cout << "Введите логин \nВвод -> ";
	cin >> Login;
	cout << "Введите пароль \nВвод -> ";
	cin >> Pass;
	cout << "Введите имя \nВвод -> ";
	cin >> Name;
	cout << "Введите фамилию \nВвод -> ";
	cin >> Surname;
	cout << "Введите отчество \nВвод -> ";
	cin >> Patronomic;
	cout << "Введите номер телефона \nВвод -> ";
	cin >> Phone;
	cout << "Введите адресс \nВвод -> ";
	cin >> Adress;

	vector<student> tmp;
	tmp.push_back(student({ x0r.encrypt(Login), x0r.encrypt(Pass), Name, Surname, Patronomic, Phone, Adress }));

	fstream txt("LoginData.txt", ios::app);
	if (!txt) {
		cerr << "err" << endl;
	}
	else { cout << "Complete" << endl; }


	for (size_t i = 0; i < user.size(); i++) {
		txt << tmp[i].login << ":" << user[i].password << ":";
		txt << tmp[i].name << ":" << user[i].surname << ":" << user[i].patronomic << ":" << user[i].phoneNum << ":" << user[i].adress << ":;" << endl;
	}
	
	txt.close();
}



void fenix::GuestMode::outputLoginData(std::string fileName) {
	ifstream txt(fileName);
	string word, stroka;
	string tmp[1][7];

	while (!txt.eof()) {
		int i = 0, j = 0;

		getline(txt, stroka);
		for (auto letter : stroka) {
			if (letter != ':') {
				word += letter;
			}
			else {
				tmp[0][j++] = word;
				word.clear();
			}
			if (letter == ';') {
				user.push_back(student({ tmp[0][0], tmp[0][1], tmp[0][2], tmp[0][3], tmp[0][4], tmp[0][5], tmp[0][6] }));
				j = 0;
				continue;
			}

		}
		i++;
	}
	txt.close();
}

void fenix::GuestMode::log_in() {
_Back:
	char choose;
	cout << "1. Вход \n2. Регистрация \n3. Вход от имени админа" << endl;
	choose = _getch();

	if (choose == '1') {
		string log, pass;
		cout << "Для входа в учетку введите ваш логин и пароль" << endl;
		cout << "Введите логин " << endl;
		cout << "Ввод -> ";
		cin >> log;
		cout << "Введите пароль " << endl;
		cout << "Ввод -> ";
		cin >> pass;

		outputLoginData("LoginData.txt");

		for (size_t i = 0; i < user.size(); i++) {
			if (log == x0r.decryption(user[i].login) && pass == x0r.decryption(user[i].password)) {
				cout << "Добро пожаловать " << user[i].name << endl;
				GuestMenu();
				break;
			}
			else {
				system("cls");
				cout << "Неверный логин или пароль" << endl;
				system("Pause");
				goto _Back;
			}
		}
	
	}
	else if (choose == '2') {
		system("cls");
		registarion();
	}
	else if (choose == '3') {
		string log, pass;
		cout << "Для входа в режиме админа введите логин и пароль" << endl;
		cout << "Введите логин " << endl;
		cout << "Ввод -> ";
		cin >> log;
		cout << "Введите пароль " << endl;
		cout << "Ввод -> ";
		cin >> pass;

		outputLoginData("AdminData.txt");

		for (size_t i = 0; i < user.size(); i++) {
			if (log == x0r.decryption(user[i].login) && pass == x0r.decryption(user[i].password)) {
				cout << "Добро пожаловать админ!" << endl;
				
				break;
			}
			else {
				system("cls");
				cout << "Неверный логин или пароль" << endl;
				system("Pause");
				goto _Back;
			}
		}

	}

}

void fenix::GuestMode::menuTest() {
_MenuTest:
	fstream menu("testsList.txt", ios::in | ios::out);

	string stroka, chooseTest;
	while (!menu.eof()) {
		getline(menu, stroka);
		cout << stroka << endl;
	}

	stroka.clear();
	menu.seekg(menu.beg);

	cout << "Введите название теста который хотите начать" << endl;
	getline(cin, chooseTest);

	chooseTest += ".txt";

	ifstream check(chooseTest);
	if (!check.is_open()) {
		cout << "\n\nВведенный вами тест не найден." << endl;
		system("pause");
		goto _MenuTest;
	}
	else {
		startTest(chooseTest);
	}


}

void fenix::GuestMode::startTest(string file) {
	system("cls");
	ifstream test(file);
	if (!test.is_open()) {
		cerr << "Ошибка не удалось открыть файл" << endl;
	}

	char userInput[12], answer[12];
	int grade = 0, i = 0, j = -1;

	string stroka;

	while (!test.eof()) {
		getline(test, stroka);

		for (auto str : stroka) {
			if (str == ';') {
				cout << "\n\nВведите вариант ответа в виде заглавной буквы латинского алфавита. \nбудьте внимательны, вы не сможете больше вернуться к этому вопросу" << endl;
				do {
					cout << "Ввод -> ";
					cin >> userInput[i];
					if (userInput[i] == 'A' || userInput[i] == 'B' || userInput[i] == 'C') {
						break;
					}
					cout << "Такого варианта ответа нет" << endl;
				} while (true);

				i++;
				system("cls");
				continue;
			}
			if (str == '~') {
				getline(test, stroka);
				j = 0;
				cout << "Правильные ответы" << endl;
				break;
			}
		}
		cout << stroka << '\n';

		if (j == 0) {
			for (auto str : stroka) {
				if (isalpha(str)) {
					answer[j] = str;
					if (userInput[j] == answer[j]) {
						grade++;
					}
					j++;
				}
			}
		}

	} // while

	cout << "Ваш результат: " << grade << "/12" << endl;

	int choise;
	cout << "1. посмотреть правильные ответы \n2. назад" << endl ;
	cin >> choise;

	if (choise == 1) {
		viewResult(file, userInput, answer);
	}
	else if (choise == 2) {
		GuestMenu();
	}

}

void fenix::GuestMode::viewResult(string file, char* userInput, char* answer) {
	ifstream test(file);
	if (!test.is_open()) {
		cerr << "Ошибка не удалось открыть файл" << endl;
	}

	string stroka;
	int i = 0;
	cout << "\033[0m";
	while (test) {
		getline(test, stroka);

		for (auto lett : stroka) {
			if (lett == ';') {
				i++;
			}
			if (lett == '~') {
				break;
			}
			if (lett == userInput[i]) {
				cout << "\033[0;33m" << stroka << "\033[0m" << '\n';
			}
			if (userInput[i] == answer[i]) {
				continue;
			}
			if (lett == answer[i]) {
				cout << "\033[0;32m" << stroka << "\033[0m" << '\n';
				goto _Skip;
			}

		}
		
		if (false) {
		_Skip:
			continue;
		}
		cout << stroka << '\n';

	} // идеально. ну хотя нет, единственное не получаеться оборвать цикл перед ответами в конце
	test.close();
	int grade = 0, j = 0;
	for (auto str : stroka) {
		if (isalpha(str)) {
			answer[j] = str;
			if (userInput[j] == answer[j]) {
				grade++;
			}
			j++;
		}
	}
	cout << "Желтым отмечен ваш ответ, зеленым правильный ответ" << endl;

	cout << "правильных ответов " << grade << "/12" << endl;
	cout << "Процент правильных ответов " << (grade / 12.0) * 100 << endl;
	cout << "Ваша оценка " << grade << " Балла(ов)" << endl;

	ofstream create("C++ basic result.txt");
	fstream save("C++ basic result.txt");


		int t = 0, u = 0;
		save << file << '\n';
		while (u <= 12) {
			if (t < 12) {
				save << userInput[t++];
			}
			if (t == 12) {
				save << '\n';
				t++;
			}
			if (t == 13) {
				save << answer[u++];
			}

		}
		save.close();

}

void fenix::GuestMode::GuestMenu() {
	char choose;
	cout << "1. Пройти тест \n2. Посмотреть прошлые результаты" << endl;
	choose = _getch();
	if (choose == '1') {
		menuTest();
	}
	else if (choose == '2') {
		showLastResult();
	}
}

void fenix::GuestMode::showLastResult() {

	fstream fileResult("C++ basic result.txt");

	string testFileName, stroka, Ans, userAns;
	char guestInpit[12], answer[12];

	while (getline(fileResult, stroka)) {
		testFileName = stroka;
		break;
	}
	fileResult.seekg(fileResult.beg);

	while (getline(fileResult, stroka)) {
		getline(fileResult, stroka);
		userAns = stroka;
		break;
	}
	fileResult.seekg(fileResult.beg);

	while (getline(fileResult, stroka)) { // все, лень уже делать норм цикл. а доделать хоть что то хочется
		getline(fileResult, stroka);
		getline(fileResult, stroka);

		Ans = stroka;
		break;
	}
	fileResult.close();

	for (int i = 0; i < 12; i++) {
		guestInpit[i] = userAns[i];
	}
	for (int i = 0; i < 12; i++) {
		answer[i] = Ans[i];
	}

	viewResult(testFileName, guestInpit, answer);

} // да уж, чет все оооочень долго пишеться как то. а так задачка интересная :D

// ================= AdminMode ========================

void fenix::AdminMode::setAdmin() {
	fstream txt("AdminData.txt", ios::in | ios::out);
	string check;
	getline(txt, check);
	for (auto chack : check) {
		if (chack == ':') {
			return;
		}
	}
	txt.seekg(txt.beg);

	string login, pass;
	system("cls");
	cout << "Здраствуйте задайте логин и пароль администратора" << endl;
	cout << "Введите логин" << endl;
	cin >> login;
	cout << "Введите пароль" << endl;
	cin >> pass;

	if (!txt) {
		cerr << "err" << endl;
		exit(505);
	}
	txt << x0r.encrypt(login) << ":" << x0r.encrypt(pass) << ":;";
	cout << "Данные администратора успешно сохранены" << endl;

	txt.close();

}

void fenix::AdminMode::addTest() {
	//system("cls");

	fstream File("testsList.txt", ios::app);
	try {
		if (!File) {
			throw ERRORS("не удалось открыть файл");
		}
	}
	catch (ERRORS err) {
		printf("Произошла ошибка: %s", err);
	}

	string testName;

	cout << "Введите название теста" << endl;
	getline(cin, testName);


	File << "\n:Новый тест:\n" << testName << "\n;"; // поэтому мы сделаеи по умному(нет) и запихнем все в конец

	testName += ".txt";
	ofstream create(testName); // и офстримом создадим нужный нам файл
	setTest(testName); // ах да ну и заполняем наш файлик


	/*while (File) {
		getline(File, word);
		cout << word << '\n';
	}*/

	/*
	string newTestName, section;
	int choose;
	cout << "1. добавления теста в уже существующий раздел" << endl <<
			"2. добавления теста в новый раздел" << endl;
	do {
		cin >> choose;
		if (choose == 1 || choose == 2) {
			break;
		}
		cout << "Выберите один из имеющихся вариантов" << endl;
	} while (true);

	//File.seekg(File.beg);
	if (choose == 1) {
		cin.ignore(4096, '\n');
		cout << "Введите название раздела/темы для добавления нового теста" << endl;
		getline(cin, section);
		cout << "Введите название теста" << endl;
		getline(cin, newTestName);

		section.insert(0, ":");
		section.insert(section.size(), ":");


		while (File) {
			getline(File, word);
			if (word == section) {

			}
				if (word == "\n") {
					//File.seekg(-1, File.beg);
					File << "\n" << newTestName;
					cout << "yeeeee" << endl;
					break;
				}
				// в общем в теории она должна была искать знак ; потом передвинуться на одну позицию назад и
				// туда записать название. ноооо я хз как это делать seekg вроде не робит
		}
	}
	else if (choose == 2) {

	}
	*/

}

void fenix::AdminMode::setTest(string file) {
	vector<QuestionTemp> newQustion(12); // эта функция заполняет уже раннее созданный пустой файл

	for (size_t i = 0, p = 12; i < newQustion.size(); i++) {
		system("cls");

		cin.ignore(4096, '\n');
		cout << "Осталось задать вопросов: " << p-- << endl;
		cout << "Введите вопрос" << endl;
		getline(cin, newQustion[i].question);
		cout << "Введите вариант ответа \"A\"" << endl;
		getline(cin, newQustion[i].variant_A);
		cout << "Введите вариант ответа \"B\"" << endl;
		getline(cin, newQustion[i].variant_B);
		cout << "Введите вариант ответа \"C\"" << endl;
		getline(cin, newQustion[i].variant_C);
		cout << "Введите правильный вариант ответа в виде заглавной латинской буквы" << endl;
		do {
			cin >> newQustion[i].answer;
			if (newQustion[i].answer == 'A' || newQustion[i].answer == 'B' || newQustion[i].answer == 'C') {
				break;
			}

		} while (true);
	}

	fstream newTest("tmpTest.txt", ios::app);

	if (!newTest.is_open()) {
		cerr << "Произошла ошибка при открытии файла" << endl;
	}

	for (size_t i = 0; i < newQustion.size(); i++) {   // записываем заполненный тест в файл в соответствии моему канону 
		newTest << i + 1 << ". " << newQustion[i].question << '\n';
		newTest << "A. " << newQustion[i].variant_A << '\n';
		newTest << "B. " << newQustion[i].variant_B << '\n';
		newTest << "C. " << newQustion[i].variant_C << '\n' << ";\n";

	}
	newTest << "\n~ ";
	for (size_t i = 0; i < newQustion.size(); i++) { // записываем в конец файла краткий список ответов
		newTest << newQustion[i].answer << ' ';
	}
	newTest.close();

}
