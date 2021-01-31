#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <algorithm>
#include <chrono>

struct Date_birthsday {
    int day;
    int month;
    int year;
};

struct Workers {
    std::string name;
    std::string surname;
    std::string sex;
    int age;

    Date_birthsday birthDate;
};

enum MENU {
    EDIT_DATABASE = 1,
    SORT_TO_ALPHABET = 2,
    SEARCH_TO_SURNAME = 3,
    SEARCH_TO_AGE = 4,
    SEARCH_SURNAME_TOFIRST_LETT = 5,
    SHOW_BIRTHSDAY_DAY = 9,
    SHOW_WORKERS_LIST = 8,
    SEARCH_TO_SEXXX = 6,
    SEARCH_OLD_MAN = 7,
    EX1T = 0
};

void basicEmploeeList(std::vector<Workers>& listWorkers) {

    listWorkers.push_back(Workers({ "lora", "loreyn", "female", 26, { 24, 6, 1994 } }));
    listWorkers.push_back(Workers({ "john", "smith", "male", 34, { 13, 2, 1986 } }));
    listWorkers.push_back(Workers({ "katerin", "kylie", "female", 53, { 30, 5, 1967  } }));
    listWorkers.push_back(Workers({ "alister", "jonson", "male", 64, { 11, 8, 1956 } }));
    listWorkers.push_back(Workers({ "joudy", "lilith", "female", 56, { 22, 7, 1964  } }));
    listWorkers.push_back(Workers({ "asumi", "misa", "female", 22, { 8, 4, 1998 } }));
    listWorkers.push_back(Workers({ "lee", "tong", "male", 71, { 28, 11, 1949 } }));
    listWorkers.push_back(Workers({ "steve", "cook", "male", 34, { 8, 4, 1986 } }));
}

void viewListWorkers(std::vector<Workers> listWorkers) {
    for (int i = 0; i < listWorkers.size(); i++) {
        std::cout <<"Сотрудник " << i + 1 << "\nИмя:\t\t" << listWorkers[i].name << "\nФамилия:\t" << listWorkers[i].surname << "\nПол:\t\t" << listWorkers[i].sex <<
            "\nВозраст:\t" << listWorkers[i].age << "\nДата рождения:\t" << listWorkers[i].birthDate.day << "/" << listWorkers[i].birthDate.month <<
            "/" << listWorkers[i].birthDate.year << "\n\n";
    }
}

void addWorkers(std::vector<Workers>& AddToList) {
    using namespace std;
    AddToList.push_back(Workers());

    cout << "Заполните данные сотрудника" << endl;
    cout << "Имя " << endl;
    cin >> AddToList.back().name;
    cout << "Фамилия " << endl;
    cin >> AddToList.back().surname;
    cout << "Пол (Введите male / female)" << endl;
    cin >> AddToList.back().sex;
    cout << "Возраст" << endl;
    cin >> AddToList.back().age;
    cout << "Дата рождения: день, месяц, год\n" << endl;
    cin >> AddToList.back().birthDate.day >> AddToList.back().birthDate.month >> AddToList.back().birthDate.year;
}

void delete_workers(std::vector<Workers>& ListWorkers, int id) {
    ListWorkers.erase(ListWorkers.begin() + (id - 1));
}

bool BoolSort(Workers alpha, Workers beta) {
    return beta.surname > alpha.surname;
}
void sort_Surname_To_Alphabet(std::vector<Workers>& ListWorkers) {
    sort(ListWorkers.begin(), ListWorkers.end(), BoolSort);
}

void SearchToSurname(std::vector<Workers>& ListWorkers, std::string surnameSRC) {
    int id;
    for (int i = 0; i < ListWorkers.size(); i++) {
        if (ListWorkers[i].surname == surnameSRC) {
            id = i;
            std::cout << "Сотрудник " << id + 1 << "\nИмя:\t\t" << ListWorkers[id].name << "\nФамилия:\t" << ListWorkers[id].surname << "\nПол:\t\t" << ListWorkers[id].sex <<
                "\nВозраст:\t" << ListWorkers[id].age << "\nДата рождения:\t" << ListWorkers[id].birthDate.day << "/" << ListWorkers[id].birthDate.month <<
                "/" << ListWorkers[id].birthDate.year << "\n\n";
        }
        else {
            std::cout << "\nВведеная вами фамилия не найдена ";
            break;
        }
    }
}

void SearchToAge(std::vector<Workers>& ListWorkers, int ageSRC) {
    int id = -1;
    for (int i = 0; i < ListWorkers.size(); i++) {      
         if (ListWorkers[i].age == ageSRC) {
            id = i;
            std::cout << "Сотрудник " << i + 1 << "\nИмя:\t\t" << ListWorkers[id].name << "\nФамилия:\t" << ListWorkers[id].surname << "\nПол:\t\t" << ListWorkers[id].sex <<
                "\nВозраст:\t" << ListWorkers[id].age << "\nДата рождения:\t" << ListWorkers[id].birthDate.day << "/" << ListWorkers[id].birthDate.month <<
                "/" << ListWorkers[id].birthDate.year << "\n\n";
         }
         if (i == ListWorkers.size() -1 && id == -1) {
             std::cout << "\nСотрудников введенного вами возраста не найдено\n\n";
             //break;
         }        
    }
}

