//**************************
// Author:  yh
// Time:    2022/5/13
//**************************

#include <iostream>


using namespace std;


int main() {
    {
        int *ip1, *ip2; // ip1 ip2 都是指向int型对象的指针
        double dp, *dp2; // dp2是指向double型对象的指针 dp是double型对象

        int ival = 42;
        // p是一个指向int的指针 初始化p使得它指向ival的int对象
        // 因为 引用不是对象 没有实际的地址 所以不能定义指向引用的指针
        int *p = &ival; // p存放ival的地址 p是指向ival的指针

        double dval;
        double *pd = &dval; // pi 指向double型对象的地址
        double *pd2 = pd; // pd2指向pd 指向double型对象的指针

        // 在声明语句中指针的类型实际上被用于指定它所指向对象的类型 所以两者必须匹配
        //int *pi1 = pd; // error 类型不匹配
        //int *pi2 = &dval;; // error 类型不匹配


    }

    {
        int iv = 42;
        int *piv = &iv;
        cout << *piv;   // 由符号*（解引用符号）得到指针p所指向的对象，输出42；
        *p = 58; // 由符号*得到指针p所指向的对象 既可由p为变量ival赋值
        cout << *piv;

        int i = 43;
        int &r = i; // &紧随着类型名出现 是声明的一部分 r是一个引用
        int *pi; // &紧随着类型名出现 是声明的一部分 p是一个指针
        pi = &i; // &在表达式中 是一个取地址符号
        *pi = i; // *在表达式中 是一个解引用符号
        int &r2 = *pi; // &是声明的一部分 *是一个解引用符号
    }
    {
        // 指向指针的指针
        int iVal = 1024;
        int *piVal = &iVal; // p1 指向int型的数
        int **ppiVal = &piVal; // ppi指向int型的指针
    }


    {
        //指向指针的引用
        int i = 42;
        int *p; // p 是一个对int型的指针
        int *&r = p; // r 是一个对指针p的引用 r是p的别名
        r = &i; //r 引用了一个指针  p也指向对象i
        *r = 0; // 解引用i  将i改成0
    }


    return 0;
}