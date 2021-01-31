#include <iostream>

template<int size>
class StaticStack {
private:
    char arr[size];
    int top = -1;
public:
    
    void add(char symbol) {
        if(top+1 < size) {
            arr[++top] = symbol;
        }
        else {
            std::cerr << "Ошибка! стек переполнен" << std::endl;
            return;
        }
    }

    void remove() {
        top--;
    }

    int getSize() { return top + 1; }

    bool isEmpty() { return top == -1 ? true : false; }

    bool isFull() { return top + 1 == size ? true : false; }
    
    void removeAll() { top = -1; }

    char getElemment() { return arr[top]; }

    void show() {
        for (size_t i = 0; i < size; i++) {
            std::cout << arr[i];
        }
        std::cout << std::endl;
    }

};


class stack {
private:
    char *arry = nullptr;
    int size = 0;
public:

    void add(char symbol) {
        if (size == 0) {
            arry = new char[++size];
            arry[0] = symbol;
        }
        else {
            char* newArr = new char[size+1];
            for (size_t i = 0; i < size; i++) {
                newArr[i] = arry[i];
            }
            newArr[size++] = symbol;
            delete[] arry;
            arry = newArr;
        }
    }

    void remove() {
        char* NewArr = new char[size - 1];
        for (size_t i = 0; i < size-1; i++) {
            NewArr[i] = arry[i];
        }
        delete[] arry;
        arry = NewArr;
        size--;
    }

    int getSize() { return size; }

    bool isEmpty() { return size == 0 ? true : false; }

    bool isFull() { return size != 0 ? true : false; }

    void removeAll() {
        size = 0; 
        delete[] arry;
    }

    char getElemment() { return arry[size-1]; }

    void show() {
        for (size_t i = 0; i < size; i++) {
            std::cout << arry[i];
        }
        std::cout << std::endl;
    }

};


int main()
{
    setlocale(LC_ALL, "RUS");
    using namespace std;
                 
    StaticStack<7> pancake;
    pancake.add('s');
    pancake.add('k');
    pancake.add('i');
    pancake.add('l');
    pancake.add('l');
    pancake.add('e');
    pancake.add('t');
    //pancake.add('o');

    pancake.show();

    std::cout << pancake.getSize();

    pancake.remove();
    cout << endl;
    std::cout << pancake.getSize();
    cout << endl;
    pancake.removeAll();
    std::cout << pancake.getSize();
    cout << endl;


    //////////////////////////////////

    stack cupCake;
    cupCake.add('P');
    cupCake.add('a');
    cupCake.add('n');
    cupCake.add('c');
    cupCake.add('a');
    cupCake.add('k');
    cupCake.add('e');

    cupCake.show();

    std::cout << cupCake.getSize();

    cupCake.remove();
    cout << endl;
    std::cout << cupCake.getSize();
    cout << endl;
    cupCake.removeAll();
    std::cout << cupCake.getSize();
    cout << endl;

}