void SearchSurnameToFirstLett(std::vector<Workers>& ListWorkers, char letterSRC) {
    int id = -1;
    for (int i = 0; i < ListWorkers.size(); i++) {
        if (ListWorkers[i].surname[0] == letterSRC) {
            id = i;
            std::cout << "Сотрудник " << i + 1 << "\nИмя:\t\t" << ListWorkers[id].name << "\nФамилия:\t" << ListWorkers[id].surname << "\nПол:\t\t" << ListWorkers[id].sex <<
                "\nВозраст:\t" << ListWorkers[id].age << "\nДата рождения:\t" << ListWorkers[id].birthDate.day << "/" << ListWorkers[id].birthDate.month <<
                "/" << ListWorkers[id].birthDate.year << "\n\n";
        }
        if (i == ListWorkers.size() - 1 && id == -1) {
            std::cout << "\nСотрудников с фамилией на букву \"" << letterSRC << "\" не найдено\n\n";
        }

    }
}

void SearchToSex(std::vector<Workers>& ListWorkers, std::string SexXx) {
    int id = -1;
    for (int i = 0; i < ListWorkers.size(); i++) {
        if (ListWorkers[i].sex == SexXx) {
            id = i;
            std::cout << "Сотрудник " << i + 1 << "\nИмя:\t\t" << ListWorkers[id].name << "\nФамилия:\t" << ListWorkers[id].surname << "\nПол:\t\t" << ListWorkers[id].sex <<
                "\nВозраст:\t" << ListWorkers[id].age << "\nДата рождения:\t" << ListWorkers[id].birthDate.day << "/" << ListWorkers[id].birthDate.month <<
                "/" << ListWorkers[id].birthDate.year << "\n\n";
        }
        
    }
}

void ViewPensioners(std::vector<Workers>& ListWorkers) {
    int id;
    for (int i = 0; i < ListWorkers.size(); i++) {
        if (ListWorkers[i].age >= 60 && ListWorkers[i].sex == "male") {
            id = i;
            std::cout << "Сотрудник " << i + 1 << "\nИмя:\t\t" << ListWorkers[id].name << "\nФамилия:\t" << ListWorkers[id].surname << "\nПол:\t\t" << ListWorkers[id].sex <<
                "\nВозраст:\t" << ListWorkers[id].age << "\nДата рождения:\t" << ListWorkers[id].birthDate.day << "/" << ListWorkers[id].birthDate.month <<
                "/" << ListWorkers[id].birthDate.year << "\n\n";
        }
        if (ListWorkers[i].sex == "female" && ListWorkers[i].age >= 55) {
            id = i;
            std::cout << "Сотрудник " << i + 1 << "\nИмя:\t\t" << ListWorkers[id].name << "\nФамилия:\t" << ListWorkers[id].surname << "\nПол:\t\t" << ListWorkers[id].sex <<
                "\nВозраст:\t" << ListWorkers[id].age << "\nДата рождения:\t" << ListWorkers[id].birthDate.day << "/" << ListWorkers[id].birthDate.month <<
                "/" << ListWorkers[id].birthDate.year << "\n\n";
        }
    }
}

void ViewBirthdate(std::vector<Workers>& ListWorkers) {
    int id;
    tm newtime;
    time_t long_time;

    time(&long_time);
    localtime_s(&newtime, &long_time);

    for (int i = 0; i < ListWorkers.size(); i++) {
        if (ListWorkers[i].birthDate.month == newtime.tm_mon + 1) {
            id = i;
            std::cout << "Сотрудник " << i + 1 << "\nИмя:\t\t" << ListWorkers[id].name << "\nФамилия:\t" << ListWorkers[id].surname << "\nПол:\t\t" << ListWorkers[id].sex <<
                "\nВозраст:\t" << ListWorkers[id].age << "\nДата рождения:\t" << ListWorkers[id].birthDate.day << "/" << ListWorkers[id].birthDate.month <<
                "/" << ListWorkers[id].birthDate.year << "\n\n";
        }
    }
}

void showTime() {
    tm newtime;
    time_t long_time;

    time(&long_time);
    localtime_s(&newtime, &long_time);
    std::cout << "      Дата и время\n";
    std::cout << "\t  " << newtime.tm_hour << ":" << newtime.tm_min << std::endl;
    std::cout << "\t" << newtime.tm_mon + 1 << "/" << newtime.tm_mday << "/" << newtime.tm_year + 1900 << std::endl;
}