#include <iostream>
#include "funcBook.h" 

#define templateForCout                      \
			if (list[i].sex == 0) {           \
		cout << "\n\n���: \t\t" << "�������";  \
		}                                       \
		else if (list[i].sex == 1) {             \
			cout << "\n\n���: \t\t" << "�������"; \
		}                                          \
		cout << "\nAge: \t\t " << list[i].datta.age - list[i].datta.year; \
		cout << "\n�������: \t" << list[i].surname << "\n���: \t\t" << list[i].name << "\n��������: \t" << list[i].patronymic <<  \
			"\n���� ��������:  " << list[i].datta.day << "/" << list[i].datta.month << "/" << list[i].datta.year <<  \
			"\n����� ��������: " << list[i].phone << "\n������: \t" << list[i].adress << endl; 
// ��� ������������� �������� ����� � ����� ������ ������ ������ "\" � ������� ����� ����� ����� �� ���� ������ ���� �������. � �� �� ������		  
// �� � ������ ����������� �� ��� ������ ����� �������� � �����

namespace fenix {
	// func.cpp ����� ����� ��� �������


	void PhoneBook::contact_list(std::vector<PhoneBook>& list) { // ���� ������� ��������� � ��������� ��� ������, �� ����������� ����� ��������� ������� ���� ������ ��� ��������� � ����� :: ��� �������
		//vector<phoneBook>& list;
		list.push_back(PhoneBook({ 1, "����������", "�������", "�����������", "+7(707)526-19-00", "����� ������� 142", {9, 12, 1989} }));
		list.push_back(PhoneBook({ 1, "����������", "����", "����������",  "+7(727)634-44-50", "�������� ������� 223" , {11, 5, 1991} }));
		list.push_back(PhoneBook({ 1, "��������", "��������", "���������", "+7(707)149-10-79", "����� ������ 56", {22, 7, 1991} }));
		list.push_back(PhoneBook({ 0, "���������", "�������", "��������", "+7(777)854-55-77", "�������� ���� 136", {30, 1, 1996} }));
		list.push_back(PhoneBook({ 0, "���������", "�����", "����������", "+7(707)157-69-90", "����� ������ 44", {21, 11, 1991} }));
		list.push_back(PhoneBook({ 0, "����������", "���������", "��������", "+7(777)321-75-14", "�������� ��������� 231", {1, 7, 1989} }));
		list.push_back(PhoneBook({ 0, "����������", "�����", "���������", "+7(700)745-16-15", "����� ���������� 62", {24, 10, 1999} }));
		list.push_back(PhoneBook({ 1, "�������", "�����", "������������", "+7(702)864-12-47", "����� ������ 56", {23, 7, 1995} }));

	} // *������ ������� ������� ���������� � ���� ����� � �������� ���������� **���� ������ ���������� �� ������

	void PhoneBook::show_contacts(std::vector<PhoneBook>& list) {
		cout << "������ ���������" << endl;
		for (size_t i = 0; i < list.size(); i++) {
			templateForCout;
		}
	}


	void PhoneBook::add_contact(vector<PhoneBook>& list) {
		list.push_back(PhoneBook());
		int tmp;

		cout << "������� ��� (1 - �������, 0 - �������):  ";
		cin >> tmp; list.back().sex = tmp;
		cout << "������� ���:  ";
		cin >> list.back().name;
		cout << "������� �������:  ";
		cin >> list.back().surname;
		cout << "������� ��������:  ";
		cin >> list.back().patronymic;

		cout << "������� ���� ��������: (������ �� �� ����)" << endl;
		cout << "������� ���� ";
		cin >> tmp; list.back().datta.day = tmp;
		cout << "������� �����  ";
		cin >> tmp; list.back().datta.month = tmp;
		cout << "������� ���  ";
		cin >> tmp; list.back().datta.year = tmp;

		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ��� ������� ������
		cout << "������� ����� ��������: (������: +7(747)664-02-15)" << endl;
		getline(cin, list.back().phone);
		cout << "������� ������: (������: ����� ��������� 33)" << endl;
		getline(cin, list.back().adress);
		
	}

