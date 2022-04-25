//**************************
// Author:  yh
// Time:    2022/4/20
//**************************

#include <iostream>
#include "mathOperate.h"
using namespace std;

int main() {
    int a = 5, b = 8;
    cout << "a + b: " << add(a, b) << endl;
    cout << "a - b: " << sub(a, b) << endl;
    cout << "a * b: " << mul(a, b) << endl;
    //cout << "a / b: " << div(5, 8) << endl;

    return 0;
}