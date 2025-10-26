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
    Transistor(const std::string &type, double gain, double maxCurrent);
    ~Transistor();

    void setType(const std::string &t);
    void setGain(double g);
    void setMaxCurrent(double i);

    std::string getType() const;
    double getGain() const;
    double getMaxCurrent() const;

    void printInfo() const;
};


void updateTransistor(Transistor &tr);

#endif
