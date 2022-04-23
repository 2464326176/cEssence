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
//这句话 不是简单的变量赋值 更重要的是 要告诉C++编译器 分配内存 ,再继承类中 用到了a 不然会报错..


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

//1 static关键字 遵守  派生类的访问控制规则
//2  不是简单的变量赋值 更重要的是 要告诉C++编译器 你要给我分配内存 ,我再继承类中 用到了a 不然会报错..
//3 A类中添加构造函数
//A类的构造函数中   A的构造函数是私有的构造函数 ...
//被别的类继承要小心....
//单例场景 .... UML

int main() {
    A a1;
    a1.print();

    B b1;
    //b1.A::a = 200;
    b1.get_child();
    return 0;
}
