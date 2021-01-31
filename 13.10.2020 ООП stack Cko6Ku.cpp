
#include <iostream>
#include <vector>

class stack {
private:
    char* arry = nullptr;
    int size = 0;
    std::vector<char> tmp;

public:

    void add(char symbol) {
        if (size == 0) {
            arry = new char[++size];
            arry[0] = symbol;
        }
        else {
            char* newArr = new char[size + 1];
            for (size_t i = 0; i < size; i++) {
                newArr[i] = arry[i];
            }
            newArr[size++] = symbol;
            delete[] arry;
            arry = newArr; 
        }
    }

    void check() {
        int figureOpn = int(), squareOpn = int(), simpleOpn = int();
        int figureCls = int(), squareCls = int(), simpleCls = int();
        char isOpen[] = { '[', '(', '{' };
        char isClosed[] = { ']', ')', '}' };
        int Ocount = 0, Ccount = 0;
        std::string checkMas;

        for (size_t i = 0; i < size; i++) {
            if (arry[i] == '[' || arry[i] == '{' || arry[i] == '(') {
                if (arry[i] == '[') {
                    squareOpn++;
                    checkMas.push_back('[');
                    
                }
                else if (arry[i] == '{') {
                    figureOpn++;
                    checkMas.push_back('{');
                    
                }
                else if (arry[i] == '(') {
                    simpleOpn++;
                    checkMas.push_back('(');
                    
                }
            }
            if (arry[i] == ']' || arry[i] == '}' || arry[i] == ')') {
                if (arry[i] == ']') {
                    squareCls++;
                    checkMas.push_back(']');
                }
                else if (arry[i] == '}') {
                    figureCls++;
                    checkMas.push_back('}');
                }
                else if (arry[i] == ')') {
                    checkMas.push_back(')');
                    simpleCls++;
                }
            }
           
                
        }
        int err = 0;
        for (size_t i = 0; i < checkMas.size(); i++) {
            if (checkMas[i] != checkMas[i+1]) {
          //     std::cout << "error " << checkMas[i];
            }
            if (checkMas[i] == '[' || checkMas[i] == '{' || checkMas[i] == '(') {
                if (checkMas[i] == '[') {
                    squareOpn++;
                    if (checkMas[i + 1] == ']') {
                        squareCls++;
                    }
                    else {
                        err = i;
                        break;
                    }
                }
                else if (checkMas[i] == '{') {
                    figureOpn++;
                    if (checkMas[i + 1] == '}') {
                        figureCls++;
                    }
                    else {
                        err = i;
                        break;
                    }
                }
                else if (checkMas[i + 1] == '(') {
                    simpleOpn++;
                    if (checkMas[i] == ')') {
                        simpleCls++;
                    }
                    else {
                        err = i;
                        break;
                    }
                }
            }
            std::cout << checkMas[i];

        }

        if (figureOpn == figureCls && squareOpn == squareCls && simpleOpn == simpleCls) {
            std::cout << "\n\nOk" << std::endl;
        }
        else std::cout << "Error" << std::endl;

        printf("\nopen figure %d, open square %d, open simple %d\n", figureOpn, squareOpn, squareOpn);
        printf("closed figure %d, closed square %d, closed simple %d\n", figureCls, squareCls, squareCls);
        //std::cout << "\ncheck bracket mas " << checkMas;
    }

    void remove() {
        char* NewArr = new char[size - 1];
        for (size_t i = 0; i < size - 1; i++) {
            NewArr[i] = arry[i];
        }
        delete[] arry;
        arry = NewArr;
        size--;
    }

    int getSize() { return size; }

    char getElemment() { return arry[size - 1]; }

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
    

    stack Cko6uyc;
    Cko6uyc.add('(');
    Cko6uyc.add('{');
    Cko6uyc.add('x');
    Cko6uyc.add('-');
    Cko6uyc.add('y');
    Cko6uyc.add('-');
    Cko6uyc.add('z');
    Cko6uyc.add('}');
    Cko6uyc.add('*');
    Cko6uyc.add('[');
    Cko6uyc.add('x');
    Cko6uyc.add('+');
    Cko6uyc.add('2');
    Cko6uyc.add('y');
    Cko6uyc.add(']');
    Cko6uyc.add('-');
    Cko6uyc.add('(');
    Cko6uyc.add('z');
    Cko6uyc.add('+');
    Cko6uyc.add('4');
    Cko6uyc.add('x');
    Cko6uyc.add(')');
    Cko6uyc.add(')');
    Cko6uyc.add(';');

    Cko6uyc.show();
    cout << "\n\n";
    Cko6uyc.check();
}

// ■ Пример правильной строки : ({ x - y - z }*[x + 2y] - (z + 4x));
// ■ Пример неправильной строки : ([x - y - z}*[x + 2y) - {z + 4x)].
