//**************************
// Author:  yh
// Time:    2022/4/19
//**************************

#ifndef CESSENCE_OBJECT_H
#define CESSENCE_OBJECT_H


#include <iostream>

using namespace std;

//HeroFighter  AdvHeroFighter EnemyFighter


class HeroFighter {
public:
    virtual int power()  //C++会对这个函数特殊处理
    {
        return 10;
    }
};

class EnemyFighter {
public:
    int attack() {
        return 15;
    }
};


class AdvHeroFighter : public HeroFighter {
public:
    virtual int power() {
        return 20;
    }
};

class AdvAdvHeroFighter : public HeroFighter {
public:
    virtual int power() {
        return 30;
    }
};


#endif //CESSENCE_OBJECT_H
