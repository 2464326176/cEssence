//**************************
// Author:  yh
// Time:    2022/2/28
//**************************

#include "virtualTable.h"

using namespace std;

int main() {
    char a3[3];
    char a2[2];
    cout << "sizeof(int): " << sizeof(int) << endl;
    cout << "sizeof(int *): " << sizeof(int *) << endl;
    cout << "sizeof(char a[2]): " << sizeof(a2) << endl;
    cout << "sizeof(char a[3]): " << sizeof(a3) << endl;
    
    cout << "sizeof(A0): " << sizeof(A0) << endl;
    cout << "sizeof(B0): " << sizeof(B0) << endl;
    cout << "sizeof(C0): " << sizeof(C0) << endl;
    
    A a;
    cout << "sizeof(k): " << sizeof(a.k) << endl;
    cout << "sizeof(int *): " << sizeof(int *) << endl;
    cout << "sizeof(A): " << sizeof(A) << endl;
    cout << "sizeof(B): " << sizeof(B) << endl;
    cout << "sizeof(C): " << sizeof(C) << endl;
    
    cout << "sizeof(A1): " << sizeof(A1) << endl;
    cout << "sizeof(B1): " << sizeof(B1) << endl;
    cout << "sizeof(C1): " << sizeof(C1) << endl;
    
    cout << "sizeof(A2): " << sizeof(A2) << endl;
    cout << "sizeof(B2): " << sizeof(B2) << endl;
    cout << "sizeof(C2): " << sizeof(C2) << endl;
    return 0;
}
