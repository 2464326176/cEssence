//**************************
// Author:  yh
// Time:    2022/2/25
//**************************

#include "pointArray.h"
#include <iostream>

using namespace std;

int printfArray(int array[][2]) {
    printf("%d \n", array[0][1]);

    return 0;
}

int printfArray(int **p) {
    printf("%d \n", *((int*)p + 2 * 0 + 0));
    printf("%d \n", *((int*)p) + 2 * 1 + 0);
    printf("%d \n", *((int*)p) + 2 * 2 + 0);

    return 0;
}

int printfArray(int *p) {
    printf("%d \n", *(p + 1));

    return 0;
}

int printfArray1(int (*p)[2]) {
    printf("%d \n", *(*(p + 0) + 1));
    return 0;
}


int main() {

    int a1[10] = {1, 2, 3, 4, 5, 6, 7, 7};
    int *p1 = &a1[0];
    int *p2 = a1;

    int a2[][2]{
            {1, 2},
            {3, 4},
            {5, 6},
    };
    int (*p3)[2] = a2;  // p3ָ��2������Ԫ�ص�һλ���飬 ָ���ά�����0��
    printfArray(a2);
    printfArray((int *) a2);
    printfArray((int **) a2);
    printfArray1(a2);


    *(p1 + 1), (p2 + 1), a1[1]; // ���ߵȼۣ���������ڶ���Ԫ�أ�ǰ����Ϊָ�뷨������Ϊ�±귨
    a2[0], *(a2 + 0), *a2; // 0��0��Ԫ�ص�ַ
    a2 + 1, &a2[1]; // 1���׵�ַ
    a2[1], *(a2 + 1); // 1��0��Ԫ�ص�ַ
    a2[1] + 2, *(a2 + 1) + 2, &a2[1][2]; // 1��2��Ԫ�ص�ַ
    *(a2[1] + 2), *(*(a2 + 1) + 2), a2[1][2]; // 1��2��Ԫ��ֵ

    return 0;
}