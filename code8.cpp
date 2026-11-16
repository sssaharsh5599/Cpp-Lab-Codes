#include <iostream>
#include <cstring>
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

class Exam : public Student {
protected:
    float marks[6];

public:
    void getMarks() {
        cout << "Enter marks in 6 subjects:\n";
        for (int i = 0; i < 6; i++) {
            cout << "Subject " << i + 1 << ": ";
            cin >> marks[i];
        }
    }

    void showMarks() const {
        for (int i = 0; i < 6; i++)
            cout << "Subject " << i + 1 << ": " << marks[i] << "\n";
    }
};

class Result : public Exam {
    float total;
    float percentage;

public:
    void calculate() {
        total = 0;
        for (int i = 0; i < 6; i++)
            total += marks[i];
        percentage = total / 6;
    }

    void showResult() const {
        cout << "\n------ RESULT ------\n";
        showStudent();
        showMarks();
        cout << "Total      : " << total << "\n";
        cout << "Percentage : " << percentage << "%\n";
        cout << "--------------------\n";
    }
};

int main() {
    Result r;
    r.getStudent();
    r.getMarks();
    r.calculate();
    r.showResult();
    return 0;
}
