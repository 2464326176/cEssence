//**************************
// Author:  yh
// Time:    2022/4/19
//**************************

#include <iostream>

using namespace std;

class A {
public:
    void get() {
        cout << "b " << b << endl;
    }

    void print() {
        cout << "AAAAA " << endl;
    }

public:
    int a;
    int b;
};

class B : public A {
public:
    void get_child() {
        cout << "b " << b << endl;
    }

    void print() {
        cout << "BBBB " << endl;
    }
public:
    int b;
    int c;
};

int main() {
    B b1;
    b1.print();

    b1.A::print();
    b1.B::print(); //默认情况

    b1.b = 1; //
    b1.get_child();

    // 对象的作用域
    b1.A::b = 100; //修改父类的b
    b1.B::b = 200; //修改子类的b 默认情况是B

    b1.get();
    return 0;
}
