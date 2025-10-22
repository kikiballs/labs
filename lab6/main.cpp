#include "transistor.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001);  
    SetConsoleCP(65001);
    Transistor collection;

    collection.addTransistor("NPN", 100, 2.5);
    collection.addTransistor("PNP", 120, 3.0);
    collection.addTransistor("MOSFET", 200, 5.0);

    std::cout << "\n Початкові дані:\n";
    collection.printAll();

    std::cout << "\n Оновлення данихфіів:\n";
    collection.updateGain(1, 150);
    collection.updateMaxCurrent(0, 3.2);
    collection.inputTransistor(); 


    collection.printAll();

    return 0;
}

