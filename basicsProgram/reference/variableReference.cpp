//**************************
// Author:  yh
// Time:    2022/5/13
//**************************

#include <iostream>

using namespace std;


int main() {
    int value = 1024;
    int &refVal = value; // refVal 指向value 是value的另外一个名字
    //int &refVale2; //error

    int &refVal3 = refVal; //refVal3绑定到value
    printf("%d %d %d \n", value, refVal, refVal3); // 1024 1024 1024

    int i= refVal; // i被初始化为value的值
    refVal3 = 101;
    printf("%d %d %d %d\n", value, refVal, refVal3, i); // 101 101 101 1024


    //int &refVal4 = 10;
    double dValue = 3.1415926;
    //int &refValue5 = dValue; //error 引用的类型必须一致




    return 0;
}