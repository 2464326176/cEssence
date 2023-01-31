//**************************
// Author:  yh
// Time:    2022/4/30
//**************************
#include <iostream>


using namespace std;
// ��Ļ
/*
    ��� �����������Ļ
    ���� ��Ļ���뵽����
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

