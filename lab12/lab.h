#ifndef LAB_H
#define LAB_H

#include <iostream>
#include <vector>

class Set {
private:
    std::vector<int> elements; 

public:
    Set();
    void input();         
    void print() const;   
    int size() const;     

    bool operator>=(const Set &other) const;
    Set operator-(const Set &other) const;  
};

#endif
