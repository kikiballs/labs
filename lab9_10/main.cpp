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
        cout << "\n1 - Мультиметр \n 2 - Осцилограф \n Ваш вибір: ";
        cin >> type;

        Device* d;
        if (type == 1) d = new Multimeter();
        else d = new Oscilloscope();

        d->input();
        list.push_back(d);
    }

    cout << "\n Список приладів \n";
    double total = 0;

    for (auto d : list) {
        d->print();
        total += d->getValue();
    }

    cout << "\n Сумарний параметр = " << total << "\n";

    for (auto d : list) delete d;
}
