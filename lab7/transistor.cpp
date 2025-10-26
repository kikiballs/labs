#include "transistor.h"

Transistor::Transistor() {
    std::cout << "Об'єкт Transistor створено.\n";
}

Transistor::~Transistor() {
    std::cout << "Об'єкт Transistor знищено.\n";
}

void Transistor::addTransistor(const std::string &type, double gain, double maxCurrent) {
    if (gain <= 0 || maxCurrent <= 0) {
        std::cout << " Некоректні дані!\n";
        return;
    }
    transistors.push_back({type, gain, maxCurrent});
}

// Виведення всіх транзисторів
void Transistor::printAll() const {
    if (transistors.empty()) {
        std::cout << "Масив порожній.\n";
        return;
    }
    std::cout << "\n===== Список транзисторів =====\n";
    for (size_t i = 0; i < transistors.size(); ++i) {
        std::cout << i + 1 << ". "
                  << "Тип: " << transistors[i].type
                  << ", Підсилення: " << transistors[i].gain
                  << ", Iмакс: " << transistors[i].maxCurrent << "A\n";
    }
}


void Transistor::updateGain(int index, double newGain) {
    if (index < 0 || index >= (int)transistors.size() || newGain <= 0) {
        std::cout << " Некоректне оновлення!\n";
        return;
    }
    transistors[index].gain = newGain;
}

void Transistor::updateMaxCurrent(int index, double newMaxCurrent) {
    if (index < 0 || index >= (int)transistors.size() || newMaxCurrent <= 0) {
        std::cout << " Некоректне оновлення!\n";
        return;
    }
    transistors[index].maxCurrent = newMaxCurrent;
}

void Transistor::removeTransistor(int index) {
    if (index < 0 || index >= (int)transistors.size()) {
        std::cout << " Некоректний індекс!\n";
        return;
    }
    transistors.erase(transistors.begin() + index);
    std::cout << "✅ Транзистор видалено.\n";
}


void Transistor::clearAll() {
    transistors.clear();
    std::cout << "✅ Всі транзистори видалено.\n";
}


void Transistor::inputTransistor() {
    std::string type, gainStr, currentStr;
    double gain = 0, maxCurrent = 0;

    std::cout << "\n=== Введення нового транзистора ===\n";
    std::cout << "Введіть тип транзистора: ";
    std::getline(std::cin >> std::ws, type);

    std::cout << "Введіть коефіцієнт підсилення: ";
    std::getline(std::cin, gainStr);
    gain = std::stod(gainStr);

    std::cout << "Введіть максимальний струм (A): ";
    std::getline(std::cin, currentStr);
    maxCurrent = std::stod(currentStr);

    addTransistor(type, gain, maxCurrent);
}
