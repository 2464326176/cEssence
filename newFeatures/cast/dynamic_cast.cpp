/*
 * @Author: yh
 * @Date: 2023-03-17 23:53:25
 * @LastEditTime: 2023-03-18 00:05:04
 * @Description:
 * @FilePath: \cEssence\newFeatures\cast\dynamic_cast.cpp
 */
#include <iostream>
#include <stdio.h>

using namespace std;

struct A {
    virtual void test() { printf_s("in A\n"); }
};

struct B : A {
    virtual void test() { printf_s("in B\n"); }

    void test2() { printf_s("test2 in B\n"); }
};

struct C : B {
    virtual void test() { printf_s("in C\n"); }

    void test2() { printf_s("test2 in C\n"); }
};

void Globaltest(A &a) {
    try {
        C &c = dynamic_cast<C &>(a);
        printf_s("in GlobalTest\n");
    } catch (std::bad_cast) {
        printf_s("Can't cast to C\n");
    }
}

int main() {
    A *pa = new C;
    A *pa2 = new B;

    pa->test(); // in c

    B *pb = dynamic_cast<B *>(pa); // 向上转换 是安全的
    if (pb) {
        pb->test2(); // test2 in B
    } else {
        cout << "dynamic_cast<B *>(pa) error" << endl;
    }

    C *pc = dynamic_cast<C *>(pa2); // 向下转换 是不安全的
    if (pc) {
        pc->test2();
    } else {
        cout << "dynamic_cast<C *>(pa2) error" << endl;
    }

    C ConStack;
    Globaltest(ConStack); // in GlobalTest

    // will fail because B knows nothing about C
    B BonStack;
    Globaltest(BonStack); // Can't cast to C
}