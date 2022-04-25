//**************************
// Author:  yh
// Time:    2022/4/24
//**************************

#include <iostream>

using namespace std;

void reset(int *pInt) {
    printf("pInt addr:%d pInt:%d,\n", *pInt, pInt);
    *pInt = 0;
    pInt = 0;
    printf("pInt addr:%d pInt:%d,\n", *pInt, pInt);
}
int main() {
    int n = 4, m = 5;
    int *p = &n, *q = &m;
    *p = 6; // n = 6
    p = q;
    printf("m addr:%d m:%d, n addr:%d n:%d\n", m, &m, n, &n);

    reset(&m);
    printf("m addr:%d m:%d, n addr:%d n:%d\n", m, &m, n, &n);

    return 0;
}