#include "device.h"

Device::Device(std::string n, double p) : name(n), power(p) {}
Device::~Device() {}

void Device::input() {
    std::cout << "Введіть назву приладу: ";
    std::getline(std::cin >> std::ws, name);

    do {
        std::cout << "Введіть потужність : ";
        std::cin >> power;
        if (power <= 0) std::cout << "Помилка! Потужність > 0\n";
    } while (power <= 0);
}

void Device::print() const {
    std::cout << "Назва: " << name << ", Потужність: " << power << " Вт\n";
}

double Device::getValue() const { return power; }


Multimeter::Multimeter(std::string n, double p, double a)
    : Device(n, p), accuracy(a) {}

Multimeter::~Multimeter() {}

void Multimeter::input() {
    Device::input();
    do {
        std::cout << "Введіть точність : ";
        std::cin >> accuracy;
        if (accuracy <= 0) std::cout << "Помилка! Точність > 0\n";
    } while (accuracy <= 0);
}

void Multimeter::print() const {
    std::cout << "[Мультиметр] ";
    Device::print();
    std::cout << "Точність: " << accuracy << "\n";
}

double Multimeter::getValue() const { return accuracy; }



Oscilloscope::Oscilloscope(std::string n, double p, double b)
    : Device(n, p), bandwidth(b) {}

Oscilloscope::~Oscilloscope() {}

void Oscilloscope::input() {
    Device::input();
    do {
        std::cout << "Введіть смугу пропускання : ";
        std::cin >> bandwidth;
        if (bandwidth <= 0) std::cout << "Помилка! Значення > 0\n";
    } while (bandwidth <= 0);
}

void Oscilloscope::print() const {
    std::cout << "[Осцилограф] ";
    Device::print();
    std::cout << "Смуга пропускання: " << bandwidth << " MHz\n";
}

double Oscilloscope::getValue() const { return bandwidth; }
