//**************************
// Author:  yh
// Time:    2022/5/13
//**************************

#include <iostream>

using namespace std;
int i = 101;

int  main() {
    int j = 0;

    printf("%d %d\n", i, j);    // 101  0(全局变量 i 101， 局部变量j 0)

    int i = j;
    printf("%d %d\n", i, j); // 5 0(局部变量 i 5， 局部变量j 0)
    printf("%d %d\n", ::i, j); // 101   0(全局变量 i 101， 局部变量j 0)


    return 0;
}
