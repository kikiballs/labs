#include "lab.h"
#include <algorithm>

Set::Set() {}

void Set::input() {
    int n;
    std::cout << "Введіть кількість елементів: ";
    std::cin >> n;
    elements.clear();
    for (int i = 0; i < n; i++) {
        int x;
        std::cout << "Елемент " << i + 1 << ": ";
        std::cin >> x;
        
        if (std::find(elements.begin(), elements.end(), x) == elements.end())
            elements.push_back(x);
        else
            std::cout << "Такий елемент вже є, пропущено.\n";
    }
}

void Set::print() const {
    std::cout << "{ ";
    for (int el : elements) std::cout << el << " ";
    std::cout << "}";
}

int Set::size() const {
    return elements.size();
}

bool Set::operator>=(const Set &other) const {
    return this->elements.size() >= other.elements.size();
}

Set Set::operator-(const Set &other) const {
    Set result;
    for (int el : elements)
        if (std::find(other.elements.begin(), other.elements.end(), el) == other.elements.end())
            result.elements.push_back(el);
    return result;
}
