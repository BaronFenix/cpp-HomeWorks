#include "examHeader.h"

void fenix::GuestMode::registarion() {
	cout << "��������� ������ ��� �����������" << endl;
	string Login, Pass, Name, Surname, Patronomic, Phone, Adress;
	cout << "������� ����� \n���� -> ";
	cin >> Login;
	cout << "������� ������ \n���� -> ";
	cin >> Pass;
	cout << "������� ��� \n���� -> ";
	cin >> Name;
	cout << "������� ������� \n���� -> ";
	cin >> Surname;
	cout << "������� �������� \n���� -> ";
	cin >> Patronomic;
	cout << "������� ����� �������� \n���� -> ";
	cin >> Phone;
	cout << "������� ������ \n���� -> ";
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
	cout << "1. ���� \n2. ����������� \n3. ���� �� ����� ������" << endl;
	choose = _getch();

	if (choose == '1') {
		string log, pass;
		cout << "��� ����� � ������ ������� ��� ����� � ������" << endl;
		cout << "������� ����� " << endl;
		cout << "���� -> ";
		cin >> log;
		cout << "������� ������ " << endl;
		cout << "���� -> ";
		cin >> pass;

		outputLoginData("LoginData.txt");

		for (size_t i = 0; i < user.size(); i++) {
			if (log == x0r.decryption(user[i].login) && pass == x0r.decryption(user[i].password)) {
				cout << "����� ���������� " << user[i].name << endl;
				GuestMenu();
				break;
			}
			else {
				system("cls");
				cout << "�������� ����� ��� ������" << endl;
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
		cout << "��� ����� � ������ ������ ������� ����� � ������" << endl;
		cout << "������� ����� " << endl;
		cout << "���� -> ";
		cin >> log;
		cout << "������� ������ " << endl;
		cout << "���� -> ";
		cin >> pass;

		outputLoginData("AdminData.txt");

		for (size_t i = 0; i < user.size(); i++) {
			if (log == x0r.decryption(user[i].login) && pass == x0r.decryption(user[i].password)) {
				cout << "����� ���������� �����!" << endl;
				
				break;
			}
			else {
				system("cls");
				cout << "�������� ����� ��� ������" << endl;
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

	cout << "������� �������� ����� ������� ������ ������" << endl;
	getline(cin, chooseTest);

	chooseTest += ".txt";

	ifstream check(chooseTest);
	if (!check.is_open()) {
		cout << "\n\n��������� ���� ���� �� ������." << endl;
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
		cerr << "������ �� ������� ������� ����" << endl;
	}

	char userInput[12], answer[12];
	int grade = 0, i = 0, j = -1;

	string stroka;

	while (!test.eof()) {
		getline(test, stroka);

		for (auto str : stroka) {
			if (str == ';') {
				cout << "\n\n������� ������� ������ � ���� ��������� ����� ���������� ��������. \n������ �����������, �� �� ������� ������ ��������� � ����� �������" << endl;
				do {
					cout << "���� -> ";
					cin >> userInput[i];
					if (userInput[i] == 'A' || userInput[i] == 'B' || userInput[i] == 'C') {
						break;
					}
					cout << "������ �������� ������ ���" << endl;
				} while (true);

				i++;
				system("cls");
				continue;
			}
			if (str == '~') {
				getline(test, stroka);
				j = 0;
				cout << "���������� ������" << endl;
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

	cout << "��� ���������: " << grade << "/12" << endl;

	int choise;
	cout << "1. ���������� ���������� ������ \n2. �����" << endl ;
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
		cerr << "������ �� ������� ������� ����" << endl;
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

	} // ��������. �� ���� ���, ������������ �� ����������� �������� ���� ����� �������� � �����
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
	cout << "������ ������� ��� �����, ������� ���������� �����" << endl;

	cout << "���������� ������� " << grade << "/12" << endl;
	cout << "������� ���������� ������� " << (grade / 12.0) * 100 << endl;
	cout << "���� ������ " << grade << " �����(��)" << endl;

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
	cout << "1. ������ ���� \n2. ���������� ������� ����������" << endl;
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

	while (getline(fileResult, stroka)) { // ���, ���� ��� ������ ���� ����. � �������� ���� ��� �� �������
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

} // �� ��, ��� ��� �������� ����� �������� ��� ��. � ��� ������� ���������� :D

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
	cout << "����������� ������� ����� � ������ ��������������" << endl;
	cout << "������� �����" << endl;
	cin >> login;
	cout << "������� ������" << endl;
	cin >> pass;

	if (!txt) {
		cerr << "err" << endl;
		exit(505);
	}
	txt << x0r.encrypt(login) << ":" << x0r.encrypt(pass) << ":;";
	cout << "������ �������������� ������� ���������" << endl;

	txt.close();

}

void fenix::AdminMode::addTest() {
	//system("cls");

	fstream File("testsList.txt", ios::app);
	try {
		if (!File) {
			throw ERRORS("�� ������� ������� ����");
		}
	}
	catch (ERRORS err) {
		printf("��������� ������: %s", err);
	}

	string testName;

	cout << "������� �������� �����" << endl;
	getline(cin, testName);


	File << "\n:����� ����:\n" << testName << "\n;"; // ������� �� ������� �� ������(���) � �������� ��� � �����

	testName += ".txt";
	ofstream create(testName); // � ��������� �������� ������ ��� ����
	setTest(testName); // �� �� �� � ��������� ��� ������


	/*while (File) {
		getline(File, word);
		cout << word << '\n';
	}*/

	/*
	string newTestName, section;
	int choose;
	cout << "1. ���������� ����� � ��� ������������ ������" << endl <<
			"2. ���������� ����� � ����� ������" << endl;
	do {
		cin >> choose;
		if (choose == 1 || choose == 2) {
			break;
		}
		cout << "�������� ���� �� ��������� ���������" << endl;
	} while (true);

	//File.seekg(File.beg);
	if (choose == 1) {
		cin.ignore(4096, '\n');
		cout << "������� �������� �������/���� ��� ���������� ������ �����" << endl;
		getline(cin, section);
		cout << "������� �������� �����" << endl;
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
				// � ����� � ������ ��� ������ ���� ������ ���� ; ����� ������������� �� ���� ������� ����� �
				// ���� �������� ��������. ����� � �� ��� ��� ������ seekg ����� �� �����
		}
	}
	else if (choose == 2) {

	}
	*/

}

void fenix::AdminMode::setTest(string file) {
	vector<QuestionTemp> newQustion(12); // ��� ������� ��������� ��� ������ ��������� ������ ����

	for (size_t i = 0, p = 12; i < newQustion.size(); i++) {
		system("cls");

		cin.ignore(4096, '\n');
		cout << "�������� ������ ��������: " << p-- << endl;
		cout << "������� ������" << endl;
		getline(cin, newQustion[i].question);
		cout << "������� ������� ������ \"A\"" << endl;
		getline(cin, newQustion[i].variant_A);
		cout << "������� ������� ������ \"B\"" << endl;
		getline(cin, newQustion[i].variant_B);
		cout << "������� ������� ������ \"C\"" << endl;
		getline(cin, newQustion[i].variant_C);
		cout << "������� ���������� ������� ������ � ���� ��������� ��������� �����" << endl;
		do {
			cin >> newQustion[i].answer;
			if (newQustion[i].answer == 'A' || newQustion[i].answer == 'B' || newQustion[i].answer == 'C') {
				break;
			}

		} while (true);
	}

	fstream newTest("tmpTest.txt", ios::app);

	if (!newTest.is_open()) {
		cerr << "��������� ������ ��� �������� �����" << endl;
	}

	for (size_t i = 0; i < newQustion.size(); i++) {   // ���������� ����������� ���� � ���� � ������������ ����� ������ 
		newTest << i + 1 << ". " << newQustion[i].question << '\n';
		newTest << "A. " << newQustion[i].variant_A << '\n';
		newTest << "B. " << newQustion[i].variant_B << '\n';
		newTest << "C. " << newQustion[i].variant_C << '\n' << ";\n";

	}
	newTest << "\n~ ";
	for (size_t i = 0; i < newQustion.size(); i++) { // ���������� � ����� ����� ������� ������ �������
		newTest << newQustion[i].answer << ' ';
	}
	newTest.close();

}
