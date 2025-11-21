#include "transistor.h"
#include <limits>


TransistorList::TransistorList() : head(nullptr) {}


TransistorList::~TransistorList() {
    Node* cur = head;
    while (cur) {
        Node* next = cur->next;
        delete cur;
        cur = next;
    }
    head = nullptr;
}

bool TransistorList::isEmpty() const {
    return head == nullptr;
}


void TransistorList::addFront(const std::string &type, double gain, double maxCurrent) {
    Node* n = new Node(type, gain, maxCurrent);
    n->next = head;
    head = n;
}

void TransistorList::addBack(const std::string &type, double gain, double maxCurrent) {
    Node* n = new Node(type, gain, maxCurrent);

    if (isEmpty()) {
        head = n;
        return;
    }

    Node* cur = head;
    while (cur->next != nullptr)
        cur = cur->next;

    cur->next = n;
}

void TransistorList::addAfter(const std::string &afterType,
                              const std::string &type,
                              double gain,
                              double maxCurrent)
{
    Node* cur = head;
    while (cur && cur->type != afterType)
        cur = cur->next;

    if (!cur) {
        std::cout << "Елемент не знайдено\n";
        return;
    }

    Node* n = new Node(type, gain, maxCurrent);
    n->next = cur->next;
    cur->next = n;
}


void TransistorList::removeFront() {
    if (isEmpty()) return;

    Node* temp = head;
    head = head->next;
    delete temp;
}

void TransistorList::removeBack() {
    if (isEmpty()) return;

    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }

    Node* cur = head;
    while (cur->next->next != nullptr)
        cur = cur->next;

    delete cur->next;
    cur->next = nullptr;
}

void TransistorList::removeByType(const std::string &type) {
    if (isEmpty()) return;

    if (head->type == type) {
        removeFront();
        return;
    }

    Node* cur = head;
    while (cur->next && cur->next->type != type)
        cur = cur->next;

    if (!cur->next) return;

    Node* temp = cur->next;
    cur->next = temp->next;
    delete temp;
}


void TransistorList::print() const {
    if (isEmpty()) {
        std::cout << "Список порожній.\n";
        return;
    }

    Node* cur = head;
    while (cur) {
        std::cout << "Тип: " << cur->type
                  << ", Підсилення: " << cur->gain
                  << ", Imax: " << cur->maxCurrent << "A\n";
        cur = cur->next;
    }
}


void TransistorList::inputTransistor() {
    std::string type, gainStr, curStr;
    double gain = 0, maxC = 0;

    std::cout << "Введіть тип транзистора: ";
    std::getline(std::cin >> std::ws, type);

    std::cout << "Введіть коефіцієнт підсилення: ";
    std::getline(std::cin, gainStr);
    gain = std::stod(gainStr);

    std::cout << "Введіть максимальний струм: ";
    std::getline(std::cin, curStr);
    maxC = std::stod(curStr);

    addBack(type, gain, maxC);
}
