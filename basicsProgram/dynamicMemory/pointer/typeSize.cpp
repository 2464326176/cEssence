//**************************
// Author:  yh
// Time:    2022/1/28
//**************************

#include <iostream>

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
    printf("pInt    %d %d %d %p\n", 0x61fdfc, 4, 0x61fdfc - 4, 0x61fdfc - 4);
    
    return 0;
}