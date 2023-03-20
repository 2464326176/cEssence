#include <iostream>

int fun(int a, int b) { return a + b; }

// int fun(int &a, int &b) { return a + b; }

double fun(const double a, const double b) { return a + b; }

int main() {
    int a = 2, b = 6;
    printf("%d", fun(a, b));
    printf("%d", fun(1, 2));
    printf("%lf", fun(1.3, 2.4));
    return 0;
}