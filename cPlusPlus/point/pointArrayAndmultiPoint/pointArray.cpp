//**************************
// Author:  yh
// Time:    2022/2/26
//**************************

#include "pointArray.h"
#include <iostream>


int main() {
    char *name[] = {"follow me", "great wall", "hello world"};
    char **p;
    print(name, 3);

    for (int i = 0; i < 3; ++i) {
        p = name + i;
        printf("%s \n", *p);
    }

    return 0;
}

void print(char *name[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%s \n", name[i]);
    }
}
