#ifndef TRANSISTOR_H
#define TRANSISTOR_H

#include <iostream>
#include <string>


class Transistor {
private:
    std::string type;
    double gain;
    double maxCurrent;

public:
    Transistor();
    Transistor(const std::string &t, double g, double mc);

    void input();
    void print() const;
};



template <typename T>
class Storage {
private:
    T value;

public:
    Storage(T v) : value(v) {}

    void print() const {
        std::cout << "Value: " << value << "\n";
    }
};



template <>
class Storage<Transistor> {
private:
    Transistor value;

public:
    Storage(Transistor t) : value(t) {}

    void print() const {
        std::cout << "Transistor stored:\n";
        value.print();
    }
};



template <>
class Storage<std::string> {
private:
    std::string value;

public:
    Storage(std::string s) : value(s) {}

    void print() const {
        std::cout << "STRING (specialized): [" << value << "]\n";
    }
};

#endif
