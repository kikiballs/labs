#include "device.h"
#include "friend.h"
#include <iostream>
#include <vector>
#include <windows.h>
#include <limits>

using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    vector<Device*> devices;

    int n;
    cout << "Скільки приладів бажаєте додати? ";
    while (!(cin >> n) || n <= 0) {
        cout << "Введіть ціле число: ";
        cin.clear();
        cin.ignore( numeric_limits <streamsize>::max(), '\n');
    }



    for (int i = 0; i < n; ++i) {
        cout << "\n Прилад #" << (i + 1) << " \n";
        cout << "Оберіть тип приладу: 1 - Мультиметр, 2 - Осцилограф : ";
        int type;
        while (!(cin >> type) || (type != 1 && type != 2)) {
            cout << "Введіть 1 або  2: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

        Device* dev = nullptr;
        if (type == 1) {
            dev = new Multimeter();
        } else {
            dev = new Oscilloscope();
        }

        dev->input();           
        devices.push_back(dev);
    }


    cout << " Введені прилади \n";
    for (auto d : devices) d->print();


    FriendDevice fd;
    cout << "\n  Показ деталей першого приладу (як приклад):\n";
    if (!devices.empty()) fd.showDetails(*devices[0]);


    if (devices.size() >= 2) {
        cout << "\n  Порівняння потужності між 1 та 2 приладом:\n";
        fd.comparePower(*devices[0], *devices[1]);
    }


    double total = fd.totalPower(devices);
    cout << "\n Загальна потужність  усіх  приладів: " << total << " Вт\n";


    for (auto d : devices) delete d;
    devices.clear();

    return 0;
}
