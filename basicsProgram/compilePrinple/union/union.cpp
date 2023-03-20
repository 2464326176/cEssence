/*
 * @Author: yh
 * @Date: 2023-01-08 16:48:45
 * @LastEditTime: 2023-01-08 16:52:25
 * @Description: 
 * @FilePath: \cEssence\basicsProgram\union\union.cpp
 */
#include <iostream>

using namespace std;

union{
    unsigned char a;
    unsigned int i;
}u;

int main() {
    u.i = 0Xf0f1f2f3;
    cout << std::hex << int(u.i) << std::endl;
    cout << std::hex << int(u.a) << std::endl;
    return 0;
}