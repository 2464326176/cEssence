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
    b1.B::print(); //Ĭ�����

    b1.b = 1; //
    b1.get_child();

    // �����������
    b1.A::b = 100; //�޸ĸ����b
    b1.B::b = 200; //�޸������b Ĭ�������B

    b1.get();
    return 0;
}
