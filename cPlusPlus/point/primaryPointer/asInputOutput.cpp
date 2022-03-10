//**************************
// Author:  yh
// Time:    2022/3/6
//**************************
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>


void asInput(char *input);
void asInput(char *input, int num);
void asOutput(char *input, char *output);



void asInput(char *input) {
    char* pCh = input;

    while(*pCh++ != '\0') {
        *pCh = toupper(*pCh);
    }
    printf("to upper: %s \n", input);
};

void asInput(int *input, int num) {
    int* pInt = input;
    for(int i = 0; i < num; ++i) {
        printf("%d ", *(pInt+i));
    }
    printf("\n");
};

void asOutput(char *input, char *output) {
    char *pIntput = input, *pOutput = output;
    while(*output++ = *pIntput++ ) {

    }
    *output = '\0';
};

int main() {
    char pCh[] = "hello world!!!";
    int a[5] = {5, 4, 6, 7, 8};
    char buf[20];
    asInput(pCh);
    printf("pch: %s \n", pCh);
    asInput(a, sizeof(a) / sizeof(int));

    asOutput(pCh, buf);
    printf("buf: %s \n", buf);
    return 0;
}