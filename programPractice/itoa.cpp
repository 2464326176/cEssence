//**************************
// Author:  yh
// Time:    2022/1/24
//**************************
#include <iostream>
#include <cstring>
#define LENG 10

int _cast() {
    char cStr[LENG];
    char *p = nullptr;
    p = (char *)malloc(LENG * sizeof(char *));

    printf("%d, %d, %d\n", strlen(p), sizeof(p), LENG * sizeof(char *));
    printf("%d, %d\n", strlen(cStr), sizeof(cStr));
    strncpy(p, "i like world!!!", LENG * sizeof(char *));

    char *pStr = "a";
    int i = (int)"a";
    int i1 = (int)p;
    int i2 = reinterpret_cast<int>(&p);
    printf("%d, %d, %d\n", i, i1, i2);
    /*int iValue1 = const_cast<int>(p);
    int iValue2 = static_cast<int>(&p);
    int iValue3 = dynamic_cast<int>(p);
    int iValue4 = const_cast<int>(p);*/

    printf("%d", iValue1);

    return 0;
}

void _union() {
    union {
        unsigned char ch;
        unsigned int i;
    } u;

    u.i = 0xf0f1f2f3;
    std::cout << std::hex << u.i << std::endl;
    std::cout << std::hex << (int)u.ch << std::endl;



}


int main() {

    return 0;
}

























