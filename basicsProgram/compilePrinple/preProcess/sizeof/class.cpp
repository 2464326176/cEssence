/*
 * @Author: yh
 * @Date: 2023-03-15 23:51:54
 * @LastEditTime: 2023-03-16 00:19:49
 * @Description:
 * @FilePath: \cEssence\basicsProgram\BasicCompilationPrinciple\preProcess\sizeof\class.cpp
 */
#include <iostream>
#pragma pack(8)

using namespace std;

class c1 {
    int i;
};

class c2 {
    char ch;
};

class c3 {
    int i;
    short s;
};

class c4 {
    int i;
    short s;
    char ch;
};

class c5 {
    int k;
    int i;
    short s;
    char ch;
    char chr;
};

class c6 {
    int l;
    int k;
    int i;
    short s;
    char ch;
    char chr;
};


int main() {
    cout << sizeof(c1) << endl;
    cout << sizeof(c2) << endl;
    cout << sizeof(c3) << endl;
    cout << sizeof(c4) << endl;
    cout << sizeof(c5) << endl;
    cout << sizeof(c6) << endl;
    return 0;
}