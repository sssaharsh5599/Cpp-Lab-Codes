#include <iostream>
using namespace std;

class B;

class A {
    int x;

public:
    A(int v = 0) { x = v; }
    void show() const { cout << "A.x = " << x << "\n"; }
    friend void swapValues(A &, B &);
};

class B {
    int y;

public:
    B(int v = 0) { y = v; }
    void show() const { cout << "B.y = " << y << "\n"; }
    friend void swapValues(A &, B &);
};

void swapValues(A &a, B &b) {
    int temp = a.x;
    a.x = b.y;
    b.y = temp;
}

int main() {
    int n1, n2;
    cout << "Enter two numbers: ";
    cin >> n1 >> n2;

    A a(n1);
    B b(n2);

    cout << "\nBefore swapping:\n";
    a.show();
    b.show();

    swapValues(a, b);

    cout << "\nAfter swapping:\n";
    a.show();
    b.show();

    return 0;
}
