//**************************
// Author:  yh
// Time:    2022/4/15
//**************************
#include "object.h"

void objTest() {
    Object t1;
    t1.print();

    Object t2;
    t2.print();
}

void objInit() {
    // 0.无参数的构造函数
    Object t0;

    // 1. 括号调用构造函数
    Object t1(1, 2);
    t1.print();

    // 2. 等号调用构造函数
    Object t2 = (3, 4);
    Object t3 = 5;

    //3. copy构造函数
    Object t4 = Object(5, 6);

    //对象的初始化 和 对象的赋值 是两个不同的概念
    t1 = t4;  //把t4 copy给 t1
    t1.print();
}

void printOnject(const Object obj) {
    cout << "p: " << ((obj.m_p) ? obj.m_p : "nullPtr") << " m_a: " << obj.m_a << " m_b: " << obj.m_b << endl;
}

//getObject函数 返回一个元素
//结论1 : 函数的返回值是一个元素 (复杂类型的), 返回的是一个新的匿名对象(所以会调用匿名对象类的copy构造函数)

//结论2: 有关 匿名对象的去和留
//如果用匿名对象  初始化 另外一个同类型的对象, 匿名对象 转成有名对象
//如果用匿名对象  赋值给 另外一个同类型的对象, 匿名对象 被析构
//返回一个新对象(没有名字 匿名对象)
Object getObject() {
    Object t1(1, 2);
    return t1;
}

// 1 copy function
void copyConstructFun() {
    Object t0(1, 2);
    Object t1(1, 2);
    Object t2(t1);  // copy construct function
    Object t3;
    t3 = t2;        // = 运算符重载
    Object t4 = t2; // copy construct function
}

// 2 copy function
void copyConstructFun1() {
    /*Object t0(1, 2);
    Object t1 = getObject(); //
    t1.print();*/
    Object t2;
    t2 = getObject(); // 赋值构造函数
    t2.print();

    //getObject();
}

int main() {
    //objTest();
    //objInit();
    //copyConstructFun();
    copyConstructFun1();
    return 0;
}