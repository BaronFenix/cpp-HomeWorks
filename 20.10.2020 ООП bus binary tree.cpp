
#include <iostream>
#include <string>
#include <fstream>

namespace fenix {
    using namespace std;

    class buSinesTree {
    private:
        class knot {
        public:
            string name;
            string surname;
            int BusNumber;
            int routeNumber;
            int passengers;
            knot* leftPtr;
            knot* rightPtr;

            knot(string name = string(), string surname = string(), int busNum = int(), int route = int(), int pass = int(), knot* left = nullptr, knot* right = nullptr) {
                this->name = name;
                this->surname = surname;
                this->BusNumber = busNum;
                this->routeNumber = route;
                this->passengers = pass;
                this->leftPtr = left;
                this->rightPtr = right;
            }
        };

        knot* root;
        int size;
        int key;
    public:

        buSinesTree();
        void add(string name, string surname, int busNum, int route, int pass);
        void search(int busNum);
        void uploadToTXT();
        knot* getRoot() { return this->root; }
        void recursivePrint(knot* rudy);
        void showTree();

    };

    buSinesTree::buSinesTree() {
        root = nullptr;
        size = 0;
        key = 0;
    }

    void buSinesTree::add(string name, string surname, int busNum, int route, int pass) {
        if (size == 0) {
            root = new knot(name, surname, busNum, route, pass);
            size++;
        }
        else if (size == 1) {
            if (busNum < root->BusNumber) {
                root->leftPtr = new knot(name, surname, busNum, route, pass);
                size++;
            }
            else if (busNum > root->BusNumber) {
                root->rightPtr = new knot(name, surname, busNum, route, pass);
                size++;
            }
            else if (busNum == root->BusNumber) {
                cerr << "Ошибка! в массиве уже имеется такой номер маршрута" << endl;
                return;
            }
        }
        else {
            knot* end = root;
            while (true) {
                if (busNum < end->BusNumber) {
                    if (end->leftPtr == nullptr) {
                        end->leftPtr = new knot(name, surname, busNum, route, pass);
                        break;
                    }
                    else {
                        end = end->leftPtr;
                    }
                }
                else if (busNum > end->BusNumber) {
                    if (end->rightPtr == nullptr) {
                        end->rightPtr = new knot(name, surname, busNum, route, pass);
                        break;
                    }
                    else {
                        end = end->rightPtr;
                    }
                }
                else if (busNum == end->BusNumber) {
                    cerr << "Ошибка! в массиве уже имеется такой номер маршрута" << endl;
                    break;
                }
            }
            size++;
        }
    }

    void buSinesTree::search(int busNum) {
        knot* it = root;

        while (it != nullptr) {

            if (it->BusNumber == busNum) {
                cout << "Имя водителя: \t\t" << it->name << "\nФамилия Водителя: \t" << it->surname << endl;
                cout << "Номер автобуса: \t" << it->BusNumber << "\nНомер маршрута \t\t" << it->routeNumber << endl;
                cout << "Пассажирских мест: \t" << it->passengers << endl;
                return;
            }
            else if (it->BusNumber > busNum) {
                it = it->leftPtr;
            }
            else if (it->BusNumber < busNum) {
                it = it->rightPtr;
            }

        }

        cout << "Автобус с " << busNum << " номером маршрута не найден" << endl;
    }

