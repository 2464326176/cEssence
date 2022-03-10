//**************************
// Author:  yh
// Time:    2022/3/10
//**************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void oneDimensionalArray() {
    int array[200] = {0}; //�����ʱ�� ȷ�����е�ֵΪ0
    memset(array, 0, sizeof(array)); //��ʾ�� �����ڴ��
    //C�涨һά����
    //array��������Ԫ�صĵ�ַ c+1 ���� 4���ֽ�
    //&array ����������ĵ�ַ //&c+1 ���� 200*4
    printf("%d %d %d %d", array, &array, array + 1, &array + 1);
}

void printArray01(int a[3][5]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", a[i][j]);
        }
    }
}

void printArray02(int a[][5]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", a[i][j]);
        }
    }
}

void printArray03(int (*a)[5]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", a[i][j]);
        }
    }
}

int main() {
    int a[3][5], i = 0, j = 0;
    int tmp = 1;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            a[i][j] = tmp++;
        }
    }

    printArray03(a);

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", a[i][j]);
        }
    }

    printf("\na %d , a+1:%d ", a, a + 1);  // a+1�Ĳ��� (5*4) 20���ֽ�
    printf("\n&a %d , &a+1:%d ", &a, &a + 1); // a+1 ���� (3*5*4) 60 ���ֽ�

    {
        //����һ��ָ�������ָ�����
        int (*pArray)[5];//���߱�����  ���� 4���ֽڵ��ڴ� 32bitƽ̨��
        pArray = a;

        printf("\n");
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 5; j++) {
                printf("%d ", pArray[i][j]);
            }
        }
    }

    //��ά�������ı���  ����ָ�� ������ һά�ĳ���

    // (a+i) ������������i�еĵ�ַ  ����ָ��
    // *(a+i) ���� 1��ָ��  ��i����Ԫ�صĵ�ַ
    // *(a+i) + j  ===> &  a[i][j]
    //*( *(a+i) + j) ===>a[i][j]Ԫ�ص�ֵ
    //a[i][j] <=== >*( *(a+i) + j)
    //a[i] ===> a[0+i] ==> *(a+i);
    //a[i][j] === a[0+i][j]  ==>  *(a+i)[j]  ===>  *(a+i)[0 + j] ==>  *( *(a+i)  + j)

    return 0;
}
