//**************************
// Author:  yh
// Time:    2022/3/10
//**************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//怎么样表达int a[10]这种数据类型那？int[]
//类型本质：固定大小内存块的别名
//定义数组类型

//定义数组指针变量的方法1
//用数组类型 *
void pointArray1() {
    char *Myarray[] = {"1111", "33333", "aaaa"}; //指针数组 用一个指针 来指向一个数组

    typedef int(MyArrayType)[5]; //定义了一个数据类型  数组数据类型
    MyArrayType myArray;         // int myArray[5]; 用类型定义变量
    MyArrayType *pArray;         // int (*pArray)[5]; 定义一个指针变量 这个指针变量 指向一个数组

    int i = 0;
    {
        int a;
        int *p = NULL;
        p = &a;
    }

    {
        int myArray2[5];    //相当于一级指针
        pArray = &myArray2; //相当于2级指针
        for (i = 0; i < 5; i++) {
            (*pArray)[i] = i + 1;
        }

        for (i = 0; i < 5; i++) {
            printf("%d ", (*pArray)[i]);
        }
    }
}

//定义数组指针变量的第二种方法
void pointArray2() {
    //定义声明一个数组指针类型
    typedef int(*PArrayType)[5];
    PArrayType pArray; //告诉编译器 给我分配一个指针变量

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

//定义数组指针变量的第三种方法
//前2种方法 通过类型定义变量 比较麻烦
void pointArray3() {
    // int [][5]
    int(*pMyArray)[5]; //直接定义一个指向数组的 数组指针变量
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