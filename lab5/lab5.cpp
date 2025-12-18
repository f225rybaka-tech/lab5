#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

// Абстрактний клас
class Ssavci {
public:
    virtual void describe() const = 0; // суто віртуальна функція
    virtual ~Ssavci() {}               // віртуальний деструктор
};

// Похідний клас ЛЮДИ
class People : public Ssavci {
    string name;
    int age;

public:
    People(string n, int a) : name(n), age(a) {}

    void describe() const override {
        cout << "Людина: " << name << ", вік: " << age << endl;
    }
};

// Проміжний клас ТВАРИНИ
class Animals : public Ssavci {
protected:
    string breed;

public:
    Animals(string b) : breed(b) {}
};

// Клас КОНІ
class Horses : public Animals {
public:
    Horses(string b) : Animals(b) {}

    void describe() const override {
        cout << "Кінь породи: " << breed << endl;
    }
};

// Клас КОРОВИ
class Cows : public Animals {
public:
    Cows(string b) : Animals(b) {}

    void describe() const override {
        cout << "Корова породи: " << breed << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Масив вказівників на базовий клас
    Ssavci* list[3];

    list[0] = new People("Андрій", 20);
    list[1] = new Horses("Орловська");
    list[2] = new Cows("Голштинська");

    // Поліморфізм (пізнє зв’язування)
    for (int i = 0; i < 3; i++) {
        list[i]->describe();
    }

    // Звільнення пам’яті
    for (int i = 0; i < 3; i++) {
        delete list[i];
    }

    return 0;
}