	void PhoneBook::del_contact(vector<PhoneBook>& list) {
	
		int id = NULL;
		printf("\n������� ������� ��� �������� ");
		//scanf_s("%d", &id);

		string surDel;
		cin >> surDel;

		for (size_t i = 0; i < list.size(); i++) {
			if (list[i].surname == surDel) {
				id = i;
				list.erase(list.begin() + (id));
				cout << "\n\n������� ������� ������\n\n";
				system("pause");
				break;
			}
			
		}
		if (id == NULL) {
			cout << "\n\n��������� ������� �� �������!\n\n";
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
			cout << "�������� ������� ���������";
		}

		contBook << "���������� ����� ";
		for (size_t i = 0; i < list.size(); i++) {
			if (list[i].sex == 0) {

				contBook << "\n\n���: \t\t" << "�������";
			}
			else if (list[i].sex == 1) {

				contBook << "\n\n���: \t\t" << "�������";
			}
			contBook << "\nAge: \t\t " << list[i].datta.age - list[i].datta.year;
			contBook << "\n�������: \t" << list[i].surname << "\n���: \t\t" << list[i].name << "\n��������: \t" << list[i].patronymic <<
				"\n���� ��������:  " << list[i].datta.day << "/" << list[i].datta.month << "/" << list[i].datta.year <<
				"\n����� ��������: " << list[i].phone << "\n������: \t" << list[i].adress << endl;
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
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ��� ������� ������
		while (contBook)
		{
			// �� ���������� ��, ��� ����� ���������, � ������, � ����� ������� ��� ������ �� �����
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
	    printf("�������� ����� \n");
	    printf("1. ����� �� ������� \n2. ����� �� ���� �������� \n3. ����� �� ����");

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
			cout << "�� ����� �������� ����� \n";
			system("Pause");
			goto Back;
		}
	}

	void PhoneBook::SexSearch(vector<PhoneBook>& list) {
		int sx = -1;
		cout << "������� ��� ������: 0 - �������, 1 - ������� \n";
		cout << "���� -> ";
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
		cout << "������� ������� ��� ������ \n";
		cout << "���� -> ";
		cin >> surSrch;

		for (size_t i = 0; i < list.size(); i++) {
			if (surSrch == list[i].surname) {
				templateForCout;
				counter++;
			}
		}
		if (counter == 0) {
			cout << "��������� ������� �� �������";
		}
	}
	void PhoneBook::DateSearch(vector<PhoneBook>& list) {
		int DateSrch;
		cout << "������� ��� �������� ��� ������ \n";
		cout << "���� -> ";
		cin >> DateSrch;

		for (size_t i = 0; i < list.size(); i++) {
			if (DateSrch == list[i].datta.year) {
				templateForCout;
			}
		}
	}


	void PhoneBook::choose_theme() {
		int choise;

		cout << "�������� ���������� �������: \n" << endl;
		cout << "1. ������ ��� � ������� ����� \n2. ����� ��� � ������� ����� \n3. ����� ��� � ����� �����" <<
			"\n4. ������� ��� � ������ ������ ����� \n5. ������� ��� � ����� ����� \n6. ������ ��� � ����� ����� ";

		cout << "\n\n���� -> ";
		cin >> choise;

		switch (choise) {
		case 1:
			cout << "\n������ ���� ��������� " << system("Color 0A") << endl;
			break;
		case 2:
			cout << "������� ���� ��������� " << system("Color 7C");
			break;
		case 3:
			cout << "����� ����� ������ ����������� " << system("Color 1F");
			break;
		case 4:
			cout << "�������� ���� ���������" << system("Color 2E");
			break;
		case 5:
			cout << "������������ ���� ���������" << system("Color 9E");
			break;
		case 6:
			cout << "������������ ���� ���������" << system("Color 0F");
			break;

		default:
			cout << "������! �� ����� �������� �����";
			break;
		}

	}

	void PhoneBook::showTime() {
		tm newtime;
		time_t long_time;

		time(&long_time);
		localtime_s(&newtime, &long_time);
		std::cout << "      ���� � �����\n";
		std::cout << "\t  " << newtime.tm_hour << ":" << newtime.tm_min << std::endl;
		std::cout << "\t" << newtime.tm_mon + 1 << "/" << newtime.tm_mday << "/" << newtime.tm_year + 1900 << std::endl;
	}

}

