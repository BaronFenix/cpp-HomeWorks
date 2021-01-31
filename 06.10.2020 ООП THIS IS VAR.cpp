#include <iostream>
#include <string>
#include <typeinfo>
#include <sstream>

class var {
private:
	int num = 0;
	double drob = 0;
	std::string str = "empty";
public:

	int getnum() {
		return num;
	}

	var(int num) : num(num) { }
	var(const char* str) : str(str) { } 
	var(double dub) : drob(dub) { }

	var operator+(var varya);
	var operator-(var varya);
	var operator*(var& voron);
	var operator/(var& kar);
	var operator*=(var var_varych);
	var operator/=(var& vasya);
	var operator+=(var kar_karych);
	var operator-=(var Var_For_Vendetta);
	const var operator>(var Vision);
	const var operator<(var Vision) const;
	bool operator<=(var Vision);
	bool operator>=(var Vision);
	bool operator==(var varface);
	bool operator!=(var varzilla);
	friend std::ostream& operator<<(std::ostream& out, const var& object);
	void show();
	
}; // вот так то лучше. куда по аккуратнее смотрится, и че я сразу так не начал

/*std::string operator+(std::string left) {
	std::stringstream cloud;

	if (drob != 0 && str != "empty") {
		std::string strNum;
		cloud << drob << str;
		cloud >> strNum;

		//str = str + strNum;
		//strNum = strNum + str;
		return strNum;
	}
}*/

var var::operator+(var varya) {
	std::stringstream cloud;
	if (drob != 0 && varya.str != "empty") {

		double strNum;
		cloud << varya.str;
		cloud >> strNum;
		return drob + strNum;
	}
	else if (num != 0 && varya.str != "empty") {
		int strNum;
		cloud << varya.str;
		cloud >> strNum;
		return num + strNum;
	}
	else if (num != 0 && varya.drob != 0) {
		return num + varya.drob;
	}
	else if (str != "empty" && varya.drob != 0) {
		std::string strNum;
		cloud << str << varya.drob;
		cloud >> strNum;

		return strNum.c_str();
	}
	else if (str != "empty" && varya.num != 0) {
		std::string strNum;
		cloud << str << varya.num;
		cloud >> strNum;

		return strNum.c_str();
	}
	else if (str != "empty" && varya.str != "empty") {
		std::string strNum;
		cloud << str << varya.str;
		cloud >> strNum;

		return strNum.c_str();
	}
	return *this;
}

var var::operator-(var varya) {
	std::stringstream cloud;
	if (drob != 0 && varya.str != "empty") {

		double strNum;
		cloud << varya.str;
		cloud >> strNum;
		return drob - strNum;
	}
	else if (num != 0 && varya.str != "empty") {
		int strNum;
		cloud << varya.str;
		cloud >> strNum;
		return num - strNum;
	}
	else if (num != 0 && varya.drob != 0) {
		return num - varya.drob;
	}
	return *this;

}

var var::operator*(var& voron) {
	std::stringstream cloud;
	std::string tmp;
	if (drob != 0 && voron.str != "empty") {
		double strNum;
		cloud << voron.str;
		cloud >> strNum;
		return drob * strNum;
	}
	else if (num != 0 && voron.str != "empty") {
		int strNum;
		cloud << voron.str;
		cloud >> strNum;
		return num * strNum;
	}
	else if (num != 0 && voron.drob != 0) {
		return num * voron.drob;
	}
	else if (str != "empty" && voron.str != "empty") {
		for (auto alpha : str) {
			for (auto beta : voron.str) {
				if (alpha == beta) {
					tmp.push_back(alpha);
				}
			}
		}
		return tmp.c_str();
	}
	else {
		return *this;
	}
}

var var::operator/(var& kar) {
	std::string result, tmp;
	std::stringstream cloud;
	bool O_o = true;

	if (str != "empty" && kar.str != "empty") {
		for (auto first : str) {
			for (auto second : kar.str) {
				if (first == second) {
					O_o = false;
					break;
				}
			}
			if (!O_o) {                                             // ну да, да, подглядел интересную реализацию. подумаешь..  
				O_o = true;                                            // ибо идей особо не было как исправить это дублирование
				continue;
			}
			result.push_back(first);
		}
		return result.c_str();
	}

	else if (drob != 0 && kar.str != "empty") {
		double strNum;
		cloud << kar.str;
		cloud >> strNum;
		return drob / strNum;
	}
	else if (num != 0 && kar.str != "empty") {
		int strNum;
		cloud << kar.str;
		cloud >> strNum;
		return num / strNum;
	}
	else if (num != 0 && kar.drob != 0) {
		return num / kar.drob;
	}

	else {
		return *this;
	}

}

