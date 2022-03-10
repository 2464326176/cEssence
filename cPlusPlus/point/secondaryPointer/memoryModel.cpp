//**************************
// Author:  yh
// Time:    2022/3/9
//**************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �ڴ�ģ��
void memoryModel() {
    //1. ָ������
    char *p1[4] = {"hello", "world", "!!!"};

    //2. ��ά����
    char p2[3][7] = {"hello", "world", "!!!"};

    //3. ��ά���ڴ� ����
    char **p3 = (char **) malloc(3 * sizeof(char *)); //int array[3];
    for (int i = 0; i < 3; i++) {
        p3[i] = (char *) malloc(10 * sizeof(char)); //char buf[10]
    }

    // �ͷ��ڴ�
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
                tmp = myArray[i];  //������������Ԫ�� ��������ָ���ֵ //�ı�ָ���ָ��
                myArray[i] = myArray[j];
                myArray[j] = tmp;
            }
        }
    }
}

// ��һ���ڴ�ģ��
int main1() {
    int i = 0, j = 0;
    int num = 0;
    char *tmp = NULL;

    //ָ������ �����е�ÿһ��Ԫ����ָ��
    char *myArray[4] = {"aaaaaa", "ccccc", "bbbbbb", "111111"};

    //��ӡ
    num = sizeof(myArray) / sizeof(myArray[0]);

    printf("before sort\n");
    printfArray(myArray, num);

    sortArrayByExchangePoint(myArray, num);

    printf("after sort\n");
    printfArray(myArray, num);
    return 0;
}

// �ڶ����ڴ�ģ��
//����ı����ǣ�dm03_����ָ��������_��2���ڴ�ģ�� �� myArray + 1
// dm03_����ָ��������_��1���ڴ�ģ��   myArray + 1 ��һ�� ��
//ָ��Ĳ�����һ��  ָ����ָ����ڴ�ռ�������಻һ�� ��������
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

// ���������ڴ��
void sortMyArrayBySwapMemoryBlock(char myArray[10][30], int num) {
    char tmpBuf[30];
    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j++) {
            if (strcmp(myArray[i], myArray[j]) > 0) {
                strcpy(tmpBuf, myArray[i]);  //���������ڴ��
                strcpy(myArray[i], myArray[j]);
                strcpy(myArray[j], tmpBuf);
            }
        }
    }

}

int main2() {
    int num = 4;
    char myArray[10][30] = {"aaaaaa", "ccccc", "bbbbbbb", "1111111111111"};

    //myArray�� ������ֻ����ģ���10�� ��ÿ��30�С�����������ʲô��myArray+1  ��ά�������ı��ʣ�
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

// �������ڴ�ģ��

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
    //����
    for (i = 0; i < num; i++) {
        for (j = i; j < num; j++) {
            if (strcmp(myArray[i], myArray[j]) > 0) {
                tmp = myArray[i];  //ע��  ������������Ԫ�� ��������ָ���ֵ //�ı�ָ���ָ��
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

    freeMemoryBlock(p2, num); //p2��һ��Ұָ��
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