#include <iostream>
#include "transistor.h"

int main() {

    
    Transistor tr;
    tr.input();
    tr.print();


    std::cout << "\n TEMPLATE GENERAL VERSION \n";
    Storage<int> s1(123);
    s1.print();


    std::cout << "\n PARTIAL SPECIALIZATION (Transistor)\n";
    Storage<Transistor> s2(tr);
    s2.print();


    std::cout << "\n FULL SPECIALIZATION (string) \n";
    Storage<std::string> s3("Hello template!");
    s3.print();

    return 0;
}
