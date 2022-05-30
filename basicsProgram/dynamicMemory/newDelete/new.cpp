/*
 * @Author: yh
 * @Date: 2022/5/30 23:04
 * @Description: 
 * @FilePath: new.cpp
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
    int *p1 = new int; // 16211936
    int *p2 = new int(); // 0
    int *p3 = new int(0); // 0
    int *pia1 = new int[10]; // 16211936 0 16187728 0 0 0 150994953 29383 16211936 0
    int *pia2 = new int[10](); // 0 0 0 0 0 0 0 0 0 0
    int *pia3 = new int[10]{1, 3, 5, 7, 8, 9, 6}; // 1 3 5 7 8 9 6 0 0 0
    
    string *ps1 = new string[10];
    string *ps2 = new string[10](); // null
    string *ps3 = new string[10]{"a", "bbb", "cc", "dasd", "asdk", "aksdl;a"}; // a bbb cc dasd asdk aksdl;a
    
    printf("p1: %d p2: %d p3: %d, ps1: %s\n", *p1, *p2, *p3, ps1->c_str()); // p1: 16211936 p2: 0 p3: 0, ps1:
    
    for (int *p = pia1; p != pia1 + 10; ++p) {
        printf("%d ", *p);
    }
    printf("\n"); // 16211936 0 16187728 0 0 0 150994953 29383 16211936 0
    
    for (int *p = pia2; p != pia2 + 10; ++p) {
        printf("%d ", *p);
    }
    printf("\n");
    
    for (int *p = pia3; p != pia3 + 10; ++p) {
        printf("%d ", *p);
    }
    printf("\n");
    
    for (string *p = ps2; p != ps2 + 10; ++p) {
        printf("%s ", p->c_str());
    }
    printf("\n");
    for (string *p = ps3; p != ps3 + 10; ++p) {
        printf("%s ", p->c_str());
    }
    printf("\n");
    return 0;
}