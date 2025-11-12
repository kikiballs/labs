#include "friend.h"
#include <iostream>
using namespace std;

void FriendDevice::showDetails(const Device &d) {
    cout << "\n Назва: " << d.name << ", Потужність: " << d.power << " Вт\n";
}

void FriendDevice::comparePower(const Device &d1, const Device &d2) {
   
    if (d1.power > d2.power)
        cout << d1.name << " споживає більше енергії, ніж " << d2.name << ".\n";
    else if (d1.power < d2.power)
        cout << d2.name << " споживає більше енергії, ніж " << d1.name << ".\n";
    else
        cout << "Обидва прилади мають однакову потужність.\n";
}

double FriendDevice::totalPower(const vector<Device*> &devices) {
    double sum = 0;
    for (auto d : devices)
        sum += d->power;
    return sum;
}
