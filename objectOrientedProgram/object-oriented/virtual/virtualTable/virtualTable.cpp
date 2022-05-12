//**************************
// Author:  yh
// Time:    2022/2/28
//**************************

#include "virtualTable.h"
#include <iostream>

using namespace std;

int main() {
    A a;
    cout << "sizeof(k): " << sizeof(a.k) << endl;
    cout << "sizeof(int *): " << sizeof(int *) << endl;
    cout << "sizeof(A): " << sizeof(A) << endl;
    cout << "sizeof(B): " << sizeof(B) << endl;
    cout << "sizeof(C): " << sizeof(C) << endl;


    cout << sizeof(A) << endl << sizeof(B) << endl << sizeof(C) << endl;
    cout << sizeof(B2) << endl;
    return 0;
}