    void buSinesTree::uploadToTXT() {
        fstream busyBus("AutoPark.txt", ios::in | ios::out);

        if (!busyBus) {
            cerr << "Произошла ошибка загрузки" << endl;
            exit(228);
        }
        else {
            cout << "Данные о автобусах успешно загружены" << endl;
        }
        knot* it = root;
        // вывод корня списка
        busyBus << "Имя водителя: \t\t" << it->name << "\nФамилия Водителя: \t" << it->surname << "\n";
        busyBus << "Номер автобуса: \t" << it->BusNumber << "\nНомер маршрута \t\t" << it->routeNumber << "\n";
        busyBus << "Пассажирских мест: \t" << it->passengers << "\n\n";
        for (size_t i = 0; i < size; i++) {
 
            // первый цикл. элементы leftptr
            if (it->leftPtr != nullptr) {
                it = it->leftPtr;
                busyBus << "Имя водителя: \t\t" << it->name << "\nФамилия Водителя: \t" << it->surname << "\n";
                busyBus << "Номер автобуса: \t" << it->BusNumber << "\nНомер маршрута \t\t" << it->routeNumber << "\n";
                busyBus << "Пассажирских мест: \t" << it->passengers << "\n\n";
                i--;
            }
            else {
                if (it->leftPtr != nullptr) {
                    it = it->leftPtr;
                    busyBus << "Имя водителя: \t\t" << it->name << "\nФамилия Водителя: \t" << it->surname << "\n";
                    busyBus << "Номер автобуса: \t" << it->BusNumber << "\nНомер маршрута \t\t" << it->routeNumber << "\n";
                    busyBus << "Пассажирских мест: \t" << it->passengers << "\n\n";
                    i--;
                }
                if (it->rightPtr != nullptr) {
                    it = it->rightPtr;
                    busyBus << "Имя водителя: \t\t" << it->name << "\nФамилия Водителя: \t" << it->surname << "\n";
                    busyBus << "Номер автобуса: \t" << it->BusNumber << "\nНомер маршрута \t\t" << it->routeNumber << "\n";
                    busyBus << "Пассажирских мест: \t" << it->passengers << "\n\n";
                    i--;
                }
            }
         // даже незнаю какое из двух зол меньшее вывод рекурсией с передачей корня или огромный двойной цикл... 
        }
        knot* two = root;                      //второй цикл. элементы rightPtr
        for (size_t j = 0; j < size; j++) {
            if (two->rightPtr != nullptr) {
                two = two->rightPtr;
                busyBus << "Имя водителя: \t\t" << two->name << "\nФамилия Водителя: \t" << two->surname << "\n";
                busyBus << "Номер автобуса: \t" << two->BusNumber << "\nНомер маршрута \t\t" << two->routeNumber << "\n";
                busyBus << "Пассажирских мест: \t" << two->passengers << "\n\n";
                j--;
            }
            else {
                if (two->rightPtr != nullptr) {
                    two = two->rightPtr;
                    busyBus << "Имя водителя: \t\t" << two->name << "\nФамилия Водителя: \t" << two->surname << "\n";
                    busyBus << "Номер автобуса: \t" << two->BusNumber << "\nНомер маршрута \t\t" << two->routeNumber << "\n";
                    busyBus << "Пассажирских мест: \t" << two->passengers << "\n\n";
                    j--;
                }
                if (two->leftPtr != nullptr) {
                    two = two->leftPtr;
                    busyBus << "Имя водителя: \t\t" << two->name << "\nФамилия Водителя: \t" << two->surname << "\n";
                    busyBus << "Номер автобуса: \t" << two->BusNumber << "\nНомер маршрута \t\t" << two->routeNumber << "\n";
                    busyBus << "Пассажирских мест: \t" << two->passengers << "\n\n";
                    j--;
                }
            }
        }
        busyBus.close();
    }

    void buSinesTree::showTree() {
        knot* it = root;
        knot* two = root;
        for (size_t i = 0; i < size; i++) {
            if (i == 0) { // вывод корня
                cout << "Имя водителя: \t\t" << root->name << "\nФамилия Водителя: \t" << root->surname << "\n";
                cout << "Номер автобуса: \t" << root->BusNumber << "\nНомер маршрута \t\t" << root->routeNumber << "\n";
                cout << "Пассажирских мест: \t" << root->passengers << "\n\n";
            }
            // первый цикл. элементы leftptr
            for (size_t j = 0; j < size; j++) {
                if (it->leftPtr != nullptr) {
                    it = it->leftPtr;
                    cout << "Имя водителя: \t\t" << it->name << "\nФамилия Водителя: \t" << it->surname << "\n";
                    cout << "Номер автобуса: \t" << it->BusNumber << "\nНомер маршрута \t\t" << it->routeNumber << "\n";
                    cout << "Пассажирских мест: \t" << it->passengers << "\n\n";
                    i--;
                }
                else {
                    if (it->leftPtr != nullptr) {
                        it = it->leftPtr;
                        cout << "Имя водителя: \t\t" << it->name << "\nФамилия Водителя: \t" << it->surname << "\n";
                        cout << "Номер автобуса: \t" << it->BusNumber << "\nНомер маршрута \t\t" << it->routeNumber << "\n";
                        cout << "Пассажирских мест: \t" << it->passengers << "\n\n";
                        i--;
                    }
                    if (it->rightPtr != nullptr) {
                        it = it->rightPtr;
                        cout << "Имя водителя: \t\t" << it->name << "\nФамилия Водителя: \t" << it->surname << "\n";
                        cout << "Номер автобуса: \t" << it->BusNumber << "\nНомер маршрута \t\t" << it->routeNumber << "\n";
                        cout << "Пассажирских мест: \t" << it->passengers << "\n\n";
                        i--;
                    }

                }
                ///второй цикл. элементы rightPtr
                if (two->rightPtr != nullptr) {
                    two = two->rightPtr;
                    cout << "Имя водителя: \t\t" << two->name << "\nФамилия Водителя: \t" << two->surname << "\n";
                    cout << "Номер автобуса: \t" << two->BusNumber << "\nНомер маршрута \t\t" << two->routeNumber << "\n";
                    cout << "Пассажирских мест: \t" << two->passengers << "\n\n";
                    j--;
                }
                else {
                    if (two->rightPtr != nullptr) {
                        two = two->rightPtr;
                        cout << "Имя водителя: \t\t" << two->name << "\nФамилия Водителя: \t" << two->surname << "\n";
                        cout << "Номер автобуса: \t" << two->BusNumber << "\nНомер маршрута \t\t" << two->routeNumber << "\n";
                        cout << "Пассажирских мест: \t" << two->passengers << "\n\n";
                        j--;
                    }
                    if (two->leftPtr != nullptr) {
                        two = two->leftPtr;
                        cout << "Имя водителя: \t\t" << two->name << "\nФамилия Водителя: \t" << two->surname << "\n";
                        cout << "Номер автобуса: \t" << two->BusNumber << "\nНомер маршрута \t\t" << two->routeNumber << "\n";
                        cout << "Пассажирских мест: \t" << two->passengers << "\n\n";
                        j--;
                    }

                }
            }
        }
        // мда, вышло кое как методом проб и ошибок. а теперь надо реализовать в виде рекурсии дабы сократить код
         // который я по сути с рекурсивных функций и списывал)
    }

