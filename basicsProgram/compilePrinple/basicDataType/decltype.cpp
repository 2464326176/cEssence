//**************************
// Author:  yh
// Time:    2022/5/14
//**************************

#include <iostream>

using namespace std;

int f() {
    return 12;
}

int main() {
    //decltype类型说明符
    
    // 从表达式类型推断出来定义的变量的类型，但是不想用该表达式的值的初始值变量，
    // decltype选择并且返回操作数的数据类型，编译器分析表达式并且得到他的类型，不去计算表达式的值；
    decltype(f())  sum = x; // sum的类型就是函数f的返回类型
    // 编译器并不实际调用f，而是使用当调用发生时f的返回类型作为sum的类型

    //decltype 处理顶层const和引用的方式和auto有些不一样
    // 如果decltype使用的表达式时一个变量，则decltype返回该变量的类型（包括顶层const和引用在内）；
    const int ci = 0, &cj = ci;
    decltype(ci)  x = 0; // x的类型时const int
    decltype(cj)  y = x; // y的类型时const int &，y绑定到变量x
    //decltype(cj)  z; //error z是一个引用 必须初始化


    //如果decltype使用的是表达式不是一个变量，则decltype返回表达式结果对应的类型；
    // 有些表达式将向decltype返回一个引用类型，一般当这种情况发生时，意味着该表达式的结果能作为一条赋值语句的左值；

    int i = 42, *p = &i, &r = i;
    decltype(r + 0) b; // 正确 加法是int
    decltype(*p) c; //error c是int & 必须初始化


    //decltype的结果类型与表达式密切相关，对于decltype所用的表达式来说，
    // 如果变量名加上了一堆括号，则得到的类型与不加括号会不一样；
    // 如果decltype使用的是一个不加括号的变量，则得到的结果就是该变量的类型；
    // 如果给变量加了一层或者多层括号，编译器会把它当作一个表达式，变量是一种可以作为赋值语句左值的特殊的表达式，所以这样的decltype就会得到引用类型；

    //decltype((i)) d; // error d是一个int &，必须初始化
    decltype(i)	e; //正确 e是一个（未初始化的）int

    // tips:decltype((variable))的结果永远是引用，而decltype(variable) 结果只有当variable本身是一个引用的时候才是引用；


    return 0;
}