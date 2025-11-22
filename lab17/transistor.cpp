#include "transistor.h"
#include <iostream>

Transistor::Transistor() : type("none"), gain(0), maxCurrent(0) {}

Transistor::Transistor(const std::string &t, double g, double mc)
    : type(t), gain(g), maxCurrent(mc) {}

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
              << ", MaxCurrent: " << maxCurrent << "A\n";
}
