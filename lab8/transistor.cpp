#include "transistor.h"


Transistor::Transistor() {
    type = "Без типу";
    gain = 0;
    maxCurrent = 0;
    std::cout << "Створено об'єкт Transistor (за замовчуванням)\n";
}

Transistor::Transistor(const std::string &type, double gain, double maxCurrent) {
    this->type = type;
    this->gain = gain;
    this->maxCurrent = maxCurrent;
    std::cout << "Створено об'єкт Transistor (з параметрами)\n";
}


Transistor::~Transistor() {
    std::cout << "Об'єкт Transistor знищено\n";
}

void Transistor::setType(const std::string &t) { type = t; }

void Transistor::setGain(double g) {
    if (g > 0) gain = g;
    else std::cout << " Некоректне значення коефіцієнта підсилення.\n";
}

void Transistor::setMaxCurrent(double i) {
    if (i > 0) maxCurrent = i;
    else std::cout << " Некоректне значення струму.\n";
}

std::string Transistor::getType() const { return type; }
double Transistor::getGain() const { return gain; }
double Transistor::getMaxCurrent() const { return maxCurrent; }

void Transistor::printInfo() const {
    std::cout << "Тип: " << type
              << ", Підсилення: " << gain
              << ", Максимальний струм: " << maxCurrent << "A\n";
}

void updateTransistor(Transistor &tr) {
    std::string newType;
    double newGain, newCurrent;

    std::cout << "\n=== Оновлення даних транзистора через посилання ===\n";
    std::cout << "Поточні дані:\n";
    tr.printInfo();

    std::cout << "\nВведіть новий тип: ";
    std::getline(std::cin >> std::ws, newType);

    std::cout << "Введіть новий коефіцієнт підсилення: ";
    std::cin >> newGain;

    std::cout << "Введіть новий максимальний струм (A): ";
    std::cin >> newCurrent;

    tr.setType(newType);
    tr.setGain(newGain);
    tr.setMaxCurrent(newCurrent);

    std::cout << "✅ Дані транзистора оновлено!\n";
}
