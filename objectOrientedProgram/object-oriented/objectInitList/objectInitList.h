//**************************
// Author:  yh
// Time:    2022/4/17
//**************************

#ifndef CESSENCE_OBJECTINITLIST_H
#define CESSENCE_OBJECTINITLIST_H

#include <iostream>

using namespace std;

class objectInitList0 {
public:
    objectInitList0(int _a) {
        a = _a;
        cout << "objectInitList0 construct function a" << a << endl;
    }

    objectInitList0() {
        cout << "~objectInitList0 destruct function a" << a << endl;
    }

private:
    int a;
};

//1 构造函数的初始化列表  解决: 在B类中 组合了一个 A类对象 (A类设计了构造函数)
//根据构造函数的调用规则 设计A的构造函数, 必须要用;没有机会初始化A
//新的语法  Constructor::Contructor() : m1(v1), m2(v1,v2), m3(v3)
class objectInitList {
public:
    objectInitList(int _b1, int _b2) : a1(1), a2(2), c(0) {
        b1 = _b1;
        b2 = _b2;
        cout << "objectInitList1 construct function" << endl;
    }

    objectInitList(int _b1, int _b2, int m, int n) : a1(m), a2(n), c(0) {
        b1 = _b1;
        b2 = _b2;
        cout << "objectInitList2 construct function" << endl;
    }

    ~objectInitList() {
        cout << "objectInitList destruct function" << endl;
    }

private:
    int b1;
    int b2;
    objectInitList0 a2;
    objectInitList0 a1;
    const int c;
};


#endif //CESSENCE_OBJECTINITLIST_H
