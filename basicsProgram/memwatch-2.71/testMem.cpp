/*
 * @Author: yh
 * @Date: 2023-01-05 01:09:49
 * @LastEditTime: 2023-01-05 01:15:01
 * @Description: 
 * @FilePath: \cEssence\basicsProgram\memwatch-2.71\testMem.cpp
 */
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "memwatch.h"
#include <csignal>

int main() {
    char *p = nullptr;
    //TRACE("Hello world!\n");

    p = (char *)malloc(210);
    free(p);
    p = (char *)malloc(20);
    p = (char *)malloc(200); /* causes unfreed error */
    p[-1] = 0;       /* causes underflow error */
    free(p);

    return 0;
}