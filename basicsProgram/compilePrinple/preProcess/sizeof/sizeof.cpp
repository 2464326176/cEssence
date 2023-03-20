/*
 * @Author: yh
 * @Date: 2023-03-15 23:51:54
 * @LastEditTime: 2023-03-16 00:15:42
 * @Description:
 * @FilePath: \cEssence\basicsProgram\BasicCompilationPrinciple\preProcess\sizeof.cpp
 */
#include <iostream>
#pragma pack(8)

using namespace std;

union un1 {
    int i;
    double d;
};

union un2 {
    char ch[13];
    char ch1;
};

union un3 {
    char ch[13];
    int i;
};

int main() {
    cout << sizeof(un1) << endl;
    cout << sizeof(un2) << endl;
    cout << sizeof(un3) << endl;

    return 0;
}