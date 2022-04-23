//**************************
// Author:  yh
// Time:    2022/4/20
//**************************

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <winbase.h>
using namespace std;

#define DLL_PATH "D:\\lyh\\opengrok\\source\\cEssence\\interfacePackageDesign\\displayInvocate\\cmake-build-debug\\math\\TEXT.dll"
#define MYMATH_DLL_PATH "D:\\lyh\\opengrok\\source\\cEssence\\interfacePackageDesign\\displayInvocate\\cmake-build-debug\\math\\MYMATH.dll"

typedef int (__cdecl *optAdd)(int a, int b);
typedef int (__cdecl *optSub)(int a, int b);
typedef int (__cdecl *optMul)(int a, int b);

struct MathOperate {
    HINSTANCE pHinstLib;
    optAdd pAdd;
    optSub pSub;
    optMul pMul;
} mathOperate;

MathOperate pHandle;

BOOL loadLibrary() {
    BOOL fRunTimeLinkSuccess = TRUE;
    pHandle.pHinstLib = LoadLibrary(TEXT(MYMATH_DLL_PATH));
    if (NULL != pHandle.pHinstLib) {
        pHandle.pAdd = (optAdd) GetProcAddress(pHandle.pHinstLib, "add");
        if (NULL == pHandle.pAdd) {
            printf("%lu/n", GetLastError());
            fRunTimeLinkSuccess = FALSE;
        }

        pHandle.pSub = (optSub) GetProcAddress(pHandle.pHinstLib, "sub");
        if (NULL == pHandle.pSub) {
            printf("%lu/n", GetLastError());
            fRunTimeLinkSuccess = FALSE;
        }

        pHandle.pMul = (optMul) GetProcAddress(pHandle.pHinstLib, "mul");
        if (NULL == pHandle.pMul) {
            printf("%lu/n", GetLastError());
            fRunTimeLinkSuccess = FALSE;
        }

    } else {
        printf("load library %s fail!!!", MYMATH_DLL_PATH);
        fRunTimeLinkSuccess = FALSE;
    }

    return fRunTimeLinkSuccess;
}


typedef int (__cdecl *myAdd)(LPWSTR);

int load( )
{
    HINSTANCE hinstLib;
    myAdd ProcAdd;
    BOOL fFreeResult, fRunTimeLinkSuccess = FALSE;

    hinstLib = LoadLibrary(TEXT(DLL_PATH));

    if (hinstLib != NULL)
    {
        ProcAdd = (myAdd) GetProcAddress(hinstLib, "myPuts");

        if (NULL != ProcAdd)
        {
            fRunTimeLinkSuccess = TRUE;
            (ProcAdd) (L"Message sent to the DLL function/n");
        }

        fFreeResult = FreeLibrary(hinstLib);
    }

    if (! fRunTimeLinkSuccess)
        printf("Message printed from executable/n");

    return 0;
}

BOOL freeLibrary() {
    BOOL fFreeResult = FALSE;
    if(NULL != pHandle.pHinstLib) {
        BOOL fFreeResult = FreeLibrary(pHandle.pHinstLib);
        if(!fFreeResult) {
            printf("FreeLibrary success!!!/n");
        }

        return fFreeResult;
    }
    printf("not need FreeLibrary!!!/n");
    return fFreeResult;
}

int main() {
    int a = 5, b = 8;

    if(loadLibrary()) {
        cout << "a + b: " << pHandle.pAdd(a, b) << endl;
        cout << "a - b: " << pHandle.pSub(a, b) << endl;
        cout << "a * b: " << pHandle.pMul(a, b) << endl;
    }

    freeLibrary();
    return 0;
}
