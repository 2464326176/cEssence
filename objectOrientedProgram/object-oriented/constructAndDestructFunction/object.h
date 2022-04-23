//**************************
// Author:  yh
// Time:    2022/4/15
//**************************

#ifndef CESSENCE_OBJECT_H
#define CESSENCE_OBJECT_H

#include <iostream>
#include <cstring>

using namespace std;

class Object {
public:
    Object() {
        m_a = 10;
        m_p = (char *) malloc(100);
        strcpy(m_p, "hello world!!!");
        cout << this << " construct function of no parameters!!!" << endl;
    }

    Object(int a) {
        m_a = a;
        m_b = 2;
        m_p = nullptr;
        cout << "m_a: " << m_a << endl;
        cout << this << "construct function of one parameters!!!" << endl;
    }

    Object(int a, int b) {
        m_a = a;
        m_b = b;
        m_p = nullptr;
        cout << "m_a: " << m_a << "m_b: " << m_b << endl;
        cout << this << "construct function of two parameters!!!" << endl;
    }

    Object(const Object &obj) {
        this->m_a = obj.m_a + 1;
        this->m_b = obj.m_b + 1;
        this->m_p = obj.m_p;
        cout << "p: " << ((m_p) ? m_p : "nullPtr") << " m_a: " << m_a << " m_b: " << m_b << endl;
        cout << "copy construct function!!!" << endl;
    }

    ~Object() {
        if (m_p != nullptr) {
            free(m_p);
            m_p = nullptr;
        }
        cout << this << " destruct function!!!" << endl;
    }

    void print() {
        cout << this << "p: " << ((m_p) ? m_p : "nullPtr") << " m_a: " << m_a << " m_b: " << m_b << endl;
    }

    int m_a;
    int m_b;
    char *m_p;
};


#endif //CESSENCE_OBJECT_H
