//**************************
// Author:  yh
// Time:    2022/3/1
//**************************

#include "inherit.h"


/*
兼容规则中所指的替代包括以下情况：
	子类对象可以当作父类对象使用
	子类对象可以直接赋值给父类对象
	子类对象可以直接初始化父类对象
	父类指针可以直接指向子类对象
	父类引用可以直接引用子类对象
	*/


void printByPoint(Parent *base) {
    base->printP();

}

void printByReference(Parent &base) {
    base.printP();
}

void virtualPrintByPoint(Parent *base) {
    base->print();

}

void virtualPrintByReference(Parent &base) {
    base.print();
}

void inherit() {
    Parent p1;
    p1.printP();

    Child c1;
    c1.printC();
    c1.printP();

    //赋值兼容性原则
    //1-1 基类指针 (引用) 指向 子类对象
    Parent *p = NULL;
    p = &c1;
    p->printP();

    //1-2 指针做函数参数
    printByPoint(&p1);
    printByPoint(&c1);

    //1-3引用做函数参数
    printByReference(p1);
    printByReference(c1);

    //第二层含义
    //可以让子类对象   初始化   父类对象
    //子类就是一种特殊的父类
    Parent p3 = c1;
}

void virtualInherit() {
    Parent p1;
    Child c1;

    //赋值兼容性原则
    //1-1 基类指针 (引用) 指向 子类对象
    Parent *p = NULL;
    p = & p1;
    p->print();
    p = &c1;
    p->print();

    //1-2 指针做函数参数
    virtualPrintByPoint(&p1); // parent
    virtualPrintByPoint(&c1); // child

    //1-3引用做函数参数
    virtualPrintByReference(p1); // parent
    virtualPrintByReference(c1); // child

}

int main() {
    //Derive d(10);
    //std::cout << d.val << d.Base::val << std::endl;
    //inherit();
    virtualInherit();

    return 0;
}
