#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <chrono>
#include <list>
#include <map>
#include <functional>
#include <conio.h>
#include "crypton.cpp"
#include <sstream>
#include <iostream>
#include <windows.h>


namespace fenix {
	class crypton {
	private:
		int key = 0x7f3;
	public:
		std::string encrypt(std::string data) {
			std::string xxx;
			for (size_t i = 0; i < strlen(data.c_str()); i++) {
				xxx += data[i] ^ key;
			}
			return xxx;
		}

		std::string decryption(std::string xxx) {
			std::string data;
			for (size_t i = 0; i < strlen(xxx.c_str()); i++) {
				data += xxx[i] ^ key;
			}
			return data;
		}
	};

	using namespace std;

	class ERRORS {
	private:
		string error;
	public:
		ERRORS() {}
		ERRORS(string err) : error(err) { }
	};

	class GuestMode {
	protected:
		class student {
		public:
			string login;
			string password;

			string name;
			string surname;
			string patronomic;
			string phoneNum;
			string adress;

			student() {}
			student(string login, string pass, string name, string surname, string patronomic, string phone, string adress) :
				login(login), password(pass), name(name), surname(surname), patronomic(patronomic), phoneNum(phone), adress(adress) {
			}
			void setLogin(string Log) { login = Log; };
		};

		vector<student> user;
		crypton x0r;
	public:



		void registarion();
		void log_in();
		void outputLoginData(std::string fileName);
		void menuTest();
		void startTest(string file);
		void viewResult(string file, char* userInput, char* answer);
		void GuestMenu();
		void showLastResult();
		
		
		

	};


	class AdminMode : public GuestMode{
	private:
		struct QuestionTemp { // класс шаблон дл€ легкого добавлени€ вопросов
			string question;
			string variant_A;
			string variant_B;
			string variant_C;
			char answer;
			QuestionTemp() {}
			QuestionTemp(string question, string variant_A, string variant_B, string variant_C, char answer) {
				this->question = question;
				this->variant_A = variant_A;
				this->variant_B = variant_B;
				this->variant_C = variant_C;
				this->answer = answer;
			}
		};

	public:
	    void setAdmin();
		static void addTest();
		static void setTest(string file);
		


		void showLogData() {
			cout << x0r.decryption(user[0].login) << endl;
			cout << x0r.decryption(user[0].password) << endl;
		}
	};



} // fenix