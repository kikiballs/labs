#include "transistor.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    Transistor list;

    list.addTransistor("NPN", 100, 2.5);
    list.addTransistor("PNP", 120, 3.0);
    list.printAll();

    list.inputTransistor();     
    list.printAll();

    list.updateGain(0, 150);
    list.updateMaxCurrent(1, 3.3);

    list.removeTransistor(1);
    list.printAll();

    list.clearAll();
    list.printAll();

    return 0;
}
