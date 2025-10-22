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
    if (count < SIZE_TBL) {
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


void Transistor::inputTransistor() {
    if (count >= SIZE_TBL) {
        std::cout << "⚠️ Масив заповнено, не можна додати новий транзистор.\n";
        return;
    }

    std::string type;
    double gain = 0, maxCurrent = 0;

    std::cout << "\n=== Введення нового транзистора ===\n";

    std::cout << "Введіть тип транзистора: ";
    std::cin >> type;

    do {
        std::cout << "Введіть коефіцієнт підсилення (>0): ";
        std::cin >> gain;
        if (gain <= 0)
            std::cout << "Помилка! Введіть число більше за 0.\n";
    } while (gain <= 0);

    do {
        std::cout << "Введіть максимальний струм (A, >0): ";
        std::cin >> maxCurrent;
        if (maxCurrent <= 0)
            std::cout << "Помилка! Введіть число більше за 0.\n";
    } while (maxCurrent <= 0);

    addTransistor(type, gain, maxCurrent);
    std::cout << "✅ Транзистор успішно додано!\n";
}
