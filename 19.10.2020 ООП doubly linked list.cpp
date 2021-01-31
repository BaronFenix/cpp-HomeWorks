
#include <iostream>

template<typename var>
class DoublyGlist {
private:
	template <typename var>
	class knot {
	public:
		var data;
		knot* backPtr;
		knot* nextPtr;

		knot(var value = var(), knot* next = nullptr, knot* back = nullptr) {
			data = value;
			nextPtr = next;
			backPtr = back;
		}
	};
	knot<var> *root;
	int size;

public:

	DoublyGlist();
	void addToTail(var elemental);
	void show();
	void addToHead(var elementarno);
	void deleteRoot();
	void deletEnd();
	void deleteAll();
	void addAt(var elemento, int id);
	void deleteAt(int id);
	int search(var key);
	int SearchAndReplace(var illuminati, var newValue);
	void reverse();
	void fakeRevers();
	
};

template<typename var>
DoublyGlist<var>::DoublyGlist() {
	root = nullptr;
	size = 0;
}

template<typename var>
void DoublyGlist<var>::addToTail(var elemental) {
	if (size == 0) {
		root = new knot<var>(elemental);
		size++;
	}
	else if (size == 1) {
		knot<var> *newKnot = new knot<var>(elemental, root, root);
		root->backPtr = newKnot;
		root->nextPtr = newKnot;
		size++;
	}
	/*else {
		knot<var>* newKnot = new knot<var>(elemental, root, root->backPtr);
		root->backPtr->nextPtr = newKnot;
		root->backPtr = newKnot;
		size++;
	}*/
	else {
	knot<var>* end = root->backPtr;
	end->nextPtr = new knot<var>(elemental, root, end);
	root->backPtr = end->nextPtr;
	size++;
	}          // ъмм вроде такой варик тоже робит 

}

template<typename var>
void DoublyGlist<var>::addToHead(var elementarno) {
	if (size == 0) {
		root = new knot<var>(elementarno);
		size++;
	}
	else if (size == 1) {
		knot<var>* newEnot = new knot<var>(elementarno, root, root);
		//root = newEnot;
		root->nextPtr = newEnot;
		root->backPtr = newEnot;
		root = newEnot;
		size++;
	}
	else {
		knot<var>* newVar = new knot<var>(elementarno, root, root->backPtr);
		root->backPtr->nextPtr = newVar;
		root->backPtr = newVar;
		root = newVar;
		size++;
	}
}

template<typename var>
void DoublyGlist<var>::deleteRoot() {
	knot<var>* save = new knot<var>;
	save = root->backPtr;
	save = root->nextPtr;
	delete root;
	root = save;
	size--;
}

template<typename var>
void DoublyGlist<var>::deletEnd() {
	knot<var>* save = new knot<var>;
	save = root->backPtr->nextPtr;
	save = root->backPtr->backPtr;
	delete root->backPtr;
	root->backPtr = save;
	size--;                 // прекол, если честно не думал что будет работать
}                    

template<typename var>
void DoublyGlist<var>::deleteAll() {
	while (size) {
		deletEnd();
	}
	root->data = 0;
	root->backPtr = nullptr; // вроде и так робит но пусть будет контрольный
	root->nextPtr = nullptr;
}

template<typename var>
void DoublyGlist<var>::show() {
	knot<var>* iterator = root; 
	for (size_t i = 0; i < size; i++) {
		std::cout << iterator->data << " ";
		iterator = iterator->nextPtr;
	}

	/*for (knot<var>* it = root; it != root->backPtr; it = it->nextPtr) {
		std::cout << it->data << " ";
		if (it->nextPtr == root->backPtr) {
			std::cout << it->nextPtr->data << " ";
			break;
		}
	}*/   
	//вот прикольный варик нооо он больше для линейного. ну или я хз как сделать чтобы последний элем. не терялся

}

template<typename var>
void DoublyGlist<var>::addAt(var elemento, int id) {
	if (id == 1) {
		addToHead(elemento); // хыыы идеально
	}
	else {
		knot<var>* it = root;
		for (size_t i = 0; i < size; i++) {
			if (i + 1 == id - 1) {
				break;
			}
			it = it->nextPtr;
		}
		knot<var>* newKnot = new knot<var>(elemento, it->nextPtr, it);

		it->nextPtr = newKnot;
		it->backPtr->nextPtr = it;
		it->nextPtr = newKnot;
		size++;
	}
}

