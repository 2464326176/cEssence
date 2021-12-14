//**************************
// Author:  yh
// Time:    2021/12/3
//**************************

#include "newDelete.h"
#include <iostream>


using namespace std;

int fLogMemory = 0;      // Perform logging (0=no; nonzero=yes)?
int cBlocksAllocated = 0;  // Count of blocks allocated.

// User-defined operator new.
void *operator new( size_t stAllocateBlock ) {
    static int fInOpNew = 0;   // Guard flag.

    if ( fLogMemory && !fInOpNew ) {
        fInOpNew = 1;
        cout << "Memory block " << ++cBlocksAllocated << " allocated for " << stAllocateBlock << " bytes" << endl;
        fInOpNew = 0;
    }
    return malloc( stAllocateBlock );
}

// User-defined operator delete.
void operator delete( void *pvMem ) {
    static int fInOpDelete = 0;   // Guard flag.
    if ( fLogMemory && !fInOpDelete ) {
        fInOpDelete = 1;
        cout << "Memory block " << cBlocksAllocated--
             << " deallocated" << endl;
        fInOpDelete = 0;
    }

    free( pvMem );
}

int main( int argc, char *argv[] ) {
    fLogMemory = 1;   // Turn logging on
    for(int i = 0; i < 10; ++i) {
        char *pMem = new char[10];
        delete[] pMem;
    }
    fLogMemory = 0;  // Turn logging off.
    return 0;
}