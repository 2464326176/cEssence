/*
 * @Author: yh
 * @Date: 2022-05-20 23:53:25
 * @LastEditTime: 2023-03-26 18:58:57
 * @Description:
 * @FilePath: \cEssence\basicsProgram\pointerTopic\pointer\typeSize.cpp
 */
//**************************
// Author:  yh
// Time:    2022/1/28
//**************************

#include <iostream>

#pragma pack(2)

struct st1 {
    char c;
    int i;
    char c1;
    int i1;
};

struct st {
    char c;
    int i;
    char c1;
    int i1;
};

int main() {
    int _i;
    char _c;
    char _str[20];
    int _int[20];
    char *pStr;
    int *pInt;
    printf("_i      %d\n", sizeof(_i));
    printf("_c      %d\n", sizeof(_c));
    printf("char    %d\n", sizeof(char));
    printf("int     %d\n", sizeof(int));
    printf("char *  %d\n", sizeof(char *));
    printf("int *   %d\n", sizeof(int *));
    printf("_str    %d\n", sizeof(_str));
    printf("_int    %d\n", sizeof(_int));
    printf("pStr    %d\n", sizeof(pStr));
    printf("pInt    %d\n", sizeof(pInt));
    printf("st1: %d, st2: %d\n", sizeof(st), sizeof(st1));
    return 0;
}