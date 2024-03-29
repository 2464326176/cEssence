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
    int array[16] = {0};             //编译的时间 确定所有的值为0
    memset(array, 0, sizeof(array)); //显示的 重置内存块
    for (int i = 0; i < sizeof(array); i++) {
        array[i] = i;
    }
    // C规定一维数组
    // array是数组首元素的地址 c+1 步长 4个字节
    // &array 是整个数组的地址 //&c+1 步长 200*4
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

    printf("a: %p , a+1: %p\n", a, a + 1);     // a+1的步长 (5*4) 20个字节
    printf("&a: %p , &a+1: %p\n", &a, &a + 1); // a+1 步长 (3*5*4) 60 个字节

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            a[i][j] = tmp++;
        }
    }

    // twoDimensionalArray01(a);
    // twoDimensionalArray02(a);
    twoDimensionalArray03(a);

    {
        //定义一个指向数组的指针变量
        int(*pArray)[5]; //告诉编译器  分配 4个字节的内存 32bit平台下
        pArray = a;

        for (i = 0; i < 3; i++) {
            for (j = 0; j < 5; j++) {
                printf("%d ", pArray[i][j]);
            }
        }
        printf("\n");
    }

    //多维数组名的本质  数组指针 ，步长 一维的长度
    // (a+i) 代表是整个第i行的地址  二级指针
    // *(a+i) 代表 1级指针  第i行首元素的地址
    // *(a+i) + j  ===> &a[i][j]
    //*( *(a+i) + j) ===>a[i][j]元素的值
    // a[i][j] <=== >*( *(a+i) + j)
    // a[i] ===> a[0+i] ==> *(a+i);
    // a[i][j] === a[0+i][j]  ==>  *(a+i)[j]  ===>  *(a+i)[0 + j] ==>  *( *(a+i)  + j)
}

int main() {
    oneDimensionalArray();
    twoDimensionalArray();
    return 0;
}
