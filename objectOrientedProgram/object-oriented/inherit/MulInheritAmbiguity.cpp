//**************************
// Author:  yh
// Time:    2022/4/19
//**************************


#include <iostream>

using namespace std;

class A {
public:
    int a;
};

class A1 : public A {
public:
    int a1;
};

class A2 : public A {
public:
    int a2;
};

class D : public A1, public A2 {
public:
    int d;
};

class B {
public:
    int b;
};

class B1 : virtual public B {
public:
    int b1;
};

class B2 : virtual public B {
public:
    int b2;
};

class C : public B1, public B2 {
public:
    int c;
};

int main() {

    C c1;
    c1.b1 = 100;
    c1.b2 = 200;
    c1.c = 300;

    c1.b = 500; //�̳еĶ����� �� ��̳н������

    cout<<sizeof(A)<<endl; //4
    cout<<sizeof(A1)<<endl; //12 //����virtual�Ժ� , C++���������ڸ�����͵͵��������
    cout<<sizeof(A2)<<endl;  //8
    cout<<sizeof(D)<<endl;

    cout<<sizeof(B)<<endl; //4
    cout<<sizeof(B1)<<endl; //12 //����virtual�Ժ� , C++���������ڸ�����͵͵��������
    cout<<sizeof(B2)<<endl;  //8
    cout<<sizeof(C)<<endl;

    //c1.B1::b = 500;
    //c1.B2::b = 500;

    return 0;
}