//**************************
// Author:  yh
// Time:    2021/11/4
//**************************
#include <iostream>
#include <string>
#include <numeric>
using namespace std;

int main() {
    string str("hello world!");
    cout << str.begin() << " " <<  str.end();
    string s = accumulate(str.begin(), str.end(), string(" | "));
    cout << s;

    return 0;
}
