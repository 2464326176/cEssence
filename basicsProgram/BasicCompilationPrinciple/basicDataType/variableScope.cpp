//**************************
// Author:  yh
// Time:    2022/5/13
//**************************

#include <iostream>

using namespace std;
int i = 101;

int  main() {
    int j = 0;

    printf("%d %d\n", i, j);    // 101  0(ȫ�ֱ��� i 101�� �ֲ�����j 0)

    int i = j;
    printf("%d %d\n", i, j); // 5 0(�ֲ����� i 5�� �ֲ�����j 0)
    printf("%d %d\n", ::i, j); // 101   0(ȫ�ֱ��� i 101�� �ֲ�����j 0)


    return 0;
}
