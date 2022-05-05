//**************************
// Author:  yh
// Time:    2022/4/30
//**************************
#include <iostream>


using namespace std;
// 屏幕
/*
    输出 程序输出到屏幕
    输入 屏幕输入到程序
 */

int main() {
    int a = 100;
    int *pa = &a;
    char str[] = "hello world!";

    cout << "str: " << str << "\t" << sizeof(str) << endl;
    cout << "a " << a << " &a: " << &a << endl;
    cout << "*pa " << *pa << "pa " << pa << "&pa: " << &pa << endl;

    return 0;
}

