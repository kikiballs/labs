#ifndef TRANSISTOR_H
#define TRANSISTOR_H

#include <iostream>
#include <array>
#include <string>

const int SIZE_TBL = 5; // розмір масиву

// Структура для зберігання даних про транзистор
struct transistor_s_t {
    std::string type;     // тип транзистора
    double gain;          // коефіцієнт підсилення
    double maxCurrent;    // максимальний струм
};

// Клас для роботи з масивом транзисторів
class Transistor {
private:
    std::array<transistor_s_t, SIZE_TBL> transistors;
    int count; // кількість введених елементів

public:
    Transistor();  // конструктор
    ~Transistor(); // деструктор

    void addTransistor(const std::string &type, double gain, double maxCurrent);
    void printAll() const;
    void updateGain(int index, double newGain);
    void updateMaxCurrent(int index, double newMaxCurrent);

    void inputTransistor();
};

#endif
