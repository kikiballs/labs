#include "transistor.h"

// Конструктор
Transistor::Transistor() {
    count = 0;
    std::cout << "Об'єкт Transistor створено.\n";
}

// Деструктор
Transistor::~Transistor() {
    std::cout << "Об'єкт Transistor знищено.\n";
}

// Додавання нового транзистора
void Transistor::addTransistor(const std::string &type, double gain, double maxCurrent) {
    if (count < SIZE) {
        if (gain <= 0 || maxCurrent <= 0) {
            std::cout << " Помилка: некоректні дані.\n";
            return;
        }
        transistors[count] = { type, gain, maxCurrent };
        count++;
    } else {
        std::cout << " Масив заповнено!\n";
    }
}

// Виведення всіх транзисторів
void Transistor::printAll() const {
    if (count == 0) {
        std::cout << "Масив порожній.\n";
        return;
    }
    for (int i = 0; i < count; i++) {
        std::cout << "Транзистор " << i + 1 << ":\n";
        std::cout << "  Тип: " << transistors[i].type << "\n";
        std::cout << "  Коефіцієнт підсилення: " << transistors[i].gain << "\n";
        std::cout << "  Максимальний струм: " << transistors[i].maxCurrent << " A\n";
    }
}

// Оновлення коефіцієнта підсилення
void Transistor::updateGain(int index, double newGain) {
    if (index < 0 || index >= count || newGain <= 0) {
        std::cout << " Некоректне оновлення.\n";
        return;
    }
    transistors[index].gain = newGain;
}

// Оновлення максимального струму
void Transistor::updateMaxCurrent(int index, double newMaxCurrent) {
    if (index < 0 || index >= count || newMaxCurrent <= 0) {
        std::cout << " Некоректне оновлення.\n";
        return;
    }
    transistors[index].maxCurrent = newMaxCurrent;
}
