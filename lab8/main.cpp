#include "transistor.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    
    Transistor tr1("NPN", 100, 2.5);

    std::cout << "\nПочаткові дані:\n";
    tr1.printInfo();

    
    updateTransistor(tr1);

    std::cout << "\nПісля оновлення:\n";
    tr1.printInfo();

    return 0;
}
