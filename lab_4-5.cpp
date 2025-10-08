#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
using namespace std;

class Transistor {
private:
    string type;       
    double gain;      
    double maxCurrent;

public:
    
    Transistor() {
        type = "Default";
        gain = 1.0;
        maxCurrent = 1.0;
        cout << "Створено транзистор за замовчуванням.\n";
    }

   
    Transistor(string t, double g, double c) {
        setType(t);
        setGain(g);
        setMaxCurrent(c);
        cout << "Створено транзистор з параметрами.\n";
    }

   
    ~Transistor() {
        cout << "Знищено транзистор: " << type << endl;
    }

    
    void setType(string t) {
        if (t == "pnp" || t == "npn") {
            type = t;
        } else {
            cout << "Помилка: невідомий тип транзистора!\n";
            type = "Unknown";
        }
    }

    void setGain(double g) {
        if (g <= 0) {
            cout << "Помилка: коефіцієнт підсилення має бути > 0!\n";
            gain = 1.0;
        } else {
            gain = g;
        }
    }

    void setMaxCurrent(double c) {
        if (c <= 0) {
            cout << "Помилка: максимальний струм має бути > 0!\n";
            maxCurrent = 1.0;
        } else {
            maxCurrent = c;
        }
    }

   
    void input() {
        cout << "\nВведіть дані для транзистора:\n";

        cout << "Тип (pnp / npn): ";
        string t;
        cin >> t;
        setType(t);

        cout << "Коефіцієнт підсилення: ";
        double g;
        cin >> g;
        setGain(g);

        cout << "Максимальний струм (A): ";
        double c;
        cin >> c;
        setMaxCurrent(c);
    }

  
    void display() const {
        cout << "Транзистор [Тип: " << type
             << ", Підсилення: " << gain
             << ", Макс. струм: " << maxCurrent << " A]\n";
    }

  
    bool hasGainMoreThan(double n) const {
        return gain > n;
    }

    bool canHandleCurrent(double c) const {
        return maxCurrent >= c;
    }
};

int main() {
    SetConsoleOutputCP(65001);  
    SetConsoleCP(65001); 
    

  
    Transistor defaultTransistor;
    defaultTransistor.display();

   
    Transistor npnTransistor("npn", 150.0, 5.0);
    npnTransistor.display();

   
    Transistor customTransistor;
    customTransistor.input();
    customTransistor.display();

   
    vector<Transistor> transistors = {
        defaultTransistor,
        npnTransistor,
        customTransistor
    };

    cout << "\n--- Транзистори з коефіцієнтом підсилення більше 100 ---\n";
    bool found = false;
    for (const auto &t : transistors) {
        if (t.hasGainMoreThan(100)) {
            t.display();
            found = true;
        }
    }
    if (!found)
        cout << "Немає транзисторів з таким коефіцієнтом.\n";

    cout << "\n--- Транзистори, що витримують струм не менше 3 A ---\n";
    found = false;
    for (const auto &t : transistors) {
        if (t.canHandleCurrent(3.0)) {
            t.display();
            found = true;
        }
    }
    if (!found)
        cout << "Немає транзисторів, що витримують 3 A.\n";

    return 0;
}
