/*
 * @Author: yh
 * @Date: 2022-05-20 23:53:25
 * @LastEditTime: 2023-02-14 00:51:54
 * @Description:
 * @FilePath: \cEssence\exceptionHandling\cassert\_asser.cpp
 */

#include <assert.h>
#include <stdio.h>

void print_number(int *myInt) {
    assert(myInt != nullptr);
    printf("%d\n", *myInt);
}

int main() {
    int a = 10;
    int *b = nullptr;
    int *c = nullptr;

    b = &a;
    print_number(b);
    print_number(c);
    return 0;
}