    void buSinesTree::recursivePrint(knot* rudy) {
        //knot* rudy = root;
        if (rudy == NULL) { return; }

       
        cout << "Имя водителя: \t\t" << rudy->name << "\nФамилия Водителя: \t" << rudy->surname << "\n";
        cout << "Номер автобуса: \t" << rudy->BusNumber << "\nНомер маршрута \t\t" << rudy->routeNumber << "\n";
        cout << "Пассажирских мест: \t" << rudy->passengers << "\n\n";

        recursivePrint(rudy->rightPtr);
        recursivePrint(rudy->leftPtr);

    } // не ну без передачи рута в функции это просто анрил сделать.
         // ибо руди должен все время менятся а без передачи рута или дублирования сиаутов не выйдет




} // namespace fenix

int main()
{
    setlocale(LC_ALL, "RUS");
    using namespace std;
    system("color 0D");

    fenix::buSinesTree splinter;

    splinter.add("Василий", "Пупкин", 78, 21554, 48);
    splinter.add("Роман", "валентинов", 63, 15164, 52);
    splinter.add("Big", "smoke", 82, 45735, 55);
    splinter.add("Аркадий", "Паровозов", 32, 45785, 38);
    splinter.add("Жанибек", "Тракторбеков", 119, 12045, 62);
    splinter.add("Акакий", "Акакиевич", 56, 98750, 52);
    splinter.add("Акинакий", "ямахатович", 59, 00545, 52);


    int choose;
    do {
        cout << "1. Добавить узел. \n2. Поиск по номеру маршрута " << endl;
        cout << "3. Загрузить информацию об автобусах в TXT \n4. вывод дерева в хронологическом порядке" << endl;
        cout << "5. Рекурсивный вывод дерева \n0. Выход" << endl;
        cin >> choose;

        if (choose == 1) {
            system("cls");
            string name, surname;
            int busNum, route, passengers;

            cout << "Введите имя водителя" << endl;
            cin >> name;
            cout << "Введите фамилию водителя" << endl;
            cin >> surname;
            cout << "Введите 5 значный номер автобуса (пример 12455)" << endl;
            cin >> busNum;
            cout << "введите номер маршрута" << endl;
            cin >> route;
            cout << "Введите количество пассажирских мест автобуса" << endl;
            cin >> passengers;

            splinter.add(name, surname, busNum, route, passengers);
            system("pause");
        }
        else if (choose == 2) {
            system("cls");
            int key;
            cout << "Введите номер маршрута автобуса для поиска и вывода информации о нем" << endl;
            cin >> key;
            splinter.search(key);
            system("pause");
        }
        else if (choose == 3) {
            system("cls");
            splinter.uploadToTXT();
            system("pause");
        }
        else if (choose == 4) {
            system("cls");
            splinter.showTree();
            system("pause");
        }
        else if (choose == 5) {
            system("cls");
            splinter.recursivePrint(splinter.getRoot());
            system("pause");
        }
        else if (choose == 0) {
            system("cls");
            system("pause");
            break;
        }
        else {
            system("cls");
        }
        
        
        system("cls");
    } while (choose != 0);


    return 0;
}

