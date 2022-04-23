//**************************
// Author:  yh
// Time:    2022/3/15
//**************************

#include <stdio.h>
#include <stdlib.h>

//fgetc fputc
int _fgetc_fputc() {
    FILE *fp;
    char ch, filename[10];
    printf("please input file name:\n");
    scanf("%s", filename);
    if((fp = fopen(filename, "w+"))  == NULL) {
        printf("open file %s error", filename);
        exit(0);
    }

    ch = getchar();
    printf("# exit:\n");
    ch = getchar();
    while(ch != '#') {
        fputc(ch, fp);
        putchar(ch);
        ch = getchar();
    }
    fclose(fp);
    putchar('\n');
    return 0;
}


int main() {
    FILE *fp = fopen("", "r+");


    return 0;
}