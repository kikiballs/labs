#include <iostream>
#include <memory>
#include "classes.h"

using namespace std;

int main() {

    Transistor tr;
    tr.input();
    tr.print();


    cout << "\n UNIQUE_PTR DEMO \n";
    unique_ptr<Item> item1 = make_unique<Item>();

   

    unique_ptr<Item> item2 = std::move(item1);
    cout << "item1 after move: " << item1.get() << endl;
    cout << "item2 after move: " << item2.get() << endl;


    cout << "\n SHARED_PTR DEMO \n";
    shared_ptr<Item> spMain = make_shared<Item>();

    shared_ptr<Item> spCopy1 = spMain;
    shared_ptr<Item> spCopy2 = spMain;

    cout << "use_count before block: " << spMain.use_count() << endl;

    {
        shared_ptr<Item> spInner = spMain;
        cout << "use_count inside block: " << spMain.use_count() << endl;
    }

    cout << "use_count after block: " << spMain.use_count() << endl;


    // ===== ПУНКТ 4: WEAK_PTR =====
    cout << "\n WEAK_PTR DEMO \n";

    weak_ptr<ChildA> weakA;
    weak_ptr<ChildB> weakB;

    {
        shared_ptr<ChildA> a = make_shared<ChildA>();
        shared_ptr<ChildB> b = make_shared<ChildB>();

        a->b = b;  
        b->a = a;  

        weakA = a;
        weakB = b;

        cout << "A use_count inside block: " << a.use_count() << endl;
        cout << "B use_count inside block: " << b.use_count() << endl;
    }

    cout << boolalpha;
    cout << "After block: weakA.expired() = " << weakA.expired() << endl;
    cout << "After block: weakB.expired() = " << weakB.expired() << endl;
    cout << "Objects destroyed without memory leak.\n";


    cout << "\n DOUBLE-LINKED LIST \n";

    auto n1 = make_shared<List>(Transistor("NPN", 100, 2.5));
    auto n2 = make_shared<List>(Transistor("PNP", 120, 3.0));
    auto n3 = make_shared<List>(Transistor("MOSFET", 150, 5.0));

    n1->next = n2;
    n2->prev = n1;

    n2->next = n3;
    n3->prev = n2;

    cout << "\nForward:\n";
    n1->print();
    n2->print();
    n3->print();

    cout << "\nBackward:\n";
    auto p = n3->prev.lock();
    p->print();

    p = p->prev.lock();
    p->print();

    return 0;
}
