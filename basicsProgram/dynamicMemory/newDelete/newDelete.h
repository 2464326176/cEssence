/*
 * @Author: yh
 * @Date: 2022-05-20 23:53:25
 * @LastEditTime: 2023-03-14 23:15:39
 * @Description:
 * @FilePath: \cEssence\basicsProgram\dynamicMemory\newDelete\newDelete.h
 */
//**************************
// Author:  yh
// Time:    2021/12/3
//**************************

#ifndef CESSENCE_NEWDELETE_H
#define CESSENCE_NEWDELETE_H
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <memory>

using namespace std;
class Blanks {
public:
    void *operator new(size_t size, char ch) {
        printf("%d | %c\n", size, ch);
        void *pvTemp = malloc(size);
        if (pvTemp) {
            memset(pvTemp, ch, size);
        }
        return pvTemp;
    }
};

int fLogMemory = 0;       // Perform logging (0=no; nonzero=yes)?
int cBlocksAllocated = 0; // Count of blocks allocated.

// User-defined operator new.
void *operator new(size_t stAllocateBlock) {
    static int fInOpNew = 0; // Guard flag.

    if (fLogMemory && !fInOpNew) {
        fInOpNew = 1;
        cout << "Memory block " << ++cBlocksAllocated << " allocated for " << stAllocateBlock << " bytes" << endl;
        fInOpNew = 0;
    }
    return malloc(stAllocateBlock);
}

// User-defined operator delete.
void operator delete(void *pvMem) {
    static int fInOpDelete = 0; // Guard flag.
    if (fLogMemory && !fInOpDelete) {
        fInOpDelete = 1;
        cout << "Memory block " << cBlocksAllocated-- << " deallocated" << endl;
        fInOpDelete = 0;
    }

    free(pvMem);
}

#endif // CESSENCE_NEWDELETE_H
