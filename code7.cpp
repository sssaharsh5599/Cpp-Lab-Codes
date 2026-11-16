#include <iostream>
#include <cmath>
using namespace std;

const float PI = 3.14159;

float AREA(float radius) {
    return PI * radius * radius;
}

float AREA(float length, float breadth) {
    return length * breadth;
}

float AREA(int a, int b, int c) {
    float s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    float r, l, b;
    int x, y, z;

    cout << "Enter radius of circle: ";
    cin >> r;
    cout << "Area of circle = " << AREA(r) << "\n";

    cout << "\nEnter length and breadth of rectangle: ";
    cin >> l >> b;
    cout << "Area of rectangle = " << AREA(l, b) << "\n";

    cout << "\nEnter three sides of triangle: ";
    cin >> x >> y >> z;
    if (x + y > z && y + z > x && x + z > y)
        cout << "Area of triangle = " << AREA(x, y, z) << "\n";
    else
        cout << "Invalid triangle\n";

    return 0;
}
