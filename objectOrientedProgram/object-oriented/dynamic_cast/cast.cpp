/*
 * @Author: yh
 * @Date: 2023-01-08 16:32:14
 * @LastEditTime: 2023-01-08 16:42:52
 * @Description: 
 * @FilePath: \cEssence\objectOrientedProgram\object-oriented\dynamic_cast\cast.cpp
 */
#include <iostream>

using namespace std;

class A {
public:
    virtual void foo() {
        cout << "A foo" << endl;
    }

    void pp() {
        cout << "A pp" << endl;
    }
};

class B : public A {
public:
    void foo() {
        cout << "B foo" << endl;
    }

    void pp() {
        cout << "B pp" << endl;
    }

    void funcB() {
        cout << "B funcB" << endl;
    }
};

int main() {
    A a;
    A *pa = &a;
    pa->foo();
    pa->pp();
    if (nullptr == (dynamic_cast<B *>(pa))) {
        cout << "cast error" << endl;
    } else {
        cout << "cast ok" << endl;
    }

    (dynamic_cast<B *>(pa))->funcB();
    //(dynamic_cast<B *>(pa))->foo();
    (dynamic_cast<B *>(pa))->pp();
    return 0;
}