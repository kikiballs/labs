#ifndef DEVICE_H
#define DEVICE_H

#include <iostream>
#include <string>
#include <vector>

class Device {
private:
    std::string name;
    double power;

public:
    Device(std::string n = "", double p = 0);
    virtual ~Device();

    virtual void input();
    virtual void print() const;
    virtual double getValue() const; 
};

class Multimeter : public Device {
private:
    double accuracy;

public:
    Multimeter(std::string n = "", double p = 0, double a = 0);
    ~Multimeter();

    void input() override;
    void print() const override;
};

class Oscilloscope : public Device {
private:
    double bandwidth;

public:
    Oscilloscope(std::string n = "", double p = 0, double b = 0);
    ~Oscilloscope();

    void input() override;
    void print() const override;
};

#endif
