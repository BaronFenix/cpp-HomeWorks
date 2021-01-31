#include "Header_big_task.h" 
//#include "func_big_task.cpp"

///////////////////////////////////////////////

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); 
    std::cout << "Hello World!\n";

    using namespace std;
    system("Color 0D");
    ///////////////////
    

    //////////////////
    std::vector<Workers> listWorkers;
    
    basicEmploeeList(listWorkers);

    int choose;
    
    back_to_menu:
    system("CLS");
    showTime();
    cout << "\n\n-*-*-*-*-*-*-*-*МЕНЮ-*-*-*-*-*-*-*-*" << "\n\n"; 
    cout << "1. Редактирование списка сотрудников \n2. Сортировка фамилий по алфавиту" << endl;
    cout << "3. Поиск сотрудника по фамилии \n4. Поиск сотрудников по возрасту" << endl;;
    cout << "5. Поиск сотрудников по первой букве фамилии \n6. Поиск сотрудников по полу" << endl;;
    cout << "7. Вывод на экран сотрудников пенсионеров  \n8. Вывод на экран списка сотрудников" << endl;;
    cout << "9. Показ дней рождения сотрудников в текущем месяце \n0. Выход" << "\n\n";
    cout << "Ввод -> ";
    cin >> choose;
    
    
    if (choose == EDIT_DATABASE) { // #1
        system("CLS");
        int choice, id;
        cout << "0. Назад в меню " << endl;
        cout << "1. Добавление сотрудника " << endl;
        cout << "2. Удаление сотрудника " << endl;
        cin >> choice;

        switch (choice) {   // #1.1
        case 1:
            addWorkers(listWorkers);
            cout << "Обновленный список сотрудников \n\n";
            viewListWorkers(listWorkers);
            system("pause");
            goto back_to_menu;
            break;

        case 2: // 1.2
            viewListWorkers(listWorkers);
            cout << "Введите индекс сотрудника для удаления его из базы";
            cin >> id;
            system("CLS");
            delete_workers(listWorkers, id);
            cout << "Обновленный список сотрудников \n\n";
            viewListWorkers(listWorkers);
            system("pause");
            goto back_to_menu;
            break;

        case 0: // 1.3
            goto back_to_menu;
            break;
        default:   // #1.4
            cout << "Ошибка! введено не верное число! вы будете возвращены к главному меню";
            system("pause");
            goto back_to_menu;
            break;
        }
    }
    else if (choose == SORT_TO_ALPHABET) { // #2
        system("CLS");
        sort_Surname_To_Alphabet(listWorkers);
        cout << "Отсортированный список сотрудников \n\n";

        viewListWorkers(listWorkers);
        system("pause");
        goto back_to_menu;
    }
    else if (choose == SEARCH_TO_SURNAME) { // #3
        system("CLS");
        cout << "Введите фамилию для поиска -> ";
        string SearchSure;
        cin >> SearchSure;
        
        SearchToSurname(listWorkers, SearchSure);
        cout << "\n\n";
        system("pause");
        goto back_to_menu;

    }
    else if (choose == SEARCH_TO_AGE) { // #4
        system("CLS");
        cout << "Введите возраст для поиска сотрудников -> ";
        int SearchAge;
        cin >> SearchAge;

        SearchToAge(listWorkers, SearchAge);
        cout << "\n\n";
        system("pause");
        goto back_to_menu;
    }
    else if (choose == SEARCH_SURNAME_TOFIRST_LETT) { // #5
        system("CLS");
        cout << "Введите первую букву фамилии для поиска сотрудников -> ";
        char SearchLetter;
        cin >> SearchLetter;

        SearchSurnameToFirstLett(listWorkers, SearchLetter);
        system("pause");
        goto back_to_menu;
    }
    else if (choose == SEARCH_TO_SEXXX) { // #6
        system("CLS");
        string SearchSex = " ";

        while (SearchSex != "male" && SearchSex != "female") {
            cout << "Введите \"male\" для поиска мужчин или \"female\" для поиска женщин -> ";
            cin >> SearchSex;
            system("CLS");
        }
        
        SearchToSex(listWorkers, SearchSex);
        system("pause");
        goto back_to_menu;
    }
    else if (choose == SEARCH_OLD_MAN) { // #7
        system("CLS");
        ViewPensioners(listWorkers);

        system("pause");
        goto back_to_menu;
    }
    else if (choose == SHOW_WORKERS_LIST) { // #8
        system("CLS");
        viewListWorkers(listWorkers);

        system("pause");
        goto back_to_menu;
    }
    else if (choose == SHOW_BIRTHSDAY_DAY) { // #9
        system("CLS");
        
        ViewBirthdate(listWorkers);
        

        system("pause");
        goto back_to_menu;
    }
    else if (choose == EX1T) { // #9
        return 0;
    }
    else if (choose <= -1 || choose >= 10) {

    goto back_to_menu;
    }
  


    return 0;
}

