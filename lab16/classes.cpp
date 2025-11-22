#include "classes.h"



Transistor::Transistor() : type("none"), gain(0), maxCurrent(0) {}


Transistor::Transistor(const std::string &t, double g, double mc)
    : type(t), gain(g), maxCurrent(mc) {}


Transistor::~Transistor() {
    std::cout << "Transistor destroyed\n";
}


void Transistor::input() {

    std::cout << "Enter type: ";
    std::getline(std::cin >> std::ws, type);


    std::cout << "Enter gain: ";
    std::cin >> gain;

    std::cout << "Enter max current: ";
    std::cin >> maxCurrent;

}

void Transistor::print() const {

    std::cout << "Type: " << type
              << ", Gain: " << gain
              << ", Max current: " << maxCurrent << "A\n";
}



Item::Item() {
    std::cout << "Item created\n";
}

Item::~Item() {
    std::cout << "Item destroyed\n";
}


//a
ChildA::ChildA() {
    std::cout << "ChildA created\n";
}
ChildA::~ChildA() {
    std::cout << "ChildA destroyed\n";
}


//b
ChildB::ChildB() {
    std::cout << "ChildB created\n";
}
ChildB::~ChildB() {
    std::cout << "ChildB destroyed\n";
}



List::List(const Transistor &t) : data(t) {}
void List::print() const {
    data.print();
}
