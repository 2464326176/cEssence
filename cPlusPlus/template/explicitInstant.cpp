//**************************
// Author:  yh
// Time:    2021/12/20
//**************************
#include <iostream>

/*
//MyStack 的实例化，而不保留对象的任何存储。 为所有成员生成代码。
template class MyStack<int, 6>;
// 仅显式实例化构造函数成员函数：
template MyStack<int, 6>::MyStack( void );
// 将特定成员标记为外部且未实例化：
extern template class MyStack<int, 6>;
extern template MyStack<int, 6>::MyStack( void );
// 可以使用 extern 关键字来防止编译器在多个对象模块中生成相同的实例化代码。
// 如果调用该函数，则必须在至少一个链接的模块中使用指定的显式模板参数来实例化模板函数，否则会在生成程序时收到链接器错误
 */


template <class T> void f(T) {
    printf_s("Less specialized function called\n");
}

template <class T> void f(T*) {
    printf_s("More specialized function called\n");
}

template <class T> void f(const T*) {
    printf_s("Even more specialized function for const T*\n");
}

int main() {
    int i =0;
    const int j = 0;
    int *pi = &i;
    const int *cpi = &j;

    f(i);   // Calls less specialized function.
    f(pi);  // Calls more specialized function.
    f(cpi); // Calls even more specialized function.
    // Without partial ordering, these calls would be ambiguous.
}