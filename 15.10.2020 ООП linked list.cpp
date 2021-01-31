#include <iostream>

template<class var>
class GList {
private:
	template<class var>
	class Node {
	public:
		Node* next;
		var data;
		Node(var data = var(), Node* next = nullptr) {
			this->next = next;
			this->data = data;
		}

	};

	Node<var>* root;
	int size;
public:

	GList();
	void add(var element);
	void addToBegin(var elemental);
	void deleteRoot();
	void popBack();
	void deleteAll();
	void show();
	var& operator[](int id);
};

template<class var>
GList<var>::GList() {
	size = 0;
	root = nullptr;
}

template<class var>
void GList<var>::add(var element) {
	if (size == 0) {
		root = new Node<var>(element);
		size++;
	}
	else {
		Node<var>* end = root;
		while (end->next != nullptr) {
			end = end->next;
		}
		end->next = new Node<var>(element);
		size++;
	}
}

template<typename var>
void GList<var>::addToBegin(var elemental) { 
	root = new Node<var>(elemental, root);  // найс рофл от даника
	size++;
}

template<typename var>
void GList<var>::popBack() {
	Node<var>* it = root;

	while (it->next && it->next->next != nullptr) {
		it = it->next;
	}
	delete it->next;
	it->next = nullptr;
}

template<class var>
void GList<var>::deleteRoot() {
	Node<var>* tmp = new Node<var>;
	tmp = root->next;
	delete root;
	root = tmp;
}

template<class var>
void GList<var>::deleteAll() {
	while (size) {
		popBack();
		size--;
	}
	root->data = 0;
	root->next = nullptr;
}

template<class var>
void GList<var>::show() {
	Node<var> *iterator = root; // недоитератор но пойдет. работу свою делает

	while (iterator->next != nullptr) {
		std::cout << iterator->data << " ";
		iterator = iterator->next;
		
		if (iterator->next == nullptr) {
			std::cout << iterator->data << " ";
			break;
		}
	}
}

template<class var>
var& GList<var>::operator[](int id) {
	if (id-- > size) {
		std::cerr << "error! id out of range";
		exit;
	}
	Node<var>* it = root;
	int i = 0;
	while (it->next != nullptr) {
		if (id == i) {
			break;
		}
		i++; 
		it = it->next;
	}
	return it->data;
}



int main()
{

	GList<int> mylitsia;

	mylitsia.add(2);
	mylitsia.add(5);
	mylitsia.add(17);
	mylitsia.add(26);
	mylitsia.addToBegin(99);
	mylitsia.addToBegin(34);

	mylitsia.show();
	std::cout << "\n\n";
	

	mylitsia.popBack();
	mylitsia.show();
	std::cout << "\n\n";


	mylitsia.deleteRoot();
	mylitsia.show();
	std::cout << "\n\n";

	int o = mylitsia[1];
	std::cout << "o = " << o;

	std::cout << "\n\n";
	mylitsia.deleteAll();
	mylitsia.show();

	return 0;
}