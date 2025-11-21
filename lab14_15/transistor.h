#ifndef TRANSISTOR_H
#define TRANSISTOR_H

#include <string>
#include <iostream>

struct Node {
    std::string type;
    double gain;
    double maxCurrent;
    Node* next;

    Node(const std::string &t, double g, double m)
        : type(t), gain(g), maxCurrent(m), next(nullptr) {}
};

class TransistorList {
private:
    Node* head;

public:
    TransistorList();
    ~TransistorList();

    bool isEmpty() const;

    void addFront(const std::string &type, double gain, double maxCurrent);
    void addBack(const std::string &type, double gain, double maxCurrent);
    void addAfter(const std::string &afterType,
                  const std::string &type,
                  double gain,
                  double maxCurrent);

    void removeFront();
    void removeBack();
    void removeByType(const std::string &type);

    void print() const;

    void inputTransistor(); 
};

#endif
