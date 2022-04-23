//**************************
// Author:  yh
// Time:    2022/2/26
//**************************

#include "pointFunction.h"
#include <iostream>

int fun(int (*x1)(int), int (*x2)(int, int)) {
    int a, b, i = 3, j = 5;
    a = (*x1)(i);
    b = (*x2)(i, j);
    return a > b ? a : b;
}

int main() {
    int a = 6, b = 8;
    int (*pFunction)(int, int);
    int (*pFunction1)(int);

    pFunction = max;
    pFunction1 = autoIncrease;

    int c = max(a, b);
    int d = pFunction(a, b);
    int e = (*pFunction)(a, b);
    int f = fun(pFunction1, pFunction);

    std::cout << c << " " << d << " " << e << " " << f << " "<< std::endl;
    return 0;
}

int max(int x, int y) {
    return x > y ? x : y;
}

int autoIncrease(int x) {
    return ++x;
}
