#include <iostream>
using namespace std;

class Student {
protected:
    int roll;
    char name[50];

public:
    void getStudent() {
        cout << "Enter roll no: ";
        cin >> roll;
        cout << "Enter name: ";
        cin.ignore();
        cin.getline(name, 50);
    }

    void showStudent() const {
        cout << "Roll No : " << roll << "\n";
        cout << "Name    : " << name << "\n";
    }
};

class Test : virtual public Student {
protected:
    float theory;

public:
    void getTheory() {
        cout << "Enter theory marks: ";
        cin >> theory;
    }
};

class Sports : virtual public Student {
protected:
    float sportsMarks;

public:
    void getSports() {
        cout << "Enter sports marks: ";
        cin >> sportsMarks;
    }
};

class Result : public Test, public Sports {
    float total;

public:
    void calculate() {
        total = theory + sportsMarks;
    }

    void show() const {
        cout << "\n------ RESULT ------\n";
        showStudent();
        cout << "Theory marks : " << theory << "\n";
        cout << "Sports marks : " << sportsMarks << "\n";
        cout << "Total marks  : " << total << "\n";
        cout << "--------------------\n";
    }
};

int main() {
    Result r;
    r.getStudent();
    r.getTheory();
    r.getSports();
    r.calculate();
    r.show();
    return 0;
}
