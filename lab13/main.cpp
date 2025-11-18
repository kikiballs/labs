#include "device.h"
#include <vector>



int main() {
    system("chcp 65001 > nul");


    vector<device*> devices;

    try {
        cout << " Введення приладів \n";
        Multimetr m;
        m.input();

        Oscyloskop o;
        o.input();

        devices.push_back(new Multimetr(m));
        devices.push_back(new Oscyloskop(o));

        ofstream fout("devices.txt");
        if (!fout) throw runtime_error(" Не вдалося відкрити файл для запису ");
        for (auto p : devices) p->saveToFile(fout);
        fout.close();

        cout << "\n Дані збережено у файл devices.txt\n";

        cout << "\n  Вивід на екран \n";
        for (auto p : devices) p->print();

       
        if (*devices[0] > *devices[1])
            cout << "\n Перший прилад має більшу потужність.\n";
        else
            cout << "\n Другий прилад має більшу або рівну потужність.\n";

        
        ifstream fin("devices.txt");
        if (!fin) throw runtime_error(" Не вдалося відкрити файл для читання");
        cout << "\n Зчитування з файлу \n";
        string line;
        while (getline(fin, line))
            cout << line << endl;
        fin.close();
    }
    catch (exception &e) {
        cerr << "\n Помилка: " << e.what() << endl;
    }

    for (auto p : devices) delete p;
    return 0;
}
