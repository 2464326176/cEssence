/*
 * @Author: yh
 * @Date: 2023-03-15 23:51:54
 * @LastEditTime: 2023-03-16 00:43:14
 * @Description:
 * @FilePath: \cEssence\basicsProgram\BasicCompilationPrinciple\preProcess\sizeof\virtual.cpp
 */
#include <iostream>
//#pragma pack(2)
using namespace std;

class Base {
public:
    Base(int x) : a(x) {}

    void print() { cout << "base" << endl; }

private:
    int a;
};

class Derived : public Base {
public:
    Derived(int x) : Base(x - 1), b(x) {}
    void print() { cout << "derived" << endl; }

private:
    int b;
};

class Base1 {
public:
    Base1(int x) : a(x) {}

    virtual void print() { cout << "base" << endl; }

private:
    int a;
};

class Derived1 : public Base1 {
public:
    Derived1(int x) : Base1(x - 1), b(x) {}
    void print() { cout << "derived" << endl; }

private:
    int b;
};

int main() {
    Base base(1);
    Base1 base1(2);
    Derived derived(3);
    Derived1 derived1(4);
    cout << sizeof(base) << endl;
    cout << sizeof(derived) << endl;
    cout << sizeof(base1) << endl;
    cout << sizeof(derived1) << endl;
    return 0;
}