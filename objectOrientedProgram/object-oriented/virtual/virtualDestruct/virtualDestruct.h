//**************************
// Author:  yh
// Time:    2022/4/7
//**************************

#ifndef CESSENCE_VIRTUALDESTRUCT_H
#define CESSENCE_VIRTUALDESTRUCT_H

#include <iostream>
#include <cstring>
using namespace std;


//ÐéÎö¹¹º¯Êý
class A {
public:
    A() {
        p = new char[20];
        strcpy(p, "obja");
        printf("A()\n");
    }

    virtual ~A() {
        delete[] p;
        printf("~A()\n");
    }

protected:
private:
    char *p;
};

class B : public A {
public:
    B() {
        p = new char[20];
        strcpy(p, "objb");
        printf("B()\n");
    }

    ~B() {
        delete[] p;
        printf("~B()\n");
    }

protected:
private:
    char *p;
};


class C : public B {
public:
    C() {
        p = new char[20];
        strcpy(p, "objc");
        printf("C()\n");
    }

    ~C() {
        delete[] p;
        printf("~C()\n");
    }

protected:
private:
    char *p;
};
#endif //CESSENCE_VIRTUALDESTRUCT_H
