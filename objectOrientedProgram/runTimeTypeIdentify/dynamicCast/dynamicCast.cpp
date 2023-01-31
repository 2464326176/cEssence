/*
 * @Author: yh
 * @Date: 2023-01-15 00:21:53
 * @LastEditTime: 2023-01-16 01:01:08
 * @Description: 
 * @FilePath: \cEssence\objectOrientedProgram\runTimeTypeIdentify\dynamicCast\dynamicCast.cpp
 */
#include <iostream>
#include <typeinfo>

using namespace std;

class A {
public:
    virtual ~A() {
        printf("~A()\n");
    }
};

class B : public A {
public:
    virtual ~B() {
        printf("~B()\n");
    }
};

class C : public B {
public:
    virtual ~C() {
        printf("~C()\n");
    }
};

class D : public B, public A {
public:
    virtual ~D() {
        printf("~D()\n");
    }
};

int main(int argc, char const *argv[]) {
    A *pa = new C;
    B *pb = nullptr;
    pb = dynamic_cast<B *>(pa); // Succeed. The type of ‘pa’ (class type 'C') is publicly derived from the target type 'B'.

    pb = new B;
    C *pc = dynamic_cast<C *>(pb); // Fail. The type of ‘pb’ (class type 'B') is a public base class of the target type 'C'. ‘pc’ will equal to nullptr.

    //pa = new D; // Fail. ‘A’ is an ambiguous base of ‘D’. Converting a pointer of 'D' to a pointer of 'A' is not allowed.
    //pb = dynamic_cast< B* >(pa);

    C c;
    B b;
    A &ra1 = c, &ra2 = b;
    try {
        /* succeed */
        C &rc1 = dynamic_cast<C &>(ra1);
        cout << "succeed!" << endl;
        /* fail */
        C &rc2 = dynamic_cast<C &>(ra2);
    } catch (bad_cast) {
        cout << "failed!" << endl;
    }
    return 0;
}