var var::operator*=(var var_varych) {
	std::stringstream cloud;

	if (str != "empty" && var_varych.str != "empty") {
		for (auto alpha : str) {
			for (auto beta : var_varych.str) {
				if (alpha == beta) {
					str.push_back(alpha);
				}
			}
		}
		return str.c_str();
	}
	else if (drob != 0 && var_varych.str != "empty") {
		double strNum;
		cloud << var_varych.str;
		cloud >> strNum;
		return drob = drob * strNum;
	}
	else if (num != 0 && var_varych.str != "empty") {
		int strNum;
		cloud << var_varych.str;
		cloud >> strNum;
		return num = num * strNum;
	}
	else if (num != 0 && var_varych.drob != 0) {
		return num = num * var_varych.drob;
	}
	else {
		return *this;
	}

} // не совчем понял что она должны делать так что да. 
 //ну вроде +- логично microsoft = microsoft * windows = microsoftioso

var var::operator/=(var& vasya) {
	bool O_o = true;
	std::stringstream cloud;
	if (str != "empty" && vasya.str != "empty") {

		for (auto first : str) {
			for (auto second : vasya.str) {
				if (first == second) {
					O_o = false;
					break;
				}
			}
			if (!O_o) {
				O_o = true;
				continue;
			}
			str.push_back(first);
		}
		return str.c_str();
	}
	else if (drob != 0 && vasya.str != "empty") {
		double strNum;
		cloud << vasya.str;
		cloud >> strNum;
		return drob = drob * strNum;
	}
	else if (num != 0 && vasya.str != "empty") {
		int strNum;
		cloud << vasya.str;
		cloud >> strNum;
		return num = num / strNum;
	}
	else if (num != 0 && vasya.drob != 0) {
		return num = num / vasya.drob;
	}
	else {
		return *this;
	}
}

var var::operator +=(var kar_karych) {
	std::stringstream cloud;
	std::string left = str, right = kar_karych.str, result;
	if (str != "empty" && kar_karych.str != "empty") {
		str = str + right;   // да тут по идее и цикл не нужен нооо.. мне лень проверять // UPD. ну да, я все таки проверил и как оказалось отнюдь не зря
		return *this;
	}
	else if (drob != 0 && kar_karych.str != "empty") {
		double strNum;
		cloud << kar_karych.str;
		cloud >> strNum;
		return drob = drob + strNum;
	}
	else if (num != 0 && kar_karych.str != "empty") {
		int strNum;
		cloud << kar_karych.str;
		cloud >> strNum;
		return num = num + strNum;
	}
	else if (num != 0 && kar_karych.drob != 0) {
		return num = num + kar_karych.drob;
	}
	else {
		return *this;
	}
}

var var::operator -=(var Var_For_Vendetta) {
	std::stringstream cloud;
	std::string left = str, right = Var_For_Vendetta.str, result;
	bool V = true;

	//str = str - right; // ну вот как прикажете минусовать строки? это же просто не логично. а хотяяяя можно засунуть логику деления   
	if (str != "empty" && Var_For_Vendetta.str != "empty") {

		for (auto first : str) {
			for (auto second : Var_For_Vendetta.str) {
				if (first == second) {
					V = false;
					break;
				}
			}
			if (!V) {
				V = true;
				continue;
			}
			str.push_back(first);
		}
		return str.c_str();
	}
	else if (drob != 0 && Var_For_Vendetta.str != "empty") {
		double strNum;
		cloud << Var_For_Vendetta.str;
		cloud >> strNum;
		return drob = drob - strNum;
	}
	else if (num != 0 && Var_For_Vendetta.str != "empty") {
		int strNum;
		cloud << Var_For_Vendetta.str;
		cloud >> strNum;
		return num = num - strNum;
	}
	else if (num != 0 && Var_For_Vendetta.drob != 0) {
		return num = num - Var_For_Vendetta.drob;
	}
	else {
		return *this;
	}
}

