//**************************
// Author:  yh
// Time:    2021/12/19
//**************************
#include <iostream>
#include "../../unit/unit.h"
int main() {
    int* pValue = nullptr; // declare pointer and initialize it so that it doesn't store a random address
    int i = 5;
    pValue = &i; // assign pointer to address of object
    int j = *pValue; // dereference pValue to retrieve the pValue at its address

    int value= 10;
    int *p = nullptr;
    p  = &value;
    printf("value: %d, value: %p\n p: %d, p: %p", value, &value, *p, p);

    return 0;
}
