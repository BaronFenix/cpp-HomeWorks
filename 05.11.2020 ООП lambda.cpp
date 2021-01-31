
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <functional>

namespace fenix {
	using namespace std;


	class earth { //: public country
	private:
		class country {
		public:
			std::string countryName;
			std::vector<string> city;
			country() {}
			country(string cntr) : countryName(cntr) {}

			country setCity(int id, string newCity) {
				city[id] = newCity;
				return *this;
			}
			int getCity() {
				return city.size();
			}
			void showCity() {
				for (size_t i = 0; i < city.size(); i++) {
					cout << i+1 << city[i] << endl;
				}
			}

		};

		//std::string country;
		std::vector<country> strana;

	public:

		void inputFile() {
			fstream world("country.txt", ios::in | ios::out);
			try {
				if (!world.is_open()) {
					throw 505;
				}
				else {
					char symbol;
					//string tmpStr; // о по кайфу, минус переменная. крч она нужна была для сбора целого слова но чару 
					string temp;
					int i = 0;
					while (world.get(symbol)) {

						if (symbol == ':') {
							getline(world, temp);
							strana.push_back(temp);
							temp.clear();
							continue;
						}
						if (isdigit(symbol)) {
							world.get(symbol); // скипну ка я эту точку. а пробел так и быть пусть живет
							getline(world, temp);   // хмм а зачем здесь собирать город по буковке если можно также использовать getline? *Задумчиво чешет подбородок*
							strana[i].city.push_back(temp);
							temp.clear();
							if (symbol == ',') {
								continue;
							}
						}
						if (symbol == ';') {
							i++;
							continue;
						}
						// tmpStr.push_back(symbol); //ачо всмысле? она здесь не нужна?
						        // пы.сы. и на эту дичь я угробил как минимум два часа пока не понял что без хитростей в виде знаков перед словом тут не обойтись 
					} // while
				}
			}
			catch (int err) {
				cout << "Произошла ошибка: " << err << " при открытии файла" << endl;
			}
		}

		void searchCity() {
			BACK:
			cout << "Выберите действие " << endl;
			cout << "1. Поиск города \n2. Поиск и замена города" << endl;
			int choice;
			string error;
			try{
				cin >> choice;
				if (choice == 1 || choice == 2) { } // ибо им не понравилось !=
				else {
					throw error = "необходимо ввести 1 или 2";
				}
			}
			catch (string f) {
				cout << "Ошибка ввода: " << f << endl;
				goto BACK;
			}
			
			cout << "Выберите страну в которой хотите найти город" << endl;
			for (size_t j = 0; j < strana.size(); j++) {
				cout << j + 1 << ". " << strana[j].countryName << endl;
			}
			int countryID;
			cin >> countryID;
	
			string search;
			cout << "Введите название города" << endl;
			cin >> search;
			int index = -1;
			search.insert(0, " "); // добавляем пробел в начало который копируется из файла
			for (size_t i = 0; i < strana[countryID-1].city.size(); i++) {
				if (strana[countryID-1].city[i] == search) {
					index = i;
					if (choice == 1) {
						cout << "Город найден его индекс " << index + 1 << endl;
						break;
					}
					else if (choice == 2) {
						string newCity;
						cout << "Введите новый город" << endl;
						cin >> newCity;
						strana[countryID-1].setCity(i, newCity);
						strana[countryID].city[i].insert(0, " ");
						break;
					}
				}
			}
			if (index == -1) {
				cout << "Введенный вами город не найден" << endl;
			}
		} // а че писать две одинаковые функции где различается лишь одно действие :D
		// шла третья функция а я все незнаю где заюзать эти лямблы
		
		void addCoty() { // addCoCi так как сокращение от country и city выглядит как то нуууу не очень звучно, возьмем лучше последние буквы 
			string newCountry, newCity;
			cout << "Введите название страны" << endl;
			cin >> newCountry;
			
			strana.push_back(newCountry);
			
			auto addCity = [this](int id, string newCity) { // агааа а вот и нашелся повод залябдиться
				cout << "Введите название города" << endl;
				cin >> newCity;
				strana[id].city.push_back(newCity);
			};
			AddAgain:
			addCity(strana.size(), newCity);
			
			cout << "Город успешно добавлен. \nХотите добавить еще один город?" << endl;
			cout << "1. Да \n0. Нет" << endl;
			bool choose;
			cin >> choose;

			if (choose) {
				goto AddAgain;
			}
			else {
				return;
			}
		}

