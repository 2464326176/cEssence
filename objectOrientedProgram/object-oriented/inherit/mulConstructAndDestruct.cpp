//**************************
// Author:  yh
// Time:    2022/4/18
//**************************

#include <iostream>

using namespace std;

class Object {
public:
    Object(int a, int b) {
        this->a = a;
        this->b = b;
        cout << "object construct fun" << "a" << a << " b " << b << endl;
    }

    ~Object() {
        cout << "object destruct fun" << endl;
    }

protected:
    int a;
    int b;
};


class Parent : public Object {
public:
    Parent(char *p) : Object(1, 2) {
        this->p = p;
        cout << "parent construct fun " << p << endl;
    }

    ~Parent() {
        cout << "parent destruct fun " << p << endl;
    }

    void printP(int a, int b) {
        cout << "parent..." << endl;
    }

protected:
    char *p;

};


class child : public Parent {
public:
    child(char *p) : Parent(p), obj1(3, 4), obj2(5, 6) {
        this->myp = p;
        cout << "child construct fun " << myp << endl;
    }

    ~child() {
        cout << "child destruct fun " << myp << endl;
    }

    void printC() {
        cout << "child..." << endl;
    }

protected:
    char *myp;
    Object obj1;
    Object obj2;
};


void objPlay() {
    child c1("inherit text");
}

int main() {
    objPlay();
    return 0;
}
