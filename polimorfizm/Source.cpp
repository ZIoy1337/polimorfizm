#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const double PI = 3.14159265358979323846;

// Task 1: Shapes
class Shape {
public:
    virtual double CalculateArea() = 0;
    virtual void Print() = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape {
    double lengths, widths;
public:
    Rectangle(double l, double w) : lengths(l), widths(w) {}
    double CalculateArea() override { return lengths * widths; }
    void Print() override {
        cout << "Rectangle: Length = " << lengths << ", Width = " << widths << ", Area = " << CalculateArea() << endl;
    }
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double CalculateArea() override { return PI * radius * radius; }
    void Print() override {
        cout << "Circle: Radius = " << radius << ", Area = " << CalculateArea() << endl;
    }
};

class Triangle : public Shape {
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double CalculateArea() override { return 0.5 * base * height; }
    void Print() override {
        cout << "Triangle: Base = " << base << ", Height = " << height << ", Area = " << CalculateArea() << endl;
    }
};

// Task 2: Zoo Animals
class Animal {
public:
    virtual void MakeSound() = 0;
    virtual void PrintInfo() = 0;
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    void MakeSound() override { cout << "Gav!" << endl; }
    void PrintInfo() override { cout << "this is a dog" << endl; }
};

class Cat : public Animal {
public:
    void MakeSound() override { cout << "meow!" << endl; }
    void PrintInfo() override { cout << "this is a cat" << endl; }
};

class Bird : public Animal {
public:
    void MakeSound() override { cout << "cvirin!" << endl; }
    void PrintInfo() override { cout << "this is a bird" << endl; }
};

// Task 3: Bank Accounts
class Account {
protected:
    double balance;
public:
    Account(double initial) : balance(initial) {}
    virtual void CalculateInterest() = 0;
    virtual void Deposit(double amount) { balance += amount; }
    virtual void Print() {
        cout << "Balance: " << balance << endl;
    }
    virtual ~Account() {}
};

class SavingsAccount : public Account {
public:
    SavingsAccount(double initial) : Account(initial) {}
    void CalculateInterest() override { balance += balance * 0.05; }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(double initial) : Account(initial) {}
    void CalculateInterest() override {
        double fee = balance * 0.02;
        if (balance > fee) {
            balance -= fee;
        }
        else {
            balance = 0;
        }
    }
};

class FixedDepositAccount : public Account {
public:
    FixedDepositAccount(double initial) : Account(initial) {}
    void CalculateInterest() override { balance += balance * 0.10; }
    void Deposit(double amount) override {
        cout << "Cannot deposit until maturity." << endl;
    }
};

int main() {
    // Task 1: Shapes
    Shape* shapes[3];
    shapes[0] = new Rectangle(5, 10);
    shapes[1] = new Circle(3);
    shapes[2] = new Triangle(4, 6);
    for (int i = 0; i < 3; i++) {
        shapes[i]->Print();
        delete shapes[i];
    }

    // Task 2: Zoo Animals
    Animal* zoo[3];
    zoo[0] = new Dog();
    zoo[1] = new Cat();
    zoo[2] = new Bird();
    for (int i = 0; i < 3; i++) {
        zoo[i]->MakeSound();
        zoo[i]->PrintInfo();
        delete zoo[i];
    }

    // Task 3: Bank Accounts
    Account* accounts[3];
    accounts[0] = new SavingsAccount(1000);
    accounts[1] = new CheckingAccount(1000);
    accounts[2] = new FixedDepositAccount(1000);

    for (int i = 0; i < 3; i++) {
        accounts[i]->Deposit(500);
        accounts[i]->CalculateInterest();
        accounts[i]->Print();
        delete accounts[i];
    }

    return 0;
}
