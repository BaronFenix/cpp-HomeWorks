
#include <iostream>

class O4ePeDb {
private:
	int* arry;
	int size = 0;
public:

	bool isEmpty() {
		return size == 0 ? true : false;
	}

	void add(int num) {
		if (size == 0) {
			arry = new int[++size];
			arry[0] = num;
		}
		else {
			int* newArr = new int[size + 1];
			for (size_t i = 0; i < size; i++) {
				newArr[i] = arry[i];
			}
			newArr[size++] = num;

			delete[] arry;
			arry = newArr;

		}
	}
	void remove() {
		int* newArr = new int[size - 1];
		for (size_t i = 0, p = 1; i < size - 1; i++) {

			newArr[i] = arry[p++];
		}

		delete[] arry;
		arry = newArr;
		size--;
	}

	void show() {
		for (size_t i = 0; i < size; i++) {
			std::cout << arry[i] << " ";
		}
	}

};

///////////////////////////////////////////////

class queueue {
private:
	int* arry;
	int* priority;
	int size = 0;
public:

	bool isEmpty() {
		return size == 0 ? true : false;
	}

	void PriorityAds(int menNum, int primacy){
		int* newArr = new int[size+1];
		int* newPriora = new int[size + 1];
		int index;
		
		if (size == 0) {
			index = 0;
		}
		else {
			index = 0;
			while (index < size) {
				if (priority[index] < primacy) {
					break;
				}
				index++;
			}
		}

		for (size_t i = 0; i < index; i++) {
			newArr[i] = arry[i];
			newPriora[i] = priority[i];
		}
		newArr[index] = menNum;
		newPriora[index] = primacy;

		for (size_t i = index + 1; i < size + 1; i++) {
			newArr[i] = arry[i - 1];
			newPriora[i] = priority[i - 1];
		}

		delete[] arry;
		delete[] priority;
		priority = newPriora;
		arry = newArr;
		size++;
	}

	void remove() {
		int* newArr = new int[size - 1];
		for (size_t i = 0, p = 1; i < size - 1; i++) {

			newArr[i] = arry[p++];
		}

		delete[] arry;
		arry = newArr;
		size--;
	}

	void show() {
		for (size_t i = 0; i < size; i++) {
			std::cout << arry[i] << " ";
		}
	}
	void showPriora() {
		for (size_t i = 0; i < size; i++) {
			std::cout << priority[i] << " ";
		}
	}

	void showTable() {
		std::cout << "ID \t" << "Приоритет" << std::endl;
		std::cout << "____________________\n";
		for (size_t i = 0; i < size; i++) {
			std::cout << arry[i] << " \t";
			std::cout << priority[i] << "\n";
		}
	}
};


////////////////////////////////////////
// queueuue v3.0

template<class $>
class queueueV3_0 {
private:
	$* massy;
	int* prioritetto;
	int size = 0;
public:

	bool isEmpty() {
		return size == 0 ? true : false;
	}

	void add($ elem, int primacy) {
		if (size == 0) {
			massy = new $[++size];
			prioritetto = new int[size];
			massy[0] = elem;
			prioritetto[0] = primacy;
		}
		else {
			$* newArr = new $[++size];
			int* newPrimacy = new int[size];
			for (size_t i = 0; i < size-1; i++) {
				newArr[i] = massy[i];
				newPrimacy[i] = prioritetto[i];
			}
			newArr[size-1] = elem;
			newPrimacy[size-1] = primacy;
			delete[] massy;
			delete[] prioritetto;
			massy = newArr;
			prioritetto = newPrimacy;
			
		}
	}

