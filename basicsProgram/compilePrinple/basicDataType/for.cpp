/*
 * @Author: yh
 * @Date: 2022/10/20 23:53
 * @Description: 
 * @FilePath: for.cpp
 */

#include <iostream>
#include <ntgdi.h>
#include <d2d1helper.h>

using namespace std;

int getArrayLength() {
    printf("getArrayLength\n");
    return 5;
}

int autoincrement(int &i) {
    printf("autoincrement\n");
    ++i;
    return i;
}

int main() {
//    if (true || getArrayLength()) {
//        cout << "ok";
//    }
//
//    if (true && getArrayLength()) {
//        cout << "ok";
//    }

//    for (int i = 0; i < getArrayLength(); autoincrement(i)) {
//        cout << i << " ";
//    }
//    cout << endl;
    
    int x = 20;
    for (int i = 0; i < 1; ++i)
        int y = 30;
    
    //cout << x << y << endl; // error
    return 0;
}
