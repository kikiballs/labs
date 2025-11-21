#include "transistor.h"

int main() {
    system("chcp 65001 > nul");


    TransistorList list;

    list.addFront("NPN", 100, 2.5);
    list.addBack("PNP", 120, 3.2);
    list.addAfter("NPN", "MOSFET", 200, 5.0);

    std::cout << " Початковий список \n";
    list.print();

    std::cout << "\n Ввід нового транзистора \n";
    list.inputTransistor();

    std::cout << "\n Після вводу \n";
    list.print();

    list.removeFront();
    list.removeBack();
    list.removeByType("MOSFET");

    std::cout << "\n Після видалень \n";
    list.print();

    return 0;
}
