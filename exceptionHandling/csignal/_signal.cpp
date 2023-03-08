/*
 * @Author: yh
 * @Date: 2022-05-20 23:53:26
 * @LastEditTime: 2023-02-14 00:47:18
 * @Description: 
 * @FilePath: \cEssence\exceptionHandling\csignal\_signal.cpp
 */
//**************************
// Author:  yh
// Time:    2022/1/13
//**************************

#include "_signal.h"
#include <signal.h>
#include <stdio.h>


sig_atomic_t signaled = 0;

void my_handler(int param) { signaled = 1; }

int main() {
    void (*prev_handler)(int);

    prev_handler = signal(SIGINT, my_handler);

    raise(SIGINT);

    printf("signaled is %d \n", signaled);
    return 0;
}