
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <chrono>
#include <vector>


int main(int argc, char *argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    using namespace std;
    //////////////////////////////////
    srand(time(NULL));

    int col = 0, row = 0, count = 0;
    
    cout << "Введите Размер массива" << endl;
    cout << "Количество столбцов " << endl;
    cin >> col;
    cout << "Количество строк" << endl;
    cin >> row;

    vector<vector<int> >arrLekin(col, vector<int>(row));

    int maxxx = col > row ? col : row;

    vector<vector<int> >Max(maxxx, vector<int>(3));
    vector<vector<int> >Min(maxxx, vector<int>(3));

    for (size_t i = 0; i < col; i++) {
        for (size_t j = 0; j < row; j++) {
            arrLekin[i][j] = rand()% 10; // i * col + j  для заполнения по возр.
        }
    }

    for (size_t i = 0; i < col; i++) {
        Min[i][0] = arrLekin[i][0];
        Min[i][1] = i;
        Min[i][2] = 0;
        for (size_t j = 1; j < row; j++) {

            if (arrLekin[i][j] < Min[i][0]){
                Min[i][0] = arrLekin[i][j]; 
                Min[i][1] = i;     
                Min[i][2] = j;    
            }
        }
    }

    for (size_t j = 0; j < row; j++) {
        Max[j][0] = arrLekin[0][j];
        Max[j][0] = 0;
        Max[j][0] = j;
        for (size_t i = 1; i < col; i++) {

            if (arrLekin[i][j] > Max[j][0]) {
                Max[j][0] = arrLekin[i][j];
                Max[j][1] = i; 
                Max[j][2] = j; 
            }
        }
    }

    for (size_t i = 0; i < col; i++) {
        for (size_t j = 0; j < row; j++) {

            if (Min[i][0] == Max[j][0] && Min[i][1] == Max[j][1] && Min[i][2] == Max[j][2]){
                cout << "Седловая точка найдена ее координаты: " << i << " вертикаль " << j << " горизонталь\nКрч это число -> " << arrLekin[i][j];
                count++;
            }
        }
    }
    if (count==0) {
        cout << "Седловая точка не найдена\n";
    }
    
    cout << "\n\n";
    for (size_t i = 0; i < col; i++) {
        for (size_t j = 0; j < row; j++) {

            cout << arrLekin[i][j] << " ";
        }
        cout << endl;
    }


    //////////////////////////////////
    cout << "argument number: " << argc << endl;

    cout << "1: " << argv[0] << endl;
    cout << "2: " << argv[1] << endl;
    cout << "3: " << argv[2] << endl;


    ////////////////////

    fstream project_B("project_C.txt", ios::in | ios::out); //, ios::in | ios::out

    if (!project_B) {
        cout << "Error";
        exit(1);
    }
    else {
        cout << "Файл успешно загружен";
    }
    

    project_B << "Здесь был люциус даяниус VII \n";
    //project_B.close();
    /////
    // #2
   // fstream project_B("project_C.txt", ios::in | ios::out);

    string names[] = { "А также", "Людвиг ван бетховен", "Беннедикт камбербетч", "карлос гонсалес IV", "Сильвио ла фарель", "Феликс де цефалони", "Фергюсон великий" };
    
    for (size_t i = 0; i < names[0].size(); i++) {
        project_B << names[i] << "\n";
    }
    
    project_B.close();



}
