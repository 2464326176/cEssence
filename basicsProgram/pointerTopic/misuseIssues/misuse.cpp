#include <iostream>
#include <stdint.h>

using namespace std;

#define PINT int *
typedef int *PINT1;

int main(int argc, char **argv) {
    int val = 6;
    int *p1, p2;  // p1 int *, p2 int;
    PINT p3, p4;  // p3 int *, p4 int;
    PINT1 p5, p6; // p5 int *, p6 int *;
    p1 = &val;
    // p2 = &val;
    p3 = &val;
    // p4 = &val;
    p5 = &val;
    p6 = &val;

    int num = INT32_MAX /*2147483647*/;
    int *pi = &num;
    short *ps = (short *)pi;
    printf("pi: %p, value: %x, %d\n", pi, *pi, *pi);
    printf("pi: %p, value: %hx, %hd\n", ps, *ps, *ps);
    return 0;
}