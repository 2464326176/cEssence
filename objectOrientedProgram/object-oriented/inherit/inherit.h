//**************************
// Author:  yh
// Time:    2022/3/1
//**************************

#ifndef CESSENCE_INHERIT_H
#define CESSENCE_INHERIT_H

#include <iostream>

using namespace std;

class Base {
public:
    int val;

    Base() {
        val = 1;
    }
};

class Derive : public Base {
public:
    int val;

    Derive(int i) {
        val = Base::val + i;
    }
};

class Parent {
public:
    Parent() {
        cout << "parent construct fun" << endl;
    }

    Parent(const Parent &obj) {
        cout << "copy construct FUN" << endl;
    }

    void printP() {
        cout << "Parent..." << endl;
    }

    virtual void print() {
        cout << "Parent print fun" << endl;
    }

    ~Parent() {
        cout << "parent destruct fun" << endl;
    }

private:
    int a;
};

class Child : public Parent {
public:
    Child() {
        cout << "child construct fun" << endl;
    }

    ~Child() {
        cout << "child destruct fun" << endl;
    }

    void printC() {
        cout << "Child...." << endl;
    }

    virtual void print() {
        cout << "Child print fun" << endl;
    }

private:
    int c;
};


#endif //CESSENCE_INHERIT_H
