#ifndef TRANSISTOR_H
#define TRANSISTOR_H

#include <iostream>
#include <string>
#include <vector>

struct transistor_s_t {
    std::string type;
    double gain;
    double maxCurrent;
};

class Transistor {
private:
    std::vector<transistor_s_t> transistors; 

public:
    Transistor();
    ~Transistor();

    void addTransistor(const std::string &type, double gain, double maxCurrent);
    void printAll() const;
    void updateGain(int index, double newGain);
    void updateMaxCurrent(int index, double newMaxCurrent);

    void removeTransistor(int index); 
    void clearAll();                  
    void inputTransistor();       
    
        
    void insertTransistor(int index, const std::string &type, double gain, double maxCurrent);
    void swapTransistors(int index1, int index2);


};

#endif
