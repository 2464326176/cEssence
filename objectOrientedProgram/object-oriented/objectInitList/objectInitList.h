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

//1 ���캯���ĳ�ʼ���б�  ���: ��B���� �����һ�� A����� (A������˹��캯��)
//���ݹ��캯���ĵ��ù��� ���A�Ĺ��캯��, ����Ҫ��;û�л����ʼ��A
//�µ��﷨  Constructor::Contructor() : m1(v1), m2(v1,v2), m3(v3)
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
