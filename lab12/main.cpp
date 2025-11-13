#include "lab.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
using namespace std;

int main() {

    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);


    int n;
    cout << " кількість множин: ";
    cin >> n;

    vector<Set> sets(n);

    for (int i = 0; i < n; i++) {
        cout << "\n Множина №" << i + 1 << ":\n";
        sets[i].input();
    }

    cout << "\n Введені множини:\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ": ";
        sets[i].print();
        cout << " (кількість елементів: " << sets[i].size() << ")\n";
    }


//sort    
    sort(sets.begin(), sets.end(), [](const Set &a, const Set &b) {
        return a.size() < b.size();
    });

    cout << "\n Після сортування за кількістю елементів:\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ": ";
        sets[i].print();
        cout << " (" << sets[i].size() << " елементів)\n";
    }

    if (n >= 2) {
        Set diff = sets.back() - sets.front();
        cout << "\n Різниця множини з найбільшою і найменшою кількістю елементів:\n";
        diff.print();
        cout << endl;
    } else {
        cout << "\n Недостатньо множин для обчислення різниці.\n";
    }

    return 0;
}
