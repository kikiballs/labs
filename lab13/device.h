#ifndef DEVICE_H
#define DEVICE_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
using namespace std;



class device {
protected:
    string name;
    double power; 


public:
    device(string n = "Невідомий прилад", double p = 0.0);
    virtual ~device();

    virtual void input();                    
    virtual void print() const;               
    virtual void saveToFile(ofstream &fout) const; 
    virtual void readFromFile(ifstream &fin);   


    bool operator>(const device &other) const; 

};



class Multimetr : public device {
private:

    double accuracy; 

public:

    Multimetr(string n = "Мультиметр", double p = 0.0, double a = 0.0);
    void input() override;
    void print() const override;
    void saveToFile(ofstream &fout) const override;
    void readFromFile(ifstream &fin) override;

};



class Oscyloskop : public device {
private:

    double frequency; 

public:

    Oscyloskop(string n = "Осцилограф", double p = 0.0, double f = 0.0);
    void input() override;
    void print() const override;
    void saveToFile(ofstream &fout) const override;
    void readFromFile(ifstream &fin) override;

};


#endif
