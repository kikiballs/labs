#include "device.h"




device::device(string n, double p) : name(n), power(p) {}
device::~device() {}

void device::input() {

    cout << "Введіть назву приладу: ";
    cin >> name;
    cout << "Введіть потужність : ";
    cin >> power;
    if (power < 0)
        throw invalid_argument(" Потужність не може бути від'ємною ");

}

void device::print() const {

    cout << "Прилад: " << name << ", потужність: " << power << " Вт\n";

}

void device::saveToFile(ofstream &fout) const {

    if (!fout)

        throw runtime_error(" Помилка відкриття файлу для запису");

    fout << name << " " << power << endl;
}

void device::readFromFile(ifstream &fin) {
    if (!fin)
        throw runtime_error(" Помилка відкриття файлу для читання");

    fin >> name >> power;
}

bool device::operator>(const device &other) const {
    return power > other.power;
}



Multimetr::Multimetr(string n, double p, double a)
    : device(n, p), accuracy(a) {}


void Multimetr::input() {
    cout << "Введіть назву мультиметра: ";
    cin >> name;
    cout << "Введіть потужність : ";
    cin >> power;
    cout << "Введіть точність : ";
    cin >> accuracy;
    if (accuracy <= 0)
        throw invalid_argument(" Точність повинна бути більшою за 0");
}

void Multimetr::print() const {
    cout << "Мультиметр: " << name << ", потужність: " << power
         << " Вт, точність: " << accuracy << " %\n";
}

void Multimetr::saveToFile(ofstream &fout) const {
    device::saveToFile(fout);
    fout << accuracy << endl;
}

void Multimetr::readFromFile(ifstream &fin) {
    device::readFromFile(fin);
    fin >> accuracy;
}




Oscyloskop::Oscyloskop(string n, double p, double f)
    : device(n, p), frequency(f) {}

void Oscyloskop::input() {
    cout << "Введіть назву осцилографа: ";
    cin >> name;
    cout << "Введіть потужність : ";
    cin >> power;
    cout << "Введіть максимальну частоту : ";
    cin >> frequency;
    if (frequency <= 0)
        throw invalid_argument(" Частота повинна бути більшою за 0");
}


void Oscyloskop::print() const {
    cout << "Осцилограф: " << name << ", потужність: " << power
         << " Вт, макс. частота: " << frequency << " Гц\n";
}


void Oscyloskop::saveToFile(ofstream &fout) const {
    device::saveToFile(fout);
    fout << frequency << endl;
}


void Oscyloskop::readFromFile(ifstream &fin) {
    device::readFromFile(fin);
    fin >> frequency;
}
