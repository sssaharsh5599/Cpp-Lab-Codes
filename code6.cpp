#include <iostream>
using namespace std;

class Complex {
    float real, imag;

public:
    Complex(float r = 0, float i = 0) {
        real = r;
        imag = i;
    }

    Complex& operator++() {
        ++real;
        ++imag;
        return *this;
    }

    Complex operator++(int) {
        Complex temp = *this;
        ++real;
        ++imag;
        return temp;
    }

    Complex& operator--() {
        --real;
        --imag;
        return *this;
    }

    Complex operator--(int) {
        Complex temp = *this;
        --real;
        --imag;
        return temp;
    }

    Complex operator+(const Complex &c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(const Complex &c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    void display() const {
        cout << real;
        if (imag >= 0) cout << " + " << imag << "i";
        else cout << " - " << -imag << "i";
        cout << "\n";
    }
};

int main() {
    float r1, i1, r2, i2;

    cout << "Enter first complex number (real imag): ";
    cin >> r1 >> i1;
    cout << "Enter second complex number (real imag): ";
    cin >> r2 >> i2;

    Complex c1(r1, i1), c2(r2, i2);

    cout << "\nc1 = "; c1.display();
    cout << "c2 = "; c2.display();

    cout << "\n(a) Unary operators\n";
    ++c1;
    cout << "++c1 = "; c1.display();
    --c1;
    cout << "--c1 = "; c1.display();
    c2++;
    cout << "c2++ = "; c2.display();
    c2--;
    cout << "c2-- = "; c2.display();

    cout << "\n(b) Binary operators\n";
    Complex sum = c1 + c2;
    Complex diff = c1 - c2;
    cout << "c1 + c2 = "; sum.display();
    cout << "c1 - c2 = "; diff.display();

    return 0;
}
