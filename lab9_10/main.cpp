#include "device.h"
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    vector<Device*> list;
    int n;

    cout << "Скільки приладів додати? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int type;
        cout << "\n1 - Мультиметр \n2 - Осцилограф \n Ваш вибір: ";
        cin >> type;

        Device* dev;
        if (type == 1)
            dev = new Multimeter();
        else
            dev = new Oscilloscope();

        dev->input();
        list.push_back(dev);
    }

    cout << "\n Список приладів \n";

    double totalPower = 0;
    for (auto d : list) {
        d->print();
        totalPower += d->getValue(); 
    }

    double avgPower = totalPower / list.size();

    cout << "\n Загальна споживана потужність: " << totalPower << " Вт\n";
    cout << "Середня потужність: " << avgPower << " Вт\n";

    for (auto d : list)
        delete d;

    return 0;
}
