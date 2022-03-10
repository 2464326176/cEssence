//**************************
// Author:  yh
// Time:    2022/3/6
//**************************
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void test() {
    char a[] = "i am a student";
    char b[64];

    for (int i = 0; *(a + i) != '\0'; i++) {
        *(b + i) = *(a + i);
    }

    b[i] = '\0'; //÷ÿ“™
    printf("a:%s \n", a);
    printf("b:%s \n", b);
    return;
}

void copy_str1(char *from, char *to) {
    for (; *from != '\0'; from++, to++) {
        *to = *from;
    }
    *to = '\0';
    return;
}

void copy_str2(char *from, char *to) {
    for (; *from != '\0';) {
        *to++ = *from++;
    }
    *to = '\0';
    return;
}

void copy_str3(char *from, char *to) {
    while ((*to = *from) != '\0') {
        from++;
        to++;
    }
}

void copy_str4(char *from, char *to) {
    while ((*to++ = *from++) != '\0') { ;}
}


void copy_str5(char *from, char *to) {
    while ((*to++ = *from++)) { ;
    }
}


void copy_str_err(char *from, char *to) {
    while ((*to++ = *from++)) { ;
    }

    printf("from:%s \n", from);
}

int copy_str_good(char *from, char *to) {
    char *tmpfrom = from;
    char *tmpto = to;
    if (from == NULL || to == NULL) {
        return -1;
    }


    while (*tmpto++ = *tmpfrom++);  //ø’”Ôæ‰
    printf("from:%s \n", from);
}

int main() {
    int ret = 0;
    char *from = "abcd";
    char buf2[20];
    /*copy_str25_err(from, buf2);
    copy_str26_good(from, buf2);*/
    return 0;
}
