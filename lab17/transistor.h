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





template <typename T1, typename T2>
class Storage {
private:
    T1 value1;
    T2 value2;

public:
    Storage(T1 v1, T2 v2) : value1(v1), value2(v2) {}

    void print() const {
        std::cout << "General Storage: (" << value1 << ", " << value2 << ")\n";
    }
};





template <typename T2>
class Storage<Transistor, T2> {
private:
    Transistor tr;
    T2 extra;

public:
    Storage(Transistor t, T2 e) : tr(t), extra(e) {}

    void print() const {
        std::cout << "PARTIAL SPECIALIZATION Storage<Transistor, T2>:\n";
        tr.print();
        std::cout << "Extra value: " << extra << "\n";
    }
};




template <>
class Storage<Transistor, std::string> {
private:
    Transistor tr;
    std::string label;

public:
    Storage(Transistor t, std::string s) : tr(t), label(s) {}

    void print() const {
        std::cout << "FULL SPECIALIZATION Storage<Transistor, std::string>:\n";
        std::cout << "Label: " << label << "\n";
        tr.print();
    }
};

#endif
