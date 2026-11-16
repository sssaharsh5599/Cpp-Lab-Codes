#include <iostream>
#include <cstring>
using namespace std;

class Person {
    char name[64];
    int age;
    char address[64];
    float basic, hra, da, pf, totalSalary;

public:
    Person() {
        strcpy(name, "N/A");
        strcpy(address, "N/A");
        age = 0;
        basic = hra = da = pf = totalSalary = 0;
    }

    Person(const char *n, int a, const char *addr, float b) {
        strncpy(name, n, 63);
        name[63] = '\0';
        strncpy(address, addr, 63);
        address[63] = '\0';
        age = a;
        basic = b;
        hra = 0.20 * basic;
        da = 0.10 * basic;
        pf = 0.12 * basic;
        totalSalary = basic + hra + da - pf;
    }

    int getAge() const { return age; }

    void displaySlip() const {
        cout << "\n------ SALARY SLIP ------\n";
        cout << "Name    : " << name << "\n";
        cout << "Age     : " << age << "\n";
        cout << "Address : " << address << "\n";
        cout << "Basic   : " << basic << "\n";
        cout << "HRA     : " << hra << "\n";
        cout << "DA      : " << da << "\n";
        cout << "PF      : -" << pf << "\n";
        cout << "Net Pay : " << totalSalary << "\n";
        cout << "-------------------------\n";
    }

    ~Person() {}
};

inline void ageRange(Person p[], int n, int &youngest, int &eldest) {
    youngest = eldest = p[0].getAge();
    for (int i = 1; i < n; i++) {
        if (p[i].getAge() < youngest) youngest = p[i].getAge();
        if (p[i].getAge() > eldest) eldest = p[i].getAge();
    }
}

int main() {
    Person p[10];
    int n;
    cout << "How many persons (max 10)? ";
    cin >> n;
    if (n < 1 || n > 10) {
        cout << "Invalid count\n";
        return 1;
    }

    for (int i = 0; i < n; i++) {
        char name[64], addr[64];
        int age;
        float basic;

        cout << "\nPerson " << i + 1 << "\n";
        cout << "Name: ";
        cin.ignore();
        cin.getline(name, 64);
        cout << "Age: ";
        cin >> age;
        cout << "Address: ";
        cin.ignore();
        cin.getline(addr, 64);
        cout << "Basic salary: ";
        cin >> basic;

        p[i] = Person(name, age, addr, basic);
    }

    int young, old;
    ageRange(p, n, young, old);
    cout << "\nYoungest age: " << young << "\nEldest age  : " << old << "\n";

    for (int i = 0; i < n; i++)
        p[i].displaySlip();

    return 0;
}
