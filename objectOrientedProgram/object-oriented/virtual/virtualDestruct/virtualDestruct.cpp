//**************************
// Author:  yh
// Time:    2022/4/7
//**************************

#include "virtualDestruct.h"

//只执行了 父类的析构函数
//向通过父类指针  把 所有的子类对象的析构函数 都执行一遍
//向通过父类指针 释放所有的子类资源
void howtodelete(A *base) {
    delete base;  //这句话不会表现成多态 这种属性
}

void howtodelete(B *base) {
    delete base;  //这句话不会表现成多态 这种属性
}

int A::a = 0;

int main() {
//    A *a = new A; //A() ~A()
//    B *b = new B; //A() B() ~B() ~A()
//    delete a;
//    delete b;
    
    C *myC = new C; //new delete匹配
    //delete myC; //直接通过子类对象释放资源 不需要写virtual
    howtodelete(myC);
    
    return 0;
}

