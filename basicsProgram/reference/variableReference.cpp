//**************************
// Author:  yh
// Time:    2022/5/13
//**************************

#include <iostream>

using namespace std;


int main() {
    int value = 1024;
    int &refVal = value; // refVal ָ��value ��value������һ������
    //int &refVale2; //error

    int &refVal3 = refVal; //refVal3�󶨵�value
    printf("%d %d %d \n", value, refVal, refVal3); // 1024 1024 1024

    int i= refVal; // i����ʼ��Ϊvalue��ֵ
    refVal3 = 101;
    printf("%d %d %d %d\n", value, refVal, refVal3, i); // 101 101 101 1024


    //int &refVal4 = 10;
    double dValue = 3.1415926;
    //int &refValue5 = dValue; //error ���õ����ͱ���һ��




    return 0;
}