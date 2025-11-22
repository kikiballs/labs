#ifndef CLASSES_H
#define CLASSES_H


#include <iostream>
#include <memory>
#include <string>


class Transistor {
private:
    std::string type;
    double gain;
    double maxCurrent;



public:
    Transistor();
    Transistor(const std::string &t, double g, double mc);
    ~Transistor();
    void input();
    void print() const;
};




class Item {
public:
    Item();
    ~Item();
};



class ChildB;


class ChildA {
public:
    std::shared_ptr<ChildB> b;
    ChildA();
    ~ChildA();
};



class ChildB {
public:
    std::weak_ptr<ChildA> a;
    ChildB();
    ~ChildB();
};




class List {
public:
    Transistor data;
    std::shared_ptr<List> next;
    std::weak_ptr<List> prev;

    List(const Transistor &t);
    void print() const;
};


#endif
