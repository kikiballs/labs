#include "device.h"
#include <iostream>
using namespace std;


//device
Device::Device(string n, double p) : name(n), power(p) {}
Device::~Device() {}

void Device::input() {
    cout << "Введіть назву приладу: ";
    getline(cin >> ws, name);
    cout << "Введіть потужність : ";
    cin >> power;
}

void Device::print() const {
    cout << "Назва: " << name << ", Потужність: " << power << " Вт";
}

double Device::getPower() const {
    return power;
}


//:multimeter
Multimeter::Multimeter(string n, double p, double a)
    : Device(n, p), accuracy(a) {}

Multimeter::~Multimeter() {}

void Multimeter::input() {
    Device::input();
    cout << "Введіть точність (%): ";
    cin >> accuracy;
}

void Multimeter::print() const {
    cout << "[Мультиметр] ";
    Device::print();
    cout << ", Точність: " << accuracy << "%\n";
}



//:oscilloscope
Oscilloscope::Oscilloscope(string n, double p, double b)
    : Device(n, p), bandwidth(b) {}

Oscilloscope::~Oscilloscope() {}

void Oscilloscope::input() {
    Device::input();
    cout << "Введіть смугу пропускання : ";
    cin >> bandwidth;
}

void Oscilloscope::print() const {
    cout << "[Осцилограф] ";
    Device::print();
    cout << ", Смуга пропускання: " << bandwidth << " МГц\n";
}
