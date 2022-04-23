//**************************
// Author:  yh
// Time:    2022/1/13
//**************************

#include <stdio.h>
#include <stdlib.h>
#include <cstring>

int _getenv() {
    char *pPath = getenv("PATH");
    printf("path: \n %s \n", pPath);
    char *pToken = strtok(pPath, ";");
    while (pToken != NULL) {
        printf("%s \n", pToken);
        pToken = strtok(NULL, ";");
    }

    return 0;
}