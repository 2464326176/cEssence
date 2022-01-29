//**************************
// Author:  yh
// Time:    2022/1/18
//**************************
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 5
void printfArray(int *array, int length) {
    int i = 0;
    while(i < length) {
        printf("array[%d]: %d \n", i, *(array + i));
        ++i;
    }
}

void ptrArray() {
    srand(time(NULL));
    int integerNum = 3;  // 一个整型数
    int *pInteger = &integerNum; // 一个指向整形数的指针
    int **pInt = &pInteger; //一个指向指针的指针 指向的指针是指向一个整型数
    printf("%d, %d, %d\n %p, %p, %p \n", integerNum, *pInteger, **pInt, &integerNum, pInteger, pInt);


    int a[ARRAY_SIZE] = {4, 5, 8, 9, 4}; // 一个有5个整型数的数组
    printfArray(a, sizeof(a) / sizeof(int));
    int *a1[ARRAY_SIZE]; // 一个有5个指针的数组，该指针是指向一个整型数

    for(int i = 0; i < ARRAY_SIZE; ++i) {
        int *p = NULL;
        p = (int *)malloc(sizeof(int *));
        *p = i + (rand() % 10) + 1;
        a1[i] = p;
    }

    for(int i = 0; i < ARRAY_SIZE; ++i) {
        printf("array[%d]: %d ", i, *a1[i]);
        free(a1[i]);
    }

    int (*a2)[5]; // 一个指向有5个整型数数组的指针
    /*int (*a3)(int); // 一个指向函数的指针 该函数有一个整型参数并返回一个整型数
    int (*a4[10])(int); // 一个有10个指针的数组 该指针指向一个函数 该函数有一个整型参数并返回一个整型数*/

    return ;
}















int main() {
    /*void (*f)();
    void *f();*/
    ptrArray();

    /*int a = 5, b = 6;
    int const *cPtr1 = &a; // const 指针(指针指向的内容不能被修改)
    int* const cPtr2 = &b; // 指向const的指针(指针本身的值无法改变 所以必须初始化)

    //cPtr2 = &a; // error
    //const int* const; // 指向const的const指针
    printf("%d", *cPtr1);*/
    return 0;
}















