//**************************
// Author:  yh
// Time:    2022/2/28
//**************************

#ifndef CESSENCE_VIRTUALTABLE_H
#define CESSENCE_VIRTUALTABLE_H

class A {
public:
    char k[3];
public:
    virtual void aa() {

    }
};

class B : public virtual A {
    char j[3];
public:
    virtual void bb() {

    }
};

class C : public virtual B {
    char j[3];
public:
    virtual void cc() {

    }
};






#endif //CESSENCE_VIRTUALTABLE_H