const var var::operator<(var Vision) const { // юххю оптимизация просто зашкаливает две одинаковые функции где только скобки смотрят в разные стороны
	std::stringstream cloud;           // стоп. всмысле этого не было в задании? да вы издеваетесь?

	if (str != "empty" && Vision.str != "empty") {

		return str.c_str() < Vision.str.c_str() ? str.c_str() : Vision.str.c_str();
	}
	else if (drob != 0 && Vision.str != "empty") {
		double strNum;
		cloud << Vision.str;
		cloud >> strNum;
		return drob < strNum ? drob : strNum;
	}
	else if (num != 0 && Vision.drob != 0) {
		return drob < num ? drob : num;
	}
	else if (Vision.str != "empty" && drob != 0) {
		double strNum;
		cloud << str;
		cloud >> strNum;
		return drob > strNum ? true : false;
	}
	else {
		return *this;
	}
}

const var var::operator>(var Vision) {
	std::stringstream cloud;

	if (str != "empty" && Vision.str != "empty") {

		return str.c_str() > Vision.str.c_str() ? str.c_str() : Vision.str.c_str();
	}
	else if (drob != 0 && Vision.str != "empty") {
		double strNum;
		cloud << Vision.str;
		cloud >> strNum;
		return drob > strNum ? drob : strNum;
	}
	else if (num != 0 && Vision.str != "empty") {
		int strNum;
		cloud << Vision.str;
		cloud >> strNum;
		return num > strNum ? num : strNum;
	}
	else if (num != 0 && Vision.drob != 0) {
		return drob > num ? drob : num;
	}
	else {
		return *this;
	}
}

bool var::operator<=(var Vision) {
	std::stringstream cloud;

	if (str != "empty" && Vision.str != "empty") {

		return str.c_str() <= Vision.str.c_str() ? true : false;
	}
	else if (drob != 0 && Vision.str != "empty") {
		double strNum;
		cloud << Vision.str;
		cloud >> strNum;
		return drob <= strNum ? true : false;
	}
	else if (num != 0 && Vision.str != "empty") {
		int strNum;
		cloud << Vision.str;
		cloud >> strNum;
		return num <= strNum ? true : false;
	}
	else if (num != 0 && Vision.drob != 0) {
		return drob <= num ? true : false;
	}
	else if (str != "empty" && Vision.drob != 0) {
		double strNum;
		cloud << str;
		cloud >> strNum;
		return Vision.drob <= strNum ? true : false;
	}
	else if (str != "empty" && Vision.num != 0) {
		double strNum;
		cloud << str;
		cloud >> strNum;
		return Vision.num <= strNum ? true : false;
	}
	else if (str != "empty" && Vision.str != "empty") {
		return str.c_str() <= Vision.str.c_str() ? true : false;
	}
	else {
		return 0;
	}
}

bool var::operator>=(var Vision) {
	std::stringstream cloud;

	if (str != "empty" && Vision.str != "empty") {

		return str.c_str() > Vision.str.c_str() ? true : false;
	}
	else if (drob != 0 && Vision.str != "empty") {
		double strNum;
		cloud << Vision.str;
		cloud >> strNum;
		return drob >= strNum ? true : false;
	}
	else if (num != 0 && Vision.str != "empty") {
		int strNum;
		cloud << Vision.str;
		cloud >> strNum;
		return num >= strNum ? true : false;
	}
	else if (num != 0 && Vision.drob != 0) {
		return drob >= num ? true : false;
	}
	else if (str != "empty" && Vision.drob != 0) {
		double strNum;
		cloud << str;
		cloud >> strNum;
		return Vision.drob >= strNum ? true : false;
	}
	else if (str != "empty" && Vision.num != 0) {
		double strNum;
		cloud << str;
		cloud >> strNum;
		return Vision.num >= strNum ? true : false;
	}
	else if (str != "empty" && Vision.str != "empty") {
		return str.c_str() >= Vision.str.c_str() ? true : false;
	}
	else {
		return 0;
	}
}