		void remove() {
		BACK:
			cout << "Выберите действие " << endl;
			cout << "1. Удаление страны \n2. Удаление города" << endl;
			int choice;
			string error;
			try {
				cin >> choice;
				if (choice == 1 || choice == 2) {} // да да копипаста
				else {
					throw error = "необходимо ввести 1 или 2";
				}
			}
			catch (string f) {
				cout << "Ошибка ввода: " << f << endl;
				goto BACK;
			}
			if (choice == 1) {
				string Country, City;
				cout << "Введите название страны которую хотите удалить" << endl;
				cin >> Country;

				Country.insert(Country.size(), ":");
				for (size_t i = 0; i < strana.size(); i++) {
					if (strana[i].countryName == Country) {
						strana.erase(strana.begin() + (i));
					}
				}
				cout << "Страна была успешно удалена" << endl;
			}
			else if (choice == 2) {
			_DeleteAgain:
				cout << "Выберите страну в которой хотите найти город" << endl;
				for (size_t j = 0; j < strana.size(); j++) {
					cout << j + 1 << ". " << strana[j].countryName << endl;
				}
				int countryID;
				cin >> countryID;

				cout << "Введите город который хотите удалить" << endl;
				string delCity;
				cin >> delCity;
				delCity.insert(0, " ");

				auto deleteCity = [this](int CountryID, string city) {

					for (size_t i = 0; i < strana[CountryID - 1].city.size(); i++) {
						if (strana[CountryID - 1].city[i] == city) {
							strana[CountryID - 1].city.erase(strana[CountryID - 1].city.begin() + (i));
						}
					}
					cout << "Город был успешно удален" << endl;
				};
				
				deleteCity(countryID, delCity);

				
				cout << "\nХотите удалить еще один город?" << endl;
				cout << "1. Да \n2. Нет" << endl;
				int choose;
				_CinAgain:
				cin >> choose;
				if (choose == 0 || choose == 1) {}
				else { goto _CinAgain; }
				
				if (choose == 1) {
					goto _DeleteAgain;
				}
				else if (choose == 2){
					return;
				}

			}

		}

		void deleteCity(string city) {
			cout << "Выберите страну в которой хотите найти город" << endl;
			for (size_t j = 0; j < strana.size(); j++) {
				cout << j + 1 << ". " << strana[j].countryName << endl;
			}
			int countryID;
			cin >> countryID;

			for (size_t i = 0; i < strana[countryID - 1].city.size(); i++) {
				if (strana[countryID - 1].city[i] == city) {
					strana[countryID-1].city.erase(strana[countryID-1].city.begin() + (i));
				}
			}
		}

		int getCityCount() {
			int cityCounter = 0;
			for (size_t i = 0; i < strana.size(); i++) {
				cityCounter += strana[i].city.size();
			}
			return cityCounter;
		}

		int getCountryCount() {
			int countryCounter = strana.size();
			return countryCounter ;
		}

		void show() {
			for (size_t i = 0; i < strana.size(); i++) {
				 cout << "\n" <<  strana[i].countryName << endl;
				 strana[i].showCity();
			}
		}
	};
}
int main()
{
	setlocale(LC_ALL, "RUS");
	using namespace std;

	std::cout << "Hello World!\n";
	std::cout << "i'm clone" << std::endl;
	std::cout << "i'm clone" << std::endl;


	fenix::earth asd;

	asd.inputFile();
	cout << "\n__________________________\n";
	//asd.show();

	//asd.searchCity();
	asd.show();
	//asd.searchCity();
	//asd.deleteCountry(); //робит

	asd.remove();
	cout << "\n\nqq\n\n" << endl;
	return 0;
}



