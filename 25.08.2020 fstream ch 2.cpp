
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <chrono>


namespace aviato {
    using namespace std; // хыы ее величество лень
    
    class date {
    public:
        int day;
        int month;
        int year;
    };

    class aviaTicket { // мда походу из за того что изначально была структура а не класс были проблемы
    //public:
    private:
        string TickIndex[25];
        string destination_from;
        string dedtination_to;
        string name;
        string surname;
        int age;
        double timeStart;
        double timeFinish;
        
        date DateStart;
        date DateFinish;

    public:         
        aviaTicket() { // string TickInd,string destFrom, string destTo, string inpName, string inpSurname, int inpAge, double timeS, double timeF, date DateST, date DateFN
            TickIndex[24] = "024DGH45613YT5R43EE2124";             // а ведь тут было это... оставлю на память
            destination_from = "Rome";
            dedtination_to = "Berlin";
            name = "Roberto";
            surname = "Baldinini";
            age = 38;
            timeStart = 10.45;
            timeFinish = 13.30;
            DateStart = {27, 9, 2020};
            DateFinish = {27, 9, 2020};
        }
      //  aviaTicket() { // конструктор по умолчанию. // все больше вроде не требуют его
        //}
        void print(aviato::aviaTicket &NewTicket);
        void createTicket(aviato::aviaTicket &NewTicket);

        string getTickID() { return TickIndex[24]; };
        string getDestFrom() { return destination_from; };
        string getDestTo() { return dedtination_to; };
        string getName() { return name; };
        string getSurname() { return surname; };
        int getAge() { return age; };
        double getTimeST() { return timeStart; };
        double getTimeFN() { return timeFinish; };
        
        //int getDateStart() { return DateStart.day, DateStart.month, DateStart.year; }; //
        // void getDateFinish() { printf("%d/%d/%d", DateFinish.day, DateFinish.month, DateFinish.year); }; 
        
        // ну в общем то почитал малеха про этот конструктор и как понял он используется для инициализации приватных переменных ну и вот решил по баловатся хыыы     
        // все набаловался, эти функции не робят // upd. а теперь норм сожет потому что изначально был struct а не class
    };

    void aviaTicket::createTicket(aviato::aviaTicket &NewTicket) {
 
        //char numbTick[24];
        //numbTick = ('A' + rand() % ('A' - 'Z') && 1 + rand() % 100);
        //string destTo, destFrom, name, surname;
        //int age, day_ST, month_ST, year_ST, day_FN, month_FN, year_FN;
        //double timeST, timeFN;

        cout << "Заполните информацию о пассажире" << endl;
        cout << "Введите имя" << endl;
        cin >> name;
        cout << "Введите фамилию" << endl;
        cin >> surname;
        cout << "Введите возраст" << endl;
        cin >> age;
        
        cout << "\nЗаполните данные билета" << endl;
        cout << "Введите место вылета" << endl;
        cin >> destination_from;              // хмм интерееесно эта функция видит переменные структуры...   обнаружил я прочитав очередной пример на сайте
        cout << "Введите место назначения" << endl;
        cin >> dedtination_to;


        cout << "Введите Дату вылета (Пример 26 9 2020)" << endl;
        cin >> DateStart.day >> DateStart.month >> DateStart.year;
        cout << "Введите время вылета (Пример 14.30)" << endl;
        cin >> timeStart;

        cout << "Введите Дату прилета (Пример 26 9 2020)" << endl;
        cin >> DateFinish.day >> DateFinish.month >> DateFinish.year;
        cout << "Введите время посадки (Пример 14.30)" << endl;
        cin >> timeFinish;
        
        for (int i = 0; i < 24; i++) {
           TickIndex[i] = ('A' + rand() % ('A' - 'Z') && 1 + rand() % 100);
        }

        //aviaTicket NewTicket(TickIndex, destination_from, dedtination_to, name, surname, age, timeStart, timeFinish, { DateStart.day, DateStart.month, DateStart.year }, { DateFinish.day, DateFinish.month, DateFinish.year });
    } // ну та емае забыл фигурные скобки для структур вложенных и не мог понять шо не так. и уже думал что вся эта функция зря написана
    
    void aviaTicket::print(aviato::aviaTicket &NewTicket) {

        fstream tictak("ticket.txt", ios::in | ios::out);

        if (!tictak) {
            cout << "error";
            exit(1);
        }
        else {
            cout << "\nБилет распечатан";
        }

        tictak << "\t\t\t Авиакомпания structAir \n";   // стоп блен а так можно было? хмм типа из за того что я все это обьявил в паблике при инициализации? *Задумчивый смайл*
        tictak << "\t\tДата вылета: " << NewTicket.DateStart.day << "/" << NewTicket.DateStart.month << "/" << NewTicket.DateStart.year << "    ";
        tictak << "Дата прилета: " << NewTicket.DateFinish.day << "/" << NewTicket.DateFinish.month << "/" << NewTicket.DateFinish.year << "\n";
        tictak << "\t\tрейс " << NewTicket.getDestFrom() << " -> " << NewTicket.getDestTo() << "\n";
        tictak << "\t\tВремя вылета: " << NewTicket.getTimeST() << "\tВремя прилета: " << NewTicket.getTimeFN() << "\n";
        
        tictak << "\n\t\t\tИнформация о пассажире \n";
        tictak << "\t\tИмя " << NewTicket.getName() << "   Фамилия " <<NewTicket.getSurname() << "   Возраст " << NewTicket.getAge() << "\n";
        tictak << "\t\t\tНомер билета:  " << NewTicket.getTickID();
        tictak.close();
    } // ладно это было долго, это было мучительно, но вроде вышло. а теперь можно и телефонной книжкой занятся с этим опытом

}
int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    using namespace std;
    srand(time(0));

    ////////////////////////////////////////////
    string citys[10] = { "рим", "париж", "мадрид", "берлин", "москва", "лондон", "хельсинги", "рио-де-жанейро", "гавана", "антананариву" };
    // ios::in | ios::out
    fstream city("city.txt", ios::in | ios::out); // ofstream запись \ ios::app запись в конец документа

    if (!city) {
        cout << "Error";
        exit(1);
    }
    else {
        cout << "Файл с городами успешно загружен";
    }

    for (ptrdiff_t i = 0; i < 10; i++) {
        city << citys[i] << '\n';
    }
    city << "\nВсего хорошего! Жалкие людишки >:O \n";
    city.close();

    // №3. подсчет символов в файле
    //fstream city("city.txt", ios::out);
    city.open("city.txt");
    int count = 0;
    char symb;
    while (city.get(symb)) {
        count++;
    }

    printf("\n\nВ файле найдено %d символов", count);
    city.close();

    ////////////////////////////////////////
    // #4 Предъявите билетик пожалуйста
    //aviato::aviaTicket newTicket; // агаа не работаешь сабака.. ну и хрен с тобой создам функцию без аргументов или как их там величать

   
                                                            // фууух робит а значит моя функция не пропадет зря
    //aviato::aviaTicket newTicket("214YT57FG8E468HTJJ7842S1", "ALM", "ASN", "Richard", "Osborne", 34, 12.45, 16.15, { 12, 9, 2020 }, { 13, 9, 2020 });
    aviato::aviaTicket newTicket;

    newTicket.createTicket(newTicket);

    newTicket.print(newTicket);
}
