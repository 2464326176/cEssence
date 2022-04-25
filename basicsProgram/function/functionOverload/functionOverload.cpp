//**************************
// Author:  yh
// Time:    2022/4/15
//**************************
#include <iostream>
#include "functionOverload.h"

using namespace std;


void myPrint(int a) {
    printf("a: %d \n", a);
}

void myPrint(char *p) {
    printf("%s \n", p);
}

void myPrint(int a, int b) {
    printf("a: %d ", a);
    printf("b: %d \n", b);
}

/*
//返回值 不是 判断函数重载的标准
int myPrint(int a, int b)
{
	printf("a:%d ", a);
	printf("b:%d \n", b);
}
*/

// 函数重载 和 函数默认参数 在一起
void myfunc(int a, int b, int c = 0) {
    printf("a:%d b:%d c:%d \n", a, b, c);
}

void myfunc(int a, int b) {
    printf("a:%d b:%d\n", a, b);
}

void myfunc(int a) {
    printf("a:%d\n", a);
}

/*
1 当函数名和不同的参数搭配时函数的含义不同
2 函数重载的判断标准
    名称 参数 返回值
    名称相同 参数不一样(个数/类型)
3 返回值 不是 判断函数重载的标准
4 重载函数的调用标准
*/

//1声明一个函数类型
typedef void (myTypeFunc)(int a,int b) ;  //int
//myTypeFunc *myfuncp = NULL; //定义一个函数指针 这个指针指向函数的入口地址

//声明一个函数指针类型
typedef void (*myPTypeFunc)(int a,int b) ;  //声明了一个指针的数据类型
//myPTypeFunc fp = NULL;  //通过  函数指针类型 定义了 一个函数指针 ,

//定义一个函数指针 变量
void (*myVarPFunc)(int a, int b);

int main() {
    myPrint(1);
    myPrint("hello world!!!");
    myPrint(1, 2);

    // 函数重载和函数默认参数在一起
    //myfunc(1, 2); //函数调用时,会产生二义性
    myfunc(1);

    myPTypeFunc fp; //定义了一个 函数指针 变量

    fp = myfunc;
    //fp(1);
    fp(1, 2);
    return 0;
}
