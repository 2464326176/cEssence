//**************************
// Author:  yh
// Time:    2022/3/9
//**************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 内存模型
void memoryModel() {
    //1. 指针数组
    char *p1[4] = {"hello", "world", "!!!"};

    //2. 二维数组
    char p2[3][7] = {"hello", "world", "!!!"};

    //3. 二维堆内存 申请
    char **p3 = (char **) malloc(3 * sizeof(char *)); //int array[3];
    for (int i = 0; i < 3; i++) {
        p3[i] = (char *) malloc(10 * sizeof(char)); //char buf[10]
    }

    // 释放内存
    for (int i = 0; i < 3; i++) {
        free(p3[i]);
        p3[i] = nullptr;
    }
    free(p3);
    p3 = nullptr;
}

void printfArray(char **myArray, int num) {
    for (int i = 0; i < num; i++) {
        //printf("%s \n", myArray[i]);
        printf("%s \n", *(myArray + i));
    }
}

void sortArrayByExchangePoint(char **myArray, int num) {
    char *tmp = NULL;
    for (int i = 0; i < num; i++) {
        for (int j = i; j < num; j++) {
            if (strcmp(myArray[i], myArray[j]) > 0) {
                tmp = myArray[i];  //交换的是数组元素 交换的是指针的值 //改变指针的指向
                myArray[i] = myArray[j];
                myArray[j] = tmp;
            }
        }
    }
}

// 第一种内存模型
int main1() {
    int i = 0, j = 0;
    int num = 0;
    char *tmp = NULL;

    //指针数组 数组中的每一个元素是指针
    char *myArray[4] = {"aaaaaa", "ccccc", "bbbbbb", "111111"};

    //打印
    num = sizeof(myArray) / sizeof(myArray[0]);

    printf("before sort\n");
    printfArray(myArray, num);

    sortArrayByExchangePoint(myArray, num);

    printf("after sort\n");
    printfArray(myArray, num);
    return 0;
}

// 第二种内存模型
//问题的本质是：dm03_二级指针做输入_第2种内存模型 的 myArray + 1
// dm03_二级指针做输入_第1种内存模型   myArray + 1 不一样 ；
//指针的步长不一样  指针所指向的内存空间的数据类不一样 。。。。
void printMyArray02_err(char **myArray, int num) {
    for (int i = 0; i < num; i++) {
        //printf("%s \n", myArray[i]);
        printf("%s \n", *(myArray + i));  //
    }
}

void printfArray02(char myArray[10][30], int num) {
    for (int i = 0; i < num; i++) {
        //printf("%s \n", myArray[i]);
        printf("%s \n", *(myArray + i));  //
    }
}

// 交换的是内存块
void sortMyArrayBySwapMemoryBlock(char myArray[10][30], int num) {
    char tmpBuf[30];
    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j++) {
            if (strcmp(myArray[i], myArray[j]) > 0) {
                strcpy(tmpBuf, myArray[i]);  //交换的是内存块
                strcpy(myArray[i], myArray[j]);
                strcpy(myArray[j], tmpBuf);
            }
        }
    }

}

int main2() {
    int num = 4;
    char myArray[10][30] = {"aaaaaa", "ccccc", "bbbbbbb", "1111111111111"};

    //myArray： 编译器只会关心：有10行 ，每行30列。。。。。干什么？myArray+1  多维数组名的本质，
    {
        int len1 = sizeof(myArray);
        int len2 = sizeof(myArray[0]);
        int size = len1 / len2;
        printf("len1:%d , len2:%d  size:%d \n", len1, len2, size);

    }

    printf("before sort\n");
    printfArray02(myArray, num);

    sortMyArrayBySwapMemoryBlock(myArray, num);

    printf("after sort\n");
    printfArray02(myArray, num);

    return 0;
}

// 第三种内存模型

char **getMemoryBlock(int num) {
    char **p2 = NULL;
    p2 = (char **) malloc(sizeof(char *) * num);
    if (p2 == NULL) {
        return NULL;
    }

    for (int i = 0; i < num; i++) {
        p2[i] = (char *) malloc(sizeof(char) * 100); //char buf[100];
        sprintf(p2[i], "%d%d%d", i + 1, i + 1, i + 1);
    }
    return p2;
}

void printMyArray03(char **myArray, int num) {
    int i = 0;
    for (i = 0; i < num; i++) {
        //printf("%s \n", myArray[i]);
        printf("%s \n", *(myArray + i));
    }
}

void sortMyArray03(char **myArray, int num) {
    int i = 0, j = 0;
    char *tmp = NULL;
    //排序
    for (i = 0; i < num; i++) {
        for (j = i; j < num; j++) {
            if (strcmp(myArray[i], myArray[j]) > 0) {
                tmp = myArray[i];  //注意  交换的是数组元素 交换的是指针的值 //改变指针的指向
                myArray[i] = myArray[j];
                myArray[j] = tmp;
            }
        }
    }
}

void freeMemoryBlock(char **p2, int num) {
    for (int i = 0; i < num; i++) {
        if (p2[i] != NULL) {
            free(p2[i]);
            p2[i] = NULL;
        }
    }

    if (p2 != NULL) {
        free(p2);
        p2 = nullptr;
    }
}

void safeFreeMemoryBlock(char ***p2, int num) {
    char **p = *p2;
    for (int i = 0; i < num; i++) {
        if (p[i] != NULL) {
            free(p[i]);
            p[i] = NULL;
        }
    }

    if (p != NULL) {
        free(p);
        *p2 = nullptr;
    }
}

int main() {
    int i = 0, j = 0, num = 5;
    char **p2 = NULL;
    char *tmp = NULL;
    p2 = getMemoryBlock(num);

    printf("before sort\n");
    printMyArray03(p2, num);

    sortMyArray03(p2, num);

    printf("after sort\n");
    printMyArray03(p2, num);

    freeMemoryBlock(p2, num); //p2是一个野指针
    if (p2 != nullptr) {
        printf("A wild pointer appears\n");
        p2 = nullptr;
    }

    /*safeFreeMemoryBlock(&p2, num);
    if (p2 != nullptr) {
        printf("A wild pointer appears\n");
        p2 = nullptr;
    }*/
    return 0;
}