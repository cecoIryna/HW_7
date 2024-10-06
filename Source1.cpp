#include <iostream>
#include "Header.h"
using namespace std;

int main() {
    DynamicArray a(5);
    a.Input();
    a.Output();

    cout << "Adding 10 elements:" << endl;
    DynamicArray b = a + 10;
    b.Output();

    cout << "Removing 2 elements:" << endl;
    DynamicArray c = a - 2;
    c.Output();

    cout << "Multiplying elements by 2:" << endl;
    DynamicArray d = a * 2;
    d.Output();

    cout << "Concatenating two arrays:" << endl;
    DynamicArray e = a + b;
    e.Output();

    cout << "Array difference:" << endl;
    DynamicArray f = a - b;
    f.Output();

    cout << "Incrementing array size by 1:" << endl;
    ++a;
    a.Output();

    cout << "Decrementing array size by 1:" << endl;
    --a;
    a.Output();

    return 0;
}
