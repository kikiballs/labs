#include <iostream>
#include "transistor.h"

int main() {


    Transistor tr;
    tr.input();
    tr.print();

 
    std::cout << "\nGENERAL TEMPLATE VERSION\n";
    Storage<int, double> s1(123, 4.56);
    s1.print();

    std::cout << "\nPARTIAL SPECIALIZATION: Storage<Transistor, int>\n";
    Storage<Transistor, int> s2(tr, 10);
    s2.print();

  
    std::cout << "\nFULL SPECIALIZATION: Storage<Transistor, std::string>\n";
    Storage<Transistor, std::string> s3(tr, "Power transistor");
    s3.print();

    return 0;
}