template<typename var>
void DoublyGlist<var>::deleteAt(int id) {
	if (id == 1) {
		deleteRoot();
	}
	else {
		knot<var>* it = root;
		for (size_t i = 0; i < size; i++) {
			if (i + 1 == id - 1) {
				break;
			}
			it = it->nextPtr;
		}
		knot<var>* save = new knot<var>;
		save = it->nextPtr->backPtr;
		save = it->nextPtr->nextPtr;

		delete it->nextPtr;
		it->nextPtr = save;
		size--;
	}
}

template<typename var>
int DoublyGlist<var>::search(var key) {
	knot<var>* it = root;
	for (size_t i = 0; i < size; i++) {
		if (it->data == key) {
			return i;
		}
		it = it->nextPtr;
	}
	return 0;
	// сначало думал как бы запилить что то типа бин. поиска, но потом дошло что масс.. структура должна быть отсортирована 
}

template<typename var>
int DoublyGlist<var>::SearchAndReplace(var illuminati, var newValue) {

	knot<var>* it = root;
	int counter = 0;
	for (size_t i = 0; i < size; i++) {
		if (it->data == illuminati) {
			it->data = newValue;
			counter++;
		}
		it = it->nextPtr;
	}
	if (counter == 0) {
		return -1;
	}
	else {
		return counter;
	}
	
}

template<typename var>
void DoublyGlist<var>::reverse() {
	knot<var>* rev = root->backPtr;
	
	knot<var>* Current = root;
	knot<var>* tmpBack = root->backPtr;
	knot<var>* tmpNext = root->nextPtr;

	while(Current != root->backPtr){
		tmpNext->nextPtr = Current->nextPtr;
		tmpBack->backPtr = Current->backPtr;
		Current->nextPtr = tmpBack;
		Current->backPtr = tmpNext;
		tmpBack = Current;
		tmpNext = Current->nextPtr;
		Current = tmpNext;
		Current->nextPtr = tmpBack;

		Current = Current->nextPtr;
	}                                // ну все, все, сдаюсь. твоя взяла двулинейный циклический лист. но знай я еще вернусь за реваншем..
	
	
	/////////////////////////////////////////////
	/*
	knot<var>* current = root;
	knot<var>* temp = current->nextPtr;
	current->nextPtr = current->backPtr;
	current->backPtr = temp;
	current = current->nextPtr;

	if (current->backPtr == root) {
		return;
		//return node;
	}
	else {
		// Иначе продолжай
		reverse();
	}
	*/
}

template<typename var>
void DoublyGlist<var>::fakeRevers() {
	knot<var>* iterator = root->backPtr;
	/*for (ptrdiff_t i = size; i >= 0; i--) {
		std::cout << iterator->data << " ";
		iterator = iterator->backPtr;
	}*/
	
	for (knot<var>* it = root->backPtr; it != root; it = it->backPtr) {
		std::cout << it->data << " ";
	}
	// эхх ну вот даже схитрить нормально не дают че за народ.. чуть что ошибки выдавать
} // а я то думал ща запилю нормальный мужитский реверс без всяких ваших там непонятных мутных махинаций

int main()
{
	setlocale(LC_ALL, "RUS");
	
	DoublyGlist<int> cycJIuK;
	/*
	cycJIuK.addToTail(5);
	cycJIuK.addToTail(55);
	cycJIuK.addToTail(555);
	*/
	cycJIuK.addToHead(999);
	cycJIuK.addToHead(99);
	cycJIuK.addToHead(9);
	cycJIuK.addToHead(6);
	
	cycJIuK.show();
	std::cout << "\n\n";

	cycJIuK.addAt(777, 2); 
	cycJIuK.show();
	std::cout << "\n\n";

	cycJIuK.deleteAt(3); 
	cycJIuK.show();
	std::cout << "\n\n";

	int result = cycJIuK.search(999);

	if (result == 0) {
		std::cout << "Искомый тобою элемент не найден, мой юный падаван" << std::endl;
	}
	else {
		std::cout << "Искомый тобою элемент находится в системе под индексом " << result << ". Удачи, падаван" << std::endl;
	}


	cycJIuK.addToHead(55);
	cycJIuK.addAt(55, 5);
	cycJIuK.addToTail(55);
	cycJIuK.show();
	std::cout << "\n\n";

	int count = cycJIuK.SearchAndReplace(55, 77);
	cycJIuK.show();
	std::cout << "\n\n";

	if (count == 0) {
		std::cout << "Искомый тобою элемент не найден, мой юный падаван. а как гласит древняя мудрость: \"на нет и суда нет\"" << std::endl;
	}
	else {
		std::cout << "Искомый тобою элемент найден и был трансмутирован в иное существо. трансмутаций произошло: "<< count << std::endl;
	}

	std::cout << "\n\n";

	//cycJIuK.fakeRevers();
	//cycJIuK.show();
}

