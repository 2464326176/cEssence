//**************************
// Author:  yh
// Time:    2022/2/28
//**************************

#ifndef CESSENCE_VIRTUALTABLE_H
#define CESSENCE_VIRTUALTABLE_H
#include <iostream>

class A0 {
    virtual void print() {
        std::cout << "NOT OK" << std::endl;
    }
};

class B0 : public A0 {
    int a;
    virtual void print1() {
        std::cout << "ok" << std::endl;
    }
};

class C0 : public B0 {
    int c;
    virtual void print2() {
        std::cout << "ok" << std::endl;
    }
    
    virtual void print3() {
        std::cout << "ok" << std::endl;
    }
};

class A {
public:
    char k[3];
public:
    virtual void aa() {
    
    }
};

class B : public virtual A {
public:
    virtual void aa11() {
    
    }
};

class C : public virtual B {
    char j[3];
public:
    virtual void aa1111() {
    
    }
};

class A1 {
    char a[2];
public:
    virtual void aa() {};
};

class B1 : public virtual A1 {
    char b[2];
    char a[2];
public:
    virtual void bb() {};
    virtual void aa() {};
};

class C1 : public virtual B1 {
    char a[2];
    char b[2];
    char c[2];
public:
    virtual void cc() {};
    virtual void aa() {};
    virtual void bb() {};
};

class A2 {
public:
    void *p1;
private:
    void *p2;
protected:
    void *p3;
};
class B2 : public A2 {};

class C2 : public virtual A2 {};
#endif //CESSENCE_VIRTUALTABLE_H
