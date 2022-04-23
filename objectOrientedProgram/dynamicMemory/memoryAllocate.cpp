//**************************
// Author:  yh
// Time:    2022/1/27
//**************************

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
int g_i1 = 1, g_i2 = 0, g_i3;
static int g_si1 = 1, g_si2 = 0, g_si3;

int main() {
    static int s_i1 = 1, s_i2 = 0, s_i3;
    int i1 = 1, i2 = 0, i3;
    char cStr[20] = "lyh";
    char cStr1[10] = "lyh";
    char cStr2[10];
    float f = 0.0;
    float f1;
    char cStr3[10] = "lyh";
    char cStr4[10];
    char*p = (char *)malloc(64);
    char*q = "hello world!";
    strncpy(p, "hello world!", sizeof(p));

    /* stack area */
    printf("stack addr start:                       \n");
    printf("local intern init i1:                   %p, %d\n", &i1, &i1);
    printf("local intern init i2:                   %p, %d\n", &i2, &i2);
    printf("local intern not init i3:               %p, %d\n", &i3, &i3);
    printf("local intern not init i3 end:           %p, %d\n", size_t(&i3) - sizeof(i3), size_t(&i3) - sizeof(i3));

    /* string area*/
    printf("string addr start:                      %p, %d\n", (size_t)cStr + sizeof(cStr), (size_t)cStr + sizeof(cStr));
    printf("cStr:                                   %p, %d\n", &cStr, &cStr);
    printf("cStr1:                                  %p, %d\n", &cStr1, &cStr1);
    printf("cStr2:                                  %p, %d\n", cStr2, cStr2);
    printf("f:                                      %p, %d\n", &f, &f);
    printf("f1:                                     %p, %d\n", &f1, &f1);
    printf("cStr3:                                  %p, %d\n", &cStr3, &cStr3);
    printf("cStr4:                                  %p, %d\n", cStr4, cStr4);
    printf("q:                                      %p, %d\n", &q, &q);
    printf("string addr end:                        \n");
    printf("stack addr end:                         \n");

    /* heap area */
    printf("heap addr start:                        \n");
    printf("heap end:                               %p, %d\n", p + 100, p + 100);
    printf("heap start:                             %p, %d\n", p, p);
    printf("heap addr end:                          \n");

    /* static area start */
    printf("static area start:                      \n");
    /* bss segment */
    printf("local intern static not init s_i3:      %p, %d\n", &s_i3, &s_i3);
    printf("local intern static init s_i2:          %p, %d\n", &s_i2, &s_i2);
    printf("global extern static not init g_si3:    %p, %d\n", &g_si3, &g_si3);
    printf("global extern static init g_si2:        %p, %d\n", &g_si2, &g_si2);
    printf("global extern not init g_i3:            %p, %d\n", &g_i3, &g_i3);
    printf("global extern init g_i2:                %p, %d\n", &g_i2, &g_i2);

    /*constant area*/
    printf("text constant area addr start:          %p, %d\n", &"hello world!", &"hello world!");

    /* data segment */
    printf("local intern static init s_i1:          %p, %d\n", &s_i1, &s_i1);
    printf("global extern static init g_si1:        %p, %d\n", &g_si1, &g_si1);
    printf("global extern init g_i1:                %p, %d\n", &g_i1, &g_i1);

    printf("static area end:                        \n");
    /* static area end */

    /* code area and */
    printf("code area start:                        \n");
    printf("code addr start:                        %p, %d\n", &main, &main);
    printf("code area and:                          \n");
    free(p);
    return 0;
}













