


#include "examHeader.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); 
    using namespace std;
    system("Color 0C");

    
    fenix::AdminMode wowo;
    fenix::GuestMode doode; // guest DarthFenix : qwerty123
    
    wowo.setAdmin();
   // doode.log_in();


    doode.log_in(); // вот и весь мэин)) а дальше перелет по функциям. даже незнаю хорошо это или плохо. ну по крайней мере не понятно



    int input = 8, answer = 12;
    

   


    cout << "= " << (static_cast<double>(input) / static_cast<double>(answer)) * 100;
    
    //wowo.menuTest();               // good
    //wowo.startTest("C++ basic.txt");
    wowo.showLastResult();
    fenix::crypton xxx;

    //doode.outputLoginData();

   // wowo.addTest();
   // fenix::AdminMode::setTest("sss");
    
    //cout << xxx.encrypt("ADMUH") << endl;
    // cout << xxx.encrypt("I7aPoJIb") << endl;
    cout << "\n\n\n";
    cout << xxx.decryption("І·ѕ¦»") << endl;
    cout << xxx.decryption("єД’Јњ№є‘") << endl;

  

    return 0;
}

