//**************************
// Author:  yh
// Time:    2022/3/10
//**************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*#ifndefine __CPlusPlus




#endif*/

// One-dimensional array
void printfOneDimensionalArray01(int array[16], size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void printfOneDimensionalArray02(int array[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void printfOneDimensionalArray03(int *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", *(array + i));
    }
    printf("\n");
}

void oneDimensionalArray() {
    int array[16] = {0};             //�����ʱ�� ȷ�����е�ֵΪ0
    memset(array, 0, sizeof(array)); //��ʾ�� �����ڴ��
    for (int i = 0; i < sizeof(array); i++) {
        array[i] = i;
    }
    // C�涨һά����
    // array��������Ԫ�صĵ�ַ c+1 ���� 4���ֽ�
    // &array ����������ĵ�ַ //&c+1 ���� 200*4
    printf("%p %p %p %p\n", array, &array, array + 1, &array + 1);
    printfOneDimensionalArray01(array, sizeof(array) / sizeof(array[0]));
    printfOneDimensionalArray02(array, sizeof(array) / sizeof(array[0]));
    printfOneDimensionalArray03(array, sizeof(array) / sizeof(array[0]));
}

// Two-dimensional array
void twoDimensionalArray01(int a[3][5]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", a[i][j]);
        }
    }
    printf("\n");
}

void twoDimensionalArray02(int a[][5]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", a[i][j]);
        }
    }
    printf("\n");
}

void twoDimensionalArray03(int (*a)[5]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", a[i][j]);
        }
    }
    printf("\n");
}

void twoDimensionalArray() {
    int a[3][5], i = 0, j = 0;
    int tmp = 1;

    printf("a: %p , a+1: %p\n", a, a + 1);     // a+1�Ĳ��� (5*4) 20���ֽ�
    printf("&a: %p , &a+1: %p\n", &a, &a + 1); // a+1 ���� (3*5*4) 60 ���ֽ�

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            a[i][j] = tmp++;
        }
    }

    // twoDimensionalArray01(a);
    // twoDimensionalArray02(a);
    twoDimensionalArray03(a);

    {
        //����һ��ָ�������ָ�����
        int(*pArray)[5]; //���߱�����  ���� 4���ֽڵ��ڴ� 32bitƽ̨��
        pArray = a;

        for (i = 0; i < 3; i++) {
            for (j = 0; j < 5; j++) {
                printf("%d ", pArray[i][j]);
            }
        }
        printf("\n");
    }

    //��ά�������ı���  ����ָ�� ������ һά�ĳ���
    // (a+i) ������������i�еĵ�ַ  ����ָ��
    // *(a+i) ���� 1��ָ��  ��i����Ԫ�صĵ�ַ
    // *(a+i) + j  ===> &a[i][j]
    //*( *(a+i) + j) ===>a[i][j]Ԫ�ص�ֵ
    // a[i][j] <=== >*( *(a+i) + j)
    // a[i] ===> a[0+i] ==> *(a+i);
    // a[i][j] === a[0+i][j]  ==>  *(a+i)[j]  ===>  *(a+i)[0 + j] ==>  *( *(a+i)  + j)
}

int main() {
    oneDimensionalArray();
    twoDimensionalArray();
    return 0;
}
