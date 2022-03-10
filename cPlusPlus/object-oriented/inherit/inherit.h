//**************************
// Author:  yh
// Time:    2022/3/1
//**************************

#ifndef CESSENCE_INHERIT_H
#define CESSENCE_INHERIT_H

class Base {
public:
    int val;

    Base() {
        val = 1;
    }
};

class Derive : public Base {
public:
    int val;
    Derive(int i) {
        val = Base::val + i;
    }
};












#endif //CESSENCE_INHERIT_H