	void PrimacyRemove() { // кажись с исключением несколько легче способ
		$* newArr = new $[size - 1];
		int* newPrimacy = new int[size -1];
		int maxPrimacy = prioritetto[0];
		int maxIndex = 0;

		for (size_t i = 0; i < size; i++) {
			if (maxPrimacy < prioritetto[i]) {
				maxPrimacy = prioritetto[i];
				maxIndex = i;
			}
		}

		for (size_t i = 0, p = 0; i < size; i++) {
			if (i == maxIndex) {
				continue;
			}
			newArr[p] = massy[i];
			newPrimacy[p] = prioritetto[i];
			p++;
		}

		delete[] massy;
		delete[] prioritetto;
		massy = newArr;
		prioritetto = newPrimacy;
		size--;
	}


	void show() {
		for (size_t i = 0; i < size; i++) {
			std::cout << massy[i] << " ";
		}
	}
	void showPriora() {
		for (size_t i = 0; i < size; i++) {
			std::cout << prioritetto[i] << " ";
		}
	}

	void showTable() {
		std::cout << "ID \t" << "Приоритет" << std::endl;
		std::cout << "____________________\n";
		for (size_t i = 0; i < size; i++) {
			std::cout << massy[i] << " \t";
			std::cout << prioritetto[i] << "\n";
		}
	}

};

int main()
{
	setlocale(LC_ALL, "RUS");

	O4ePeDb B_O4ePeDb;

	if (B_O4ePeDb.isEmpty()){
		std::cout << "Массив пуст" << "\n\n";
	}
	else {
		std::cout << "Массив заполнен" << "\n\n";
	}


	B_O4ePeDb.add(1);
	B_O4ePeDb.add(2);
	B_O4ePeDb.add(3);
	B_O4ePeDb.add(4);
	B_O4ePeDb.add(5);
	B_O4ePeDb.add(6);
	B_O4ePeDb.add(7);
	B_O4ePeDb.add(8);
	B_O4ePeDb.show();

	if (B_O4ePeDb.isEmpty()) {
		std::cout << "Массив пуст" << "\n\n";
	}
	else {
		std::cout << "Массив заполнен" << "\n\n";
	}

	B_O4ePeDb.remove();
	std::cout << "\n\n";
	B_O4ePeDb.show();

	B_O4ePeDb.remove();
	std::cout << "\n\n";
	B_O4ePeDb.show();

	B_O4ePeDb.remove();
	std::cout << "\n\n";
	B_O4ePeDb.show();


	/////////////////////
	std::cout << "\n\n///////////////////////////////\n\n";
	queueue LadaPriora;

	LadaPriora.PriorityAds(1, 3);
	LadaPriora.PriorityAds(2, 1);
	LadaPriora.PriorityAds(3, 1);
	LadaPriora.PriorityAds(4, 3);
	LadaPriora.PriorityAds(5, 7);
	LadaPriora.PriorityAds(6, 9);
	LadaPriora.PriorityAds(7, 12);
	LadaPriora.PriorityAds(8, 99);

	LadaPriora.showTable();

	LadaPriora.remove();
	std::cout << "\n\n";
	LadaPriora.show();

	LadaPriora.remove();
	std::cout << "\n\n";
	LadaPriora.show();

	LadaPriora.remove();
	std::cout << "\n\n";
	LadaPriora.show();
	std::cout << std::endl;
	
	//////////////////////////////////////
	std::cout << "\n\n///////////////////////////////\n\n";
	queueueV3_0<char> waiting;

	waiting.add('a', 3);
	waiting.add('b', 12);
	waiting.add('c', 1);
	waiting.add('d', 99);
	waiting.add('e', 7);
	waiting.add('f', 9);
	waiting.add('g', 1);
	waiting.add('h', 3);

	waiting.show();
	std::cout << "\n";
	waiting.showTable();


	waiting.PrimacyRemove();
	std::cout << "\n\n";
	waiting.show();

	waiting.PrimacyRemove();
	std::cout << "\n\n";
	waiting.show();

	waiting.PrimacyRemove();
	std::cout << "\n\n";
	waiting.show();

	waiting.PrimacyRemove();
	std::cout << "\n\n";
	waiting.show();

	

}
