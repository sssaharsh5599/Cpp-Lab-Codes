#include <iostream>
#include <cstring>
using namespace std;

class Media {
protected:
    char title[50];
    char publication[50];

public:
    virtual void read() {
        cout << "Enter title: ";
        cin.ignore();
        cin.getline(title, 50);
        cout << "Enter publication: ";
        cin.getline(publication, 50);
    }

    virtual void show() {
        cout << "Title       : " << title << "\n";
        cout << "Publication : " << publication << "\n";
    }

    virtual ~Media() {}
};

class Book : public Media {
    int pages;

public:
    void read() {
        Media::read();
        cout << "Enter number of pages: ";
        cin >> pages;
    }

    void show() {
        cout << "\n--- BOOK ---\n";
        Media::show();
        cout << "Pages       : " << pages << "\n";
    }
};

class Tape : public Media {
    float playTime;

public:
    void read() {
        Media::read();
        cout << "Enter playing time (minutes): ";
        cin >> playTime;
    }

    void show() {
        cout << "\n--- TAPE ---\n";
        Media::show();
        cout << "Play time   : " << playTime << " min\n";
    }
};

int main() {
    Media *items[10];
    int n = 0;
    char choice;

    do {
        int type;
        cout << "\n1. Book  2. Tape\nEnter type: ";
        cin >> type;

        if (type == 1) items[n] = new Book;
        else items[n] = new Tape;

        items[n]->read();
        n++;

        cout << "Add another item? (y/n): ";
        cin >> choice;
    } while ((choice == 'y' || choice == 'Y') && n < 10);

    cout << "\n======= ITEMS IN SHOP =======";
    for (int i = 0; i < n; i++)
        items[i]->show();

    for (int i = 0; i < n; i++)
        delete items[i];

    return 0;
}
