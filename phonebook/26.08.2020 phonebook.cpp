
#include <iostream>
#include "funcBook.h" 
#include <windows.h>

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    using namespace std;
 

    vector<fenix::PhoneBook> list;

    fenix::PhoneBook www;

    www.contact_list(list);

BackToMenu: // точка возврата goto для нашей менюшки
    system("CLS");
    int choose;

    www.showTime();
    printf("1. Просмотреть все контакты \n2. Поиск контакта \n3. Сортировать контакты А-Я \n4. Выбор темы \n");
    printf("5. Добавить контакт \n6. Удалить контакт \n7. Вывод в консоль данных из txt файла \n8. Загрузка контактов в txt файл \n0. Выход \n");
    printf("Ввод -> ");
    scanf_s("%d", &choose);

    switch (choose) {
        using namespace fenix;

    case MENU_SHOW_LIST:
        system("cls");
        
        www.show_contacts(list);
        system("pause");
        goto BackToMenu;
        break;

    case MENU_SEARCH:
        system("cls");
        www.chooseSearch(list);

        system("pause");
        goto BackToMenu;
        break;

    case MENU_SORT:
        system("cls");

        www.SurSortUp(list);
        www.show_contacts(list);

        printf("Контакты отсортированы по фамилиям");

        system("pause");
        goto BackToMenu;
        break;

    case MENU_THEME:
        system("cls");
        www.choose_theme();

        system("pause");
        goto BackToMenu;
        break;

    case MENU_ADD:
        system("cls");
        www.add_contact(list);
        printf("\n\nКонтакт успешно добавлен! \n");

        system("pause");
        goto BackToMenu;
        break;

    case MENU_DELETE:
        system("cls");

        www.del_contact(list);
        system("pause");
        goto BackToMenu;
        break;

    case MENU_UPLOAD_TXT:
        system("cls");
        www.upload_to_txt(list);

        system("pause");
        goto BackToMenu;
        break;

    case MENU_COUT_TXT:
        system("cls");
        www.coutFromTxt();

        system("pause");
        goto BackToMenu;
        break;

    case MENU_EXIT:
        system("cls");

        system("pause");
        goto BackToMenu;
        break;
    default:
        system("cls");

        goto BackToMenu;
        break;
    }

    ////////
    return 0;
}