bool var::operator==(var varface) {
	std::stringstream cloud;
	if (str != "empty" && varface.str != "empty") {

		return str.c_str() == varface.str.c_str() ? true : false;
	}
	else if (drob != 0 && varface.str != "empty") {
		double strNum;
		cloud << varface.str;
		cloud >> strNum;
		return drob == strNum ? true : false;
	}
	else if (num != 0 && varface.str != "empty") {
		int strNum;
		cloud << varface.str;
		cloud >> strNum;
		return num == strNum ? true : false;
	}
	else if (num != 0 && varface.drob != 0) {
		return drob == num ? true : false;
	}
	else if (str != "empty" && varface.drob != 0) {
		double strNum;
		cloud << str;
		cloud >> strNum;
		return varface.drob == strNum ? true : false;
	}
	else if (str != "empty" && varface.num != 0) {
		double strNum;
		cloud << str;
		cloud >> strNum;
		return varface.num == strNum ? true : false;
	}
	else if (str != "empty" && varface.str != "empty") {
		return str.c_str() == varface.str.c_str() ? true : false;
	}
	else {
		return 0;
	}
}

bool var::operator!=(var varzilla) {
	std::stringstream cloud;
	if (str != "empty" && varzilla.str != "empty") {

		return str.c_str() != varzilla.str.c_str() ? true : false;
	}
	else if (drob != 0 && varzilla.str != "empty") {
		double strNum;
		cloud << varzilla.str;
		cloud >> strNum;
		return drob != strNum ? true : false;
	}
	else if (num != 0 && varzilla.str != "empty") {
		int strNum;
		cloud << varzilla.str;
		cloud >> strNum;
		return num != strNum ? true : false;
	}
	else if (num != 0 && varzilla.drob != 0) {
		return drob != num ? true : false;
	}
	else if (str != "empty" && varzilla.drob != 0) {
		double strNum;
		cloud << str;
		cloud >> strNum;
		return varzilla.drob != strNum ? true : false;
	}
	else if (str != "empty" && varzilla.num != 0) {
		double strNum;
		cloud << str;
		cloud >> strNum;
		return varzilla.num != strNum ? true : false;
	}
	else if (str != "empty" && varzilla.str != "empty") {
		return str.c_str() != varzilla.str.c_str() ? true : false;
	}
	else {
		return 0;
	}
}

 std::ostream& operator<<(std::ostream& out, const var& object) { // одолжу как я эту функцию (снова)
	if (object.num == 0 && object.drob == 0) {
		std::cout << object.str;
	}
	else if (object.num == 0 && object.str == "empty") {
		std::cout << object.drob;
	}
	else if (object.drob == 0 && object.str == "empty") {
		std::cout << object.num;
	}
	return out;
}

 void var::show() {
	 if (num == 0 && drob == 0) {
		 std::cout << "string: " << str << std::endl;
	 }
	 else if (num == 0 && str == "empty") {
		 std::cout << "double: " << drob << std::endl;
	 }
	 else if (drob == 0 && str == "empty") {
		 std::cout << "int: " << num << std::endl;
	 }
 }

int main()
{
	
	setlocale(LC_ALL, "RUS");
	using namespace std;
	system("color 0D");
	
	
	var a = 12;
	var b = "guten tag";
	var j = 4.12;
	var s = "12";

	//b = j + s;
	//var c = a + b;
	cout << b << endl;
	cout << s << endl;
	//b.show();

	b = s + j; // вот здесь я вот не понял как перегрузить оператор, и как ваще понять какой тип находится слева
	b.show();                                            // а не, норм. допер все таки

	j *= s;
	j.show();

	var mic = "microsoft";
	var win = "windows";
	var micWin = mic * win;
	micWin.show();
	
	cout << endl;
	var mcrsft = mic / win;
	mcrsft.show();

	cout << endl;
	mic += win;
	mic.show();

	var q = j > s; // наес это все на что она способна. а в ифах не робит
	if (s <= j) { // ибо великий и всемогущий иф требует булиона  (куринного, говоря между нами )
		cout << "\nTRUE: q = " << endl;
		q.show();
	}
	cout << "\n\n";
	if (a == s) {
		cout << a << " == " << s << endl; // вот это поворот
	}
	if (s != j) {
		cout << s << " != " << j << endl; // кто бы мог подумать..
	}


	cout << "\n\n" << sizeof(a) << "\n" << sizeof(b) << "\n" << sizeof(j) << "\n\n";
	cout << "a = " << typeid(a.getnum()).name(); // интересная весчь для определения типа, но я не придумать как с ней быть
	return 0;
}

// каефф 600 строк однотипного кода