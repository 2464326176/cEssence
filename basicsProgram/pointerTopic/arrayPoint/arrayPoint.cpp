//**************************
// Author:  yh
// Time:    2022/3/10
//**************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��ô�����int a[10]�������������ǣ�int[]
//���ͱ��ʣ��̶���С�ڴ��ı���
//������������

//��������ָ������ķ���1
//���������� *
void pointArray1() {
    char *Myarray[] = {"1111", "33333", "aaaa"}; //ָ������ ��һ��ָ�� ��ָ��һ������

    typedef int(MyArrayType)[5]; //������һ����������  ������������
    MyArrayType myArray;         // int myArray[5]; �����Ͷ������
    MyArrayType *pArray;         // int (*pArray)[5]; ����һ��ָ����� ���ָ����� ָ��һ������

    int i = 0;
    {
        int a;
        int *p = NULL;
        p = &a;
    }

    {
        int myArray2[5];    //�൱��һ��ָ��
        pArray = &myArray2; //�൱��2��ָ��
        for (i = 0; i < 5; i++) {
            (*pArray)[i] = i + 1;
        }

        for (i = 0; i < 5; i++) {
            printf("%d ", (*pArray)[i]);
        }
    }
}

//��������ָ������ĵڶ��ַ���
void pointArray2() {
    //��������һ������ָ������
    typedef int(*PArrayType)[5];
    PArrayType pArray; //���߱����� ���ҷ���һ��ָ�����

    int c[5];
    int i = 0;
    pArray = &c;

    for (i = 0; i < 5; i++) {
        (*pArray)[i] = i + 1;
    }

    for (i = 0; i < 5; i++) {
        printf("%d ", (*pArray)[i]);
    }
}

//��������ָ������ĵ����ַ���
//ǰ2�ַ��� ͨ�����Ͷ������ �Ƚ��鷳
void pointArray3() {
    // int [][5]
    int(*pMyArray)[5]; //ֱ�Ӷ���һ��ָ������� ����ָ�����
    int c[5];
    int i = 0;
    pMyArray = &c;

    for (i = 0; i < 5; i++) {
        (*pMyArray)[i] = i + 1;
    }

    for (i = 0; i < 5; i++) {
        printf("%d ", (*pMyArray)[i]);
    }

    return;
}

int arrayPoint() {
    int a[][4] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23};
    int *p;
    int(*pArray)[4];

    for (p = a[0]; p < a[0] + 12; ++p) {
        if ((p - a[0]) % 4 == 0) {
            printf("\n");
        }
        printf("%d ", *p);
    }
    printf("\n");

    pArray = a;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("%d ", *(*(pArray + i) + j));
        }
        printf("\n");
    }
    return 0;
}

void average(float *p, int n) {
    float *p_end = p + n - 1, sum = 0, aver = 0;
    for (; p < p_end; ++p) {
        sum = sum + *p;
    }
    aver = sum / n;
    printf("aver: %f\n", aver);
}

void search(float (*p)[4], int n) {
    for (int i = 0; i < 4; ++i) {
        printf("%f ", *(*(p + n) + i));
    }
    printf("\n");
}

int main() {
    float score[3][4] = {{51, 52, 53, 54}, {61, 62, 63, 64}, {71, 72, 73, 74}};
    // average(*(score + 0) + 0, 12);
    // search(score, 2);
    float(*fArray)[4] = &score[1];
    printf("%p, %p", fArray, fArray + 1);
    return 0;
}