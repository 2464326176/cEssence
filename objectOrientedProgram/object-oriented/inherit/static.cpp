//**************************
// Author:  yh
// Time:    2022/4/19
//**************************


#include <iostream>

using namespace std;

class A {
public:
    A() {
        cout << "A construct fun" << endl;
    }

    void get() {
        cout << "b " << b << endl;
    }

    void print() {
        cout << "AAAAA " << endl;
    }

public:
    static int a;
    int b;
};

int A::a = 100;
//��仰 ���Ǽ򵥵ı�����ֵ ����Ҫ���� Ҫ����C++������ �����ڴ� ,�ټ̳����� �õ���a ��Ȼ�ᱨ��..


class B : private A {
public:
    void get_child() {
        cout << "b " << b << endl;
        cout << a << endl;
    }

    void print() {
        cout << "BBBB " << endl;
    }
public:
    int b;
    int c;
};

//1 static�ؼ��� ����  ������ķ��ʿ��ƹ���
//2  ���Ǽ򵥵ı�����ֵ ����Ҫ���� Ҫ����C++������ ��Ҫ���ҷ����ڴ� ,���ټ̳����� �õ���a ��Ȼ�ᱨ��..
//3 A������ӹ��캯��
//A��Ĺ��캯����   A�Ĺ��캯����˽�еĹ��캯�� ...
//�������̳�ҪС��....
//�������� .... UML

int main() {
    A a1;
    a1.print();

    B b1;
    //b1.A::a = 200;
    b1.get_child();
    return 0;
}
