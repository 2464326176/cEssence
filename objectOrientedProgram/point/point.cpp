//**************************
// Author:  yh
// Time:    2022/1/18
//**************************
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 5

char* getStr1() {
    char *p1 = "abcdefg";
    return p1;
}

char* getStr2() {
    char *p1 = "abcdefg1";
    return p1;
}

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
    int intArray[ARRAY_SIZE] = {4, 5, 8, 9, 4}; // 一个有5个整型数的数组

    int **pInt = &pInteger; //一个指向指针的指针 指向的指针是指向一个整型数
    int (*a2)[5]; // 一个指向有5个整型数数组的指针
    /*int (*a3)(int); // 一个指向函数的指针 该函数有一个整型参数并返回一个整型数
    int (*a4[10])(int); // 一个有10个指针的数组 该指针指向一个函数 该函数有一个整型参数并返回一个整型数*/

    printf("%d, %d, %d\n %p, %p, %p \n", integerNum, *pInteger, **pInt, &integerNum, pInteger, pInt);
    printfArray(intArray, sizeof(intArray) / sizeof(int));

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
}

// point global area
void test1() {
    char *p1 = "abcdefg1";
    char *p2 = "abcdefg";

    printf("%s %d\n", p1, p1);
    printf("%s %d\n", p2, p2);

    p1 = getStr1();
    p2 = getStr2();

    printf("%s %d\n", p1, p1);
    printf("%s %d\n", p2, p2);
    return ;
}

// point type
void test2() {
    int _int;
    char _char;
    char _str[20];
    int _intArray[20];
    char *pStr;
    int *pInt;
    int **pInt1;
    int ******pInt2;

    printf("sizeof(int))        %d\n", sizeof(int));      //sizeof(int))        4
    printf("sizeof(_int))       %d\n", sizeof(_int));     //sizeof(_int))       4
    printf("sizeof(char))       %d\n", sizeof(char));     //sizeof(char))       1
    printf("sizeof(_char))      %d\n", sizeof(_char));    //sizeof(_char))      1
    printf("sizeof(_str))       %d\n", sizeof(_str));     //sizeof(_str))       20
    printf("sizeof(_intArray))  %d\n", sizeof(_intArray));//sizeof(_intArray))  80
    printf("sizeof(char *))     %d\n", sizeof(char *));   //sizeof(char *))     8
    printf("sizeof(pStr))       %d\n", sizeof(pStr));     //sizeof(pStr))       8
    printf("sizeof(int *))      %d\n", sizeof(int *));    //sizeof(int *))      8
    printf("sizeof(pInt))       %d\n", sizeof(pInt));     //sizeof(pInt))       8
    printf("sizeof(pInt1))      %d\n", sizeof(pInt1));    //sizeof(pInt1))      8
    printf("sizeof(pInt2))      %d\n", sizeof(pInt2));    //sizeof(pInt2))      8
};

void test3() {
    int a = 5;
    int b = 7;
    int* pInt = nullptr;
    int* pInt1 = nullptr;
    pInt = &a;
    pInt1 = &b;
    a = *pInt1;
    *pInt = 8;

    printf("%d %d %d\n", a, *pInt, *pInt1); // 8 8 7
    printf("%d %d %d\n", &a, pInt, pInt1);  // 6422028 6422028 6422024
}

int main() {
    //test1();
    //test2();

    return 0;
}













int main11() {
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















