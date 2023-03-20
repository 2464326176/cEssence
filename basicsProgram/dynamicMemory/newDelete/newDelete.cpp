/*
 * @Author: yh
 * @Date: 2022-05-20 23:53:25
 * @LastEditTime: 2023-03-14 23:18:18
 * @Description:
 * @FilePath: \cEssence\basicsProgram\dynamicMemory\newDelete\newDelete.cpp
 */
//**************************
// Author:  yh
// Time:    2021/12/3
//**************************

#include "newDelete.h"

void func() {
    fLogMemory = 1; // Turn logging on
    for (int i = 0; i < 10; ++i) {
        char *pMem = new char[10];
        delete[] pMem;
    }
    fLogMemory = 0; // Turn logging off.
}

void func1() {
    Blanks *blank = new (0Xa5) Blanks;
    printf("%s\n", (char *)blank);
}

int main(int argc, char *argv[]) {
    func1();
    return 0;
}