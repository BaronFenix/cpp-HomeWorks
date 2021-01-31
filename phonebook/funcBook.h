#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <chrono>
#include<ios>
#include<limits> //used to get numeric limits

// header.h

namespace fenix {
	using namespace std;

	enum MENU {
		MENU_SHOW_LIST = 1,
		MENU_ADD = 5,
		MENU_DELETE = 6,
		MENU_SEARCH =2,
		MENU_SORT = 3,
		MENU_THEME = 4,
		MENU_UPLOAD_TXT = 8,
		MENU_COUT_TXT = 7,
		MENU_EXIT = 0

	};

	class PhoneBook{ 
	public:
		
		struct Date {
			unsigned day : 6; 
			unsigned month : 6;
			unsigned year : 16;
			unsigned age = 2020;
		};

		unsigned short sex : 1;
		string surname;
		string name;
		string patronymic;
		string phone;
		string adress;
			
		Date datta;
		

		void contact_list(std::vector<PhoneBook>& list);
		void show_contacts(std::vector<PhoneBook>& list);
		void add_contact(std::vector<PhoneBook>& list);
		void del_contact(std::vector<PhoneBook>& list);
		//void sort_contact(std::vector<phoneBook>& list);
		//void search_contact(std::vector<phoneBook>& list);
		void surnameSearch(vector<PhoneBook>& list);
		void SexSearch(vector<PhoneBook>& list);
		void choose_theme();
		void showTime();
		void coutFromTxt();
		void chooseSearch(vector<PhoneBook>& list);
		void upload_to_txt(vector<PhoneBook>& list);
		void SurSortUp(vector<PhoneBook>& list);
		void DateSearch(vector<PhoneBook>& list);
	};


}


