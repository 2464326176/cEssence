//**************************
// Author:  yh
// Time:    2022/3/11
//**************************
#include <iostream>


int main() {
    const int a = 0; // a不能被修改
    int const b = 0; // b不能被修改

    //指针指向的对象声明为const或volatile
    const char *cpch; // 修饰符修饰的指针指向的对象 不能被修改
    volatile char *vpch;
    // 指针的值（即指针中存储的实际地址）声明为const或volatile
    char *const pchc = nullptr; // 修饰符修饰的指针的值 不能被修改
    char *volatile pchv;

    // 在c语言中const修饰的变量，可以通过间接赋值方式被修改
    const int value = 10;
    int *p = const_cast<int *>(&value);
    *p = 6;

    const char cch = 'A'; // cch的值不能被修改
    char ch = 'B';

    const char *pch1 = &cch;
    //char *pch2 = &cch;   // Error
    //char *const pch3 = &cch;   // Error
    const char *const pch4 = &cch;

    //*pch1 = 'A';  // Error: object declared const
    pch1 = &ch;   // OK: pointer not declared const
    char *pch2 = "aaa";  // OK: normal pointer
    pch2 = &ch;   // OK: normal pointer
    char *const pch3 = "bbb";  // OK: object not declared const
    //pch3 = &ch;   // Error: pointer declared const
    //*pch4 = "cccc";  // Error: object declared const
    //pch4 = &ch;   // Error: pointer declared const

    const char *pch5 = &ch;
    char *pch6 = &ch;
    char *const pch7 = &ch;
    const char *const pch8 = &ch;
    return 0;
}
