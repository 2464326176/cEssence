/*
 * @Author: yh
 * @Date: 2022-05-20 23:53:25
 * @LastEditTime: 2022-03-17 00:07:29
 * @Description:
 * @FilePath: \cEssence\basicsProgram\pointerTopic\function\pointFunction.cpp
 */

#include "pointFunction.h"
#include <iostream>

int fun(int (*x1)(int), int (*x2)(int, int)) {
    int a, b, i = 3, j = 5;
    a = (*x1)(i);
    b = (*x2)(i, j);
    return a > b ? a : b;
}

int fun1(pAutoInc autoInc, pGetMax getMax) {
    int a, b, i = 3, j = 5;
    a = (*autoInc)(i);
    b = (*getMax)(i, j);
    return a > b ? a : b;
}

int max(int x, int y) { return x > y ? x : y; }

int autoIncrease(int x) { return ++x; }

int main() {
    int a = 6, b = 8;
    pGetMax getMax = max;
    pAutoInc autoInc = autoIncrease;

    int c = max(a, b);
    int d = getMax(a, b);
    int e = (*getMax)(a, b);
    int f = fun1(autoInc, getMax);

    std::cout << c << " " << d << " " << e << " " << f << " " << std::endl;
    return 0;
}
